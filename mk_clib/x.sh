if [ 1 -eq 1 ]
then

clang \
-Dmk_lang_jumbo_want=1 \
-Dmk_lang_assert_want=1 \
-Dmk_lang_crash_detail_want=1 \
-Dmk_lib_x11_headers_want=1 \
-Dmk_lib_posix_headers_want=1 \
-Dmk_sl_mallocatorg_statistics_want=1 \
-O0 \
-g \
-fsanitize=address \
x.c \
-o x.elf \
-lX11 \

else

clang \
-Dmk_lang_jumbo_want=1 \
-Dmk_lang_assert_want=1 \
-Dmk_lang_crash_detail_want=1 \
-Dmk_lib_x11_headers_want=1 \
-Dmk_lib_posix_headers_want=1 \
-Dmk_sl_mallocatorg_statistics_want=1 \
-O3 \
x.c \
-o x.elf \
-lX11 \

fi
