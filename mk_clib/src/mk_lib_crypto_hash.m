define(`mk_lib_crypto_hash_mm_list', `dnl
`blake2b_256', `BLAKE2b-256', dnl
`blake2b_384', `BLAKE2b-384', dnl
`blake2b_512', `BLAKE2b-512', dnl
`blake2s_128', `BLAKE2s-128', dnl
`blake2s_160', `BLAKE2s-160', dnl
`blake2s_224', `BLAKE2s-224', dnl
`blake2s_256', `BLAKE2s-256', dnl
`blake3', `BLAKE3', dnl
`md2', `MD2', dnl
`md4', `MD4', dnl
`md5', `MD5', dnl
`sha0', `SHA-0', dnl
`sha1', `SHA-1', dnl
`sha2_224', `SHA-224', dnl
`sha2_256', `SHA-256', dnl
`sha2_384', `SHA-384', dnl
`sha2_512', `SHA-512', dnl
`sha2_512_224', `SHA-512/224', dnl
`sha2_512_256', `SHA-512/256', dnl
`sha3_224', `SHA3-224', dnl
`sha3_256', `SHA3-256', dnl
`sha3_384', `SHA3-384', dnl
`sha3_512', `SHA3-512', dnl
`streebog_256', `Streebog-256', dnl
`streebog_512', `Streebog-512', dnl
`tiger2_128', `Tiger2/128', dnl
`tiger2_160', `Tiger2/160', dnl
`tiger2_192', `Tiger2/192', dnl
`tiger_128', `Tiger/128', dnl
`tiger_160', `Tiger/160', dnl
`tiger_192', `Tiger/192', dnl
`whirlpool', `Whirlpool', dnl
`'')dnl
define(`mk_lib_crypto_hash_mm_recurse_impl', `ifelse(`$#', `2', `', `$1(`$2', `$3')mk_lib_crypto_hash_mm_recurse(`$1', shift(shift(shift($@))))')')`'dnl
define(`mk_lib_crypto_hash_mm_recurse', `mk_lib_crypto_hash_mm_recurse_impl(`$1', mk_lib_crypto_hash_mm_list())')`'dnl
dnl
dnl
dnl
dnl
dnl
define(`mk_lib_crypto_hash_mm_for_one', `define(`mk_lib_crypto_hash_mm_one', ``'$1')`'`'mk_lib_crypto_hash_mm_one($2, $3)`'`'undefine(`mk_lib_crypto_hash_mm_one')')`'dnl
define(`mk_lib_crypto_hash_mm_pr_for_all', `ifelse(`$#', `2', `', `mk_lib_crypto_hash_mm_for_one(`$1', $2, $3)mk_lib_crypto_hash_mm_pr_for_all(`$1', shift(shift(shift($@))))')')`'dnl
define(`mk_lib_crypto_hash_mm_for_all', `mk_lib_crypto_hash_mm_pr_for_all(`$1', mk_lib_crypto_hash_mm_list())')`'dnl
