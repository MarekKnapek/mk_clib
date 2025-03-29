define(`mk_lib_crypto_xof_stream_any_mm_per_xof_c', `define(`mm_x', ``$1'')mm_x(`$2', `$4')undefine(`mm_x')')dnl
define(`mk_lib_crypto_xof_stream_any_mm_per_xof_b', `mk_lib_crypto_xof_stream_any_mm_per_xof_c(`$1', `$4', `$2', eval($3 - $# + 1))ifelse(`$#', `5', `', ``$2'`'mk_lib_crypto_xof_stream_any_mm_per_xof_b(`$1', `$2', `$3', shift(shift(shift(shift($@)))))')')dnl
define(`mk_lib_crypto_xof_stream_any_mm_per_xof_a', `mk_lib_crypto_xof_stream_any_mm_per_xof_b(`$1', `$2', `$#', shift(shift($@)))')dnl
define(`mk_lib_crypto_xof_stream_any_mm_per_xof', `mk_lib_crypto_xof_stream_any_mm_per_xof_a(`$1', `$2',
`shake_128',
`shake_256',
`')')dnl
