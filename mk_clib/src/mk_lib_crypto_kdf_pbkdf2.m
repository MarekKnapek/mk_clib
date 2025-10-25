include(`mk_lib_crypto_hash.m')dnl
define(`mk_lib_crypto_kdf_pbkdf2_mm_list', `mk_lib_crypto_hash_mm_list()')dnl
define(`mk_lib_crypto_kdf_pbkdf2_mm_for_one', `define(`mk_lib_crypto_kdf_pbkdf2_mm_one', ``'$1')`'`'mk_lib_crypto_kdf_pbkdf2_mm_one($2, $3)`'`'undefine(`mk_lib_crypto_kdf_pbkdf2_mm_one')')`'dnl
define(`mk_lib_crypto_kdf_pbkdf2_mm_for_all_impl', `ifelse(`$#', `2', `', `mk_lib_crypto_kdf_pbkdf2_mm_for_one(`$1', $2, $3)mk_lib_crypto_kdf_pbkdf2_mm_for_all_impl(`$1', shift(shift(shift($@))))')')`'dnl
define(`mk_lib_crypto_kdf_pbkdf2_mm_for_all', `mk_lib_crypto_kdf_pbkdf2_mm_for_all_impl(`$1', mk_lib_crypto_kdf_pbkdf2_mm_list())')`'dnl
