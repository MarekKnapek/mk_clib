define(`mk_lib_crypto_padding_mm_list', `dnl
`pkcs7', `PKCS#7', dnl
`iso9797pm2', `ISO-9797pm2', dnl
`'')dnl
define(`mk_lib_crypto_padding_mm_recurse_impl', `ifelse(`$#', `2', `', `$1(`$2', `$3')mk_lib_crypto_padding_mm_recurse(`$1', shift(shift(shift($@))))')')`'dnl
define(`mk_lib_crypto_padding_mm_recurse', `mk_lib_crypto_padding_mm_recurse_impl(`$1', mk_lib_crypto_padding_mm_list())')`'dnl
