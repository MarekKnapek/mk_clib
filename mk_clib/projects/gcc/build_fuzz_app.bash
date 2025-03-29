#!/usr/bin/env bash

set -x
set -e
mk_this_dir="$(dirname -- $0)"
mk_src_dir="${mk_this_dir}"/../../src
mk_app_dir="${mk_this_dir}"/../../app
cp "${mk_app_dir}"/mkcfa.c "${mk_app_dir}"/mkcfa.cpp
if [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ]; then
	mk_exe_name_suffix=".exe"
	mk_libs="-lbcrypt"
else
	mk_exe_name_suffix=".elf"
	mk_libs=""
fi
g++ -O0 -g -Wall -Wextra -Wno-misleading-indentation -Dmk_lang_jumbo_want=1 -o "${mk_this_dir}"/mkcfa"${mk_exe_name_suffix}" "${mk_app_dir}"/mkcfa.cpp "${mk_libs}"
rm -rf "${mk_app_dir}"/mkcfa.cpp
