define(`mk_mm_concat', `ifelse(`$#', `1', ``$1'', ``$1'$0(shift($@))')')dnl
