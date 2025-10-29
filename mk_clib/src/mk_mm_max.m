define(`mk_mm_max_0', `---')dnl
define(`mk_mm_max_1', ``$1'')dnl
define(`mk_mm_max_2', ``mk_lang_max($1, $2)'')dnl
define(`mk_mm_max_3', ``mk_lang_max($1, $2)'')dnl
define(`mk_mm_max_i', `ifelse(`$#', `0', `mk_mm_max_0($@)', `ifelse(`$#', `1', `mk_mm_max_1($@)', `ifelse(`$#', `2', `mk_mm_max_2($@)', `mk_mm_max_3($@), mk_mm_max_i(shift(shift($@)))')')')')dnl
define(`mk_mm_max', `ifelse(`$#', `1', ``$1'', `mk_mm_max(mk_mm_max_i($@))')')dnl
define(`mk_mm_max2', `ifelse(`$#', `2', ``$1'', `$0(mk_mm_max_i($@))')')dnl
