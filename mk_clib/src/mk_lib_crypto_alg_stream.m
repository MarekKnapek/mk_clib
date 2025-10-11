define(`mk_lib_crypto_alg_stream_mm_list', `dnl
`aes_128', `AES-128', dnl
`aes_192', `AES-192', dnl
`aes_256', `AES-256', dnl
`serpent', `Serpent', dnl
`'')dnl
define(`mk_lib_crypto_alg_stream_mm_hlf', `ifelse(`$#', `1', ``$1'', ``'`$1', mk_lib_crypto_alg_stream_mm_hlf(shift(shift($@)))')')`'dnl
define(`mk_lib_crypto_alg_stream_mm_half', `mk_lib_crypto_alg_stream_mm_hlf(mk_lib_crypto_alg_stream_mm_list())')`'dnl
define(`mk_lib_crypto_alg_stream_mm_recurse', `ifelse(`$#', `2', `', `$1(`$2')mk_lib_crypto_alg_stream_mm_recurse(`$1', shift(shift($@)))')')`'dnl
