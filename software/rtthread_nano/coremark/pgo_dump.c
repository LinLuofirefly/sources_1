#include <stddef.h>
#include <stdint.h>

#include <gcov.h>

#define PGO_STREAM_MMIO_ADDR 0x80200060u
#define PGO_ALLOC_BYTES      (64u * 1024u)

extern const struct gcov_info *const __gcov_info_start[];
extern const struct gcov_info *const __gcov_info_end[];

static unsigned char pgo_alloc_buffer[PGO_ALLOC_BYTES];
static unsigned int pgo_alloc_offset;

size_t strlen(const char *text)
{
    const char *end = text;

    while (*end != '\0')
    {
        end++;
    }
    return (size_t)(end - text);
}

static void pgo_emit_char(unsigned char value)
{
    *(volatile uint32_t *)(uintptr_t)PGO_STREAM_MMIO_ADDR = value;
}

static void pgo_dump_bytes(const void *data, unsigned int length, void *arg)
{
    static const char digits[] = "0123456789abcdef";
    const unsigned char *bytes = (const unsigned char *)data;
    unsigned int index;

    (void)arg;
    for (index = 0u; index < length; index++)
    {
        pgo_emit_char((unsigned char)digits[bytes[index] >> 4]);
        pgo_emit_char((unsigned char)digits[bytes[index] & 0x0fu]);
    }
}

static void pgo_dump_filename(const char *filename, void *arg)
{
    __gcov_filename_to_gcfn(filename, pgo_dump_bytes, arg);
}

static void *pgo_allocate(unsigned int length, void *arg)
{
    unsigned int aligned_length = (length + 7u) & ~7u;
    void *allocation;

    (void)arg;
    if ((aligned_length > PGO_ALLOC_BYTES) ||
        (pgo_alloc_offset > PGO_ALLOC_BYTES - aligned_length))
    {
        return NULL;
    }
    allocation = &pgo_alloc_buffer[pgo_alloc_offset];
    pgo_alloc_offset += aligned_length;
    return allocation;
}

void coremark_pgo_dump(void)
{
    const struct gcov_info *const *info = __gcov_info_start;
    uint32_t interrupt_enable_mask = 8u;

    /* CoreMark has already stopped its measurement counter.  Keep the
     * simulation-only gcov serializer atomic so an RT-Thread timer interrupt
     * cannot context-switch through libgcov while it walks its state. */
    __asm__ volatile ("csrrc x0, mstatus, %0"
                      : : "r"(interrupt_enable_mask) : "memory");

    __asm__ volatile ("" : "+r"(info));
    while (info != __gcov_info_end)
    {
        pgo_alloc_offset = 0u;
        __gcov_info_to_gcda(*info, pgo_dump_filename, pgo_dump_bytes,
                            pgo_allocate, NULL);
        pgo_emit_char('\n');
        info++;
    }
}
