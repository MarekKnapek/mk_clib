#define _CRT_SECURE_NO_WARNINGS
#define mk_lang_jumbo_want 1

#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_likely.h"
#include "mk_lang_likely.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_null.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#define mk_lib_crypto_mode_base_t_name vc
#define mk_lib_crypto_mode_base_t_len (128 / mk_lang_charbit)
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"

#include <stdio.h> /* sprintf FILE fopen fclose */
#include <stdlib.h> /* EXIT_SUCCESS EXIT_FAILURE */
#include <string.h> /* memcpy */


enum prf_id_e
{
	prf_id_e_sha2_256,
	prf_id_e_sha2_512,
	prf_id_e_dummy_end
};
typedef enum prf_id_e prf_id_t;

enum alg_id_e
{
	alg_id_e_aes,
	alg_id_e_serpent,
	alg_id_e_dummy_end
};
typedef enum alg_id_e alg_id_t;

enum seq_id_e
{
	seq_id_e_aes,
	seq_id_e_serpent,
	seq_id_e_aes_serpent,
	seq_id_e_dummy_end
};
typedef enum seq_id_e seq_id_t;

#define alg_key_len mk_lang_max(mk_lib_crypto_alg_aes_256_key_len_m, mk_lib_crypto_alg_serpent_key_len_m)
union alg_key_u
{
	mk_sl_cui_uint8_t m_uint8s[alg_key_len];
	mk_lib_crypto_alg_aes_256_key_t m_aes;
	mk_lib_crypto_alg_serpent_key_t m_serpent;
};
typedef union alg_key_u alg_key_t;
typedef alg_key_t const alg_key_ct;
typedef alg_key_t* alg_key_pt;
typedef alg_key_t const* alg_key_pct;

