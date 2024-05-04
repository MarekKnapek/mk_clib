set -x
set -e
this_dir="$(dirname -- ${0})"
bash "${this_dir}/../../mk_clib/projects/gcc/build_m4.sh"
gcc-13 -v
gcc-13 -std=c${2} -DNDEBUG -Dmk_lang_assert_want=1 -Dmk_lang_crash_detail_want=1 -Dmk_clib_test_smol_want=1 -D_POSIX_C_SOURCE=200809l -D_XOPEN_SOURCE=700 -D_GNU_SOURCE -O3 -Wall -Wextra -Wpedantic -o ${this_dir}/../../mk_clib/app/${1}-c${2}.elf ${this_dir}/../../mk_clib/app/${1}.c 2>&1 | tee ${this_dir}/../../mk_clib/app/${1}-c${2}.txt
${this_dir}/../../mk_clib/app/${1}-c${2}.elf
echo "Gud."
