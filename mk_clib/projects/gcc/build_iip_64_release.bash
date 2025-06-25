#!/usr/bin/env bash

#set -x
set -e
mk_this_dir="$(dirname -- $0)"
mk_src_dir="${mk_this_dir}"/../../src
mk_app_dir="${mk_this_dir}"/../../app
cp "${mk_app_dir}"/iip.c "${mk_app_dir}"/iip.cpp
if [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ]; then
	mk_exe_name_suffix="64r.exe"
else
	mk_exe_name_suffix=".elf"
fi
g++ -std=c++20 -O3 -g0 -static -fPIE -s -DNDEBUG -Dmk_lang_jumbo_want=1 -Wall -Wextra -Wno-unused-function -flarge-source-files -o "${mk_this_dir}"/iip"${mk_exe_name_suffix}" "${mk_app_dir}"/iip.cpp -lws2_32 -lbcrypt -lntdll
strip "${mk_this_dir}"/iip"${mk_exe_name_suffix}"
rm -rf "${mk_app_dir}"/iip.cpp
