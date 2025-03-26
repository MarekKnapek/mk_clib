#!/usr/bin/env bash

set -x
set -e
mk_this_dir="$(dirname -- $0)"
mk_src_dir="${mk_this_dir}"/../../src
mk_app_dir="${mk_this_dir}"/../../app
cp "${mk_app_dir}"/mkci.c "${mk_app_dir}"/mkci.cpp
if [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ]; then
	mk_exe_name_suffix=".exe"
else
	mk_exe_name_suffix=".elf"
fi
clang++ -O0 -g -Wall -Wextra -pedantic -Dmk_lang_jumbo_want=1 -o "${mk_this_dir}"/mkci"${mk_exe_name_suffix}" "${mk_app_dir}"/mkci.cpp
rm -rf "${mk_app_dir}"/mkci.cpp
