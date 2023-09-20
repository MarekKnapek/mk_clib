this_dir="$(dirname -- $0)"
src_dir="$this_dir/../../src"
m4 -I $src_dir -- $src_dir/mk_lib_crypto_alg_aes_128.h.m4          > $src_dir/mk_lib_crypto_alg_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_alg_aes_192.h.m4          > $src_dir/mk_lib_crypto_alg_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_alg_aes_256.h.m4          > $src_dir/mk_lib_crypto_alg_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_aes_128.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_aes_192.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_aes_256.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_serpent.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_aes_128.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_aes_192.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_aes_256.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_serpent.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_aes_128.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_aes_192.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_aes_256.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_serpent.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_aes_128.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_aes_192.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_aes_256.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_serpent.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_aes_128.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_aes_192.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_aes_256.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_serpent.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_aes_128.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_aes_192.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_aes_256.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_serpent.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_serpent.h