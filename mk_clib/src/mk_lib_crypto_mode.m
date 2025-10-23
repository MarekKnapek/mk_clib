define(`mk_lib_crypto_mode_mm_list', `dnl
`cbc', `CBC', dnl
`cfb', `CFB', dnl
`cfb8', `CFB8', dnl
`ctr', `CTR', dnl
`ecb', `ECB', dnl
`ofb', `OFB', dnl
`pcbc', `PCBC', dnl
`xts', `XTS', dnl
`'')dnl
define(`mk_lib_crypto_mode_mm_recurse_impl', `ifelse(`$#', `2', `', `$1(`$2', `$3')mk_lib_crypto_mode_mm_recurse(`$1', shift(shift(shift($@))))')')`'dnl
define(`mk_lib_crypto_mode_mm_recurse', `mk_lib_crypto_mode_mm_recurse_impl(`$1', mk_lib_crypto_mode_mm_list())')`'dnl
