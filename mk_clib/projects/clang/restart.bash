#!/usr/bin/env bash

set -x
set -e

mk_this_dir="$(dirname -- $0)"

bash "${mk_this_dir}"/build_m4.bash
bash "${mk_this_dir}"/build_fuzzer.bash
bash "${mk_this_dir}"/run_minimize.bash
bash "${mk_this_dir}"/run_fuzzer_plain.bash