#define alg_msg_len mk_lang_max(mk_lib_crypto_alg_aes_256_msg_len_m, mk_lib_crypto_alg_serpent_msg_len_m)
union alg_msg_u
{
	mk_sl_cui_uint8_t m_uint8s[alg_msg_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aes;
	mk_lib_crypto_alg_serpent_msg_t m_serpent;
};
typedef union alg_msg_u alg_msg_t;
typedef alg_msg_t const alg_msg_ct;
typedef alg_msg_t* alg_msg_pt;
typedef alg_msg_t const* alg_msg_pct;

#define alg_schedule_len mk_lang_max(mk_lib_crypto_alg_aes_256_schedule_len_m, mk_lib_crypto_alg_serpent_schedule_len_m)
union alg_schedule_u
{
	mk_sl_cui_uint8_t m_uint8s[alg_schedule_len];
	mk_lib_crypto_alg_aes_256_schedule_t m_aes;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent;
};
typedef union alg_schedule_u alg_schedule_t;
typedef alg_schedule_t const alg_schedule_ct;
typedef alg_schedule_t* alg_schedule_pt;
typedef alg_schedule_t const* alg_schedule_pct;

struct seq_key_aes_serpent_s
{
	mk_lib_crypto_alg_aes_256_key_t m_aes;
	mk_lib_crypto_alg_serpent_key_t m_serpent;
};
typedef struct seq_key_aes_serpent_s seq_key_aes_serpent_t;
typedef seq_key_aes_serpent_t const seq_key_aes_serpent_ct;
typedef seq_key_aes_serpent_t* seq_key_aes_serpent_pt;
typedef seq_key_aes_serpent_t const* seq_key_aes_serpent_pct;

union seq_msg_aes_serpent_s
{
	alg_msg_t m_aes;
	alg_msg_t m_serpent;
};
typedef union seq_msg_aes_serpent_s seq_msg_aes_serpent_t;
typedef seq_msg_aes_serpent_t const seq_msg_aes_serpent_ct;
typedef seq_msg_aes_serpent_t* seq_msg_aes_serpent_pt;
typedef seq_msg_aes_serpent_t const* seq_msg_aes_serpent_pct;

struct seq_schedule_aes_serpent_s
{
	alg_schedule_t m_aes;
	alg_schedule_t m_serpent;
};
typedef struct seq_schedule_aes_serpent_s seq_schedule_aes_serpent_t;
typedef seq_schedule_aes_serpent_t const seq_schedule_aes_serpent_ct;
typedef seq_schedule_aes_serpent_t* seq_schedule_aes_serpent_pt;
typedef seq_schedule_aes_serpent_t const* seq_schedule_aes_serpent_pct;

#define seq_key_len mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_key_len_m, mk_lib_crypto_alg_serpent_key_len_m), mk_lib_crypto_alg_aes_256_key_len_m + mk_lib_crypto_alg_serpent_key_len_m)
union seq_key_u
{
	mk_sl_cui_uint8_t m_uint8s[seq_key_len];
	mk_lib_crypto_alg_aes_256_key_t m_aes;
	mk_lib_crypto_alg_serpent_key_t m_serpent;
	seq_key_aes_serpent_t m_aes_serpent;
};
typedef union seq_key_u seq_key_t;
typedef seq_key_t const seq_key_ct;
typedef seq_key_t* seq_key_pt;
typedef seq_key_t const* seq_key_pct;

#define seq_msg_len mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_msg_len_m, mk_lib_crypto_alg_serpent_msg_len_m), mk_lang_max(mk_lib_crypto_alg_aes_256_msg_len_m, mk_lib_crypto_alg_serpent_msg_len_m))
union seq_msg_u
{
	mk_sl_cui_uint8_t m_uint8s[seq_msg_len];
	alg_msg_t m_aes;
	alg_msg_t m_serpent;
	seq_msg_aes_serpent_t m_aes_serpent;
};
typedef union seq_msg_u seq_msg_t;
typedef seq_msg_t const seq_msg_ct;
typedef seq_msg_t* seq_msg_pt;
typedef seq_msg_t const* seq_msg_pct;

#define seq_schedule_len mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_schedule_len_m, mk_lib_crypto_alg_serpent_schedule_len_m), mk_lib_crypto_alg_aes_256_schedule_len_m + mk_lib_crypto_alg_serpent_schedule_len_m)
union seq_schedule_u
{
	mk_sl_cui_uint8_t m_uint8s[seq_schedule_len];
	alg_schedule_t m_aes;
	alg_schedule_t m_serpent;
	seq_schedule_aes_serpent_t m_aes_serpent;
};
typedef union seq_schedule_u seq_schedule_t;
typedef seq_schedule_t const seq_schedule_ct;
typedef seq_schedule_t* seq_schedule_pt;
typedef seq_schedule_t const* seq_schedule_pct;

#define salt_len 64
union salt_aligned_u
{
	mk_lang_types_uchar_t m_uchars[salt_len];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union salt_aligned_u salt_aligned_t;
struct salt_s
{
	salt_aligned_t m_data;
};
typedef struct salt_s salt_t;
typedef salt_t const salt_ct;
typedef salt_t* salt_pt;
typedef salt_t const* salt_pct;

#define block_len 512
union block_aligned_u
{
	unsigned char m_uchars[block_len];
	seq_msg_t m_msgs[block_len / seq_msg_len];
};
typedef union block_aligned_u block_aligned_t;
struct block_s
{
	block_aligned_t m_data;
};
typedef struct block_s block_t;
typedef block_t const block_ct;
typedef block_t* block_pt;
typedef block_t const* block_pct;

struct reader_s
{
	seq_id_t m_seq_id;
	FILE* m_file;
	seq_schedule_pct m_schedulea;
	seq_schedule_pct m_scheduleb;
	mk_lang_types_ulong_t m_block_idx;
	block_pt m_block;
};
typedef struct reader_s reader_t;
typedef reader_t const reader_ct;
typedef reader_t* reader_pt;
typedef reader_t const* reader_pct;

typedef void vc_logger_ctx_t;
typedef vc_logger_ctx_t const vc_logger_ctx_ct;
typedef vc_logger_ctx_t* vc_logger_ctx_pt;
typedef vc_logger_ctx_t const* vc_logger_ctx_pct;

typedef mk_lang_types_sint_t(vc_logger_fnc_t)(vc_logger_ctx_pt, char const*) mk_lang_noexcept;
typedef vc_logger_fnc_t* vc_logger_fnc_pt;


#define magic_offset salt_len
#define magic_len 4
#define ver_offset salt_len + magic_len
#define ver_len 2
#define min_ver_maj_offset ver_offset + ver_len
#define min_ver_maj_len 1
#define min_ver_min_offset min_ver_maj_offset + min_ver_maj_len
#define min_ver_min_len 1
#define crc1_offset min_ver_min_offset + min_ver_min_len
#define crc1_len 4
#define reserved1_offset crc1_offset + crc1_len
#define reserved1_len 16
#define size_hidden_volume_offset reserved1_offset + reserved1_len
#define size_hidden_volume_len 8
#define size_volume_offset size_hidden_volume_offset + size_hidden_volume_len
#define size_volume_len 8
#define master_key_scope1_offset size_volume_offset + size_volume_len
#define master_key_scope1_len 8
#define master_key_scope2_offset master_key_scope1_offset + master_key_scope1_len
#define master_key_scope2_len 8
#define flags_offset master_key_scope2_offset + master_key_scope2_len
#define flags_len 4
#define sector_size_offset flags_offset + flags_len
#define sector_size_len 4
#define reserved2_offset sector_size_offset + sector_size_len
#define reserved2_len 120
#define crc2_offset reserved2_offset + reserved2_len
#define crc2_len 4
#define master_keys_offset crc2_offset + crc2_len
#define data_offset (128 * 1024)


#define check(x) do{ if(!(x)){ mk_lang_unlikely return EXIT_FAILURE; } }while(0)
#define check2(x) do{ int const err = ((int)(x)); if(err != EXIT_SUCCESS){ mk_lang_unlikely return err; } }while(0)
#define check_continue(x) if(!(x)){ continue; } ((void)(0))


mk_lang_constexpr static mk_lang_inline void alg_xor_3(alg_id_t const alg_id, alg_msg_pct const a, alg_msg_pct const b, alg_msg_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	switch(alg_id)
	{
		case alg_id_e_aes: mk_lib_crypto_mode_base_vc_xor3(&a->m_aes.m_data.m_uint8s[0], &b->m_aes.m_data.m_uint8s[0], &c->m_aes.m_data.m_uint8s[0]); break;
		case alg_id_e_serpent: mk_lib_crypto_mode_base_vc_xor3(&a->m_serpent.m_data.m_uint8s[0], &b->m_serpent.m_data.m_uint8s[0], &c->m_serpent.m_data.m_uint8s[0]); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void alg_xor_2(alg_id_t const alg_id, alg_msg_pt const a, alg_msg_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	switch(alg_id)
	{
		case alg_id_e_aes: mk_lib_crypto_mode_base_vc_xor2(&a->m_aes.m_data.m_uint8s[0], &b->m_aes.m_data.m_uint8s[0]); break;
		case alg_id_e_serpent: mk_lib_crypto_mode_base_vc_xor2(&a->m_serpent.m_data.m_uint8s[0], &b->m_serpent.m_data.m_uint8s[0]); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void alg_schedule_encrypt(alg_id_t const alg_id, alg_schedule_pct const schedule, alg_msg_pct const input, alg_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	switch(alg_id)
	{
		case alg_id_e_aes: mk_lib_crypto_alg_aes_256_schedule_encrypt(&schedule->m_aes, &input->m_aes, &output->m_aes); break;
		case alg_id_e_serpent: mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule->m_serpent, &input->m_serpent, &output->m_serpent); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void alg_schedule_decrypt(alg_id_t const alg_id, alg_schedule_pct const schedule, alg_msg_pct const input, alg_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	switch(alg_id)
	{
		case alg_id_e_aes: mk_lib_crypto_alg_aes_256_schedule_decrypt(&schedule->m_aes, &input->m_aes, &output->m_aes); break;
		case alg_id_e_serpent: mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule->m_serpent, &input->m_serpent, &output->m_serpent); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void alg_xts_tweak_shift(alg_id_t const alg_id, alg_msg_pt const tweak) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint8_t const s_carry = mk_sl_cui_uint8_c(0x87);

	mk_lang_types_sint_t i mk_lang_constexpr_init;
	alg_msg_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t carry_a mk_lang_constexpr_init;
	mk_sl_cui_uint8_t carry_b mk_lang_constexpr_init;

	mk_lang_static_assert(alg_msg_len == 128 / mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_v == alg_msg_len);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_v == alg_msg_len);

	mk_lang_assert(tweak);

	switch(alg_id)
	{
		case alg_id_e_aes: for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ ta.m_uint8s[i] = tweak->m_aes.m_data.m_uint8s[i]; } break;
		case alg_id_e_serpent: for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ ta.m_uint8s[i] = tweak->m_serpent.m_data.m_uint8s[i]; } break;
		default: mk_lang_assert(0); break;
	}
	mk_sl_cui_uint8_set_zero(&carry_a);
	for(i = 0; i != alg_msg_len; ++i)
	{
		mk_sl_cui_uint8_shr3(&ta.m_uint8s[i], 7, &carry_b);
		mk_sl_cui_uint8_shl2(&ta.m_uint8s[i], 1);
		mk_sl_cui_uint8_or2(&ta.m_uint8s[i], &carry_a);
		carry_a = carry_b;
	}
	if(!mk_sl_cui_uint8_is_zero(&carry_b))
	{
		mk_sl_cui_uint8_xor2(&ta.m_uint8s[0], &s_carry);
	}
	switch(alg_id)
	{
		case alg_id_e_aes: for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ tweak->m_aes.m_data.m_uint8s[i] = ta.m_uint8s[i]; } break;
		case alg_id_e_serpent: for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ tweak->m_serpent.m_data.m_uint8s[i] = ta.m_uint8s[i]; } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void alg_uint_128_to_8_le(alg_id_t const alg_id, mk_sl_cui_uint128_pct const num, alg_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(num);
	mk_lang_assert(msg);

	switch(alg_id)
	{
		case alg_id_e_aes: mk_sl_uint_128_to_8_le(num, &msg->m_aes.m_data.m_uint8s[0]); break;
		case alg_id_e_serpent: mk_sl_uint_128_to_8_le(num, &msg->m_serpent.m_data.m_uint8s[0]); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void alg_xts_decrypt(alg_id_t const alg_id, alg_schedule_pct const schedulea, alg_schedule_pct const scheduleb, mk_lang_types_ulong_t const idx, mk_lang_types_sint_t const nmsgs, alg_msg_pct const inputs, alg_msg_pt const outputs) mk_lang_noexcept
{
	alg_msg_pct input mk_lang_constexpr_init;
	alg_msg_pt output mk_lang_constexpr_init;
	mk_sl_cui_uint128_t u128 mk_lang_constexpr_init;
	alg_msg_t tweak mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_m == 128 / mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_m == 128 / mk_lang_charbit);
	mk_lang_static_assert(alg_msg_len == 128 / mk_lang_charbit);

	mk_lang_assert(schedulea);
	mk_lang_assert(scheduleb);
	mk_lang_assert(nmsgs >= 0);
	mk_lang_assert(inputs);
	mk_lang_assert(outputs);

	input = inputs;
	output = outputs;
	mk_sl_cui_uint128_from_bi_ulong(&u128, &idx);
	alg_uint_128_to_8_le(alg_id, &u128, &tweak);
	alg_schedule_encrypt(alg_id, scheduleb, &tweak, &tweak);
	for(i = 0; i != nmsgs; ++i, ++input, ++output)
	{
		alg_xor_3(alg_id, &tweak, input, output);
		alg_schedule_decrypt(alg_id, schedulea, output, output);
		alg_xor_2(alg_id, output, &tweak);
		alg_xts_tweak_shift(alg_id, &tweak);
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_pchar_pct get_seq_name(seq_id_t const seq_id) mk_lang_noexcept
{
	switch(seq_id)
	{
		case seq_id_e_aes: return "AES"; break;
		case seq_id_e_serpent: return "Serpent"; break;
		case seq_id_e_aes_serpent: return "Serpent(AES)"; break;
		default: mk_lang_assert(0); break;
	}
	return mk_lang_null;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t seq_key_len_r(seq_id_t const seq_id) mk_lang_noexcept
{
	switch(seq_id)
	{
		case seq_id_e_aes: return mk_lib_crypto_alg_aes_256_key_len_v; break;
		case seq_id_e_serpent: return mk_lib_crypto_alg_serpent_key_len_v; break;
		case seq_id_e_aes_serpent: return mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v; break;
		default: mk_lang_assert(0); break;
	}
	return -1;
}

mk_lang_constexpr static mk_lang_inline void seq_xts_decrypt(seq_id_t const seq_id, seq_schedule_pct const schedulea, seq_schedule_pct const scheduleb, mk_lang_types_ulong_t const idx, mk_lang_types_sint_t const nmsgs, seq_msg_pct const inputs, seq_msg_pt const outputs) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(schedulea);
	mk_lang_assert(scheduleb);
	mk_lang_assert(nmsgs >= 0);
	mk_lang_assert(inputs);
	mk_lang_assert(outputs);

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_v == mk_lib_crypto_alg_serpent_msg_len_v);

	switch(seq_id)
	{
		case seq_id_e_aes:
			alg_xts_decrypt(alg_id_e_aes, &schedulea->m_aes, &scheduleb->m_aes, idx, nmsgs, &inputs->m_aes, &outputs->m_aes);
		break;
		case seq_id_e_serpent:
			alg_xts_decrypt(alg_id_e_serpent, &schedulea->m_serpent, &scheduleb->m_serpent, idx, nmsgs, &inputs->m_serpent, &outputs->m_serpent);
		break;
		case seq_id_e_aes_serpent:
			alg_xts_decrypt(alg_id_e_serpent, &schedulea->m_aes_serpent.m_serpent, &scheduleb->m_aes_serpent.m_serpent, idx, nmsgs, &inputs->m_aes_serpent.m_serpent, &outputs->m_aes_serpent.m_serpent);
			alg_xts_decrypt(alg_id_e_aes, &schedulea->m_aes_serpent.m_aes, &scheduleb->m_aes_serpent.m_aes, idx, nmsgs, &inputs->m_aes_serpent.m_aes, &outputs->m_aes_serpent.m_aes);
		break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void seq_expand_enc(seq_id_t const seq_id, seq_key_pct const key, seq_schedule_pt const schedule) mk_lang_noexcept
{
	switch(seq_id)
	{
		case seq_id_e_aes: mk_lib_crypto_alg_aes_256_expand_enc(&key->m_aes, &schedule->m_aes.m_aes); break;
		case seq_id_e_serpent: mk_lib_crypto_alg_serpent_expand_enc(&key->m_serpent, &schedule->m_serpent.m_serpent); break;
		case seq_id_e_aes_serpent: mk_lib_crypto_alg_aes_256_expand_enc(&key->m_aes_serpent.m_aes, &schedule->m_aes_serpent.m_aes.m_aes); mk_lib_crypto_alg_serpent_expand_enc(&key->m_aes_serpent.m_serpent, &schedule->m_aes_serpent.m_serpent.m_serpent); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void seq_expand_dec(seq_id_t const seq_id, seq_key_pct const key, seq_schedule_pt const schedule) mk_lang_noexcept
{
	switch(seq_id)
	{
		case seq_id_e_aes: mk_lib_crypto_alg_aes_256_expand_dec(&key->m_aes, &schedule->m_aes.m_aes); break;
		case seq_id_e_serpent: mk_lib_crypto_alg_serpent_expand_dec(&key->m_serpent, &schedule->m_serpent.m_serpent); break;
		case seq_id_e_aes_serpent: mk_lib_crypto_alg_aes_256_expand_dec(&key->m_aes_serpent.m_aes, &schedule->m_aes_serpent.m_aes.m_aes); mk_lib_crypto_alg_serpent_expand_dec(&key->m_aes_serpent.m_serpent, &schedule->m_aes_serpent.m_serpent.m_serpent); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void seq_key_init(seq_id_t const seq_id, mk_sl_cui_uint8_pct const keys, int const idx, seq_key_pt const key) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(keys);
	mk_lang_assert(idx >= 0 && idx <= 1);
	mk_lang_assert(key);

	switch(seq_id)
	{
		case seq_id_e_aes:
			for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_v; ++i)
			{
				key->m_aes.m_data.m_uint8s[i] = keys[idx * mk_lib_crypto_alg_aes_256_key_len_v + i];
			}
		break;
		case seq_id_e_serpent:
			for(i = 0; i != mk_lib_crypto_alg_serpent_key_len_v; ++i)
			{
				key->m_serpent.m_data.m_uint8s[i] = keys[idx * mk_lib_crypto_alg_serpent_key_len_v + i];
			}
		break;
		case seq_id_e_aes_serpent:
			for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_v; ++i)
			{
				key->m_aes_serpent.m_aes.m_data.m_uint8s[i] = keys[idx * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v) + i];
			}
			for(i = 0; i != mk_lib_crypto_alg_serpent_key_len_v; ++i)
			{
				key->m_aes_serpent.m_serpent.m_data.m_uint8s[i] = keys[idx * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v) + mk_lib_crypto_alg_aes_256_key_len_v + i];
			}
		break;
		default:
			mk_lang_assert(0);
		break;
	}
}

mk_lang_nodiscard static mk_lang_inline int reader_read(reader_pt const reader, mk_lang_types_ulong_t const offset, mk_lang_types_ulong_t const len, mk_lang_types_void_pt const dst) mk_lang_noexcept
{
	mk_lang_types_ulong_t offset_a;
	mk_lang_types_ulong_t len_a;
	mk_lang_types_uchar_pt dst_a;
	mk_lang_types_ulong_t block_idx;
	mk_lang_types_sint_t ti;
	mk_lang_types_usize_t ts;
	mk_lang_types_sint_t offset_b;
	mk_lang_types_sint_t len_b;
	mk_lang_types_void_pt d;

	mk_lang_assert(reader);
	mk_lang_assert(offset >= salt_len);
	mk_lang_assert(dst);

	offset_a = offset;
	len_a = len;
	dst_a = ((mk_lang_types_uchar_pt)(dst));
	block_idx = (offset_a - salt_len) / block_len;
	while(len_a != 0)
	{
		if(reader->m_block_idx != block_idx)
		{
			if(reader->m_block_idx + 1 != block_idx)
			{
				ti = fseek(reader->m_file, salt_len + block_idx * block_len, SEEK_SET); check(ti == 0);
			}
			reader->m_block_idx = block_idx;
			ts = fread(reader->m_block, 1, block_len, reader->m_file); check(ts == block_len);
			seq_xts_decrypt(reader->m_seq_id, reader->m_schedulea, reader->m_scheduleb, reader->m_block_idx, block_len / seq_msg_len, &reader->m_block->m_data.m_msgs[0], &reader->m_block->m_data.m_msgs[0]);
		}
		offset_b = ((mk_lang_types_sint_t)((offset_a - salt_len) % block_len));
		len_b = ((mk_lang_types_sint_t)(mk_lang_min(len_a, ((mk_lang_types_ulong_t)(block_len - offset_b)))));
		d = memcpy(dst_a, ((mk_lang_types_uchar_pct)(reader->m_block)) + offset_b, len_b); check(d == dst_a);
		offset_a += len_b;
		len_a -= len_b;
		dst_a += len_b;
	}
	return EXIT_SUCCESS;
}

#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14

#define chunk_size (4 * 1024)
#define chunk_count (1 * 1024)

struct chunk_data_s
{
	seq_msg_t m_msgs[chunk_size / seq_msg_len];
};
typedef struct chunk_data_s chunk_data_t;
typedef chunk_data_t const chunk_data_ct;
typedef chunk_data_t* chunk_data_pt;
typedef chunk_data_t const* chunk_data_pct;

struct chunk_info_s
{
	int m_chunk_id;
	mk_lang_types_ulong_t m_chunk_idx;
};
typedef struct chunk_info_s chunk_info_t;
typedef chunk_info_t const chunk_info_ct;
typedef chunk_info_t* chunk_info_pt;
typedef chunk_info_t const* chunk_info_pct;

#include "mk_lib_cpp_tl_ring.hpp"
#include "mk_lang_exception.h"
#include "mk_sl_mallocator_lang.h"

#define mk_sl_ring_t_name vc
#define mk_sl_ring_t_elem_t chunk_info_t
#define mk_sl_ring_t_capacity chunk_count
#include "mk_sl_ring_inl_fileh.h"
#include "mk_sl_ring_inl_filec.h"

#include <algorithm>
#include <atomic>
#include <array>

typedef mk::tl::ring_t
<
	mk::wrapper::ring_t
	<
		mk_sl_ring_vc_t,
		chunk_info_t,
		&mk_sl_ring_vc_ro_is_empty,
		&mk_sl_ring_vc_ro_is_full,
		&mk_sl_ring_vc_ro_get_size,
		&mk_sl_ring_vc_ro_get_capacity,
		&mk_sl_ring_vc_ro_get_elem,
		&mk_sl_ring_vc_ro_get_head,
		&mk_sl_ring_vc_ro_get_tail,
		&mk_sl_ring_vc_rw_is_empty,
		&mk_sl_ring_vc_rw_is_full,
		&mk_sl_ring_vc_rw_get_size,
		&mk_sl_ring_vc_rw_get_capacity,
		&mk_sl_ring_vc_rw_get_elem,
		&mk_sl_ring_vc_rw_get_head,
		&mk_sl_ring_vc_rw_get_tail,
		&mk_sl_ring_vc_rw_construct,
		&mk_sl_ring_vc_rw_push_void,
		&mk_sl_ring_vc_rw_push_elem,
		&mk_sl_ring_vc_rw_pop
	>
>
ring_t;
typedef ring_t const ring_ct;
typedef ring_t* ring_pt;
typedef ring_t const* ring_pct;

typedef std::array<chunk_data_t, chunk_count> chunks_t;
typedef chunks_t* chunks_pt;

typedef std::array<chunk_info_t, chunk_count> chunk_infos_t;
typedef chunk_infos_t* chunk_infos_pt;

	struct thread_param_s
{
	std::atomic<bool>* m_keep_running;
	seq_id_t m_seq_id;
	seq_schedule_pct m_master_schedulea;
	seq_schedule_pct m_master_scheduleb;
	chunks_pt m_chunks;
	ring_pt m_ring_crypt;
	ring_pt m_ring_io;
};
typedef struct thread_param_s thread_param_t;
typedef thread_param_t const thread_param_ct;
typedef thread_param_t* thread_param_pt;
typedef thread_param_t const* thread_param_pct;

static mk_lang_inline void thread_process_chunk(thread_param_pt const param, chunk_info_t const chunk_info) mk_lang_noexcept
{
	mk_lang_types_ulong_t blocks_per_chunk;
	mk_lang_types_ulong_t msgs_per_block;
	mk_lang_types_ulong_t block_idx;
	mk_lang_types_ulong_t iblock;
	seq_msg_pt output;
	seq_msg_pct input;

	mk_lang_static_assert((chunk_size >= block_len) && ((chunk_size % block_len) == 0));
	mk_lang_static_assert((data_offset >= block_len) && ((data_offset % block_len) ==0 ));
	mk_lang_static_assert((block_len >= seq_msg_len) && ((block_len % seq_msg_len) == 0));

	mk_lang_assert(param);

	blocks_per_chunk = (chunk_size / block_len);
	msgs_per_block = (block_len / seq_msg_len);
	block_idx = (data_offset / block_len) + (chunk_info.m_chunk_idx * blocks_per_chunk);
	for(iblock = 0; iblock != blocks_per_chunk; ++iblock, ++block_idx)
	{
		output = &(*param->m_chunks)[chunk_info.m_chunk_id].m_msgs[iblock * msgs_per_block];
		input = output;;
		seq_xts_decrypt(param->m_seq_id, param->m_master_schedulea, param->m_master_scheduleb, block_idx, msgs_per_block, input, output);
	}
	param->m_ring_io->push(chunk_info);
}

static mk_lang_inline void thread_proc(thread_param_pt const param) mk_lang_noexcept
{
	chunk_info_t chunk_info;

	mk_lang_assert(param);

	for(;;)
	{
		chunk_info = param->m_ring_crypt->pop();
		if(!param->m_keep_running->load(std::memory_order_relaxed))
		{
			break;
		}
		thread_process_chunk(param, chunk_info);
	}
}

static mk_lang_inline mk_lang_types_sint_t vc_decrypt_multithreaded(seq_id_t const& seq_id, unsigned long const& size_volume_ul, seq_schedule_t const& master_schedulea, seq_schedule_t const& master_scheduleb, FILE* const& input_file, FILE* const& output_file)
{
	struct big_things_s
	{
		chunks_t m_chunks;
		ring_t m_ring_crypt;
		ring_t m_ring_io;
		chunk_infos_t m_chunk_infos;
	};
	typedef struct big_things_s big_things_t;
	typedef big_things_t const big_things_ct;
	typedef big_things_t* big_things_pt;
	typedef big_things_t const* big_things_pct;

	mk_lang_exception_t ex;
	big_things_pt big_things;
	chunks_pt chunks;
	ring_pt ring_crypt;
	ring_pt ring_io;
	chunk_infos_pt chunk_infos;
	std::atomic<bool> keep_running;
	thread_param_t param;
	mk_lang_types_uint_t hw_threads;
	std::thread* threads;
	mk_lang_types_uint_t ihw_thread;
	mk_lang_types_ulong_t nchunks_actual;
	mk_lang_types_ulong_t nchunks_min;
	mk_lang_types_ulong_t ichunk;
	mk_lang_types_ulong_t chunk_idx_to_write;
	mk_lang_types_usize_t ts;
	chunk_info_t chunk_info;
	mk_lang_types_sint_t  chunk_infos_cnt;

	mk_lang_assert((size_volume_ul >= chunk_size) && ((size_volume_ul % chunk_size) == 0));
	mk_lang_assert(input_file);
	mk_lang_assert(output_file);

	mk_lang_exception_make_none(&ex);
	mk_sl_mallocator_lang_allocate(&ex, sizeof(*big_things), ((void**)(&big_things))); check(!mk_lang_exception_is(&ex)); mk_lang_assert(big_things);
	chunks = &big_things->m_chunks;
	ring_crypt = &big_things->m_ring_crypt;
	ring_io = &big_things->m_ring_io;
	chunk_infos = &big_things->m_chunk_infos;
	::new(chunks)(chunks_t);
	::new(ring_crypt)(ring_t);
	::new(ring_io)(ring_t);
	::new(chunk_infos)(chunk_infos_t);
	keep_running.store(true);
	param.m_keep_running = &keep_running;
	param.m_seq_id = seq_id;
	param.m_master_schedulea = &master_schedulea;
	param.m_master_scheduleb = &master_scheduleb;
	param.m_chunks = chunks;
	param.m_ring_crypt = ring_crypt;
	param.m_ring_io = ring_io;
	hw_threads = std::thread::hardware_concurrency(); check(hw_threads != 0);
	mk_sl_mallocator_lang_allocate(&ex, hw_threads * sizeof(*threads), ((void**)(&threads))); check(!mk_lang_exception_is(&ex)); mk_lang_assert(threads);
	for(ihw_thread = 0; ihw_thread != hw_threads; ++ihw_thread)
	{
		::new(&threads[ihw_thread])(std::thread)(&thread_proc, &param);
	}
	nchunks_actual = size_volume_ul / chunk_size;
	nchunks_min = mk_lang_min(chunk_count, nchunks_actual);
	for(ichunk = 0; ichunk != nchunks_min; ++ichunk)
	{
		ts = fread(&(*chunks)[ichunk].m_msgs[0], 1, chunk_size, input_file); check(ts == chunk_size);
		chunk_info.m_chunk_id = ((int)(ichunk));
		chunk_info.m_chunk_idx = ichunk;
		ring_crypt->push(chunk_info);
	}
	chunk_infos_cnt = 0;
	for(; ichunk != nchunks_actual; ++ichunk)
	{
		chunk_idx_to_write = ichunk - nchunks_min;
		auto const f = std::find_if(std::begin(*chunk_infos), std::begin(*chunk_infos) + chunk_infos_cnt, [&](chunk_info_t const& ci){ return ci.m_chunk_idx == chunk_idx_to_write; });
		if(f == std::begin(*chunk_infos) + chunk_infos_cnt)
		{
			for(;;)
			{
				chunk_info = ring_io->pop();
				if(chunk_info.m_chunk_idx == chunk_idx_to_write)
				{
					break;
				}
				(*chunk_infos)[chunk_infos_cnt] = chunk_info;
				++chunk_infos_cnt;
			}
		}
		else
		{
			chunk_info = *f;
			std::move(f + 1, std::begin(*chunk_infos) + chunk_infos_cnt, f);
			--chunk_infos_cnt;
		}
		ts = fwrite(&(*chunks)[chunk_info.m_chunk_id].m_msgs[0], 1, chunk_size, output_file); check(ts == chunk_size);
		ts = fread(&(*chunks)[chunk_info.m_chunk_id].m_msgs[0], 1, chunk_size, input_file); check(ts == chunk_size);
		chunk_info.m_chunk_idx = ichunk;
		ring_crypt->push(chunk_info);
	}
	for(; ichunk != nchunks_actual + nchunks_min; ++ichunk)
	{
		chunk_idx_to_write = ichunk - nchunks_min;
		auto const f = std::find_if(std::begin(*chunk_infos), std::begin(*chunk_infos) + chunk_infos_cnt, [&](chunk_info_t const& ci){ return ci.m_chunk_idx == chunk_idx_to_write; });
		if(f == std::begin(*chunk_infos) + chunk_infos_cnt)
		{
			for(;;)
			{
				chunk_info = ring_io->pop();
				if(chunk_info.m_chunk_idx == chunk_idx_to_write)
				{
					break;
				}
				(*chunk_infos)[chunk_infos_cnt] = chunk_info;
				++chunk_infos_cnt;
			}
		}
		else
		{
			chunk_info = *f;
			std::move(f + 1, std::begin(*chunk_infos) + chunk_infos_cnt, f);
			--chunk_infos_cnt;
		}
		ts = fwrite(&(*chunks)[chunk_info.m_chunk_id].m_msgs[0], 1, chunk_size, output_file); check(ts == chunk_size);
	}
	mk_lang_assert(ring_crypt->is_empty());
	mk_lang_assert(ring_io->is_empty());
	keep_running.store(false);
	for(ihw_thread = 0; ihw_thread != hw_threads; ++ihw_thread)
	{
		ring_crypt->push();
	}
	for(ihw_thread = 0; ihw_thread != hw_threads; ++ihw_thread)
	{
		threads[ihw_thread].join();
	}
	mk_lang_assert(ring_crypt->is_empty());
	for(ihw_thread = 0; ihw_thread != hw_threads; ++ihw_thread)
	{
		threads[ihw_thread].~thread();
	}
	mk_sl_mallocator_lang_deallocate(threads, hw_threads * sizeof(*threads));
	chunks->~chunks_t();
	ring_crypt->~ring_t();
	ring_io->~ring_t();
	chunk_infos->~chunk_infos_t();
	mk_sl_mallocator_lang_deallocate(big_things, sizeof(*big_things));
	return EXIT_SUCCESS;
}

#endif

static mk_lang_inline mk_lang_types_sint_t vc_decrypt_singlethreaded(seq_id_t const& seq_id, unsigned long const& size_volume_ul, seq_schedule_t const& master_schedulea, seq_schedule_t const& master_scheduleb, FILE* const& input_file, FILE* const& output_file)
{
	mk_lang_types_ulong_t msgs_per_block;
	mk_lang_types_ulong_t nblocks;
	mk_lang_types_ulong_t iblock;
	mk_lang_types_ulong_t block_idx;
	mk_lang_types_usize_t ts;
	block_t block;

	mk_lang_static_assert((block_len >= seq_msg_len) && ((block_len % seq_msg_len) == 0));

	mk_lang_assert((size_volume_ul >= block_len) && ((size_volume_ul % block_len) == 0));
	mk_lang_assert(input_file);
	mk_lang_assert(output_file);

	msgs_per_block = (block_len / seq_msg_len);
	nblocks = size_volume_ul / block_len;
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		block_idx = (data_offset / block_len) + iblock;
		ts = fread(&block, 1, block_len, input_file); check(ts == block_len);
		seq_xts_decrypt(seq_id, &master_schedulea, &master_scheduleb, block_idx, msgs_per_block, &block.m_data.m_msgs[0], &block.m_data.m_msgs[0]);
		ts = fwrite(&block, 1, block_len, output_file); check(ts == block_len);
	}
	return EXIT_SUCCESS;
}

mk_lang_constexpr static mk_lang_inline void pbkdf2(prf_id_t const prf_id, mk_sl_cui_uint8_pct const password, int const password_len, mk_sl_cui_uint8_pct const salt, int const slt_len, mk_lang_types_ulong_t const cost, int const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	switch(prf_id)
	{
		case prf_id_e_sha2_256: mk_lib_crypto_kdf_pbkdf2_sha2_256_u8(password, password_len, salt, slt_len, cost, key_len, key); break;
		case prf_id_e_sha2_512: mk_lib_crypto_kdf_pbkdf2_sha2_512_u8(password, password_len, salt, slt_len, cost, key_len, key); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_pchar_pct get_prf_name(prf_id_t const prf_id) mk_lang_noexcept
{
	switch(prf_id)
	{
		case prf_id_e_sha2_256: return mk_lib_crypto_hash_block_sha2_256_name_str; break;
		case prf_id_e_sha2_512: return mk_lib_crypto_hash_block_sha2_512_name_str; break;
		default: mk_lang_assert(0); break;
	}
	return mk_lang_null;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t vc_decrypt(mk_lang_types_pchar_pct const input_file_path, mk_lang_types_pchar_pct const password, mk_lang_types_sint_t const password_len, mk_lang_types_ulong_t const pim, vc_logger_fnc_pt const logger_fnc, vc_logger_ctx_pt const logger_ctx, mk_lang_types_pchar_pct const output_file_path) mk_lang_noexcept
{
	FILE* input_file;
	mk_lang_types_usize_t tus;
	salt_t salt;
	mk_sl_cui_uint8_pct pwd;
	mk_sl_cui_uint8_pct slt;
	mk_lang_types_sint_t slt_len;
	mk_lang_types_ulong_t cost;
	mk_lang_types_sint_t keys_len;
	prf_id_t prf_id;
	mk_sl_cui_uint8_t keys[2 * sizeof(seq_key_t)];
	seq_key_t keya;
	seq_key_t keyb;
	seq_id_t seq_id;
	seq_schedule_t schedulea;
	seq_schedule_t scheduleb;
	reader_t reader;
	block_t block;
	mk_lang_types_sint_t ti;
	mk_sl_cui_uint8_t magic_bytes[magic_len];
	mk_lang_types_pchar_t tc;
	mk_sl_cui_uint8_t ver_bytes[ver_len];
	mk_sl_cui_uint16_t ver;
	mk_lang_types_pchar_t ver_str[mk_sl_cui_uint16_to_str_dec_len];
	mk_sl_cui_uint8_t min_ver_maj_bytes[min_ver_maj_len];
	mk_sl_cui_uint8_t min_ver_maj;
	mk_lang_types_pchar_t min_ver_maj_str[mk_sl_cui_uint8_to_str_dec_len];
	mk_sl_cui_uint8_t min_ver_min_bytes[min_ver_min_len];
	mk_sl_cui_uint8_t min_ver_min;
	mk_lang_types_pchar_t min_ver_min_str[mk_sl_cui_uint8_to_str_dec_len];
	mk_sl_cui_uint8_t size_volume_bytes[size_volume_len];
	mk_sl_cui_uint64_t size_volume;
	mk_lang_types_pchar_t size_volume_str[mk_sl_cui_uint64_to_str_dec_len];
	mk_lang_types_ulong_t size_volume_ul;
	mk_sl_cui_uint8_t master_key_scope1_bytes[master_key_scope1_len];
	mk_sl_cui_uint64_t master_key_scope1;
	mk_lang_types_pchar_t master_key_scope1_str[mk_sl_cui_uint64_to_str_dec_len];
	mk_lang_types_ulong_t master_key_scope1_ul;
	mk_sl_cui_uint8_t master_key_scope2_bytes[master_key_scope2_len];
	mk_sl_cui_uint64_t master_key_scope2;
	mk_lang_types_pchar_t master_key_scope2_str[mk_sl_cui_uint64_to_str_dec_len];
	mk_lang_types_ulong_t master_key_scope2_ul;
	mk_sl_cui_uint8_t sector_size_bytes[sector_size_len];
	mk_sl_cui_uint32_t sector_size;
	mk_lang_types_ulong_t sector_size_ul;
	mk_lang_types_pchar_t sector_size_str[mk_sl_cui_uint32_to_str_dec_len];
	seq_key_t master_keya;
	seq_key_t master_keyb;
	seq_schedule_t master_schedulea;
	seq_schedule_t master_scheduleb;
	FILE* output_file;

	mk_lang_static_assert(sizeof(seq_key_aes_serpent_t) == mk_lib_crypto_alg_aes_256_key_len_m + mk_lib_crypto_alg_serpent_key_len_m);

	mk_lang_assert(input_file_path);
	mk_lang_assert(*input_file_path);
	mk_lang_assert(password);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(output_file_path);
	mk_lang_assert(*output_file_path);

	if(logger_fnc){ logger_fnc(logger_ctx, "Opening input file.\n"); }
	input_file = fopen(input_file_path, "rb"); check(input_file);
	if(logger_fnc){ logger_fnc(logger_ctx, "Input file opened.\n"); }
	tus = fread(&salt, 1, salt_len, input_file); check(tus == salt_len);
	pwd = ((mk_sl_cui_uint8_pct)(password));
	slt = ((mk_sl_cui_uint8_pct)(&salt));
	slt_len = salt_len;
	cost = (pim == 0ul) ? (500000ul) : (15000ul + (pim * 1000ul));
	keys_len = 2 * seq_key_len;
	for(prf_id = ((prf_id_t)(0)); prf_id != prf_id_e_dummy_end; prf_id = ((prf_id_t)(((int)(prf_id)) + 1)))
	{
		if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Deriving keys from salt, password and PIM using the %s algorithm.\n", get_prf_name(prf_id)); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
		pbkdf2(prf_id, pwd, password_len, slt, slt_len, cost, keys_len, &keys[0]);
		if(logger_fnc){ logger_fnc(logger_ctx, "Keys derived.\n"); }
		for(seq_id = ((seq_id_t)(0)); seq_id != seq_id_e_dummy_end; seq_id = ((seq_id_t)(((int)(seq_id)) + 1)))
		{
			if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Trying the %s cipher.\n", get_seq_name(seq_id)); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
			seq_key_init(seq_id, &keys[0], 0, &keya);
			seq_key_init(seq_id, &keys[0], 1, &keyb);
			seq_expand_dec(seq_id, &keya, &schedulea);
			seq_expand_enc(seq_id, &keyb, &scheduleb);
			reader.m_seq_id = seq_id;
			reader.m_file = input_file;
			reader.m_schedulea = &schedulea;
			reader.m_scheduleb = &scheduleb;
			reader.m_block_idx = 1;
			reader.m_block = &block;
			ti = reader_read(&reader, magic_offset, magic_len, &magic_bytes[0]); check2(ti);
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[0], &tc); check_continue(tc == 'V');
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[1], &tc); check_continue(tc == 'E');
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[2], &tc); check_continue(tc == 'R');
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[3], &tc); check_continue(tc == 'A');
			break;
		}
		check_continue(seq_id != seq_id_e_dummy_end);
		break;
	}
	check(prf_id != prf_id_e_dummy_end);

	ti = reader_read(&reader, ver_offset, ver_len, &ver_bytes[0]); check2(ti);
	mk_sl_uint_16_from_8_be(&ver, &ver_bytes[0]);
	ti = mk_sl_cui_uint16_to_str_dec_n(&ver, &ver_str[0], mk_sl_cui_uint16_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint16_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Volume header format version: %.*s\n", ti, &ver_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint16_to_bi_size(&ver, &tus);
	check(tus == 5);

	ti = reader_read(&reader, min_ver_maj_offset, min_ver_maj_len, &min_ver_maj_bytes[0]); check2(ti);
	min_ver_maj = min_ver_maj_bytes[0];
	ti = mk_sl_cui_uint8_to_str_dec_n(&min_ver_maj, &min_ver_maj_str[0], mk_sl_cui_uint8_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint8_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Minimum program version required to open the volume: %.*s", ti, &min_ver_maj_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint8_to_bi_size(&min_ver_maj, &tus);
	check(tus == 1);

	ti = reader_read(&reader, min_ver_min_offset, min_ver_min_len, &min_ver_min_bytes[0]); check2(ti);
	min_ver_min = min_ver_min_bytes[0];
	ti = mk_sl_cui_uint8_to_str_dec_n(&min_ver_min, &min_ver_min_str[0], mk_sl_cui_uint8_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint8_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], ".%.*s\n", ti, &min_ver_min_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint8_to_bi_size(&min_ver_min, &tus);
	check(tus == 11);

	ti = reader_read(&reader, size_volume_offset, size_volume_len, &size_volume_bytes[0]); check2(ti);
	mk_sl_uint_64_from_8_be(&size_volume, &size_volume_bytes[0]);
	ti = mk_sl_cui_uint64_to_str_dec_n(&size_volume, &size_volume_str[0], mk_sl_cui_uint64_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint64_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Size of volume: %.*s\n", ti, &size_volume_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint64_to_bi_ulong(&size_volume, &size_volume_ul);
	check(size_volume_ul % block_len == 0);

	ti = reader_read(&reader, master_key_scope1_offset, master_key_scope1_len, &master_key_scope1_bytes[0]); check2(ti);
	mk_sl_uint_64_from_8_be(&master_key_scope1, &master_key_scope1_bytes[0]);
	ti = mk_sl_cui_uint64_to_str_dec_n(&master_key_scope1, &master_key_scope1_str[0], mk_sl_cui_uint64_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint64_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Byte offset of the start of the master key scope: %.*s\n", ti, &master_key_scope1_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint64_to_bi_ulong(&master_key_scope1, &master_key_scope1_ul);
	check(master_key_scope1_ul == data_offset);

	ti = reader_read(&reader, master_key_scope2_offset, master_key_scope2_len, &master_key_scope2_bytes[0]); check2(ti);
	mk_sl_uint_64_from_8_be(&master_key_scope2, &master_key_scope2_bytes[0]);
	ti = mk_sl_cui_uint64_to_str_dec_n(&master_key_scope2, &master_key_scope2_str[0], mk_sl_cui_uint64_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint64_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Size of the encrypted area within the master key scope: %.*s\n", ti, &master_key_scope2_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint64_to_bi_ulong(&master_key_scope2, &master_key_scope2_ul);
	check(master_key_scope2_ul == size_volume_ul);

	ti = reader_read(&reader, sector_size_offset, sector_size_len, &sector_size_bytes[0]); check2(ti);
	mk_sl_uint_32_from_8_be(&sector_size, &sector_size_bytes[0]);
	ti = mk_sl_cui_uint32_to_str_dec_n(&sector_size, &sector_size_str[0], mk_sl_cui_uint32_to_str_dec_len); check(ti != 0 && ti >= 1 && ti <= mk_sl_cui_uint32_to_str_dec_len);
	if(logger_fnc){ mk_lang_types_pchar_t buff[128]; ti = sprintf(&buff[0], "Sector size: %.*s\n", ti, &sector_size_str[0]); check(ti >= 1); logger_fnc(logger_ctx, &buff[0]); }
	mk_sl_cui_uint32_to_bi_ulong(&sector_size, &sector_size_ul);
	check(sector_size_ul == block_len);

	ti = reader_read(&reader, master_keys_offset + 0 * seq_key_len_r(seq_id), seq_key_len_r(seq_id), &master_keya); check2(ti);
	ti = reader_read(&reader, master_keys_offset + 1 * seq_key_len_r(seq_id), seq_key_len_r(seq_id), &master_keyb); check2(ti);
	seq_expand_dec(seq_id, &master_keya, &master_schedulea);
	seq_expand_enc(seq_id, &master_keyb, &master_scheduleb);
	ti = fseek(input_file, data_offset, SEEK_SET); check(ti == 0);
	if(logger_fnc){ logger_fnc(logger_ctx, "Opening output file.\n"); }
	output_file = fopen(output_file_path, "wb"); check(output_file);
	if(logger_fnc){ logger_fnc(logger_ctx, "Output file opened.\n"); }
	if(logger_fnc){ logger_fnc(logger_ctx, "Decrypting.\n"); }
	#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14
	if((size_volume_ul % chunk_size) == 0)
	{
		ti = vc_decrypt_multithreaded(seq_id, size_volume_ul, master_schedulea, master_scheduleb, input_file, output_file); check2(ti);
	}
	else
	#endif
	{
		ti = vc_decrypt_singlethreaded(seq_id, size_volume_ul, master_schedulea, master_scheduleb, input_file, output_file); check2(ti);
	}
	if(logger_fnc){ logger_fnc(logger_ctx, "Decryption done.\n"); }

	if(logger_fnc){ logger_fnc(logger_ctx, "Closing input file.\n"); }
	ti = fclose(input_file); check(ti == 0);
	if(logger_fnc){ logger_fnc(logger_ctx, "Input file closed.\n"); }
	if(logger_fnc){ logger_fnc(logger_ctx, "Closing output file.\n"); }
	ti = fclose(output_file); check(ti == 0);
	if(logger_fnc){ logger_fnc(logger_ctx, "Output file closed.\n"); }

	return EXIT_SUCCESS;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t str_len(mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_pchar_pct p mk_lang_constexpr_init;
	mk_lang_types_usize_t r mk_lang_constexpr_init;

	mk_lang_assert(str);

	p = str;
	while(*p){ ++p; }
	r = ((mk_lang_types_usize_t)(p - str));
	return r;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int parse_u32(unsigned long* const ul, char const* const str) mk_lang_noexcept
{
	int len mk_lang_constexpr_init;
	int ti mk_lang_constexpr_init;
	mk_sl_cui_uint32_t u32 mk_lang_constexpr_init;

	mk_lang_assert(ul);
	mk_lang_assert(str);
	mk_lang_assert(str_len(str) <= mk_lang_limits_sint_max);

	len = ((int)(str_len(str)));
	ti = mk_sl_cui_uint32_from_str_dec_n(&u32, str, len); check(ti == len);
	mk_sl_cui_uint32_to_bi_ulong(&u32, ul);

	return EXIT_SUCCESS;
}

static mk_lang_inline char const* get_exe_name(char const* const arg) mk_lang_noexcept
{
	char const* r;
	char const* p;

	r = arg;
	for(p = r; *p; ++p)
	{
		if(*p == '/' || *p == '\\')
		{
			r = p + 1;
		}
	}
	return r;
}





#include <stdio.h> /* printf fflush */


mk_lang_nodiscard static mk_lang_types_sint_t logger(vc_logger_ctx_pt const ctx, char const* const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t ti;

	((void)(ctx));
	ti = printf("%s", msg); check(ti >= 0);
	ti = fflush(stdout); check(ti == 0);
	return EXIT_SUCCESS;
}

int main(int const argc, char const* const* const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t ti;
	mk_lang_types_pchar_pct input_file_path;
	mk_lang_types_pchar_pct password;
	mk_lang_types_usize_t password_len_;
	mk_lang_types_sint_t password_len;
	mk_lang_types_ulong_t pim;
	vc_logger_fnc_pt lgr_fnc;
	vc_logger_ctx_pt lgr_ctx;
	mk_lang_types_pchar_pct output_file_path;

	mk_lang_assert(argv);

	mk_lang_cpuid_init();
	mk_sl_mallocator_lang_init();
	if(argc == 1)
	{
		ti = printf("Example usage: %s <input_file> <password> <pim> <output_file>\n", get_exe_name(argv[0])); check(ti > 0);
		return EXIT_SUCCESS;
	}
	check(argc == 5);
	input_file_path = argv[1];
	password = argv[2];
	password_len_ = str_len(password); check(password_len_ <= mk_lang_limits_sint_max); password_len = ((mk_lang_types_sint_t)(password_len_));
	ti = parse_u32(&pim, argv[3]); check2(ti);
	lgr_fnc = &logger;
	lgr_ctx = mk_lang_null;
	output_file_path = argv[4];
	ti = vc_decrypt(input_file_path, password, password_len, pim, lgr_fnc, lgr_ctx, output_file_path); check2(ti);
	mk_sl_mallocator_lang_deinit();
	return EXIT_SUCCESS;
}
