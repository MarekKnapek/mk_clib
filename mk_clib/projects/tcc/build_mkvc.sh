this_dir="$(dirname -- $0)"
pushd ${this_dir}
tcc -O2 -DNDEBUG -Dmk_lib_mt_posix_has=1 ../../app/mkvc.c
popd
