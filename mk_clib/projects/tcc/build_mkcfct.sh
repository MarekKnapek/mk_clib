this_dir="$(dirname -- $0)"
pushd ${this_dir}
tcc -O2 -DNDEBUG ../../app/mkcfct.c
popd
