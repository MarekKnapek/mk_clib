define(`mk_lib_app_cryptor_mode_stream_mm_mode_list', `dnl
`cbc', `CBC', dnl
`cfb', `CFB', dnl
`cfb8', `CFB8', dnl
`ctr', `CTR', dnl
`ecb', `ECB', dnl
`ofb', `OFB', dnl
`pcbc', `PCBC', dnl
`'')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_alg_list', `dnl
`aes_128', `AES-128', dnl
`aes_192', `AES-192', dnl
`aes_256', `AES-256', dnl
`serpent', `Serpent', dnl
`'')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_is_empty_or_x', `ifelse(`$#', `0', `1', ifelse(`$1', `x', `1', `0'))')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_concatenate_two', `ifelse(`$#', `2', ``$1, $2'', `ifelse(`$#', `1', ``$1'', `mk_mm_fatal_error(`One or two arguments expected.')')')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_extract_one_idx', `ifelse(eval($# >= 2), `1', `ifelse(`$1', `0', `ifelse(`$2', `', `x', ``$2'')', `$0(eval($1 - 1), shift(shift($@)))')', `x')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx', `ifelse(eval($# >= 3), `1', `ifelse(`$1', `0', ``$2', `$3'', `$0(eval($1 - 1), shift(shift(shift($@))))')', `x')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_product_impl_3', `define(`mk_mm_x', `$1')`'mk_mm_x(`$2', `$3', `$4', `$5')`'undefine(`mk_mm_x')`'')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_product_impl_2', `ifelse(mk_lib_app_cryptor_mode_stream_mm_is_empty_or_x(mk_lib_app_cryptor_mode_stream_mm_concatenate_two(mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx(`$2', $3))), `1', `', `mk_lib_app_cryptor_mode_stream_mm_product_impl_3(`$1', `$4', `$5', mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx(`$2', $3))`'$0(`$1', eval($2 + 1), `$3', `$4', `$5')')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_product_impl_1', `ifelse(mk_lib_app_cryptor_mode_stream_mm_is_empty_or_x(mk_lib_app_cryptor_mode_stream_mm_concatenate_two(mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx(`$2', $4))), `1', `', `mk_lib_app_cryptor_mode_stream_mm_product_impl_2(`$1', `$3', `$5', mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx(`$2', $4))`'$0(`$1', eval($2 + 1), `$3', `$4', `$5')`'')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_product', `mk_lib_app_cryptor_mode_stream_mm_product_impl_1(`$1', 0, 0, `$2', `$3')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_for_all', `mk_lib_app_cryptor_mode_stream_mm_product(`$1', `mk_lib_app_cryptor_mode_stream_mm_mode_list', `mk_lib_app_cryptor_mode_stream_mm_alg_list')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_for_single_2', `define(`mk_mm_x', `$1')`'mk_mm_x(`$2', `$3')`'undefine(`mk_mm_x')`'')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_for_single_1', `ifelse(mk_lib_app_cryptor_mode_stream_mm_is_empty_or_x(mk_lib_app_cryptor_mode_stream_mm_concatenate_two(mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx(`$2', $3))), `1', `', `mk_lib_app_cryptor_mode_stream_mm_for_single_2(`$1', mk_lib_app_cryptor_mode_stream_mm_extract_pair_idx(`$2', $3))`'$0(`$1', eval($2 + 1), `$3')')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_for_modes_all', `mk_lib_app_cryptor_mode_stream_mm_for_single_1(`$1', `0', `mk_lib_app_cryptor_mode_stream_mm_mode_list')')dnl
define(`mk_lib_app_cryptor_mode_stream_mm_for_algs_all', `mk_lib_app_cryptor_mode_stream_mm_for_single_1(`$1', `0', `mk_lib_app_cryptor_mode_stream_mm_alg_list')')dnl
