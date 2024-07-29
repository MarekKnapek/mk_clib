clang \
-Dmk_lang_jumbo_want=1 \
-Dmk_lang_assert_want=1 \
-Dmk_lang_crash_detail_want=1 \
-Dmk_lib_x11_headers_want=1 \
-Dmk_clib_app_fe_posix_mallocatorg_want=11 \
-Dmk_clib_app_fe_posix_mallocatorg_statistics_want=1 \
-O0 \
-g \
-fsanitize=address \
x.c \
-o x.elf \
-lX11 \
