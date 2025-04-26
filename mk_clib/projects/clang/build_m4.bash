#!/usr/bin/env bash

#set -x
set -e
mk_this_dir="$(dirname -- $0)"
mk_src_dir="${mk_this_dir}"/../../src
for mk_file in "${mk_src_dir}"/*.m4; do
	m4 -I "${mk_src_dir}" -- "${mk_file}" > "${mk_file:0:-3}"
done
