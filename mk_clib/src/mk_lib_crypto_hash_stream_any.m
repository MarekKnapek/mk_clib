define(`mk_lib_crypto_hash_stream_any_mm_per_hash_c', `define(`mm_x', ``$1'')mm_x(`$2', `$4')undefine(`mm_x')')dnl
define(`mk_lib_crypto_hash_stream_any_mm_per_hash_b', `mk_lib_crypto_hash_stream_any_mm_per_hash_c(`$1', `$4', `$2', eval($3 - $# + 1))ifelse(`$#', `5', `', ``$2'`'mk_lib_crypto_hash_stream_any_mm_per_hash_b(`$1', `$2', `$3', shift(shift(shift(shift($@)))))')')dnl
define(`mk_lib_crypto_hash_stream_any_mm_per_hash_a', `mk_lib_crypto_hash_stream_any_mm_per_hash_b(`$1', `$2', `$#', shift(shift($@)))')dnl
define(`mk_lib_crypto_hash_stream_any_mm_per_hash', `mk_lib_crypto_hash_stream_any_mm_per_hash_a(`$1', `$2',
`blake2s_128',
`blake2s_160',
`blake2s_224',
`md2',
`md4',
`md5',
`sha0',
`sha1',
`sha2_224',
`sha2_256',
`sha2_384',
`sha2_512',
`sha2_512_224',
`sha2_512_256',
`sha3_224',
`sha3_256',
`sha3_384',
`sha3_512',
`')')dnl
