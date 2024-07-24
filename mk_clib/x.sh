clang \
-Dmk_lang_jumbo_want=1 \
-Dmk_lang_assert_want=1 \
-Dmk_lang_crash_detail_want=1 \
-O2 \
-Isrc \
x.c \
-o x.elf \
-lX11 \
