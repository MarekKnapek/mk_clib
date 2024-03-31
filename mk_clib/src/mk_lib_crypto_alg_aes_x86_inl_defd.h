#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"


#if \
	!defined mk_lib_crypto_alg_aes_x86_t_name || \
	!defined mk_lib_crypto_alg_aes_x86_t_bits || \
	!defined mk_lib_crypto_alg_aes_x86_t_tech || \
	0
#error xxxxxxxxxx
#endif

#if(!( \
	(mk_lib_crypto_alg_aes_x86_t_bits) == 128 || \
	(mk_lib_crypto_alg_aes_x86_t_bits) == 192 || \
	(mk_lib_crypto_alg_aes_x86_t_bits) == 256 || \
	1 \
))
#error xxxxxxxxxx
#endif

#if(!( \
	(mk_lib_crypto_alg_aes_x86_t_tech) == 3 /* aesni   */ || \
	(mk_lib_crypto_alg_aes_x86_t_tech) == 4 /* vaes256 */ || \
	(mk_lib_crypto_alg_aes_x86_t_tech) == 5 /* vaes512 */ || \
	1 \
))
#error xxxxxxxxxx
#endif


#define mk_lib_crypto_alg_aes_x86_inl_defd_name mk_lib_crypto_alg_aes_x86_t_name
#define mk_lib_crypto_alg_aes_x86_inl_defd_bits (mk_lib_crypto_alg_aes_x86_t_bits)
#define mk_lib_crypto_alg_aes_x86_inl_defd_tech (mk_lib_crypto_alg_aes_x86_t_tech)


#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
#define mk_lib_crypto_alg_aes_x86_inl_defd_nr 10
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_file "mk_lib_crypto_alg_aes_128.h"
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_key_t mk_lib_crypto_alg_aes_128_key_t
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_msg_t mk_lib_crypto_alg_aes_128_msg_t
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_schedule_t mk_lib_crypto_alg_aes_128_schedule_t
#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
#define mk_lib_crypto_alg_aes_x86_inl_defd_nr 12
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_file "mk_lib_crypto_alg_aes_192.h"
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_key_t mk_lib_crypto_alg_aes_192_key_t
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_msg_t mk_lib_crypto_alg_aes_192_msg_t
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_schedule_t mk_lib_crypto_alg_aes_192_schedule_t
#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
#define mk_lib_crypto_alg_aes_x86_inl_defd_nr 14
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_file "mk_lib_crypto_alg_aes_256.h"
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_key_t mk_lib_crypto_alg_aes_256_key_t
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_msg_t mk_lib_crypto_alg_aes_256_msg_t
#define mk_lib_crypto_alg_aes_x86_inl_defd_base_schedule_t mk_lib_crypto_alg_aes_256_schedule_t
#endif


#define mk_lib_crypto_alg_aes_x86_inl_defd_key_bits mk_lib_crypto_alg_aes_x86_inl_defd_bits
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_bits 128
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_bits ((mk_lib_crypto_alg_aes_x86_inl_defd_nr + 1) * mk_lib_crypto_alg_aes_x86_inl_defd_msg_bits)

#define mk_lib_crypto_alg_aes_x86_inl_defd_key_bytes (mk_lib_crypto_alg_aes_x86_inl_defd_key_bits / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_bytes (mk_lib_crypto_alg_aes_x86_inl_defd_msg_bits / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_bytes (mk_lib_crypto_alg_aes_x86_inl_defd_schedule_bits / mk_lang_charbit)

#define mk_lib_crypto_alg_aes_x86_inl_defd_key_len_e mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _key_len_e)
#define mk_lib_crypto_alg_aes_x86_inl_defd_key_len_v mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _key_len_v)
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_e mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _msg_len_e)
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _msg_len_v)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_len_e mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_len_e)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_len_v mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_len_v)

#define mk_lib_crypto_alg_aes_x86_inl_defd_key_t mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _key_t)
#define mk_lib_crypto_alg_aes_x86_inl_defd_key_ct mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _key_ct)
#define mk_lib_crypto_alg_aes_x86_inl_defd_key_pt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _key_pt)
#define mk_lib_crypto_alg_aes_x86_inl_defd_key_pct mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _key_pct)

#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_t mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _msg_t)
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_ct mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _msg_ct)
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _msg_pt)
#define mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _msg_pct)

#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_t)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_ct mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_ct)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_pt)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_pct)

#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_encrypt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_encrypt)
#define mk_lib_crypto_alg_aes_x86_inl_defd_schedule_decrypt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _schedule_decrypt)
#define mk_lib_crypto_alg_aes_x86_inl_defd_expand_enc mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _expand_enc)
#define mk_lib_crypto_alg_aes_x86_inl_defd_expand_dec mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _expand_dec)
#define mk_lib_crypto_alg_aes_x86_inl_defd_encrypt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _encrypt)
#define mk_lib_crypto_alg_aes_x86_inl_defd_decrypt mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _decrypt)

#define mk_lib_crypto_alg_aes_x86_inl_defd_assist_128 mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _assist_128)
#define mk_lib_crypto_alg_aes_x86_inl_defd_assist_192 mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _assist_192)
#define mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _assist_256_a)
#define mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b mk_lang_concat(mk_lib_crypto_alg_aes_x86_inl_defd_name, _assist_256_b)
