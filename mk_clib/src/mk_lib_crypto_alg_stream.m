define(`mk_lib_crypto_alg_stream_mm_list', `dnl
`aes_128', `AES-128', dnl
`aes_192', `AES-192', dnl
`aes_256', `AES-256', dnl
`aes_portable_128', `AES-128 (portable)', dnl
`aes_portable_192', `AES-192 (portable)', dnl
`aes_portable_256', `AES-256 (portable)', dnl
`aes_x86_aesni_128', `AES-128 (x86 AES-NI)', dnl
`aes_x86_aesni_192', `AES-192 (x86 AES-NI)', dnl
`aes_x86_aesni_256', `AES-256 (x86 AES-NI)', dnl
`aes_x86_vaes256_128', `AES-128 (x86 VAES-256)', dnl
`aes_x86_vaes256_192', `AES-192 (x86 VAES-256)', dnl
`aes_x86_vaes256_256', `AES-256 (x86 VAES-256)', dnl
`aes_x86_vaes512_128', `AES-128 (x86 VAES-512)', dnl
`aes_x86_vaes512_192', `AES-192 (x86 VAES-512)', dnl
`aes_x86_vaes512_256', `AES-256 (x86 VAES-512)', dnl
`serpent', `Serpent', dnl
`'')dnl
define(`mk_lib_crypto_alg_stream_mm_hlf', `ifelse(`$#', `1', ``$1'', ``'`$1', mk_lib_crypto_alg_stream_mm_hlf(shift(shift($@)))')')`'dnl
define(`mk_lib_crypto_alg_stream_mm_half', `mk_lib_crypto_alg_stream_mm_hlf(mk_lib_crypto_alg_stream_mm_list())')`'dnl
define(`mk_lib_crypto_alg_stream_mm_recurse', `ifelse(`$#', `2', `', `$1($2)')')`'dnl
