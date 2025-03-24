#!/usr/bin/env bash

set -x
set -e
mk_this_dir="$(dirname -- $0)"
mk_src_dir="${mk_this_dir}"/../../src
mk_app_dir="${mk_this_dir}"/../../app
cp "${mk_app_dir}"/mkcf.c "${mk_app_dir}"/mkcf.cpp
clang++ -fsanitize=address,fuzzer -O0 -g -Wall -Wextra -pedantic -Dmk_lang_jumbo_want=1 -Dmk_lang_debug_break_want=0 -o "${mk_this_dir}"/fuzzer.elf "${mk_app_dir}"/mkcf.cpp -lssl -lcrypto
rm -rf "${mk_app_dir}"/mkcf.cpp
