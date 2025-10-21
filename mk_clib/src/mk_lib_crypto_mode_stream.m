define(`mk_lib_crypto_mode_stream_mm_list', `dnl
`cbc', `aes_128', `CBC-AES-128', dnl
`cbc', `aes_192', `CBC-AES-192', dnl
`cbc', `aes_256', `CBC-AES-256', dnl
`cbc', `serpent', `CBC-Serpent', dnl
`cfb', `aes_128', `CFB-AES-128', dnl
`cfb', `aes_192', `CFB-AES-192', dnl
`cfb', `aes_256', `CFB-AES-256', dnl
`cfb', `serpent', `CFB-Serpent', dnl
`cfb8', `aes_128', `CFB8-AES-128', dnl
`cfb8', `aes_192', `CFB8-AES-192', dnl
`cfb8', `aes_256', `CFB8-AES-256', dnl
`cfb8', `serpent', `CFB8-Serpent', dnl
`ctr', `aes_128', `CTR-AES-128', dnl
`ctr', `aes_192', `CTR-AES-192', dnl
`ctr', `aes_256', `CTR-AES-256', dnl
`ctr', `serpent', `CTR-Serpent', dnl
`ecb', `aes_128', `ECB-AES-128', dnl
`ecb', `aes_192', `ECB-AES-192', dnl
`ecb', `aes_256', `ECB-AES-256', dnl
`ecb', `serpent', `ECB-Serpent', dnl
`ofb', `aes_128', `OFB-AES-128', dnl
`ofb', `aes_192', `OFB-AES-192', dnl
`ofb', `aes_256', `OFB-AES-256', dnl
`ofb', `serpent', `OFB-Serpent', dnl
`pcbc', `aes_128', `PCBC-AES-128', dnl
`pcbc', `aes_192', `PCBC-AES-192', dnl
`pcbc', `aes_256', `PCBC-AES-256', dnl
`pcbc', `serpent', `PCBC-Serpent', dnl
`'')dnl
define(`mk_lib_crypto_mode_stream_mm_recurse', `ifelse(`$#', `2', `', `$1(`$2', `$3', `$4')mk_lib_crypto_mode_stream_mm_recurse(`$1', shift(shift(shift(shift($@)))))')')`'dnl
dnl
dnl
dnl
define(`mk_lib_crypto_mode_stream_mm_strings_impl', `ifelse(`$#', `1', `', ``'`$1'_`$2', `$3', mk_lib_crypto_mode_stream_mm_strings_impl(shift(shift(shift($@))))')')`'dnl
define(`mk_lib_crypto_mode_stream_mm_strings', `mk_lib_crypto_mode_stream_mm_strings_impl(mk_lib_crypto_mode_stream_mm_list())')`'dnl
