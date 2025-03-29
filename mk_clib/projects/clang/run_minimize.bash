#!/usr/bin/env bash

set -x
set -e
mk_this_dir="$(dirname -- $0)"
rm -rf "${mk_this_dir}"/corpus_new
mkdir "${mk_this_dir}"/corpus_new
"${mk_this_dir}"/fuzzer.elf -merge=1 "${mk_this_dir}"/corpus_new "${mk_this_dir}"/corpus
cp "${mk_this_dir}"/corpus/.gitignore "${mk_this_dir}"/corpus_new/.gitignore
rm -rf "${mk_this_dir}"/corpus
mv "${mk_this_dir}"/corpus_new "${mk_this_dir}"/corpus
