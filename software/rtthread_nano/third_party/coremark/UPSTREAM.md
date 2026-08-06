# CoreMark upstream

- Project: EEMBC CoreMark
- Repository: https://github.com/eembc/coremark
- Revision: `1f483d5b8316753a742cbf5590caf5bd0a4e4777`
- Imported: 2026-07-31
- License: Apache-2.0; also read `LICENSE.md` for the EEMBC acceptable-use terms

The benchmark sources were imported from the official revision archive. The
checksums of `core_list_join.c`, `core_main.c`, `core_matrix.c`, `core_state.c`
and `core_util.c` match the bundled `coremark.md5` file. The imported
`coremark.h` has MD5 `b0ec69b6c8e75853d06accb3b1bcf534`, while that checksum
file records `8ca974c013b380dc7f0d6d1afb76eb2d` for the header. This discrepancy
is documented instead of silently rewriting either upstream file.

Keep the benchmark sources and header unchanged; target-specific work belongs
in the separate RT-Thread `core_portme.c`, `core_portme.h` and build integration.
