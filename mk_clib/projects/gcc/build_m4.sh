set -x
set -e
this_dir="$(dirname -- $0)"
src_dir="$this_dir/../../src"
m4 -I $src_dir -- $src_dir/mk_clib_readme.md.m4                        > $src_dir/mk_clib_readme.md
m4 -I $src_dir -- $src_dir/mk_lang_bui_inl_defd.h.m4                   > $src_dir/mk_lang_bui_inl_defd.h
m4 -I $src_dir -- $src_dir/mk_lang_bui_inl_defu.h.m4                   > $src_dir/mk_lang_bui_inl_defu.h
m4 -I $src_dir -- $src_dir/mk_lang_bui_inl_filec.h.m4                  > $src_dir/mk_lang_bui_inl_filec.h
m4 -I $src_dir -- $src_dir/mk_lang_bui_inl_fileh.h.m4                  > $src_dir/mk_lang_bui_inl_fileh.h
m4 -I $src_dir -- $src_dir/mk_lang_info_platform.c.m4                  > $src_dir/mk_lang_info_platform.c
m4 -I $src_dir -- $src_dir/mk_lib_crypto_alg_aes_128.h.m4              > $src_dir/mk_lib_crypto_alg_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_alg_aes_192.h.m4              > $src_dir/mk_lib_crypto_alg_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_alg_aes_256.h.m4              > $src_dir/mk_lib_crypto_alg_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_aes_128.h.m4         > $src_dir/mk_lib_crypto_mode_cbc_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_aes_192.h.m4         > $src_dir/mk_lib_crypto_mode_cbc_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_aes_256.h.m4         > $src_dir/mk_lib_crypto_mode_cbc_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_des.h.m4             > $src_dir/mk_lib_crypto_mode_cbc_des.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_serpent.h.m4         > $src_dir/mk_lib_crypto_mode_cbc_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_tdes2.h.m4           > $src_dir/mk_lib_crypto_mode_cbc_tdes2.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_tdes3.h.m4           > $src_dir/mk_lib_crypto_mode_cbc_tdes3.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_twofish_128.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_twofish_192.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cbc_twofish_256.h.m4     > $src_dir/mk_lib_crypto_mode_cbc_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_aes_128.h.m4     > $src_dir/mk_lib_crypto_mode_cfb_128_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_aes_192.h.m4     > $src_dir/mk_lib_crypto_mode_cfb_128_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_aes_256.h.m4     > $src_dir/mk_lib_crypto_mode_cfb_128_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_serpent.h.m4     > $src_dir/mk_lib_crypto_mode_cfb_128_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_twofish_128.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_twofish_192.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_128_twofish_256.h.m4 > $src_dir/mk_lib_crypto_mode_cfb_128_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_64_des.h.m4          > $src_dir/mk_lib_crypto_mode_cfb_64_des.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_64_tdes2.h.m4        > $src_dir/mk_lib_crypto_mode_cfb_64_tdes2.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_64_tdes3.h.m4        > $src_dir/mk_lib_crypto_mode_cfb_64_tdes3.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_aes_128.h.m4       > $src_dir/mk_lib_crypto_mode_cfb_8_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_aes_192.h.m4       > $src_dir/mk_lib_crypto_mode_cfb_8_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_aes_256.h.m4       > $src_dir/mk_lib_crypto_mode_cfb_8_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_des.h.m4           > $src_dir/mk_lib_crypto_mode_cfb_8_des.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_serpent.h.m4       > $src_dir/mk_lib_crypto_mode_cfb_8_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_tdes2.h.m4         > $src_dir/mk_lib_crypto_mode_cfb_8_tdes2.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_tdes3.h.m4         > $src_dir/mk_lib_crypto_mode_cfb_8_tdes3.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_twofish_128.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_twofish_192.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_cfb_8_twofish_256.h.m4   > $src_dir/mk_lib_crypto_mode_cfb_8_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_aes_128.h.m4      > $src_dir/mk_lib_crypto_mode_ctr_be_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_aes_192.h.m4      > $src_dir/mk_lib_crypto_mode_ctr_be_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_aes_256.h.m4      > $src_dir/mk_lib_crypto_mode_ctr_be_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_des.h.m4          > $src_dir/mk_lib_crypto_mode_ctr_be_des.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_serpent.h.m4      > $src_dir/mk_lib_crypto_mode_ctr_be_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_tdes2.h.m4        > $src_dir/mk_lib_crypto_mode_ctr_be_tdes2.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_tdes3.h.m4        > $src_dir/mk_lib_crypto_mode_ctr_be_tdes3.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_twofish_128.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_twofish_192.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ctr_be_twofish_256.h.m4  > $src_dir/mk_lib_crypto_mode_ctr_be_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_aes_128.h.m4         > $src_dir/mk_lib_crypto_mode_ecb_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_aes_192.h.m4         > $src_dir/mk_lib_crypto_mode_ecb_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_aes_256.h.m4         > $src_dir/mk_lib_crypto_mode_ecb_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_des.h.m4             > $src_dir/mk_lib_crypto_mode_ecb_des.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_serpent.h.m4         > $src_dir/mk_lib_crypto_mode_ecb_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_tdes2.h.m4           > $src_dir/mk_lib_crypto_mode_ecb_tdes2.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_tdes3.h.m4           > $src_dir/mk_lib_crypto_mode_ecb_tdes3.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_twofish_128.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_twofish_192.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ecb_twofish_256.h.m4     > $src_dir/mk_lib_crypto_mode_ecb_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_aes_128.h.m4      > $src_dir/mk_lib_crypto_mode_gcm_be_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_aes_192.h.m4      > $src_dir/mk_lib_crypto_mode_gcm_be_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_aes_256.h.m4      > $src_dir/mk_lib_crypto_mode_gcm_be_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_serpent.h.m4      > $src_dir/mk_lib_crypto_mode_gcm_be_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_twofish_128.h.m4  > $src_dir/mk_lib_crypto_mode_gcm_be_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_twofish_192.h.m4  > $src_dir/mk_lib_crypto_mode_gcm_be_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_gcm_be_twofish_256.h.m4  > $src_dir/mk_lib_crypto_mode_gcm_be_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_aes_128.h.m4         > $src_dir/mk_lib_crypto_mode_ofb_aes_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_aes_192.h.m4         > $src_dir/mk_lib_crypto_mode_ofb_aes_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_aes_256.h.m4         > $src_dir/mk_lib_crypto_mode_ofb_aes_256.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_des.h.m4             > $src_dir/mk_lib_crypto_mode_ofb_des.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_serpent.h.m4         > $src_dir/mk_lib_crypto_mode_ofb_serpent.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_tdes2.h.m4           > $src_dir/mk_lib_crypto_mode_ofb_tdes2.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_tdes3.h.m4           > $src_dir/mk_lib_crypto_mode_ofb_tdes3.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_twofish_128.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_twofish_128.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_twofish_192.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_twofish_192.h
m4 -I $src_dir -- $src_dir/mk_lib_crypto_mode_ofb_twofish_256.h.m4     > $src_dir/mk_lib_crypto_mode_ofb_twofish_256.h
m4 -I $src_dir -- $src_dir/mk_sl_cui_inl_defd.h.m4                     > $src_dir/mk_sl_cui_inl_defd.h
m4 -I $src_dir -- $src_dir/mk_sl_cui_inl_defu.h.m4                     > $src_dir/mk_sl_cui_inl_defu.h
m4 -I $src_dir -- $src_dir/mk_sl_cui_inl_filec.h.m4                    > $src_dir/mk_sl_cui_inl_filec.h
m4 -I $src_dir -- $src_dir/mk_sl_cui_inl_fileh.h.m4                    > $src_dir/mk_sl_cui_inl_fileh.h
