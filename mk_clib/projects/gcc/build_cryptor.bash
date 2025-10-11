#!/usr/bin/env bash

#set -x
set -e
mk_this_dir="$(dirname -- $0)"
mk_src_dir="${mk_this_dir}"/../../src
mk_app_dir="${mk_this_dir}"/../../app
cp "${mk_app_dir}"/cryptor.c "${mk_app_dir}"/cryptor.cpp
if [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ]; then
	mk_exe_name_suffix=".exe"
else
	mk_exe_name_suffix=".elf"
fi
g++ -std=c++20 -O3 -g0 -static -fPIE -s -DNDEBUG -Dmk_lang_jumbo_want=1 -Wall -Wextra -flarge-source-files -o "${mk_this_dir}"/cryptor"${mk_exe_name_suffix}" "${mk_app_dir}"/cryptor.cpp
#g++ -O0 -ggdb -g3 -static -fPIE -Dmk_lang_jumbo_want=1 -Wall -Wextra -flarge-source-files -o "${mk_this_dir}"/cryptor"${mk_exe_name_suffix}" "${mk_app_dir}"/cryptor.cpp
strip "${mk_this_dir}"/cryptor"${mk_exe_name_suffix}"
rm -rf "${mk_app_dir}"/cryptor.cpp
