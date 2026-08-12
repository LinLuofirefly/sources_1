# CoreMark PGO profile

These GCC 13.2.0 `.gcda` files were captured from a 100-iteration
single-context CoreMark performance run on this RV32IM RTL. They cover only
the five upstream CoreMark translation units; RT-Thread, the BSP and the
HC-SR04 driver remain compiled at their separately selected optimization
level.

Use them with:

```sh
make -B BUILD_DIR=build/fpga IROM_WORDS=16384 \
  TIMER_PERIOD_CYCLES=2000000 COREMARK_ITERATIONS=10000 \
  RTTHREAD_OPT_FLAGS=-O1 \
  COREMARK_OPT_FLAGS="-O3 -fprofile-use -fno-profile-values -fprofile-correction" \
  COREMARK_FLAGS_LABEL="-O3 + PGO" \
  PGO_PROFILE_DIR=profiles/coremark_100
```
