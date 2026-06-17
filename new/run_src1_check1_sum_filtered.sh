#!/usr/bin/env bash
set -euo pipefail

/mnt/c/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1/new/run_src1_check1_sum.sh \
    | tee /tmp/src1_replay_fix_check.log \
    | grep -E 'SEG_WRITE|BUG_|F_STATE0_|F_RET|MUL_CALL|MUL_RET|FIRST_CHECK1_SUM_MISMATCH|CHECK1_OUTER_OK|LED_WRITE|CHECK1_DONE|TIMEOUT'
