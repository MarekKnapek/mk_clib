#include "mk_clib_app_vc.h"

#include "mk_lang_max.h"
#include "mk_lang_pow2.h"
#include "mk_lang_min.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_streebog_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_whirlpool.h"
#include "mk_sl_io_reader_file_portable.h"
#include "mk_sl_io_writer_file_portable.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_clib_app_vc_memcpyu8
#define mk_lang_memcpy_t_base mk_sl_cui_uint8
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memset_t_name mk_clib_app_vc_memsetu8
#define mk_lang_memset_t_base mk_sl_cui_uint8
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lib_crypto_mode_base_t_name mk_clib_app_vc_mode
#define mk_lib_crypto_mode_base_t_len 16
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"

#include <stdio.h>


#define mk_clib_app_vc_salt_len 64
#define mk_clib_app_vc_block_len 512
#define mk_clib_app_vc_msg_len 16
#define mk_clib_app_vc_msgs_per_block (mk_clib_app_vc_block_len / mk_clib_app_vc_msg_len)

#define mk_clib_app_vc_offsets_magic                        0
#define mk_clib_app_vc_offsets_volume_header_format_version 4
#define mk_clib_app_vc_offsets_minimum_program_version      6
#define mk_clib_app_vc_offsets_crc_a                        8
#define mk_clib_app_vc_offsets_reserved_a                  12
#define mk_clib_app_vc_offsets_hidden_volume_size          28
#define mk_clib_app_vc_offsets_normal_volume_size          36
#define mk_clib_app_vc_offsets_master_key_scope_start      44
#define mk_clib_app_vc_offsets_master_key_scope_len        52
#define mk_clib_app_vc_offsets_flags                       60
#define mk_clib_app_vc_offsets_block_len                   64
#define mk_clib_app_vc_offsets_reserved_b                  68
#define mk_clib_app_vc_offsets_crc_b                      188
#define mk_clib_app_vc_offsets_keys                       192
#define mk_clib_app_vc_offsets_volume          (128l * 1024l)

#define mk_clib_app_vc_lens_magic                        4
#define mk_clib_app_vc_lens_volume_header_format_version 2
#define mk_clib_app_vc_lens_minimum_program_version      2
#define mk_clib_app_vc_lens_crc_a                        4
#define mk_clib_app_vc_lens_reserved_a                  16
#define mk_clib_app_vc_lens_hidden_volume_size           8
#define mk_clib_app_vc_lens_normal_volume_size           8
#define mk_clib_app_vc_lens_master_key_scope_start       8
#define mk_clib_app_vc_lens_master_key_scope_len         8
#define mk_clib_app_vc_lens_flags                        4
#define mk_clib_app_vc_lens_block_len                    4
#define mk_clib_app_vc_lens_reserved_b                 120
#define mk_clib_app_vc_lens_crc_b                        4
#define mk_clib_app_vc_lens_keys                       256


enum mk_clib_app_vc_kdfid_e
{
	mk_clib_app_vc_kdfid_e_sha512,
	mk_clib_app_vc_kdfid_e_whirlpool,
	mk_clib_app_vc_kdfid_e_sha256,
	mk_clib_app_vc_kdfid_e_blake2s256,
	mk_clib_app_vc_kdfid_e_streebog,
	mk_clib_app_vc_kdfid_e_dummy
};
typedef enum mk_clib_app_vc_kdfid_e mk_clib_app_vc_kdfid_t;
typedef mk_clib_app_vc_kdfid_t const mk_clib_app_vc_kdfid_ct;
typedef mk_clib_app_vc_kdfid_t* mk_clib_app_vc_kdfid_pt;
typedef mk_clib_app_vc_kdfid_t const* mk_clib_app_vc_kdfid_pct;

enum mk_clib_app_vc_algid_e
{
	mk_clib_app_vc_algid_e_aes,
	mk_clib_app_vc_algid_e_serpent,
	mk_clib_app_vc_algid_e_dummy
};
typedef enum mk_clib_app_vc_algid_e mk_clib_app_vc_algid_t;

enum mk_clib_app_vc_seqid_e
{
	mk_clib_app_vc_seqid_e_aes,
	mk_clib_app_vc_seqid_e_serpent,
	mk_clib_app_vc_seqid_e_aes_serpent,
	mk_clib_app_vc_seqid_e_dummy
};
typedef enum mk_clib_app_vc_seqid_e mk_clib_app_vc_seqid_t;
typedef mk_clib_app_vc_seqid_t const mk_clib_app_vc_seqid_ct;
typedef mk_clib_app_vc_seqid_t* mk_clib_app_vc_seqid_pt;
typedef mk_clib_app_vc_seqid_t const* mk_clib_app_vc_seqid_pct;

union mk_clib_app_vc_alg_schedule_data_u
{
	mk_lib_crypto_alg_aes_256_schedule_pct m_aes;
	mk_lib_crypto_alg_serpent_schedule_pct m_serpent;
};
typedef union mk_clib_app_vc_alg_schedule_data_u mk_clib_app_vc_alg_schedule_data_t;

struct mk_clib_app_vc_alg_schedule_s
{
	mk_clib_app_vc_alg_schedule_data_t m_data;
};
typedef struct mk_clib_app_vc_alg_schedule_s mk_clib_app_vc_alg_schedule_t;

struct mk_clib_app_vc_seq_aes_keys_s
{
	mk_lib_crypto_alg_aes_256_key_t m_pri;
	mk_lib_crypto_alg_aes_256_key_t m_sec;
};
typedef struct mk_clib_app_vc_seq_aes_keys_s mk_clib_app_vc_seq_aes_keys_t;

struct mk_clib_app_vc_seq_serpent_keys_s
{
	mk_lib_crypto_alg_serpent_key_t m_pri;
	mk_lib_crypto_alg_serpent_key_t m_sec;
};
typedef struct mk_clib_app_vc_seq_serpent_keys_s mk_clib_app_vc_seq_serpent_keys_t;

struct mk_clib_app_vc_seq_aes_serpent_keys_s
{
	mk_lib_crypto_alg_aes_256_key_t m_aes_pri;
	mk_lib_crypto_alg_serpent_key_t m_serpent_pri;
	mk_lib_crypto_alg_aes_256_key_t m_aes_sec;
	mk_lib_crypto_alg_serpent_key_t m_serpent_sec;
};
typedef struct mk_clib_app_vc_seq_aes_serpent_keys_s mk_clib_app_vc_seq_aes_serpent_keys_t;

union mk_clib_app_vc_seq_keys_data_u
{
	mk_clib_app_vc_seq_aes_keys_t m_aes;
	mk_clib_app_vc_seq_serpent_keys_t m_serpent;
	mk_clib_app_vc_seq_aes_serpent_keys_t m_aes_serpent;
};
typedef union mk_clib_app_vc_seq_keys_data_u mk_clib_app_vc_seq_keys_data_t;

struct mk_clib_app_vc_seq_keys_s
{
	mk_clib_app_vc_seq_keys_data_t m_data;
};
typedef struct mk_clib_app_vc_seq_keys_s mk_clib_app_vc_seq_keys_t;
typedef mk_clib_app_vc_seq_keys_t const mk_clib_app_vc_seq_keys_ct;
typedef mk_clib_app_vc_seq_keys_t* mk_clib_app_vc_seq_keys_pt;
typedef mk_clib_app_vc_seq_keys_t const* mk_clib_app_vc_seq_keys_pct;

struct mk_clib_app_vc_key_material_data_s
{
	mk_sl_cui_uint8_t m_uint8s[2 * mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_key_len_v, mk_lib_crypto_alg_serpent_key_len_v), mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)];
};
typedef struct mk_clib_app_vc_key_material_data_s mk_clib_app_vc_key_material_data_t;

struct mk_clib_app_vc_key_material_s
{
	mk_clib_app_vc_key_material_data_t m_data;
};
typedef struct mk_clib_app_vc_key_material_s mk_clib_app_vc_key_material_t;
typedef mk_clib_app_vc_key_material_t const mk_clib_app_vc_key_material_ct;
typedef mk_clib_app_vc_key_material_t* mk_clib_app_vc_key_material_pt;
typedef mk_clib_app_vc_key_material_t const* mk_clib_app_vc_key_material_pct;

struct mk_clib_app_vc_seq_aes_schedules_s
{
	mk_lib_crypto_alg_aes_256_schedule_t m_pri;
	mk_lib_crypto_alg_aes_256_schedule_t m_sec;
};
typedef struct mk_clib_app_vc_seq_aes_schedules_s mk_clib_app_vc_seq_aes_schedules_t;

struct mk_clib_app_vc_seq_serpent_schedules_s
{
	mk_lib_crypto_alg_serpent_schedule_t m_pri;
	mk_lib_crypto_alg_serpent_schedule_t m_sec;
};
typedef struct mk_clib_app_vc_seq_serpent_schedules_s mk_clib_app_vc_seq_serpent_schedules_t;

