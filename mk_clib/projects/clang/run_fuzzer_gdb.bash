#!/usr/bin/env bash

set -x
set -e
mk_this_dir="$(dirname -- $0)"
gdb --args "${mk_this_dir}"/fuzzer.elf "${mk_this_dir}"/corpus
