#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_pow2.h"


#if(!( \
	(defined mk_lib_crypto_alg_serpent_t_name) && \
	(defined mk_lib_crypto_alg_serpent_t_type) && \
	(defined mk_lib_crypto_alg_serpent_t_bits && (mk_lib_crypto_alg_serpent_t_bits) >= 32 && (mk_lib_crypto_alg_serpent_t_bits) <= 512 && (mk_lib_crypto_alg_serpent_t_bits) % 32 == 0 && mk_lang_pow2_is((mk_lib_crypto_alg_serpent_t_bits) / 32)) && \
	(defined mk_lib_crypto_alg_serpent_t_constexpr && ((mk_lib_crypto_alg_serpent_t_constexpr) == 0 || (mk_lib_crypto_alg_serpent_t_constexpr) == 1)) && \
	(defined mk_lib_crypto_alg_serpent_t_uints_t) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_assign) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_and2) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_not1) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_or2) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_rotl2) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_rotr2) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_shl3) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_xor2) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_xor3) && \
	(defined mk_lib_crypto_alg_serpent_t_ui_broadcast) && \
	(defined mk_lib_crypto_alg_serpent_t_load) && \
	(defined mk_lib_crypto_alg_serpent_t_store) && \
	(defined mk_lib_crypto_alg_serpent_t_target) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lib_crypto_alg_serpent_inl_defd_name mk_lib_crypto_alg_serpent_t_name
#define mk_lib_crypto_alg_serpent_inl_defd_type mk_lib_crypto_alg_serpent_t_type
#define mk_lib_crypto_alg_serpent_inl_defd_bits (mk_lib_crypto_alg_serpent_t_bits)
#define mk_lib_crypto_alg_serpent_inl_defd_constexpr (mk_lib_crypto_alg_serpent_t_constexpr)
#define mk_lib_crypto_alg_serpent_inl_defd_uints_t mk_lib_crypto_alg_serpent_t_uints_t
#define mk_lib_crypto_alg_serpent_inl_defd_ui_assign mk_lib_crypto_alg_serpent_t_ui_assign
#define mk_lib_crypto_alg_serpent_inl_defd_ui_and2 mk_lib_crypto_alg_serpent_t_ui_and2
#define mk_lib_crypto_alg_serpent_inl_defd_ui_not1 mk_lib_crypto_alg_serpent_t_ui_not1
#define mk_lib_crypto_alg_serpent_inl_defd_ui_or2 mk_lib_crypto_alg_serpent_t_ui_or2
#define mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2 mk_lib_crypto_alg_serpent_t_ui_rotl2
#define mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2 mk_lib_crypto_alg_serpent_t_ui_rotr2
#define mk_lib_crypto_alg_serpent_inl_defd_ui_shl3 mk_lib_crypto_alg_serpent_t_ui_shl3
#define mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 mk_lib_crypto_alg_serpent_t_ui_xor2
#define mk_lib_crypto_alg_serpent_inl_defd_ui_xor3 mk_lib_crypto_alg_serpent_t_ui_xor3
#define mk_lib_crypto_alg_serpent_inl_defd_ui_broadcast mk_lib_crypto_alg_serpent_t_ui_broadcast
#define mk_lib_crypto_alg_serpent_inl_defd_load mk_lib_crypto_alg_serpent_t_load
#define mk_lib_crypto_alg_serpent_inl_defd_store mk_lib_crypto_alg_serpent_t_store
#define mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_t_target


#if mk_lib_crypto_alg_serpent_inl_defd_constexpr
#define mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec mk_lang_constexpr
#define mk_lib_crypto_alg_serpent_inl_defd_constexpr_init mk_lang_constexpr_init
#else
#define mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec
#define mk_lib_crypto_alg_serpent_inl_defd_constexpr_init
#endif


#define mk_lib_crypto_alg_serpent_inl_defd_cnt (mk_lib_crypto_alg_serpent_inl_defd_bits / 32)

#define mk_lib_crypto_alg_serpent_inl_defd_type_t mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _type_t)
#define mk_lib_crypto_alg_serpent_inl_defd_type_pt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _type_pt)
#define mk_lib_crypto_alg_serpent_inl_defd_type_prt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _type_prt)
#define mk_lib_crypto_alg_serpent_inl_defd_type_prct mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _type_prct)
#define mk_lib_crypto_alg_serpent_inl_defd_type_prprt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _type_prprt)

#define mk_lib_crypto_alg_serpent_inl_defd_lload mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _lload)
#define mk_lib_crypto_alg_serpent_inl_defd_sstore mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _sstore)
#define mk_lib_crypto_alg_serpent_inl_defd_xor_rk_single mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _xor_rk_single)
#define mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _xor_rk_multi)
#define mk_lib_crypto_alg_serpent_inl_defd_swaparoo mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _swaparoo)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_lt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_lt)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_lt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_lt)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_0 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_0)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_1 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_1)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_2 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_2)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_3 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_3)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_4 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_4)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_5 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_5)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_6 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_6)
#define mk_lib_crypto_alg_serpent_inl_defd_enc_7 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _enc_7)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_0 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_0)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_1 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_1)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_2 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_2)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_3 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_3)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_4 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_4)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_5 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_5)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_6 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_6)
#define mk_lib_crypto_alg_serpent_inl_defd_dec_7 mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _dec_7)
#define mk_lib_crypto_alg_serpent_inl_defd_encrypt_once mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _encrypt_once)
#define mk_lib_crypto_alg_serpent_inl_defd_decrypt_once mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _decrypt_once)
#define mk_lib_crypto_alg_serpent_inl_defd_encrypt_blocks mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _encrypt_blocks)
#define mk_lib_crypto_alg_serpent_inl_defd_decrypt_blocks mk_lang_concat(mk_lib_crypto_alg_serpent_inl_defd_name, _decrypt_blocks)