struct mk_clib_app_vc_seq_aes_serpent_schedules_s
{
	mk_lib_crypto_alg_aes_256_schedule_t m_aes_pri;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent_pri;
	mk_lib_crypto_alg_aes_256_schedule_t m_aes_sec;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent_sec;
};
typedef struct mk_clib_app_vc_seq_aes_serpent_schedules_s mk_clib_app_vc_seq_aes_serpent_schedules_t;

union mk_clib_app_vc_seq_schedules_data_u
{
	mk_clib_app_vc_seq_aes_schedules_t m_aes;
	mk_clib_app_vc_seq_serpent_schedules_t m_serpent;
	mk_clib_app_vc_seq_aes_serpent_schedules_t m_aes_serpent;
};
typedef union mk_clib_app_vc_seq_schedules_data_u mk_clib_app_vc_seq_schedules_data_t;

struct mk_clib_app_vc_seq_schedules_s
{
	mk_clib_app_vc_seq_schedules_data_t m_data;
};
typedef struct mk_clib_app_vc_seq_schedules_s mk_clib_app_vc_seq_schedules_t;
typedef mk_clib_app_vc_seq_schedules_t const mk_clib_app_vc_seq_schedules_ct;
typedef mk_clib_app_vc_seq_schedules_t* mk_clib_app_vc_seq_schedules_pt;
typedef mk_clib_app_vc_seq_schedules_t const* mk_clib_app_vc_seq_schedules_pct;

struct mk_clib_app_vc_block_oversized_data_s
{
	mk_sl_cui_uint8_t m_uint8s[mk_clib_app_vc_block_len + (mk_clib_app_vc_block_len - 1)];
};
typedef struct mk_clib_app_vc_block_oversized_data_s mk_clib_app_vc_block_oversized_data_t;

struct mk_clib_app_vc_block_oversized_s
{
	mk_clib_app_vc_block_oversized_data_t m_data;
};
typedef struct mk_clib_app_vc_block_oversized_s mk_clib_app_vc_block_oversized_t;

struct mk_clib_app_vc_block_oversized2_data_s
{
	mk_sl_cui_uint8_t m_uint8s[(mk_clib_app_vc_block_len + mk_clib_app_vc_salt_len) + (mk_clib_app_vc_block_len + mk_clib_app_vc_salt_len - 1)];
};
typedef struct mk_clib_app_vc_block_oversized2_data_s mk_clib_app_vc_block_oversized2_data_t;

struct mk_clib_app_vc_block_oversized2_s
{
	mk_clib_app_vc_block_oversized2_data_t m_data;
};
typedef struct mk_clib_app_vc_block_oversized2_s mk_clib_app_vc_block_oversized2_t;

union mk_clib_app_vc_tweak_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_clib_app_vc_msg_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aes;
	mk_lib_crypto_alg_serpent_msg_t m_serpent;
};
typedef union mk_clib_app_vc_tweak_data_u mk_clib_app_vc_tweak_data_t;

struct mk_clib_app_vc_tweak_s
{
	mk_clib_app_vc_tweak_data_t m_data;
};
typedef struct mk_clib_app_vc_tweak_s mk_clib_app_vc_tweak_t;
typedef mk_clib_app_vc_tweak_t const mk_clib_app_vc_tweak_ct;
typedef mk_clib_app_vc_tweak_t* mk_clib_app_vc_tweak_pt;
typedef mk_clib_app_vc_tweak_t const* mk_clib_app_vc_tweak_pct;

struct mk_clib_app_vc_salt_data_s
{
	mk_sl_cui_uint8_t m_uint8s[mk_clib_app_vc_salt_len];
};
typedef struct mk_clib_app_vc_salt_data_s mk_clib_app_vc_salt_data_t;

struct mk_clib_app_vc_salt_s
{
	mk_clib_app_vc_salt_data_t m_data;
};
typedef struct mk_clib_app_vc_salt_s mk_clib_app_vc_salt_t;
typedef mk_clib_app_vc_salt_t const mk_clib_app_vc_salt_ct;
typedef mk_clib_app_vc_salt_t* mk_clib_app_vc_salt_pt;
typedef mk_clib_app_vc_salt_t const* mk_clib_app_vc_salt_pct;

union mk_clib_app_vc_block_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_clib_app_vc_block_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aess[mk_clib_app_vc_block_len / mk_lib_crypto_alg_aes_256_msg_len_v];
	mk_lib_crypto_alg_serpent_msg_t m_serpents[mk_clib_app_vc_block_len / mk_lib_crypto_alg_serpent_msg_len_v];
	mk_clib_app_vc_tweak_t m_tweaks[mk_clib_app_vc_block_len / mk_clib_app_vc_msg_len];
};
typedef union mk_clib_app_vc_block_data_u mk_clib_app_vc_block_data_t;

struct mk_clib_app_vc_block_s
{
	mk_clib_app_vc_block_data_t m_data;
};
typedef struct mk_clib_app_vc_block_s mk_clib_app_vc_block_t;
typedef mk_clib_app_vc_block_t const mk_clib_app_vc_block_ct;
typedef mk_clib_app_vc_block_t* mk_clib_app_vc_block_pt;
typedef mk_clib_app_vc_block_t const* mk_clib_app_vc_block_pct;


