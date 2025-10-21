include(`mk_mm_nl.m')dnl
define(`mk_lib_crypto_alg_mm_list_all', `dnl
`aes_128', `AES-128', dnl
`aes_192', `AES-192', dnl
`aes_256', `AES-256', dnl
`serpent', `Serpent', dnl
`'')dnl
dnl
dnl
dnl
define(`mk_lib_crypto_alg_mm_pr_keys', `ifelse(`$#', `1', ``$1'', ``$1', mk_lib_crypto_alg_mm_pr_keys(shift(shift($@)))')')dnl
define(`mk_lib_crypto_alg_mm_keys', `mk_lib_crypto_alg_mm_pr_keys(mk_lib_crypto_alg_mm_list_all())')dnl
define(`mk_lib_crypto_alg_mm_line', `$1, $2')dnl
dnl
dnl
dnl
define(`mk_lib_crypto_alg_mm_call', `define(`mk_lib_crypto_alg_mm_x', `$1')mk_lib_crypto_alg_mm_x($2, $3)undefine(`mk_lib_crypto_alg_mm_x')')dnl
define(`mk_lib_crypto_alg_mm_pr_for_all', `ifelse(`$#', `2', `', `mk_lib_crypto_alg_mm_call(`$1', mk_lib_crypto_alg_mm_line(shift($@)))`'mk_lib_crypto_alg_mm_pr_for_all(`$1', shift(shift(shift($@))))')')dnl
dnl
dnl
dnl
define(`mk_lib_crypto_alg_mm_for_all', `mk_lib_crypto_alg_mm_pr_for_all(`$1', mk_lib_crypto_alg_mm_list_all())')dnl
define(`mk_lib_crypto_alg_mm_for_all_nl', `changecom(`€€€---', `---€€€')mk_lib_crypto_alg_mm_for_all(`$1`'mk_mm_nl()')changecom(`#', `')')dnl
dnl
dnl
dnl
define(`mk_lib_crypto_alg_mm_pr_for_all_sep_nl', `ifelse(`$#', `4', `mk_lib_crypto_alg_mm_call(`$1', mk_lib_crypto_alg_mm_line(shift($@)))', `mk_lib_crypto_alg_mm_call(`$1', mk_lib_crypto_alg_mm_line(shift($@)))mk_mm_nl()mk_lib_crypto_alg_mm_pr_for_all_sep_nl(`$1', shift(shift(shift($@))))')')dnl
define(`mk_lib_crypto_alg_mm_for_all_sep_nl', `mk_lib_crypto_alg_mm_pr_for_all_sep_nl(`$1', mk_lib_crypto_alg_mm_list_all())')dnl