static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_alg_encrypt_tweak(mk_clib_app_vc_algid_t const algid, mk_clib_app_vc_alg_schedule_t const schedule, mk_clib_app_vc_tweak_pct const in, mk_clib_app_vc_tweak_pt const out) mk_lang_noexcept
{
	mk_lang_assert(algid >= 0 && algid < mk_clib_app_vc_algid_e_dummy);
	mk_lang_assert(in);
	mk_lang_assert(out);

	switch(algid)
	{
		case mk_clib_app_vc_algid_e_aes:     mk_lang_assert(schedule.m_data.m_aes);     mk_lib_crypto_alg_aes_256_schedule_encrypt(schedule.m_data.m_aes,     &in->m_data.m_aes,     &out->m_data.m_aes,     1); break;
		case mk_clib_app_vc_algid_e_serpent: mk_lang_assert(schedule.m_data.m_serpent); mk_lib_crypto_alg_serpent_schedule_encrypt(schedule.m_data.m_serpent, &in->m_data.m_serpent, &out->m_data.m_serpent, 1); break;
		case mk_clib_app_vc_algid_e_dummy: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_alg_decrypt_block(mk_clib_app_vc_algid_t const algid, mk_clib_app_vc_alg_schedule_t const schedule, mk_clib_app_vc_block_pct const block_in, mk_clib_app_vc_block_pt const block_out) mk_lang_noexcept
{
	mk_lang_assert(algid >= 0 && algid < mk_clib_app_vc_algid_e_dummy);
	mk_lang_assert(block_in);
	mk_lang_assert(block_out);

	switch(algid)
	{
		case mk_clib_app_vc_algid_e_aes:     mk_lang_assert(schedule.m_data.m_aes);     mk_lib_crypto_alg_aes_256_schedule_decrypt(schedule.m_data.m_aes,     &block_in->m_data.m_aess[0],     &block_out->m_data.m_aess[0],     mk_clib_app_vc_msgs_per_block); break;
		case mk_clib_app_vc_algid_e_serpent: mk_lang_assert(schedule.m_data.m_serpent); mk_lib_crypto_alg_serpent_schedule_decrypt(schedule.m_data.m_serpent, &block_in->m_data.m_serpents[0], &block_out->m_data.m_serpents[0], mk_clib_app_vc_msgs_per_block); break;
		case mk_clib_app_vc_algid_e_dummy: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_alg_tweak_next(mk_clib_app_vc_tweak_pct const a, mk_clib_app_vc_tweak_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8;
	mk_sl_cui_uint128_t tu128;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_shr3(&a->m_data.m_uint8s[mk_clib_app_vc_msg_len - 1], mk_lang_charbit - 1, &tu8);
	mk_sl_uint_128_from_8_le(&tu128, &a->m_data.m_uint8s[0]);
	mk_sl_cui_uint128_shl2(&tu128, 1);
	mk_sl_uint_128_to_8_le(&tu128, &b->m_data.m_uint8s[0]);
	if(!mk_sl_cui_uint8_is_zero(&tu8))
	{
		tsi = 0x87;
		mk_sl_cui_uint8_from_bi_sint(&tu8, &tsi);
		mk_sl_cui_uint8_xor2(&b->m_data.m_uint8s[0], &tu8);
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_xts_decrypt_block(mk_clib_app_vc_algid_t const algid, mk_clib_app_vc_alg_schedule_t const schedule_a, mk_clib_app_vc_alg_schedule_t const schedule_b, mk_sl_cui_uint64_pct const block_id, mk_clib_app_vc_block_pct const in, mk_clib_app_vc_block_pt const out) mk_lang_noexcept
{
	mk_clib_app_vc_block_pt tweaks;
	mk_clib_app_vc_block_oversized_t tweaks_oversized;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t i;

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_v == mk_clib_app_vc_msg_len);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_v == mk_clib_app_vc_msg_len);

	mk_lang_assert(algid >= 0 && algid < mk_clib_app_vc_algid_e_dummy);
	mk_lang_assert(block_id);
	mk_lang_assert(in);
	mk_lang_assert(out);

	tweaks = ((mk_clib_app_vc_block_pt)(((((mk_lang_types_uintptr_t)(&tweaks_oversized)) + (sizeof(*tweaks) - 1)) / sizeof(*tweaks)) * sizeof(*tweaks)));
	mk_sl_uint_64_to_8_le(block_id, &tweaks->m_data.m_tweaks[0].m_data.m_uint8s[0 * 8]);
	mk_sl_cui_uint64_set_zero(&tu64);
	mk_sl_uint_64_to_8_le(&tu64, &tweaks->m_data.m_tweaks[0].m_data.m_uint8s[1 * 8]);
	mk_clib_app_vc_alg_encrypt_tweak(algid, schedule_b, &tweaks->m_data.m_tweaks[0], &tweaks->m_data.m_tweaks[0]);
	mk_clib_app_vc_mode_xor3(&in->m_data.m_tweaks[0].m_data.m_uint8s[0], &tweaks->m_data.m_tweaks[0].m_data.m_uint8s[0], &out->m_data.m_tweaks[0].m_data.m_uint8s[0]);
	for(i = 1; i != mk_clib_app_vc_msgs_per_block; ++i)
	{
		mk_clib_app_vc_alg_tweak_next(&tweaks->m_data.m_tweaks[i - 1], &tweaks->m_data.m_tweaks[i]);
		mk_clib_app_vc_mode_xor3(&in->m_data.m_tweaks[i].m_data.m_uint8s[0], &tweaks->m_data.m_tweaks[i].m_data.m_uint8s[0], &out->m_data.m_tweaks[i].m_data.m_uint8s[0]);
	}
	mk_clib_app_vc_alg_decrypt_block(algid, schedule_a, out, out);
	for(i = 0; i != mk_clib_app_vc_msgs_per_block; ++i)
	{
		mk_clib_app_vc_mode_xor2(&out->m_data.m_tweaks[i].m_data.m_uint8s[0], &tweaks->m_data.m_tweaks[i].m_data.m_uint8s[0]);
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_seq_decrypt_block(mk_clib_app_vc_seqid_t const seqid, mk_clib_app_vc_seq_schedules_pct const schedules, mk_sl_cui_uint64_pct const block_id, mk_clib_app_vc_block_pct const in, mk_clib_app_vc_block_pt const out) mk_lang_noexcept
{
	mk_clib_app_vc_algid_t first_alg;
	mk_clib_app_vc_alg_schedule_t first_sch_pri;
	mk_clib_app_vc_alg_schedule_t first_sch_sec;
	mk_clib_app_vc_algid_t second_alg;
	mk_clib_app_vc_alg_schedule_t second_sch_pri;
	mk_clib_app_vc_alg_schedule_t second_sch_sec;

	mk_lang_assert(seqid >= 0 && seqid < mk_clib_app_vc_seqid_e_dummy);
	mk_lang_assert(schedules);
	mk_lang_assert(block_id);
	mk_lang_assert(in);
	mk_lang_assert(out);

	switch(seqid)
	{
		case mk_clib_app_vc_seqid_e_aes:
			first_alg = mk_clib_app_vc_algid_e_aes;
			first_sch_pri.m_data.m_aes = &schedules->m_data.m_aes.m_pri;
			first_sch_sec.m_data.m_aes = &schedules->m_data.m_aes.m_sec;
			mk_clib_app_vc_xts_decrypt_block(first_alg, first_sch_pri, first_sch_sec, block_id, in, out);
		break;
		case mk_clib_app_vc_seqid_e_serpent:
			first_alg = mk_clib_app_vc_algid_e_serpent;
			first_sch_pri.m_data.m_serpent = &schedules->m_data.m_serpent.m_pri;
			first_sch_sec.m_data.m_serpent = &schedules->m_data.m_serpent.m_sec;
			mk_clib_app_vc_xts_decrypt_block(first_alg, first_sch_pri, first_sch_sec, block_id, in, out);
		break;
		case mk_clib_app_vc_seqid_e_aes_serpent:
			first_alg = mk_clib_app_vc_algid_e_serpent;
			first_sch_pri.m_data.m_serpent = &schedules->m_data.m_aes_serpent.m_serpent_pri;
			first_sch_sec.m_data.m_serpent = &schedules->m_data.m_aes_serpent.m_serpent_sec;
			second_alg = mk_clib_app_vc_algid_e_aes;
			second_sch_pri.m_data.m_aes = &schedules->m_data.m_aes_serpent.m_aes_pri;
			second_sch_sec.m_data.m_aes = &schedules->m_data.m_aes_serpent.m_aes_sec;
			mk_clib_app_vc_xts_decrypt_block(first_alg,  first_sch_pri,  first_sch_sec,  block_id, in,  out);
			mk_clib_app_vc_xts_decrypt_block(second_alg, second_sch_pri, second_sch_sec, block_id, out, out);
		break;
		case mk_clib_app_vc_seqid_e_dummy:
			mk_lang_assert(mk_lang_false);
		break;
		default:
			mk_lang_assert(mk_lang_false);
		break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_seq_expand_dec(mk_clib_app_vc_seqid_t const seqid, mk_clib_app_vc_seq_keys_pct const keys, mk_clib_app_vc_seq_schedules_pt const schedules) mk_lang_noexcept
{
	mk_lang_assert(seqid >= 0 && seqid < mk_clib_app_vc_seqid_e_dummy);
	mk_lang_assert(keys);
	mk_lang_assert(schedules);

	switch(seqid)
	{
		case mk_clib_app_vc_seqid_e_aes:
			mk_lib_crypto_alg_aes_256_expand_dec(&keys->m_data.m_aes.m_pri, &schedules->m_data.m_aes.m_pri);
			mk_lib_crypto_alg_aes_256_expand_enc(&keys->m_data.m_aes.m_sec, &schedules->m_data.m_aes.m_sec);
		break;
		case mk_clib_app_vc_seqid_e_serpent:
			mk_lib_crypto_alg_serpent_expand_dec(&keys->m_data.m_serpent.m_pri, &schedules->m_data.m_serpent.m_pri);
			mk_lib_crypto_alg_serpent_expand_enc(&keys->m_data.m_serpent.m_sec, &schedules->m_data.m_serpent.m_sec);
		break;
		case mk_clib_app_vc_seqid_e_aes_serpent:
			mk_lib_crypto_alg_aes_256_expand_dec(&keys->m_data.m_aes_serpent.m_aes_pri,     &schedules->m_data.m_aes_serpent.m_aes_pri    );
			mk_lib_crypto_alg_serpent_expand_dec(&keys->m_data.m_aes_serpent.m_serpent_pri, &schedules->m_data.m_aes_serpent.m_serpent_pri);
			mk_lib_crypto_alg_aes_256_expand_enc(&keys->m_data.m_aes_serpent.m_aes_sec,     &schedules->m_data.m_aes_serpent.m_aes_sec    );
			mk_lib_crypto_alg_serpent_expand_enc(&keys->m_data.m_aes_serpent.m_serpent_sec, &schedules->m_data.m_aes_serpent.m_serpent_sec);
		break;
		case mk_clib_app_vc_seqid_e_dummy:
			mk_lang_assert(mk_lang_false);
		break;
		default:
			mk_lang_assert(mk_lang_false);
		break;
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_keys_init(mk_clib_app_vc_seqid_t const seqid, mk_clib_app_vc_key_material_pct const key_material, mk_clib_app_vc_seq_keys_pt const keys) mk_lang_noexcept
{
	mk_lang_assert(seqid >= 0 && seqid < mk_clib_app_vc_seqid_e_dummy);
	mk_lang_assert(key_material);
	mk_lang_assert(keys);

	switch(seqid)
	{
		case mk_clib_app_vc_seqid_e_aes:
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_aes.m_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[0 * mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_aes_256_key_len_v);
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_aes.m_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[1 * mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_aes_256_key_len_v);
		break;
		case mk_clib_app_vc_seqid_e_serpent:
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_serpent.m_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[0 * mk_lib_crypto_alg_serpent_key_len_v], mk_lib_crypto_alg_serpent_key_len_v);
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_serpent.m_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[1 * mk_lib_crypto_alg_serpent_key_len_v], mk_lib_crypto_alg_serpent_key_len_v);
		break;
		case mk_clib_app_vc_seqid_e_aes_serpent:
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_aes_serpent.m_aes_pri    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v);
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_aes_serpent.m_serpent_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v);
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_aes_serpent.m_aes_sec    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v);
			mk_clib_app_vc_memcpyu8_fn(&keys->m_data.m_aes_serpent.m_serpent_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v);
		break;
		case mk_clib_app_vc_seqid_e_dummy:
			mk_lang_assert(mk_lang_false);
		break;
		default:
			mk_lang_assert(mk_lang_false);
		break;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_derive_keys(mk_clib_app_vc_kdfid_t const kdfid, mk_lang_types_pchar_pct const str_password, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_ulong_t const cost, mk_clib_app_vc_key_material_pt const key_material) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct password;

	mk_lang_assert(kdfid >= 0 && kdfid < mk_clib_app_vc_kdfid_e_dummy);
	mk_lang_assert(str_password);
	mk_lang_assert(password_len >= 1);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_material);

	password = ((mk_sl_cui_uint8_pct)(str_password));
	switch(kdfid)
	{
		case mk_clib_app_vc_kdfid_e_sha512:     mk_lib_crypto_kdf_pbkdf2_sha2_512    (password, password_len, salt, mk_clib_app_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_clib_app_vc_kdfid_e_whirlpool:  mk_lib_crypto_kdf_pbkdf2_whirlpool   (password, password_len, salt, mk_clib_app_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_clib_app_vc_kdfid_e_sha256:     mk_lib_crypto_kdf_pbkdf2_sha2_256    (password, password_len, salt, mk_clib_app_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_clib_app_vc_kdfid_e_blake2s256: mk_lib_crypto_kdf_pbkdf2_blake2s_256 (password, password_len, salt, mk_clib_app_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_clib_app_vc_kdfid_e_streebog:   mk_lib_crypto_kdf_pbkdf2_streebog_512(password, password_len, salt, mk_clib_app_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_clib_app_vc_kdfid_e_dummy: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_strlen(mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_pchar_pct ptr;
	mk_lang_types_sint_t len;

	mk_lang_assert(str);

	ptr = str;
	while(ptr[0] != '\0')
	{
		++ptr;
	}
	mk_lang_assert(ptr - str <= mk_lang_limits_sint_max);
	len = ((mk_lang_types_sint_t)(ptr - str));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_parse_cost(mk_lang_types_pchar_pct const str_pim, mk_lang_types_ulong_pt const cost) mk_lang_noexcept
{
	mk_lang_types_sint_t str_pim_len;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint32_t pim32[2];
	mk_sl_cui_uint64_t pim64;
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint64_t tu64;

	mk_lang_assert(str_pim);
	mk_lang_assert(cost);

	str_pim_len = mk_clib_app_vc_strlen(str_pim);
	err = mk_sl_cui_uint32_from_str_dec_n(&pim32[0], str_pim, str_pim_len);
	mk_lang_check_return(err == str_pim_len);
	if(mk_sl_cui_uint32_is_zero(&pim32[0]))
	{
		*cost = 500 * 1000;
	}
	else
	{
		mk_sl_cui_uint32_set_zero(&pim32[1]);
		mk_sl_uint_64_from_32_le(&pim64, &pim32[0]);
		tsi = 1 * 1000;
		mk_sl_cui_uint64_from_bi_sint(&tu64, &tsi);
		mk_sl_cui_uint64_mul2_wrap_lo(&pim64, &tu64);
		tsi = 15 * 1000;
		mk_sl_cui_uint64_from_bi_sint(&tu64, &tsi);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&pim64, &tu64);
		mk_sl_uint_64_to_32_le(&pim64, &pim32[0]);
		mk_lang_check_return(mk_sl_cui_uint32_is_zero(&pim32[1]));
		mk_sl_cui_uint32_to_bi_ulong(&pim32[0], cost);
	}
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_crc32(mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const len, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept
{
	static mk_sl_cui_uint32_t const table[] =
	{
		mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x77073096ul), mk_sl_cui_uint32_c(0xee0e612cul), mk_sl_cui_uint32_c(0x990951baul), mk_sl_cui_uint32_c(0x076dc419ul), mk_sl_cui_uint32_c(0x706af48ful), mk_sl_cui_uint32_c(0xe963a535ul), mk_sl_cui_uint32_c(0x9e6495a3ul),
		mk_sl_cui_uint32_c(0x0edb8832ul), mk_sl_cui_uint32_c(0x79dcb8a4ul), mk_sl_cui_uint32_c(0xe0d5e91eul), mk_sl_cui_uint32_c(0x97d2d988ul), mk_sl_cui_uint32_c(0x09b64c2bul), mk_sl_cui_uint32_c(0x7eb17cbdul), mk_sl_cui_uint32_c(0xe7b82d07ul), mk_sl_cui_uint32_c(0x90bf1d91ul),
		mk_sl_cui_uint32_c(0x1db71064ul), mk_sl_cui_uint32_c(0x6ab020f2ul), mk_sl_cui_uint32_c(0xf3b97148ul), mk_sl_cui_uint32_c(0x84be41deul), mk_sl_cui_uint32_c(0x1adad47dul), mk_sl_cui_uint32_c(0x6ddde4ebul), mk_sl_cui_uint32_c(0xf4d4b551ul), mk_sl_cui_uint32_c(0x83d385c7ul),
		mk_sl_cui_uint32_c(0x136c9856ul), mk_sl_cui_uint32_c(0x646ba8c0ul), mk_sl_cui_uint32_c(0xfd62f97aul), mk_sl_cui_uint32_c(0x8a65c9ecul), mk_sl_cui_uint32_c(0x14015c4ful), mk_sl_cui_uint32_c(0x63066cd9ul), mk_sl_cui_uint32_c(0xfa0f3d63ul), mk_sl_cui_uint32_c(0x8d080df5ul),
		mk_sl_cui_uint32_c(0x3b6e20c8ul), mk_sl_cui_uint32_c(0x4c69105eul), mk_sl_cui_uint32_c(0xd56041e4ul), mk_sl_cui_uint32_c(0xa2677172ul), mk_sl_cui_uint32_c(0x3c03e4d1ul), mk_sl_cui_uint32_c(0x4b04d447ul), mk_sl_cui_uint32_c(0xd20d85fdul), mk_sl_cui_uint32_c(0xa50ab56bul),
		mk_sl_cui_uint32_c(0x35b5a8faul), mk_sl_cui_uint32_c(0x42b2986cul), mk_sl_cui_uint32_c(0xdbbbc9d6ul), mk_sl_cui_uint32_c(0xacbcf940ul), mk_sl_cui_uint32_c(0x32d86ce3ul), mk_sl_cui_uint32_c(0x45df5c75ul), mk_sl_cui_uint32_c(0xdcd60dcful), mk_sl_cui_uint32_c(0xabd13d59ul),
		mk_sl_cui_uint32_c(0x26d930acul), mk_sl_cui_uint32_c(0x51de003aul), mk_sl_cui_uint32_c(0xc8d75180ul), mk_sl_cui_uint32_c(0xbfd06116ul), mk_sl_cui_uint32_c(0x21b4f4b5ul), mk_sl_cui_uint32_c(0x56b3c423ul), mk_sl_cui_uint32_c(0xcfba9599ul), mk_sl_cui_uint32_c(0xb8bda50ful),
		mk_sl_cui_uint32_c(0x2802b89eul), mk_sl_cui_uint32_c(0x5f058808ul), mk_sl_cui_uint32_c(0xc60cd9b2ul), mk_sl_cui_uint32_c(0xb10be924ul), mk_sl_cui_uint32_c(0x2f6f7c87ul), mk_sl_cui_uint32_c(0x58684c11ul), mk_sl_cui_uint32_c(0xc1611dabul), mk_sl_cui_uint32_c(0xb6662d3dul),
		mk_sl_cui_uint32_c(0x76dc4190ul), mk_sl_cui_uint32_c(0x01db7106ul), mk_sl_cui_uint32_c(0x98d220bcul), mk_sl_cui_uint32_c(0xefd5102aul), mk_sl_cui_uint32_c(0x71b18589ul), mk_sl_cui_uint32_c(0x06b6b51ful), mk_sl_cui_uint32_c(0x9fbfe4a5ul), mk_sl_cui_uint32_c(0xe8b8d433ul),
		mk_sl_cui_uint32_c(0x7807c9a2ul), mk_sl_cui_uint32_c(0x0f00f934ul), mk_sl_cui_uint32_c(0x9609a88eul), mk_sl_cui_uint32_c(0xe10e9818ul), mk_sl_cui_uint32_c(0x7f6a0dbbul), mk_sl_cui_uint32_c(0x086d3d2dul), mk_sl_cui_uint32_c(0x91646c97ul), mk_sl_cui_uint32_c(0xe6635c01ul),
		mk_sl_cui_uint32_c(0x6b6b51f4ul), mk_sl_cui_uint32_c(0x1c6c6162ul), mk_sl_cui_uint32_c(0x856530d8ul), mk_sl_cui_uint32_c(0xf262004eul), mk_sl_cui_uint32_c(0x6c0695edul), mk_sl_cui_uint32_c(0x1b01a57bul), mk_sl_cui_uint32_c(0x8208f4c1ul), mk_sl_cui_uint32_c(0xf50fc457ul),
		mk_sl_cui_uint32_c(0x65b0d9c6ul), mk_sl_cui_uint32_c(0x12b7e950ul), mk_sl_cui_uint32_c(0x8bbeb8eaul), mk_sl_cui_uint32_c(0xfcb9887cul), mk_sl_cui_uint32_c(0x62dd1ddful), mk_sl_cui_uint32_c(0x15da2d49ul), mk_sl_cui_uint32_c(0x8cd37cf3ul), mk_sl_cui_uint32_c(0xfbd44c65ul),
		mk_sl_cui_uint32_c(0x4db26158ul), mk_sl_cui_uint32_c(0x3ab551ceul), mk_sl_cui_uint32_c(0xa3bc0074ul), mk_sl_cui_uint32_c(0xd4bb30e2ul), mk_sl_cui_uint32_c(0x4adfa541ul), mk_sl_cui_uint32_c(0x3dd895d7ul), mk_sl_cui_uint32_c(0xa4d1c46dul), mk_sl_cui_uint32_c(0xd3d6f4fbul),
		mk_sl_cui_uint32_c(0x4369e96aul), mk_sl_cui_uint32_c(0x346ed9fcul), mk_sl_cui_uint32_c(0xad678846ul), mk_sl_cui_uint32_c(0xda60b8d0ul), mk_sl_cui_uint32_c(0x44042d73ul), mk_sl_cui_uint32_c(0x33031de5ul), mk_sl_cui_uint32_c(0xaa0a4c5ful), mk_sl_cui_uint32_c(0xdd0d7cc9ul),
		mk_sl_cui_uint32_c(0x5005713cul), mk_sl_cui_uint32_c(0x270241aaul), mk_sl_cui_uint32_c(0xbe0b1010ul), mk_sl_cui_uint32_c(0xc90c2086ul), mk_sl_cui_uint32_c(0x5768b525ul), mk_sl_cui_uint32_c(0x206f85b3ul), mk_sl_cui_uint32_c(0xb966d409ul), mk_sl_cui_uint32_c(0xce61e49ful),
		mk_sl_cui_uint32_c(0x5edef90eul), mk_sl_cui_uint32_c(0x29d9c998ul), mk_sl_cui_uint32_c(0xb0d09822ul), mk_sl_cui_uint32_c(0xc7d7a8b4ul), mk_sl_cui_uint32_c(0x59b33d17ul), mk_sl_cui_uint32_c(0x2eb40d81ul), mk_sl_cui_uint32_c(0xb7bd5c3bul), mk_sl_cui_uint32_c(0xc0ba6cadul),
		mk_sl_cui_uint32_c(0xedb88320ul), mk_sl_cui_uint32_c(0x9abfb3b6ul), mk_sl_cui_uint32_c(0x03b6e20cul), mk_sl_cui_uint32_c(0x74b1d29aul), mk_sl_cui_uint32_c(0xead54739ul), mk_sl_cui_uint32_c(0x9dd277aful), mk_sl_cui_uint32_c(0x04db2615ul), mk_sl_cui_uint32_c(0x73dc1683ul),
		mk_sl_cui_uint32_c(0xe3630b12ul), mk_sl_cui_uint32_c(0x94643b84ul), mk_sl_cui_uint32_c(0x0d6d6a3eul), mk_sl_cui_uint32_c(0x7a6a5aa8ul), mk_sl_cui_uint32_c(0xe40ecf0bul), mk_sl_cui_uint32_c(0x9309ff9dul), mk_sl_cui_uint32_c(0x0a00ae27ul), mk_sl_cui_uint32_c(0x7d079eb1ul),
		mk_sl_cui_uint32_c(0xf00f9344ul), mk_sl_cui_uint32_c(0x8708a3d2ul), mk_sl_cui_uint32_c(0x1e01f268ul), mk_sl_cui_uint32_c(0x6906c2feul), mk_sl_cui_uint32_c(0xf762575dul), mk_sl_cui_uint32_c(0x806567cbul), mk_sl_cui_uint32_c(0x196c3671ul), mk_sl_cui_uint32_c(0x6e6b06e7ul),
		mk_sl_cui_uint32_c(0xfed41b76ul), mk_sl_cui_uint32_c(0x89d32be0ul), mk_sl_cui_uint32_c(0x10da7a5aul), mk_sl_cui_uint32_c(0x67dd4accul), mk_sl_cui_uint32_c(0xf9b9df6ful), mk_sl_cui_uint32_c(0x8ebeeff9ul), mk_sl_cui_uint32_c(0x17b7be43ul), mk_sl_cui_uint32_c(0x60b08ed5ul),
		mk_sl_cui_uint32_c(0xd6d6a3e8ul), mk_sl_cui_uint32_c(0xa1d1937eul), mk_sl_cui_uint32_c(0x38d8c2c4ul), mk_sl_cui_uint32_c(0x4fdff252ul), mk_sl_cui_uint32_c(0xd1bb67f1ul), mk_sl_cui_uint32_c(0xa6bc5767ul), mk_sl_cui_uint32_c(0x3fb506ddul), mk_sl_cui_uint32_c(0x48b2364bul),
		mk_sl_cui_uint32_c(0xd80d2bdaul), mk_sl_cui_uint32_c(0xaf0a1b4cul), mk_sl_cui_uint32_c(0x36034af6ul), mk_sl_cui_uint32_c(0x41047a60ul), mk_sl_cui_uint32_c(0xdf60efc3ul), mk_sl_cui_uint32_c(0xa867df55ul), mk_sl_cui_uint32_c(0x316e8eeful), mk_sl_cui_uint32_c(0x4669be79ul),
		mk_sl_cui_uint32_c(0xcb61b38cul), mk_sl_cui_uint32_c(0xbc66831aul), mk_sl_cui_uint32_c(0x256fd2a0ul), mk_sl_cui_uint32_c(0x5268e236ul), mk_sl_cui_uint32_c(0xcc0c7795ul), mk_sl_cui_uint32_c(0xbb0b4703ul), mk_sl_cui_uint32_c(0x220216b9ul), mk_sl_cui_uint32_c(0x5505262ful),
		mk_sl_cui_uint32_c(0xc5ba3bbeul), mk_sl_cui_uint32_c(0xb2bd0b28ul), mk_sl_cui_uint32_c(0x2bb45a92ul), mk_sl_cui_uint32_c(0x5cb36a04ul), mk_sl_cui_uint32_c(0xc2d7ffa7ul), mk_sl_cui_uint32_c(0xb5d0cf31ul), mk_sl_cui_uint32_c(0x2cd99e8bul), mk_sl_cui_uint32_c(0x5bdeae1dul),
		mk_sl_cui_uint32_c(0x9b64c2b0ul), mk_sl_cui_uint32_c(0xec63f226ul), mk_sl_cui_uint32_c(0x756aa39cul), mk_sl_cui_uint32_c(0x026d930aul), mk_sl_cui_uint32_c(0x9c0906a9ul), mk_sl_cui_uint32_c(0xeb0e363ful), mk_sl_cui_uint32_c(0x72076785ul), mk_sl_cui_uint32_c(0x05005713ul),
		mk_sl_cui_uint32_c(0x95bf4a82ul), mk_sl_cui_uint32_c(0xe2b87a14ul), mk_sl_cui_uint32_c(0x7bb12baeul), mk_sl_cui_uint32_c(0x0cb61b38ul), mk_sl_cui_uint32_c(0x92d28e9bul), mk_sl_cui_uint32_c(0xe5d5be0dul), mk_sl_cui_uint32_c(0x7cdcefb7ul), mk_sl_cui_uint32_c(0x0bdbdf21ul),
		mk_sl_cui_uint32_c(0x86d3d2d4ul), mk_sl_cui_uint32_c(0xf1d4e242ul), mk_sl_cui_uint32_c(0x68ddb3f8ul), mk_sl_cui_uint32_c(0x1fda836eul), mk_sl_cui_uint32_c(0x81be16cdul), mk_sl_cui_uint32_c(0xf6b9265bul), mk_sl_cui_uint32_c(0x6fb077e1ul), mk_sl_cui_uint32_c(0x18b74777ul),
		mk_sl_cui_uint32_c(0x88085ae6ul), mk_sl_cui_uint32_c(0xff0f6a70ul), mk_sl_cui_uint32_c(0x66063bcaul), mk_sl_cui_uint32_c(0x11010b5cul), mk_sl_cui_uint32_c(0x8f659efful), mk_sl_cui_uint32_c(0xf862ae69ul), mk_sl_cui_uint32_c(0x616bffd3ul), mk_sl_cui_uint32_c(0x166ccf45ul),
		mk_sl_cui_uint32_c(0xa00ae278ul), mk_sl_cui_uint32_c(0xd70dd2eeul), mk_sl_cui_uint32_c(0x4e048354ul), mk_sl_cui_uint32_c(0x3903b3c2ul), mk_sl_cui_uint32_c(0xa7672661ul), mk_sl_cui_uint32_c(0xd06016f7ul), mk_sl_cui_uint32_c(0x4969474dul), mk_sl_cui_uint32_c(0x3e6e77dbul),
		mk_sl_cui_uint32_c(0xaed16a4aul), mk_sl_cui_uint32_c(0xd9d65adcul), mk_sl_cui_uint32_c(0x40df0b66ul), mk_sl_cui_uint32_c(0x37d83bf0ul), mk_sl_cui_uint32_c(0xa9bcae53ul), mk_sl_cui_uint32_c(0xdebb9ec5ul), mk_sl_cui_uint32_c(0x47b2cf7ful), mk_sl_cui_uint32_c(0x30b5ffe9ul),
		mk_sl_cui_uint32_c(0xbdbdf21cul), mk_sl_cui_uint32_c(0xcabac28aul), mk_sl_cui_uint32_c(0x53b39330ul), mk_sl_cui_uint32_c(0x24b4a3a6ul), mk_sl_cui_uint32_c(0xbad03605ul), mk_sl_cui_uint32_c(0xcdd70693ul), mk_sl_cui_uint32_c(0x54de5729ul), mk_sl_cui_uint32_c(0x23d967bful),
		mk_sl_cui_uint32_c(0xb3667a2eul), mk_sl_cui_uint32_c(0xc4614ab8ul), mk_sl_cui_uint32_c(0x5d681b02ul), mk_sl_cui_uint32_c(0x2a6f2b94ul), mk_sl_cui_uint32_c(0xb40bbe37ul), mk_sl_cui_uint32_c(0xc30c8ea1ul), mk_sl_cui_uint32_c(0x5a05df1bul), mk_sl_cui_uint32_c(0x2d02ef8dul),
	};

	mk_sl_cui_uint32_t state;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_sl_cui_uint8_t bytes[4];
	mk_lang_types_uchar_t idx;

	mk_lang_assert(data);
	mk_lang_assert(len >= 0);
	mk_lang_assert(digest);

	mk_sl_cui_uint32_set_max(&state);
	n = len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_32_to_8_le(&state, &bytes[0]);
		mk_sl_cui_uint8_xor2(&bytes[0], &data[i]);
		mk_sl_cui_uint8_to_bi_uchar(&bytes[0], &idx);
		mk_sl_cui_uint32_shr2(&state, 8);
		mk_sl_cui_uint32_xor2(&state, &table[idx]);
	}
	mk_sl_cui_uint32_not2(&state, digest);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_try_decrypt_header_seq(mk_clib_app_vc_seqid_t const seqid, mk_clib_app_vc_key_material_pct const key_material, mk_clib_app_vc_block_pct const block, mk_clib_app_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept
{
	mk_clib_app_vc_block_pt decrypted;
	mk_clib_app_vc_block_oversized_t decrypted_oversized;
	mk_sl_cui_uint64_t block_idx;
	mk_clib_app_vc_seq_keys_t keys;
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t tu8;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_ushort_t tus;
	mk_sl_cui_uint32_t tu32a;
	mk_sl_cui_uint32_t tu32b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_sl_cui_uint64_t tu64a;
	mk_sl_cui_uint64_t tu64b;
	mk_lang_types_ulong_t tul;
	mk_clib_app_vc_key_material_t master_key_material;
	mk_clib_app_vc_seq_keys_t master_keys;

	mk_lang_assert(seqid >= 0 && seqid < mk_clib_app_vc_seqid_e_dummy);
	mk_lang_assert(key_material);
	mk_lang_assert(block);
	mk_lang_assert(schedules);
	mk_lang_assert(volume_len);

	decrypted = ((mk_clib_app_vc_block_pt)(((((mk_lang_types_uintptr_t)(&decrypted_oversized)) + (sizeof(*decrypted) - 1)) / sizeof(*decrypted)) * sizeof(*decrypted)));
	mk_sl_cui_uint64_set_zero(&block_idx);
	mk_clib_app_vc_keys_init(seqid, key_material, &keys);
	mk_clib_app_vc_seq_expand_dec(seqid, &keys, schedules);
	mk_clib_app_vc_seq_decrypt_block(seqid, schedules, &block_idx, block, decrypted);
	tpc = 'V'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_magic + 0], &tu8)){ return 1; }
	tpc = 'E'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_magic + 1], &tu8)){ return 1; }
	tpc = 'R'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_magic + 2], &tu8)){ return 1; }
	tpc = 'A'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_magic + 3], &tu8)){ return 1; }
	mk_sl_uint_16_from_8_be(&tu16, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_volume_header_format_version]); mk_sl_cui_uint16_to_bi_ushort(&tu16, &tus); mk_lang_check_return(tus == 5);
	mk_sl_uint_16_from_8_be(&tu16, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_minimum_program_version]); mk_sl_cui_uint16_to_bi_ushort(&tu16, &tus); mk_lang_check_return(tus == 0x10b);
	mk_clib_app_crc32(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_keys], mk_clib_app_vc_lens_keys, &tu32a);
	mk_sl_uint_32_from_8_be(&tu32b, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_crc_a]); mk_lang_check_return(mk_sl_cui_uint32_eq(&tu32a, &tu32b));
	n = mk_clib_app_vc_lens_reserved_a;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(mk_sl_cui_uint8_is_zero(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_reserved_a + i]));
	}
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_hidden_volume_size]); mk_lang_check_return(mk_sl_cui_uint64_is_zero(&tu64a)); /* todo hidden volumes not supported, yet */
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_normal_volume_size]); mk_sl_cui_uint64_shl2(&tu64a, 64 - 9); mk_lang_check_return(mk_sl_cui_uint64_is_zero(&tu64a));
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_master_key_scope_start]); tul = mk_clib_app_vc_offsets_volume; mk_sl_cui_uint64_from_bi_ulong(&tu64b, &tul); mk_lang_check_return(mk_sl_cui_uint64_eq(&tu64a, &tu64b));
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_master_key_scope_len]); mk_sl_uint_64_from_8_be(&tu64b, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_normal_volume_size]); mk_lang_check_return(mk_sl_cui_uint64_eq(&tu64a, &tu64b)); *volume_len = tu64a;
	mk_sl_uint_32_from_8_be(&tu32a, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_flags]); mk_lang_check_return(mk_sl_cui_uint32_is_zero(&tu32a)); /* todo only non-system encryption supported */
	mk_sl_uint_32_from_8_be(&tu32a, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_block_len]); mk_sl_cui_uint32_to_bi_ulong(&tu32a, &tul); mk_lang_check_return(tul == mk_clib_app_vc_block_len); /* todo other block lens not supported */
	n = mk_clib_app_vc_lens_reserved_b;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(mk_sl_cui_uint8_is_zero(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_reserved_b + i]));
	}
	mk_clib_app_crc32(&decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_magic], mk_clib_app_vc_offsets_crc_b - mk_clib_app_vc_offsets_magic, &tu32a);
	mk_sl_uint_32_from_8_be(&tu32b, &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_crc_b]); mk_lang_check_return(mk_sl_cui_uint32_eq(&tu32a, &tu32b));
	mk_clib_app_vc_memcpyu8_fn(&master_key_material.m_data.m_uint8s[0], &decrypted->m_data.m_uint8s[mk_clib_app_vc_offsets_keys], mk_lang_countof(master_key_material.m_data.m_uint8s));
	mk_clib_app_vc_keys_init(seqid, &master_key_material, &master_keys);
	mk_clib_app_vc_seq_expand_dec(seqid, &master_keys, schedules);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_try_decrypt_header_kdf(mk_clib_app_vc_kdfid_t const kdfid, mk_lang_types_pchar_pct const password, mk_lang_types_sint_t const password_len, mk_clib_app_vc_salt_pct const salt, mk_lang_types_ulong_t const cost, mk_clib_app_vc_block_pct const block, mk_clib_app_vc_seqid_pt const seqid_out, mk_clib_app_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept
{
	mk_clib_app_vc_key_material_t key_material;
	mk_clib_app_vc_seqid_t seqid;
	mk_lang_types_sint_t ret;

	mk_lang_assert(kdfid >= 0 && kdfid < mk_clib_app_vc_kdfid_e_dummy);
	mk_lang_assert(password && password[0] != '\0');
	mk_lang_assert(password_len >= 1 && password_len <= 4 * 1024);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(block);
	mk_lang_assert(seqid_out);
	mk_lang_assert(schedules);
	mk_lang_assert(volume_len);

	mk_clib_app_vc_derive_keys(kdfid, password, password_len, &salt->m_data.m_uint8s[0], cost, &key_material);
	for(seqid = ((mk_clib_app_vc_seqid_t)(0)); seqid != mk_clib_app_vc_seqid_e_dummy; ++seqid)
	{
		ret = mk_clib_app_try_decrypt_header_seq(seqid, &key_material, block, schedules, volume_len);
		if(ret == 0)
		{
			*seqid_out = seqid;
			break;
		}
	}
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_try_decrypt_header(mk_clib_app_vc_kdfid_t const kdf_hint, mk_lang_types_pchar_pct const password, mk_lang_types_sint_t const password_len, mk_clib_app_vc_salt_pct const salt, mk_lang_types_ulong_t const cost, mk_clib_app_vc_block_pct const block, mk_clib_app_vc_seqid_pt const seqid_out, mk_clib_app_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept
{
	mk_clib_app_vc_kdfid_t kdfid;
	mk_lang_types_sint_t ret;

	mk_lang_assert(kdf_hint >= 0 && kdf_hint <= mk_clib_app_vc_kdfid_e_dummy);
	mk_lang_assert(password && password[0] != '\0');
	mk_lang_assert(password_len >= 1 && password_len <= 4 * 1024);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(block);
	mk_lang_assert(seqid_out);
	mk_lang_assert(schedules);
	mk_lang_assert(volume_len);

	if(kdf_hint == mk_clib_app_vc_kdfid_e_dummy)
	{
		for(kdfid = ((mk_clib_app_vc_kdfid_t)(0)); kdfid != mk_clib_app_vc_kdfid_e_dummy; ++kdfid)
		{
			ret = mk_clib_app_try_decrypt_header_kdf(kdfid, password, password_len, salt, cost, block, seqid_out, schedules, volume_len);
			if(ret == 0)
			{
				break;
			}
		}
	}
	else
	{
		ret = mk_clib_app_try_decrypt_header_kdf(kdf_hint, password, password_len, salt, cost, block, seqid_out, schedules, volume_len);
	}
	return ret;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_chs_from_bytes(mk_sl_cui_uint32_pct const bytes, mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pt const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint32_t blocks;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t tu32a;
	mk_sl_cui_uint32_t tu32b;
	mk_sl_cui_uint32_t cylinders;
	mk_sl_cui_uint32_t heads;
	mk_sl_cui_uint32_t sectors;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint8_t tu8a;
	mk_sl_cui_uint8_t tu8b;

	mk_lang_assert(bytes);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert((mk_sl_cui_uint32_shl3(bytes, 32 - 9, &blocks), mk_sl_cui_uint32_is_zero(&blocks)));
	mk_lang_assert((mk_sl_cui_uint32_shr3(bytes, 9, &blocks), mk_sl_cui_uint32_to_bi_ulong(&blocks, &tul), mk_lang_pow2_is(tul)));

	mk_sl_cui_uint32_shr3(bytes, 9, &blocks);
	tul = 255; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&blocks, &tu32a, &tu32b);
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&tu32b, &tu32a, &cylinders);
	mk_lang_assert((mk_sl_cui_uint32_shr3(&cylinders, 10, &tu32a), mk_sl_cui_uint32_is_zero(&tu32a)));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&cylinders, &tu32a, &tu32b);
	tul = 255; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&tu32b, &tu32a, &tu32b);
	mk_sl_cui_uint32_sub2_wrap_cid_cod(&blocks, &tu32b);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&blocks, &tul), tul < 255 * 63));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&blocks, &tu32a, &heads);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&heads, &tul), tul < 255));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&heads, &tu32a, &tu32b);
	mk_sl_cui_uint32_sub3_wrap_cid_cod(&blocks, &tu32b, &sectors);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&sectors, &tul), tul < 63));
	mk_sl_cui_uint32_inc1(&sectors);
	mk_sl_cui_uint32_to_bi_uchar(&heads, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(a, &tuc);
	mk_sl_cui_uint32_to_bi_uchar(&cylinders, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(c, &tuc);
	mk_sl_cui_uint32_to_bi_uchar(&sectors, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8a, &tuc);
	mk_sl_cui_uint32_shr2(&cylinders, 8);
	mk_sl_cui_uint32_shl2(&cylinders, 6);
	mk_sl_cui_uint32_to_bi_uchar(&cylinders, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8b, &tuc);
	mk_sl_cui_uint8_or3(&tu8a, &tu8b, b);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_mbr_header_generate(mk_clib_app_vc_block_pt const block, mk_sl_cui_uint64_pct const volume_len, mk_sl_cui_uint32_pct const align) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_ulong_t tul;
	mk_lang_types_sint_t ptr;
	mk_sl_cui_uint8_t chs[3];
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tu32;

	mk_lang_assert(block);
	mk_lang_assert(volume_len);
	mk_lang_assert(align);
	mk_lang_assert((mk_sl_cui_uint64_shl3(volume_len, 64 - 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* aligned to whole 512 B blocks */
	mk_lang_assert((mk_sl_cui_uint64_shr3(volume_len, 32 + 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* max 2^32 512 B blocks == 2 TB */
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(align, &tul), mk_lang_pow2_is(tul) && tul <= 64ul * 1024ul * 1024ul)); /* max align in 64 MB */

	ptr = 0;
	mk_clib_app_vc_chs_from_bytes(align, &chs[0], &chs[1], &chs[2]);
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[ptr], &tu8, 446); ptr += 446; /* bootstrap code */
	tuc = 0; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* status or physical drive */
	block->m_data.m_uint8s[ptr++] = chs[0]; /* h */
	block->m_data.m_uint8s[ptr++] = chs[1]; /* cs */
	block->m_data.m_uint8s[ptr++] = chs[2]; /* c */
	tuc = 0x06; /* 0x0e */ mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* partition type */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* h */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* cs */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* c */
	mk_sl_cui_uint32_shr3(align, 9, &tu32); mk_sl_uint_32_to_8_le(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* partition start lba */
	mk_sl_cui_uint64_shr3(volume_len, 9, &tu64); mk_sl_cui_uint64_to_bi_ulong(&tu64, &tul); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_le(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* partition len blocks */
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[ptr], &tu8, mk_clib_app_vc_block_len - ptr - 2); ptr += (mk_clib_app_vc_block_len - ptr - 2);
	tuc = 0x55; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8;
	tuc = 0xaa; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* boot signature */
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_chs(mk_lang_types_ulong_t const blocks, mk_lang_types_ulong_pt const out_c, mk_lang_types_ulong_pt const out_h, mk_lang_types_ulong_pt const out_s) mk_lang_noexcept
{
	mk_lang_types_ulong_t b;
	mk_lang_types_ulong_t s;
	mk_lang_types_ulong_t h;
	mk_lang_types_ulong_t ch;
	mk_lang_types_ulong_t c;

	mk_lang_assert(out_c);
	mk_lang_assert(out_h);
	mk_lang_assert(out_s);
	mk_lang_assert(out_c != out_h);
	mk_lang_assert(out_c != out_s);
	mk_lang_assert(out_h != out_s);

	b = blocks;
	b = mk_lang_min(b, 65535ul * 16ul * 255ul);
	if(b >= 65535ul * 16ul * 63ul)
	{
		s = 255ul;
		h = 16ul;
		ch = b / s;
	}
	else
	{
		s = 17ul;
		ch = b / s;
		h = (ch + 1023ul) / 1024ul;
		h = mk_lang_max(h, 4);
		if(ch >= (h * 1024ul) || h > 16ul)
		{
			s = 31ul;
			h = 16ul;
			ch = b / s;
		}
		if(ch >= (h * 1024ul))
		{
			s = 63ul;
			h = 16ul;
			ch = b / s;
		}
	}
	c = ch / h;
	*out_c = c;
	*out_h = h;
	*out_s = s;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_checksum(mk_clib_app_vc_block_pt const block) mk_lang_noexcept
{
	mk_sl_cui_uint32_t checksum;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tu32;

	mk_lang_assert(block);

	mk_sl_cui_uint32_set_zero(&checksum);
	n = mk_clib_app_vc_block_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&block->m_data.m_uint8s[i], &tuc);
		mk_sl_cui_uint32_from_bi_uchar(&tu32, &tuc);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&checksum, &tu32);
	}
	mk_sl_cui_uint32_not1(&checksum);
	mk_sl_uint_32_to_8_be(&checksum, &block->m_data.m_uint8s[64]);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_generate(mk_clib_app_vc_block_pt const block, mk_sl_cui_uint64_pct const disk_len) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_ulong_t blocks;
	mk_lang_types_ulong_t c;
	mk_lang_types_ulong_t h;
	mk_lang_types_ulong_t s;
	mk_lang_types_sint_t ptr;
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_ushort_t tus;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(block);
	mk_lang_assert(disk_len);
	mk_lang_assert((mk_sl_cui_uint64_shl3(disk_len, 64 - 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* aligned to whole 512 B blocks */
	mk_lang_assert((mk_sl_cui_uint64_shr3(disk_len, 9 + 32, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* max 2^32 512 B blocks == 2 TB */

	mk_sl_cui_uint64_shr3(disk_len, 9, &tu64);
	mk_sl_cui_uint64_to_bi_ulong(&tu64, &blocks);
	mk_clib_app_vc_vhd_footer_chs(blocks, &c, &h, &s);
	ptr = 0;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'o'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'n'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'e'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 't'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'i'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'x'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* cookie */
	tul = 0x2ul; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* features */
	tul = ((1ul & 0xfffful) << 16) | ((0ul & 0xfffful) << 0); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* file format version */
	mk_sl_cui_uint64_set_max(&tu64); mk_sl_uint_64_to_8_be(&tu64, &block->m_data.m_uint8s[ptr]); ptr += 8; /* data offset */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* time stamp */
	tpc = 'v'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'p'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = ' '; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* creator application */
	tul = ((1ul & 0xfffful) << 16) | ((0ul & 0xfffful) << 0); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* creator version */
	tpc = 'W'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'i'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = '2'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'k'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* creator host OS */
	mk_sl_uint_64_to_8_be(disk_len, &block->m_data.m_uint8s[ptr]); ptr += 8; /* original size */
	mk_sl_uint_64_to_8_be(disk_len, &block->m_data.m_uint8s[ptr]); ptr += 8; /* current size */
	tus = ((mk_lang_types_ushort_t)(c)); mk_sl_cui_uint16_from_bi_ushort(&tu16, &tus); mk_sl_uint_16_to_8_be(&tu16, &block->m_data.m_uint8s[ptr]); ptr += 2; /* cylinders */
	tuc = ((mk_lang_types_uchar_t)(h)); mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* heads */
	tuc = ((mk_lang_types_uchar_t)(s)); mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* sectors */ /* disk geometry */
	tul = 0x2ul; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* disk type */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* checksum */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* unique id */
	tuc = 0; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* saved state */
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[ptr], &tu8, mk_clib_app_vc_block_len - ptr); /* reserved */
	mk_clib_app_vc_vhd_footer_checksum(block);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_write_vhd(mk_sl_io_reader_file_portable_pt const reader, mk_clib_app_vc_seqid_t const seqid, mk_clib_app_vc_seq_schedules_pct const schedules, mk_sl_cui_uint64_pt const block_id, mk_sl_cui_uint64_pct const max_block_id, mk_sl_cui_uint64_pct const volume_len, mk_clib_app_vc_block_pt const block, mk_lang_types_pchar_pct const str_output) mk_lang_noexcept
{
	mk_sl_io_writer_file_portable_t writer;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t align;
	mk_lang_types_usize_t written;
	mk_sl_cui_uint8_t tu8;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_ulong_t n;
	mk_lang_types_ulong_t i;
	mk_lang_types_usize_t read;
	mk_sl_cui_uint64_t tu64;
	mk_sl_cui_uint64_t disk_len;

	mk_lang_assert(reader);
	mk_lang_assert(seqid >= 0 && seqid < mk_clib_app_vc_seqid_e_dummy);
	mk_lang_assert(schedules);
	mk_lang_assert(block_id);
	mk_lang_assert(max_block_id);
	mk_lang_assert(volume_len);
	mk_lang_assert(block);
	mk_lang_assert(str_output);

	mk_sl_io_writer_file_portable_open_n(&writer, str_output, &err); mk_lang_check_rereturn(err);
	do
	{
		tul = 1ul * 1024ul * 1024ul; mk_sl_cui_uint32_from_bi_ulong(&align, &tul);
		mk_clib_app_vc_mbr_header_generate(block, volume_len, &align);
		mk_sl_io_writer_file_portable_write(&writer, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written, &err);
		mk_lang_check_rebreak(err);
		err = mk_lang_check_line;
		mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s));
		err = 0;
		mk_sl_cui_uint8_set_zero(&tu8);
		mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[0], &tu8, mk_clib_app_vc_block_len);
		mk_sl_cui_uint32_shr3(&align, 9, &tu32);
		mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
		n = tul - 1;
		for(i = 0; i != n; ++i)
		{
			mk_sl_io_writer_file_portable_write(&writer, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written, &err);
			mk_lang_check_rebreak(err);
			err = mk_lang_check_line;
			mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s));
			err = 0;
		}
		mk_lang_check_rebreak(err);
		for(; mk_sl_cui_uint64_ne(block_id, max_block_id); mk_sl_cui_uint64_inc1(block_id))
		{
			mk_sl_io_reader_file_portable_read(reader, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &read, &err);
			mk_lang_check_rebreak(err);
			err = mk_lang_check_line;
			mk_lang_check_break(read == mk_lang_countof(block->m_data.m_uint8s));
			err = 0;
			mk_clib_app_vc_seq_decrypt_block(seqid, schedules, block_id, block, block);
			mk_sl_io_writer_file_portable_write(&writer, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written, &err);
			mk_lang_check_rebreak(err);
			err = mk_lang_check_line;
			mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s));
			err = 0;
		}
		mk_lang_check_rebreak(err);
		mk_sl_cui_uint32_to_bi_ulong(&align, &tul);
		mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul);
		mk_sl_cui_uint64_add3_wrap_cid_cod(volume_len, &tu64, &disk_len);
		mk_clib_app_vc_vhd_footer_generate(block, &disk_len);
		mk_sl_io_writer_file_portable_write(&writer, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written, &err);
		mk_lang_check_rebreak(err);
		err = mk_lang_check_line;
		mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s));
		err = 0;
	}while(mk_lang_false);
	mk_sl_io_writer_file_portable_close(&writer);
	mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_work(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_pchar_pct str_input;
	mk_lang_types_pchar_pct str_password;
	mk_lang_types_pchar_pct str_pim;
	mk_lang_types_pchar_pct str_output;
	mk_lang_types_sint_t password_len;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t cost;
	mk_clib_app_vc_block_pt block;
	mk_clib_app_vc_block_oversized2_t block_oversized;
	mk_sl_io_reader_file_portable_t reader;
	mk_lang_types_usize_t read;
	mk_clib_app_vc_salt_pt salt;
	mk_clib_app_vc_seqid_t seqid;
	mk_clib_app_vc_seq_schedules_t schedules;
	mk_sl_cui_uint64_t volume_len;
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint64_t block_id;
	mk_sl_cui_uint64_t max_block_id;

	mk_lang_check_return(argc == 5);
	str_input = argv[1];
	str_password = argv[2];
	str_pim = argv[3];
	str_output = argv[4];
	password_len = mk_clib_app_vc_strlen(str_password);
	err = mk_clib_app_vc_parse_cost(str_pim, &cost); mk_lang_check_rereturn(err);
	block = ((mk_clib_app_vc_block_pt)(((((mk_lang_types_uintptr_t)(&block_oversized)) + (sizeof(*block) - 1)) / sizeof(*block)) * sizeof(*block)));
	mk_sl_io_reader_file_portable_open_n(&reader, str_input, &err); mk_lang_check_rereturn(err);
	do
	{
		mk_sl_io_reader_file_portable_read(&reader, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &read, &err); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(read == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
		salt = ((mk_clib_app_vc_salt_pt)(block));
		block = ((mk_clib_app_vc_block_pt)(((mk_lang_types_uintptr_t)(block)) + mk_clib_app_vc_salt_len));
		err = mk_clib_app_try_decrypt_header(mk_clib_app_vc_kdfid_e_dummy, str_password, password_len, salt, cost, block, &seqid, &schedules, &volume_len); mk_lang_check_rebreak(err);
		block = ((mk_clib_app_vc_block_pt)(((mk_lang_types_uintptr_t)(block)) - mk_clib_app_vc_salt_len));
		mk_sl_io_reader_file_portable_seek_rel(&reader, mk_clib_app_vc_offsets_volume - mk_clib_app_vc_block_len, &err); mk_lang_check_rebreak(err);
		tsi = mk_clib_app_vc_offsets_volume / mk_clib_app_vc_block_len; mk_sl_cui_uint64_from_bi_sint(&block_id, &tsi);
		mk_sl_cui_uint64_shr3(&volume_len, 9, &max_block_id); mk_sl_cui_uint64_add2_wrap_cid_cod(&max_block_id, &block_id);
		err = mk_clib_app_vc_arg_write_vhd(&reader, seqid, &schedules, &block_id, &max_block_id, &volume_len, block, str_output); mk_lang_check_rebreak(err);
	}while(mk_lang_false);
	mk_sl_io_reader_file_portable_close(&reader);
	mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_readme(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_pchar_pct exe_name;
	mk_lang_types_sint_t tsi;

	((mk_lang_types_void_t)(argc));

	exe_name = mk_lang_exe_name_get(argv[0]);
	tsi = printf("Example usage: %s <input_file> <password> <pim> <output_file>\n", exe_name); mk_lang_check_return(tsi > 0);
	return 0;
}


mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_vc_arg(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_check_return(argc >= 1);
	mk_lang_check_return(argv);
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(argv[i]);
		mk_lang_check_return(argv[i][0] != '\0');
	}
	if(argc == 1)
	{
		err = mk_clib_app_vc_arg_readme(argc, argv);
		mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_cpuid_init();
		err = mk_clib_app_vc_arg_work(argc, argv);
		mk_lang_check_rereturn(err);
	}
	return 0;
}
