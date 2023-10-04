#include "mk_lib_vc.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_sl_serialization.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_null.h"
#include "mk_lang_min.h"
#include "mk_lang_alignof.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"
#include "mk_sl_uint.h"

#define mk_lang_memcpy_obj_tn mk_lib_vc_u8
#define mk_lang_memcpy_obj_t mk_sl_cui_uint8_t
#include "mk_lang_memcpy_obj_inl_fileh.h"
#include "mk_lang_memcpy_obj_inl_filec.h"

#define mk_lib_crypto_mode_base_t_name mk_lib_vc
#define mk_lib_crypto_mode_base_t_len 16
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"

#define mk_lang_bui_name mk_lib_vc_uint
#define mk_lang_bui_type mk_lang_types_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_name mk_lib_vc_uint
#define mk_sl_cui_base_type mk_lang_types_uint_t
#define mk_sl_cui_base_name mk_lang_bui_mk_lib_vc_uint
#define mk_sl_cui_base_bits mk_lang_sizeof_bi_uint_t
#define mk_sl_cui_count 1
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_lang_bui_name mk_lib_vc_usize
#define mk_lang_bui_type mk_lang_types_usize_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_size_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_name mk_lib_vc_usize
#define mk_sl_cui_base_type mk_lang_types_usize_t
#define mk_sl_cui_base_name mk_lang_bui_mk_lib_vc_usize
#define mk_sl_cui_base_bits mk_lang_sizeof_bi_size_t
#define mk_sl_cui_count 1
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn usize
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"


#define mk_lib_vc_threads_want (mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14)
#if mk_lib_vc_threads_want

#define mk_sl_ring_t_name mk_lib_vc
#define mk_sl_ring_t_elem_t mk_lib_vc_chunk_info_t
#define mk_sl_ring_t_capacity mk_lib_vc_chunk_count
#include "mk_sl_ring_inl_fileh.h"
#include "mk_sl_ring_inl_filec.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <thread>

#endif

#if mk_lang_version_at_least_cpp_20

#include <bit>

#endif


#define mk_lib_vc_min_align 16
#define mk_lib_vc_block_len 512

#define mk_lib_vc_salt_len                64
#define mk_lib_vc_magic_len                4
#define mk_lib_vc_ver_len                  2
#define mk_lib_vc_min_ver_maj_len          1
#define mk_lib_vc_min_ver_min_len          1
#define mk_lib_vc_crc1_len                 4
#define mk_lib_vc_reserved1_len           16
#define mk_lib_vc_size_hidden_volume_len   8
#define mk_lib_vc_size_volume_len          8
#define mk_lib_vc_master_key_scope1_len    8
#define mk_lib_vc_master_key_scope2_len    8
#define mk_lib_vc_flags_len                4
#define mk_lib_vc_sector_size_len          4
#define mk_lib_vc_reserved2_len          120
#define mk_lib_vc_crc2_len                 4
#define mk_lib_vc_master_keys_len        192 /* variable, max len is 3 ciphers, xts, 256bit, thus 3*2*(256/8)==192 */

#define mk_lib_vc_salt_offset               0
#define mk_lib_vc_magic_offset              (mk_lib_vc_salt_offset               + mk_lib_vc_salt_len              )
#define mk_lib_vc_ver_offset                (mk_lib_vc_magic_offset              + mk_lib_vc_magic_len             )
#define mk_lib_vc_min_ver_maj_offset        (mk_lib_vc_ver_offset                + mk_lib_vc_ver_len               )
#define mk_lib_vc_min_ver_min_offset        (mk_lib_vc_min_ver_maj_offset        + mk_lib_vc_min_ver_maj_len       )
#define mk_lib_vc_crc1_offset               (mk_lib_vc_min_ver_min_offset        + mk_lib_vc_min_ver_min_len       )
#define mk_lib_vc_reserved1_offset          (mk_lib_vc_crc1_offset               + mk_lib_vc_crc1_len              )
#define mk_lib_vc_size_hidden_volume_offset (mk_lib_vc_reserved1_offset          + mk_lib_vc_reserved1_len         )
#define mk_lib_vc_size_volume_offset        (mk_lib_vc_size_hidden_volume_offset + mk_lib_vc_size_hidden_volume_len)
#define mk_lib_vc_master_key_scope1_offset  (mk_lib_vc_size_volume_offset        + mk_lib_vc_size_volume_len       )
#define mk_lib_vc_master_key_scope2_offset  (mk_lib_vc_master_key_scope1_offset  + mk_lib_vc_master_key_scope1_len )
#define mk_lib_vc_flags_offset              (mk_lib_vc_master_key_scope2_offset  + mk_lib_vc_master_key_scope2_len )
#define mk_lib_vc_sector_size_offset        (mk_lib_vc_flags_offset              + mk_lib_vc_flags_len             )
#define mk_lib_vc_reserved2_offset          (mk_lib_vc_sector_size_offset        + mk_lib_vc_sector_size_len       )
#define mk_lib_vc_crc2_offset               (mk_lib_vc_reserved2_offset          + mk_lib_vc_reserved2_len         )
#define mk_lib_vc_master_keys_offset        (mk_lib_vc_crc2_offset               + mk_lib_vc_crc2_len              )
#define mk_lib_vc_data_offset               (128 * 1024)


/*enum mk_lib_vc_pbkdf_id_e
{
	mk_lib_vc_pbkdf_id_e_sha512,
	mk_lib_vc_pbkdf_id_e_sha256,
	mk_lib_vc_pbkdf_id_e_dummy_end
};
typedef enum mk_lib_vc_pbkdf_id_e mk_lib_vc_pbkdf_id_t;

enum mk_lib_vc_alg_id_e
{
	mk_lib_vc_alg_id_e_aes,
	mk_lib_vc_alg_id_e_serpent,
	mk_lib_vc_alg_id_e_dummy_end
};
typedef enum mk_lib_vc_alg_id_e mk_lib_vc_alg_id_t;

#define mk_lib_vc_alg_msg_len mk_lang_max(mk_lib_crypto_alg_aes_256_msg_len_m, mk_lib_crypto_alg_serpent_msg_len_m)
union mk_lib_vc_alg_msg_t_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_alg_msg_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aes;
	mk_lib_crypto_alg_serpent_msg_t m_serpent;
};
typedef union mk_lib_vc_alg_msg_t_u mk_lib_vc_alg_msg_t_t;
typedef mk_lib_vc_alg_msg_t_t const mk_lib_vc_alg_msg_t_ct;
typedef mk_lib_vc_alg_msg_t_t* mk_lib_vc_alg_msg_t_pt;
typedef mk_lib_vc_alg_msg_t_t const* mk_lib_vc_alg_msg_t_pct;

union mk_lib_vc_alg_msg_pt_u
{
	mk_lib_crypto_alg_aes_256_msg_pt m_aes;
	mk_lib_crypto_alg_serpent_msg_pt m_serpent;
};
typedef union mk_lib_vc_alg_msg_pt_u mk_lib_vc_alg_msg_pt_t;
typedef mk_lib_vc_alg_msg_pt_t const mk_lib_vc_alg_msg_pt_ct;
typedef mk_lib_vc_alg_msg_pt_t* mk_lib_vc_alg_msg_pt_pt;
typedef mk_lib_vc_alg_msg_pt_t const* mk_lib_vc_alg_msg_pt_pct;

union mk_lib_vc_alg_msg_pct_u
{
	mk_lib_crypto_alg_aes_256_msg_pct m_aes;
	mk_lib_crypto_alg_serpent_msg_pct m_serpent;
};
typedef union mk_lib_vc_alg_msg_pct_u mk_lib_vc_alg_msg_pct_t;
typedef mk_lib_vc_alg_msg_pct_t const mk_lib_vc_alg_msg_pct_ct;
typedef mk_lib_vc_alg_msg_pct_t* mk_lib_vc_alg_msg_pct_pt;
typedef mk_lib_vc_alg_msg_pct_t const* mk_lib_vc_alg_msg_pct_pct;

#define mk_lib_vc_seq_msg_aes_serpent_len mk_lang_max(mk_lib_crypto_alg_aes_256_msg_len_m, mk_lib_crypto_alg_serpent_msg_len_m)
union mk_lib_vc_seq_msg_aes_serpent_u
{
	mk_lib_crypto_alg_aes_256_msg_t m_aes;
	mk_lib_crypto_alg_serpent_msg_t m_serpent;
};
typedef union mk_lib_vc_seq_msg_aes_serpent_u mk_lib_vc_seq_msg_aes_serpent_t;
typedef mk_lib_vc_seq_msg_aes_serpent_t const mk_lib_vc_seq_msg_aes_serpent_ct;
typedef mk_lib_vc_seq_msg_aes_serpent_t* mk_lib_vc_seq_msg_aes_serpent_pt;
typedef mk_lib_vc_seq_msg_aes_serpent_t const* mk_lib_vc_seq_msg_aes_serpent_pct;

#define mk_lib_vc_seq_msg_len mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_msg_len_m, mk_lib_crypto_alg_serpent_msg_len_m), mk_lib_vc_seq_msg_aes_serpent_len)
union mk_lib_vc_seq_msg_t_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_seq_msg_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aes;
	mk_lib_crypto_alg_serpent_msg_t m_serpent;
	mk_lib_vc_seq_msg_aes_serpent_t m_aes_serpent;
};
typedef union mk_lib_vc_seq_msg_t_u mk_lib_vc_seq_msg_t_t;
typedef mk_lib_vc_seq_msg_t_t const mk_lib_vc_seq_msg_t_ct;
typedef mk_lib_vc_seq_msg_t_t* mk_lib_vc_seq_msg_t_pt;
typedef mk_lib_vc_seq_msg_t_t const* mk_lib_vc_seq_msg_t_pct;

union mk_lib_vc_seq_msg_pt_u
{
	mk_lib_crypto_alg_aes_256_msg_pt m_aes;
	mk_lib_crypto_alg_serpent_msg_pt m_serpent;
	mk_lib_vc_seq_msg_aes_serpent_pt m_aes_serpent;
};
typedef union mk_lib_vc_seq_msg_pt_u mk_lib_vc_seq_msg_pt_t;
typedef mk_lib_vc_seq_msg_pt_t const mk_lib_vc_seq_msg_pt_ct;
typedef mk_lib_vc_seq_msg_pt_t* mk_lib_vc_seq_msg_pt_pt;
typedef mk_lib_vc_seq_msg_pt_t const* mk_lib_vc_seq_msg_pt_pct;

union mk_lib_vc_seq_msg_pct_u
{
	mk_lib_crypto_alg_aes_256_msg_pct m_aes;
	mk_lib_crypto_alg_serpent_msg_pct m_serpent;
	mk_lib_vc_seq_msg_aes_serpent_pct m_aes_serpent;
};
typedef union mk_lib_vc_seq_msg_pct_u mk_lib_vc_seq_msg_pct_t;
typedef mk_lib_vc_seq_msg_pct_t const mk_lib_vc_seq_msg_pct_ct;
typedef mk_lib_vc_seq_msg_pct_t* mk_lib_vc_seq_msg_pct_pt;
typedef mk_lib_vc_seq_msg_pct_t const* mk_lib_vc_seq_msg_pct_pct;

union mk_lib_vc_block_aligned_u
{
	mk_lang_alignas(mk_lib_vc_alg_msg_len) mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_block_len];
	mk_lib_vc_alg_msg_t_t m_alg_msgs[mk_lib_vc_block_len / mk_lib_vc_alg_msg_len];
	mk_lib_vc_seq_msg_t_t m_seq_msgs[mk_lib_vc_block_len / mk_lib_vc_seq_msg_len];
};
typedef union mk_lib_vc_block_aligned_u mk_lib_vc_block_aligned_t;

struct mk_lib_vc_block_s
{
	mk_lib_vc_block_aligned_t m_data;
};
typedef struct mk_lib_vc_block_s mk_lib_vc_block_t;
typedef mk_lib_vc_block_t const mk_lib_vc_block_ct;
typedef mk_lib_vc_block_t* mk_lib_vc_block_pt;
typedef mk_lib_vc_block_t const* mk_lib_vc_block_pct;


mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_msg_xor_2(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_msg_t_pt const a, mk_lib_vc_alg_msg_t_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_lib_crypto_mode_base_mk_lib_vc_xor2(&a->m_aes    .m_data.m_uint8s[0], &b->m_aes    .m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_serpent: mk_lib_crypto_mode_base_mk_lib_vc_xor2(&a->m_serpent.m_data.m_uint8s[0], &b->m_serpent.m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_msg_xor_3(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_msg_t_pct const a, mk_lib_vc_alg_msg_t_pct const b, mk_lib_vc_alg_msg_t_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_lib_crypto_mode_base_mk_lib_vc_xor3(&a->m_aes    .m_data.m_uint8s[0], &b->m_aes    .m_data.m_uint8s[0], &c->m_aes    .m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_serpent: mk_lib_crypto_mode_base_mk_lib_vc_xor3(&a->m_serpent.m_data.m_uint8s[0], &b->m_serpent.m_data.m_uint8s[0], &c->m_serpent.m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_expand_enc(mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_key_t_pct const key, mk_lib_vc_seq_schedule_t_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes        : mk_lib_crypto_alg_aes_256_expand_enc(&key->m_aes,               &schedule->m_aes              ); break;
		case mk_lib_vc_seq_id_e_serpent    : mk_lib_crypto_alg_serpent_expand_enc(&key->m_serpent,           &schedule->m_serpent          ); break;
		case mk_lib_vc_seq_id_e_aes_serpent: mk_lib_crypto_alg_aes_256_expand_enc(&key->m_aes_serpent.m_aes, &schedule->m_aes_serpent.m_aes); mk_lib_crypto_alg_serpent_expand_enc(&key->m_aes_serpent.m_serpent, &schedule->m_aes_serpent.m_serpent); break;
		case mk_lib_vc_seq_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_expand_dec(mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_key_t_pct const key, mk_lib_vc_seq_schedule_t_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes        : mk_lib_crypto_alg_aes_256_expand_dec(&key->m_aes,               &schedule->m_aes              ); break;
		case mk_lib_vc_seq_id_e_serpent    : mk_lib_crypto_alg_serpent_expand_dec(&key->m_serpent,           &schedule->m_serpent          ); break;
		case mk_lib_vc_seq_id_e_aes_serpent: mk_lib_crypto_alg_aes_256_expand_dec(&key->m_aes_serpent.m_aes, &schedule->m_aes_serpent.m_aes); mk_lib_crypto_alg_serpent_expand_dec(&key->m_aes_serpent.m_serpent, &schedule->m_aes_serpent.m_serpent); break;
		case mk_lib_vc_seq_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_key_init(mk_lib_vc_seq_id_t const seq_id, mk_sl_cui_uint8_pct const keys_data, int const idx, mk_lib_vc_seq_key_t_pt const key) mk_lang_noexcept
{
	mk_lang_assert(keys_data);
	mk_lang_assert(idx >= 0 && idx <= 1);
	mk_lang_assert(key);

	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes        : mk_lang_memcpy_obj_mk_lib_vc_u8(&key->m_aes.m_data.m_uint8s[0],               &keys_data[idx * (mk_lib_crypto_alg_aes_256_key_len_v)],                                       mk_lib_crypto_alg_aes_256_key_len_v); break;
		case mk_lib_vc_seq_id_e_serpent    : mk_lang_memcpy_obj_mk_lib_vc_u8(&key->m_serpent.m_data.m_uint8s[0],           &keys_data[idx * (mk_lib_crypto_alg_serpent_key_len_v)],                                       mk_lib_crypto_alg_serpent_key_len_v); break;
		case mk_lib_vc_seq_id_e_aes_serpent: mk_lang_memcpy_obj_mk_lib_vc_u8(&key->m_aes_serpent.m_aes.m_data.m_uint8s[0], &keys_data[idx * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v); mk_lang_memcpy_obj_mk_lib_vc_u8(&key->m_aes_serpent.m_serpent.m_data.m_uint8s[0], &keys_data[idx * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v) + mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_serpent_key_len_v); break;
		case mk_lib_vc_seq_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_schedule_encrypt(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_schedule_pct_t const schedule, mk_lib_vc_alg_msg_t_pct const input, mk_lib_vc_alg_msg_t_pt const output) mk_lang_noexcept
{
	mk_lang_assert(input);
	mk_lang_assert(output);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_lang_assert(schedule.m_aes    ); mk_lib_crypto_alg_aes_256_schedule_encrypt(schedule.m_aes    , &input->m_aes    , &output->m_aes    ); break;
		case mk_lib_vc_alg_id_e_serpent: mk_lang_assert(schedule.m_serpent); mk_lib_crypto_alg_serpent_schedule_encrypt(schedule.m_serpent, &input->m_serpent, &output->m_serpent); break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_schedule_decrypt(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_schedule_pct_t const schedule, mk_lib_vc_alg_msg_t_pct const input, mk_lib_vc_alg_msg_t_pt const output) mk_lang_noexcept
{
	mk_lang_assert(input);
	mk_lang_assert(output);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_lang_assert(schedule.m_aes    ); mk_lib_crypto_alg_aes_256_schedule_decrypt(schedule.m_aes    , &input->m_aes    , &output->m_aes    ); break;
		case mk_lib_vc_alg_id_e_serpent: mk_lang_assert(schedule.m_serpent); mk_lib_crypto_alg_serpent_schedule_decrypt(schedule.m_serpent, &input->m_serpent, &output->m_serpent); break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_to_msgs_restrict(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_crypto_alg_aes_256_msg_len_v == 0);
	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_crypto_alg_serpent_msg_len_v == 0);

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_alg_msgs[i / mk_lib_crypto_alg_aes_256_msg_len_v].m_aes    .m_data.m_uint8s[i % mk_lib_crypto_alg_aes_256_msg_len_v] = input->m_data.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_alg_msgs[i / mk_lib_crypto_alg_serpent_msg_len_v].m_serpent.m_data.m_uint8s[i % mk_lib_crypto_alg_serpent_msg_len_v] = input->m_data.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_to_msgs_alias(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_block_t t mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input == output);

	t = *input;
	mk_lib_vc_alg_block_to_msgs_restrict(alg_id, &t, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_to_msgs(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lang_assert(input);
	mk_lang_assert(output);

	if(output != input)
	{
		mk_lib_vc_alg_block_to_msgs_restrict(alg_id, input, output);
	}
	else
	{
		mk_lib_vc_alg_block_to_msgs_alias(alg_id, input, output);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_from_msgs_restrict(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_crypto_alg_aes_256_msg_len_v == 0);
	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_crypto_alg_serpent_msg_len_v == 0);

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input != output);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_uint8s[i] = input->m_data.m_alg_msgs[i / mk_lib_crypto_alg_aes_256_msg_len_v].m_aes    .m_data.m_uint8s[i % mk_lib_crypto_alg_aes_256_msg_len_v]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_uint8s[i] = input->m_data.m_alg_msgs[i / mk_lib_crypto_alg_serpent_msg_len_v].m_serpent.m_data.m_uint8s[i % mk_lib_crypto_alg_serpent_msg_len_v]; } break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_from_msgs_alias(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_block_t t mk_lang_constexpr_init;

	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(input == output);

	t = *input;
	mk_lib_vc_alg_block_from_msgs_restrict(alg_id, &t, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_from_msgs(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lang_assert(input);
	mk_lang_assert(output);

	if(output != input)
	{
		mk_lib_vc_alg_block_from_msgs_restrict(alg_id, input, output);
	}
	else
	{
		mk_lib_vc_alg_block_from_msgs_alias(alg_id, input, output);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_idx_to_tweak(mk_lib_vc_alg_id_t const alg_id, mk_sl_cui_uint64_pct const block_idx, mk_lib_vc_alg_msg_t_pt const tweak) mk_lang_noexcept
{
	mk_sl_cui_uint64_t u64sle[2] mk_lang_constexpr_init;
	mk_sl_cui_uint128_t u128 mk_lang_constexpr_init;

	mk_lang_assert(block_idx);
	mk_lang_assert(tweak);

	u64sle[0] = *block_idx;
	mk_sl_cui_uint64_set_zero(&u64sle[1]);
	mk_sl_uint_128_from_64_le(&u128, &u64sle[0]);
	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_sl_uint_128_to_8_le(&u128, &tweak->m_aes    .m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_serpent: mk_sl_uint_128_to_8_le(&u128, &tweak->m_serpent.m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_xts_tweak_shift(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_msg_t_pt const tweak) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint8_t const s_carry = mk_sl_cui_uint8_c(0x87);

	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_vc_alg_msg_t_t tmsg mk_lang_constexpr_init;
	mk_sl_cui_uint8_t carry_a mk_lang_constexpr_init;
	mk_sl_cui_uint8_t carry_b mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_vc_alg_msg_len == mk_lib_crypto_alg_aes_256_msg_len_v);
	mk_lang_static_assert(mk_lib_vc_alg_msg_len == mk_lib_crypto_alg_serpent_msg_len_v);
	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_v == 128 / mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_v == 128 / mk_lang_charbit);

	mk_lang_assert(tweak);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ tmsg.m_uint8s[i] = tweak->m_aes    .m_data.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ tmsg.m_uint8s[i] = tweak->m_serpent.m_data.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
	mk_sl_cui_uint8_set_zero(&carry_a);
	for(i = 0; i != mk_lib_vc_alg_msg_len; ++i)
	{
		mk_sl_cui_uint8_shr3(&tmsg.m_uint8s[i], 7, &carry_b);
		mk_sl_cui_uint8_shl2(&tmsg.m_uint8s[i], 1);
		mk_sl_cui_uint8_or2(&tmsg.m_uint8s[i], &carry_a);
		carry_a = carry_b;
	}
	if(!mk_sl_cui_uint8_is_zero(&carry_b))
	{
		carry_b = s_carry;
		mk_sl_cui_uint8_xor2(&tmsg.m_uint8s[0], &carry_b);
	}
	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ tweak->m_aes    .m_data.m_uint8s[i] = tmsg.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ tweak->m_serpent.m_data.m_uint8s[i] = tmsg.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_xts_decrypt_block(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_schedule_pct_t const schedulea, mk_lib_vc_alg_schedule_pct_t const scheduleb, mk_sl_cui_uint64_pct const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_alg_msg_t_t tweak mk_lang_constexpr_init;
	mk_lib_vc_alg_msg_t_pt msg mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_m == mk_lib_vc_alg_msg_len);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_m == mk_lib_vc_alg_msg_len);
	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_vc_alg_msg_len == 0);

	mk_lang_assert(block_idx);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_vc_alg_block_to_msgs(alg_id, input, output);
	mk_lib_vc_alg_block_idx_to_tweak(alg_id, block_idx, &tweak);
	mk_lib_vc_alg_schedule_encrypt(alg_id, scheduleb, &tweak, &tweak);
	for(i = 0; i != mk_lib_vc_block_len / mk_lib_vc_alg_msg_len; ++i)
	{
		msg = &output->m_data.m_alg_msgs[i];
		mk_lib_vc_alg_msg_xor_2(alg_id, msg, &tweak);
		mk_lib_vc_alg_schedule_decrypt(alg_id, schedulea, msg, msg);
		mk_lib_vc_alg_msg_xor_2(alg_id, msg, &tweak);
		mk_lib_vc_alg_xts_tweak_shift(alg_id, &tweak);
	}
	mk_lib_vc_alg_block_from_msgs(alg_id, output, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block_aes(mk_lib_vc_seq_schedule_pct_t const schedulea, mk_lib_vc_seq_schedule_pct_t const scheduleb, mk_sl_cui_uint64_pct const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_alg_id_t alg_id mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t scha mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t schb mk_lang_constexpr_init;

	alg_id = mk_lib_vc_alg_id_e_aes;
	scha.m_aes = schedulea.m_aes;
	schb.m_aes = scheduleb.m_aes;
	mk_lib_vc_alg_xts_decrypt_block(alg_id, scha, schb, block_idx, input, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block_serpent(mk_lib_vc_seq_schedule_pct_t const schedulea, mk_lib_vc_seq_schedule_pct_t const scheduleb, mk_sl_cui_uint64_pct const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_alg_id_t alg_id mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t scha mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t schb mk_lang_constexpr_init;

	alg_id = mk_lib_vc_alg_id_e_serpent;
	scha.m_serpent = schedulea.m_serpent;
	schb.m_serpent = scheduleb.m_serpent;
	mk_lib_vc_alg_xts_decrypt_block(alg_id, scha, schb, block_idx, input, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block_aes_serpent(mk_lib_vc_seq_schedule_pct_t const schedulea, mk_lib_vc_seq_schedule_pct_t const scheduleb, mk_sl_cui_uint64_pct const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_seq_schedule_pct_t schas mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_pct_t schbs mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_pct_t schaa mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_pct_t schba mk_lang_constexpr_init;

	schas.m_serpent = &schedulea.m_aes_serpent->m_serpent;
	schbs.m_serpent = &scheduleb.m_aes_serpent->m_serpent;
	schaa.m_aes     = &schedulea.m_aes_serpent->m_aes    ;
	schba.m_aes     = &scheduleb.m_aes_serpent->m_aes    ;
	mk_lib_vc_seq_xts_decrypt_block_serpent(schas, schbs, block_idx, input , output);
	mk_lib_vc_seq_xts_decrypt_block_aes    (schaa, schba, block_idx, output, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block(mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_schedule_t_pct const schedulea, mk_lib_vc_seq_schedule_t_pct const scheduleb, mk_sl_cui_uint64_pct const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_seq_schedule_pct_t scha mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_pct_t schb mk_lang_constexpr_init;

	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes        : scha.m_aes         = &schedulea->m_aes        ; schb.m_aes         = &scheduleb->m_aes        ; mk_lib_vc_seq_xts_decrypt_block_aes        (scha, schb, block_idx, input, output); break;
		case mk_lib_vc_seq_id_e_serpent    : scha.m_serpent     = &schedulea->m_serpent    ; schb.m_serpent     = &scheduleb->m_serpent    ; mk_lib_vc_seq_xts_decrypt_block_serpent    (scha, schb, block_idx, input, output); break;
		case mk_lib_vc_seq_id_e_aes_serpent: scha.m_aes_serpent = &schedulea->m_aes_serpent; schb.m_aes_serpent = &scheduleb->m_aes_serpent; mk_lib_vc_seq_xts_decrypt_block_aes_serpent(scha, schb, block_idx, input, output); break;
		case mk_lib_vc_seq_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}


struct mk_lib_vc_reader_s
{
	mk_sl_cui_uint8_pct m_buff;
	mk_lang_types_usize_t m_buff_len;
	mk_lib_vc_seq_id_t m_seq_id;
	mk_lib_vc_seq_schedule_t_pct m_schedule_a;
	mk_lib_vc_seq_schedule_t_pct m_schedule_b;
	mk_lang_types_usize_t m_decrypted_block_id;
	mk_lib_vc_block_t m_block;
};
typedef struct mk_lib_vc_reader_s mk_lib_vc_reader_t;
typedef mk_lib_vc_reader_t const mk_lib_vc_reader_ct;
typedef mk_lib_vc_reader_t* mk_lib_vc_reader_pt;
typedef mk_lib_vc_reader_t const* mk_lib_vc_reader_pct;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_reader_make(mk_lib_vc_reader_pt const reader, mk_sl_cui_uint8_pct const buff, mk_lang_types_usize_t const buff_len, mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_schedule_t_pct const schedule_a, mk_lib_vc_seq_schedule_t_pct const schedule_b) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(buff || buff_len == 0);
	mk_lang_assert(buff_len >= mk_lib_vc_salt_len && buff_len % mk_lib_vc_block_len == 0);

	reader->m_buff = buff;
	reader->m_buff_len = buff_len;
	reader->m_seq_id = seq_id;
	reader->m_schedule_a = schedule_a;
	reader->m_schedule_b = schedule_b;
	reader->m_decrypted_block_id = 0x100;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_reader_read(mk_lib_vc_reader_pt const reader, mk_lang_types_usize_t const offset, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const dst) mk_lang_noexcept
{
	mk_lang_types_usize_t off mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt actdst mk_lang_constexpr_init;
	mk_lang_types_usize_t block_id mk_lang_constexpr_init;
	mk_sl_cui_uint64_t u64 mk_lang_constexpr_init;
	mk_lang_types_usize_t in_block_off mk_lang_constexpr_init;
	mk_lang_types_usize_t maxlen mk_lang_constexpr_init;
	mk_lang_types_usize_t actlen mk_lang_constexpr_init;

	mk_lang_assert(reader);
	mk_lang_assert(offset >= mk_lib_vc_salt_len && offset < reader->m_buff_len);
	mk_lang_assert(len >= 0 && len <= reader->m_buff_len - offset);
	mk_lang_assert(dst);

	off = offset;
	rem = len;
	actdst = dst;
	while(rem != 0)
	{
		block_id = (off - mk_lib_vc_salt_len) / mk_lib_vc_block_len;
		if(reader->m_decrypted_block_id != block_id)
		{
			reader->m_decrypted_block_id = block_id;
			mk_sl_cui_uint64_from_bi_size(&u64, &block_id);
			mk_lang_memcpy_obj_mk_lib_vc_u8(&reader->m_block.m_data.m_uint8s[0], &reader->m_buff[mk_lib_vc_salt_len + (block_id * mk_lib_vc_block_len)], mk_lib_vc_block_len);
			mk_lib_vc_seq_xts_decrypt_block(reader->m_seq_id, reader->m_schedule_a, reader->m_schedule_b, &u64, &reader->m_block, &reader->m_block);
		}
		in_block_off = (off - mk_lib_vc_salt_len) - (block_id * mk_lib_vc_block_len);
		maxlen = mk_lib_vc_block_len - in_block_off;
		actlen = mk_lang_min(maxlen, rem);
		mk_lang_memcpy_obj_mk_lib_vc_u8(actdst, &reader->m_block.m_data.m_uint8s[in_block_off], actlen);
		off += actlen;
		rem -= actlen;
		actdst += actlen;
	}
}


#define mk_lib_vc_invariants(vc) \
( \
	((vc)->m_data.m_buff) && \
	(((mk_lang_types_uintptr_t)((vc)->m_data.m_buff)) % mk_lib_vc_min_align == 0) && \
	((vc)->m_data.m_buff_len >= 0) && \
	((vc)->m_data.m_buff_len % mk_lib_vc_block_len == 0) && \
	((vc)->m_data.m_divider_a >= 0) && \
	((vc)->m_data.m_divider_b >= (vc)->m_data.m_divider_a) && \
	((vc)->m_data.m_divider_c >= (vc)->m_data.m_divider_b) && \
	((vc)->m_data.m_buff_len >= (vc)->m_data.m_divider_c) && \
	(((mk_lang_types_sint_t)((vc)->m_data.m_step)) >= 0 && ((mk_lang_types_sint_t)((vc)->m_data.m_step)) < ((mk_lang_types_sint_t)(mk_lib_vc_step_e_dummy_end))) \
)


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_vc_header(mk_lib_vc_pt const vc, mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_key_t_pct const key_a, mk_lib_vc_seq_key_t_pct const key_b) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buff mk_lang_constexpr_init;
	mk_lang_types_usize_t buff_len mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t schedule_a mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t schedule_b mk_lang_constexpr_init;
	mk_lib_vc_reader_t reader mk_lang_constexpr_init;
	mk_sl_cui_uint8_t magic[mk_lib_vc_magic_len] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t magic_pc[mk_lib_vc_magic_len] mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	buff = vc->m_data.m_buff + vc->m_data.m_divider_b;
	buff_len = vc->m_data.m_divider_c - vc->m_data.m_divider_b;
	if(!(buff_len >= 128 * 1024))
	{
		return mk_lang_false;
	}
	mk_lib_vc_seq_expand_dec(seq_id, key_a, &schedule_a);
	mk_lib_vc_seq_expand_enc(seq_id, key_b, &schedule_b);
	mk_lib_vc_reader_make(&reader, buff, buff_len, seq_id, &schedule_a, &schedule_b);
	mk_lib_vc_reader_read(&reader, mk_lib_vc_magic_offset, mk_lib_vc_magic_len, &magic[0]);
	n = mk_lib_vc_magic_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_pchar(&magic[i], &magic_pc[i]);
	}
	if
	(!(
		(magic_pc[0] == 'V') &&
		(magic_pc[1] == 'E') &&
		(magic_pc[2] == 'R') &&
		(magic_pc[3] == 'A')
	))
	{
		return mk_lang_false;
	}
	mk_lang_assert(mk_lib_vc_invariants(vc));
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_vc_format(mk_lib_vc_pt const vc, mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_key_t_pct const key_a, mk_lib_vc_seq_key_t_pct const key_b) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buff mk_lang_constexpr_init;
	mk_lang_types_usize_t buff_len mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t schedule_a mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t schedule_b mk_lang_constexpr_init;
	mk_lib_vc_reader_t reader mk_lang_constexpr_init;
	mk_sl_cui_uint8_t bytes_2[2] mk_lang_constexpr_init;
	mk_sl_cui_uint16_t u16 mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_sl_cui_uint8_t bytes_1[1] mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint8_t bytes_8[8] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t u64 mk_lang_constexpr_init;
	mk_sl_cui_uint64_t u64b mk_lang_constexpr_init;
	mk_sl_cui_uint8_t bytes_4[4] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t u32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_sl_cui_uint8_t keys_data[mk_lib_vc_master_keys_len] mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t master_key_a mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t master_key_b mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	buff = vc->m_data.m_buff + vc->m_data.m_divider_b;
	buff_len = vc->m_data.m_divider_c - vc->m_data.m_divider_b;
	if(!(buff_len >= 128 * 1024))
	{
		return mk_lang_false;
	}
	mk_lib_vc_seq_expand_dec(seq_id, key_a, &schedule_a);
	mk_lib_vc_seq_expand_enc(seq_id, key_b, &schedule_b);
	mk_lib_vc_reader_make(&reader, buff, buff_len, seq_id, &schedule_a, &schedule_b);
	mk_lib_vc_reader_read(&reader, mk_lib_vc_ver_offset, mk_lib_vc_ver_len, &bytes_2[0]);
	mk_sl_uint_16_from_8_be(&u16, &bytes_2[0]);
	mk_sl_cui_uint16_to_bi_uint(&u16, &tui);
	if(!(tui == 5))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_min_ver_maj_offset, mk_lib_vc_min_ver_maj_len, &bytes_1[0]);
	mk_sl_cui_uint8_to_bi_sint(&bytes_1[0], &tsi);
	if(!(tsi == 1))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_min_ver_min_offset, mk_lib_vc_min_ver_min_len, &bytes_1[0]);
	mk_sl_cui_uint8_to_bi_sint(&bytes_1[0], &tsi);
	if(!(tsi == 11))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_size_volume_offset, mk_lib_vc_size_volume_len, &bytes_8[0]);
	mk_sl_uint_64_from_8_be(&u64, &bytes_8[0]);
	vc->m_data.m_volume_len = u64;
	tsi = mk_lib_vc_block_len;
	mk_sl_cui_uint64_from_bi_sint(&u64, &tsi);
	mk_sl_cui_uint64_mod3_wrap(&vc->m_data.m_volume_len, &u64, &u64);
	if(!mk_sl_cui_uint64_is_zero(&u64))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_master_key_scope1_offset, mk_lib_vc_master_key_scope1_len, &bytes_8[0]);
	mk_sl_uint_64_from_8_be(&u64, &bytes_8[0]);
	tsi = mk_lib_vc_data_offset;
	mk_sl_cui_uint64_from_bi_sint(&u64b, &tsi);
	if(!mk_sl_cui_uint64_eq(&u64, &u64b))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_master_key_scope2_offset, mk_lib_vc_master_key_scope2_len, &bytes_8[0]);
	mk_sl_uint_64_from_8_be(&u64, &bytes_8[0]);
	if(!mk_sl_cui_uint64_eq(&u64, &vc->m_data.m_volume_len))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_sector_size_offset, mk_lib_vc_sector_size_len, &bytes_4[0]);
	mk_sl_uint_32_from_8_be(&u32, &bytes_4[0]);
	mk_sl_cui_uint32_to_bi_ulong(&u32, &tul);
	if(!(tul == mk_lib_vc_block_len))
	{
		return mk_lang_false;
	}
	mk_lib_vc_reader_read(&reader, mk_lib_vc_master_keys_offset, mk_lib_vc_master_keys_len, &keys_data[0]);
	mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 0, &master_key_a);
	mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 1, &master_key_b);
	mk_lib_vc_seq_expand_dec(seq_id, &master_key_a, &vc->m_data.m_master_schedule_a);
	mk_lib_vc_seq_expand_enc(seq_id, &master_key_b, &vc->m_data.m_master_schedule_b);
	mk_lang_assert(mk_lib_vc_invariants(vc));
	return mk_lang_true;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_pbkdf(mk_lib_vc_pbkdf_id_t const pbkdf_id, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	mk_lang_assert(password || password_len == 0);
	mk_lang_assert(password_len >= 0 && password_len <= 4 * 1024);
	mk_lang_assert(salt);
	mk_lang_assert(salt_len >= 16 && salt_len <= 4 * 1024);
	mk_lang_assert(cost >= 1000);
	mk_lang_assert(key_len >= 2 * 2 * 32);
	mk_lang_assert(key);

	switch(pbkdf_id)
	{
		case mk_lib_vc_pbkdf_id_e_sha512: mk_lib_crypto_kdf_pbkdf2_sha2_512_u8(password, password_len, salt, salt_len, cost, key_len, key); break;
		case mk_lib_vc_pbkdf_id_e_sha256: mk_lib_crypto_kdf_pbkdf2_sha2_256_u8(password, password_len, salt, salt_len, cost, key_len, key); break;
		case mk_lib_vc_pbkdf_id_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_offer(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept
{
	mk_lang_assert(vc);
	mk_lang_assert(buff_len >= 0 && buff_len % mk_lib_vc_block_len == 0);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	vc->m_data.m_divider_b += buff_len;
	mk_lang_assert(mk_lib_vc_invariants(vc));
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_vc_result_t mk_lib_vc_kdf(mk_lib_vc_pt const vc, mk_lib_vc_pbkdf_id_t const pbkdf_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buff mk_lang_constexpr_init;
	mk_lang_types_usize_t buff_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct salt mk_lang_constexpr_init;
	mk_lang_types_ulong_t pim mk_lang_constexpr_init;
	mk_lang_types_ulong_t cost mk_lang_constexpr_init;
	mk_sl_cui_uint8_t keys_data[2 * mk_lib_vc_seq_key_len] mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t key_a mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t key_b mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_vc_seq_id_t seq_id mk_lang_constexpr_init;
	mk_lib_vc_result_t r mk_lang_constexpr_init;
	mk_sl_cui_uint64_t u64 mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	buff = vc->m_data.m_buff + vc->m_data.m_divider_b;
	buff_len = vc->m_data.m_divider_c - vc->m_data.m_divider_b;
	if(!(buff_len >= 128 * 1024))
	{
		return mk_lib_vc_result_e_not_enough_input_data;
	}
	salt = buff;
	pim = vc->m_data.m_pim;
	cost = ((pim == 0ul) ? (500ul * 1000ul) : ((pim + 15ul) * (1ul * 1000ul)));
	mk_lib_vc_pbkdf(pbkdf_id, vc->m_data.m_password, vc->m_data.m_password_len, salt, mk_lib_vc_salt_len, cost, ((int)(sizeof(keys_data) / sizeof(keys_data[0]))), &keys_data[0]);
	n = ((mk_lang_types_sint_t)(mk_lib_vc_seq_id_e_dummy_end));
	for(i = 0; i != n; ++i)
	{
		seq_id = ((mk_lib_vc_seq_id_t)(i));
		mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 0, &key_a);
		mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 1, &key_b);
		if(mk_lib_vc_header(vc, seq_id, &key_a, &key_b))
		{
			break;
		}
	}
	if(i == n)
	{
		r = mk_lib_vc_result_e_ok;
		switch(pbkdf_id)
		{
			case mk_lib_vc_pbkdf_id_e_sha512: vc->m_data.m_step = mk_lib_vc_step_e_sha256; break;
			case mk_lib_vc_pbkdf_id_e_sha256: vc->m_data.m_step = mk_lib_vc_step_e_done; r = mk_lib_vc_result_e_bad_pwd_or_pid; break;
			case mk_lib_vc_pbkdf_id_e_dummy_end: mk_lang_assert(0); break;
			default: mk_lang_assert(0); break;
			mk_lang_assert(mk_lib_vc_invariants(vc));
			return r;
		}
	}
	if(!mk_lib_vc_format(vc, seq_id, &key_a, &key_b))
	{
		vc->m_data.m_step = mk_lib_vc_step_e_done;
		return mk_lib_vc_result_e_bad_format;
	}
	mk_lib_vc_offer(vc, 128 * 1024);
	mk_lib_vc_pop(vc, 128 * 1024);
	vc->m_data.m_seq_id = seq_id;
	n = mk_lib_vc_data_offset / mk_lib_vc_block_len;
	mk_sl_cui_uint64_from_bi_sint(&vc->m_data.m_block_idx, &n);
	n = mk_lib_vc_block_len;
	mk_sl_cui_uint64_from_bi_sint(&u64, &n);
	mk_sl_cui_uint64_div3_wrap(&vc->m_data.m_volume_len, &u64, &vc->m_data.m_volume_len);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_data.m_volume_len, &vc->m_data.m_block_idx);
	vc->m_data.m_step = mk_lib_vc_step_e_copy;
	mk_lang_assert(mk_lib_vc_invariants(vc));
	return mk_lib_vc_result_e_ok;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_vc_result_t mk_lib_vc_copy(mk_lib_vc_pt const vc) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt buff mk_lang_constexpr_init;
	mk_lang_types_usize_t buff_len mk_lang_constexpr_init;
	mk_lib_vc_block_t block mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(mk_sl_cui_uint64_le(&vc->m_data.m_block_idx, &vc->m_data.m_volume_len));

	if(mk_sl_cui_uint64_eq(&vc->m_data.m_block_idx, &vc->m_data.m_volume_len))
	{
		vc->m_data.m_step = mk_lib_vc_step_e_done;
		return mk_lib_vc_result_e_done;
	}
	buff = vc->m_data.m_buff + vc->m_data.m_divider_b;
	buff_len = vc->m_data.m_divider_c - vc->m_data.m_divider_b;
	mk_lang_assert(buff_len % mk_lib_vc_block_len == 0);
	if(!(buff_len >= mk_lib_vc_block_len))
	{
		return mk_lib_vc_result_e_not_enough_input_data;
	}
	mk_lang_memcpy_obj_mk_lib_vc_u8(&block.m_data.m_uint8s[0], buff, mk_lib_vc_block_len);
	mk_lib_vc_seq_xts_decrypt_block(vc->m_data.m_seq_id, &vc->m_data.m_master_schedule_a, &vc->m_data.m_master_schedule_b, &vc->m_data.m_block_idx, &block, &block);
	mk_lang_memcpy_obj_mk_lib_vc_u8(buff, &block.m_data.m_uint8s[0], mk_lib_vc_block_len);
	mk_sl_cui_uint64_inc1(&vc->m_data.m_block_idx);
	mk_lib_vc_offer(vc, mk_lib_vc_block_len);
	return mk_lib_vc_result_e_ok;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_init_impl(mk_lib_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_lib_vc_seq_key_aes_serpent_t) == mk_lib_vc_seq_key_aes_serpent_len);
	mk_lang_static_assert(mk_lib_vc_alg_msg_len == mk_lib_crypto_alg_aes_256_msg_len_m);
	mk_lang_static_assert(mk_lib_vc_alg_msg_len == mk_lib_crypto_alg_serpent_msg_len_m);
	mk_lang_static_assert(mk_lib_vc_seq_msg_aes_serpent_len == mk_lib_vc_alg_msg_len);
	mk_lang_static_assert(mk_lib_vc_seq_msg_len == mk_lib_vc_alg_msg_len);
	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_vc_alg_msg_len == 0);
	mk_lang_static_assert(mk_lib_vc_block_len % mk_lib_vc_seq_msg_len == 0);

	mk_lang_assert(vc);
	mk_lang_assert(buff);
	mk_lang_assert(((mk_lang_types_uintptr_t)(buff)) % mk_lib_vc_min_align == 0);
	mk_lang_assert(buff_len >= 128 * 1024);
	mk_lang_assert(buff_len % mk_lib_vc_block_len == 0);
	mk_lang_assert(password || password_len == 0);
	mk_lang_assert(password_len >= 0 && password_len <= 4 * 1024);

	vc->m_data.m_buff = buff;
	vc->m_data.m_buff_len = buff_len;
	vc->m_data.m_divider_a = 0;
	vc->m_data.m_divider_b = 0;
	vc->m_data.m_divider_c = 0;
	vc->m_data.m_step = mk_lib_vc_step_e_sha512;
	mk_lang_memcpy_obj_mk_lib_vc_u8(&vc->m_data.m_password[0], &password[0], password_len);
	vc->m_data.m_password_len = password_len;
	vc->m_data.m_pim = pim;
	#if mk_lib_vc_threads_want
	compute size of threads and chunk infos, add this into new function
	#endif
	mk_lang_assert(mk_lib_vc_invariants(vc));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_get_write_buff_(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pt* const buff, mk_lang_types_usize_t* const buff_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt buff_ mk_lang_constexpr_init;
	mk_lang_types_usize_t buff_len_ mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(buff);
	mk_lang_assert(buff_len);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	buff_ = vc->m_data.m_buff + vc->m_data.m_divider_c;
	buff_len_ = vc->m_data.m_buff_len - vc->m_data.m_divider_c;
	*buff = buff_;
	*buff_len = buff_len_;
	mk_lang_assert(mk_lib_vc_invariants(vc));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_get_read_buff_(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pt* const buff, mk_lang_types_usize_t* const buff_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt buff_ mk_lang_constexpr_init;
	mk_lang_types_usize_t buff_len_ mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(buff);
	mk_lang_assert(buff_len);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	buff_ = vc->m_data.m_buff + vc->m_data.m_divider_a;
	buff_len_ = vc->m_data.m_divider_b - vc->m_data.m_divider_a;
	*buff = buff_;
	*buff_len = buff_len_;
	mk_lang_assert(mk_lib_vc_invariants(vc));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_push_(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept
{
	mk_lang_assert(vc);
	mk_lang_assert(buff_len >= 0 && buff_len % mk_lib_vc_block_len == 0);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	vc->m_data.m_divider_c += buff_len;
	mk_lang_assert(mk_lib_vc_invariants(vc));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_pop_(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept
{
	mk_lang_assert(vc);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	vc->m_data.m_divider_a += buff_len;
	mk_lang_assert(mk_lib_vc_invariants(vc));
	if(vc->m_data.m_divider_c == vc->m_data.m_divider_a)
	{
		vc->m_data.m_divider_a = 0;
		vc->m_data.m_divider_b = 0;
		vc->m_data.m_divider_c = 0;
	}
	mk_lang_assert(mk_lib_vc_invariants(vc));
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_vc_result_t mk_lib_vc_step_(mk_lib_vc_pt const vc) mk_lang_noexcept
{
	mk_lib_vc_result_t r mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(mk_lib_vc_invariants(vc));

	switch(vc->m_data.m_step)
	{
		case mk_lib_vc_step_e_sha512   : r = mk_lib_vc_kdf(vc, mk_lib_vc_pbkdf_id_e_sha512); break;
		case mk_lib_vc_step_e_sha256   : r = mk_lib_vc_kdf(vc, mk_lib_vc_pbkdf_id_e_sha256); break;
		case mk_lib_vc_step_e_copy     : r = mk_lib_vc_copy(vc); break;
		case mk_lib_vc_step_e_dummy_end: mk_lang_assert(0); break;
		default                        : mk_lang_assert(0); break;
	}
	mk_lang_assert(mk_lib_vc_invariants(vc));
	return r;
}*/


enum mk_lib_vc_state_id_e
{
	mk_lib_vc_state_id_e_init,
	mk_lib_vc_state_id_e_dummy_end
};
typedef enum mk_lib_vc_state_id_e mk_lib_vc_state_id_t;

struct mk_lib_vc_state_init_s
{
	mk_lang_types_sint_t m_dummy;
};
typedef struct mk_lib_vc_state_init_s mk_lib_vc_state_init_t;

union mk_lib_vc_state_u
{
	mk_lib_vc_state_init_t m_init;
};
typedef union mk_lib_vc_state_u mk_lib_vc_state_t;

struct mk_lib_vc_data_s
{
	mk_lib_vc_state_t m_state;
};
typedef struct mk_lib_vc_data_s mk_lib_vc_data_t;
typedef mk_lib_vc_data_t const mk_lib_vc_data_ct;
typedef mk_lib_vc_data_t* mk_lib_vc_data_pt;
typedef mk_lib_vc_data_t const* mk_lib_vc_data_pct;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_say_response_void(mk_lib_vc_response_t const response, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lang_assert(output_buff || (!output_len || *output_len == 0));

	mk_lang_types_usize_t len mk_lang_constexpr_init;
	mk_lang_types_usize_t ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t response_sint mk_lang_constexpr_init;
	mk_sl_cui_mk_lib_vc_usize_t cui_usize mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[sizeof(mk_lang_types_usize_t)] mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	len = sizeof(mk_lang_types_usize_t);
	if(output_len && *output_len >= len)
	{
		ptr = 0;
		response_sint = response;
		mk_sl_cui_mk_lib_vc_usize_from_bi_sint(&cui_usize, &response_sint);
		mk_sl_cui_mk_lib_vc_usize_to_buis_uchar_le(&cui_usize, &uchars[0]);
		n = sizeof(mk_lang_types_usize_t);
		for(i = 0; i != n; ++i){ mk_sl_cui_uint8_from_bi_uchar(&output_buff[ptr + i], &uchars[i]); }
		ptr += n;
		*output_len = len;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_say_response_usize(mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len, mk_lib_vc_response_t const response, mk_lang_types_usize_t const usize) mk_lang_noexcept
{
	mk_lang_assert(output_buff || (!output_len || *output_len == 0));

	mk_lang_types_usize_t len mk_lang_constexpr_init;
	mk_lang_types_usize_t ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t response_sint mk_lang_constexpr_init;
	mk_sl_cui_mk_lib_vc_usize_t cui_usize mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[sizeof(mk_lang_types_usize_t)] mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	len = sizeof(mk_lang_types_usize_t) + sizeof(mk_lang_types_usize_t);
	if(output_len && *output_len >= len)
	{
		ptr = 0;
		response_sint = response;
		mk_sl_cui_mk_lib_vc_usize_from_bi_sint(&cui_usize, &response_sint);
		mk_sl_cui_mk_lib_vc_usize_to_buis_uchar_le(&cui_usize, &uchars[0]);
		n = sizeof(mk_lang_types_usize_t);
		for(i = 0; i != n; ++i){ mk_sl_cui_uint8_from_bi_uchar(&output_buff[ptr + i], &uchars[i]); }
		ptr += n;
		mk_sl_cui_mk_lib_vc_usize_from_bi_size(&cui_usize, &usize);
		mk_sl_cui_mk_lib_vc_usize_to_buis_uchar_le(&cui_usize, &uchars[0]);
		n = sizeof(mk_lang_types_usize_t);
		for(i = 0; i != n; ++i){ mk_sl_cui_uint8_from_bi_uchar(&output_buff[ptr + i], &uchars[i]); }
		ptr += n;
		*output_len = len;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_say_response_usize_usize(mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len, mk_lib_vc_response_t const response, mk_lang_types_usize_t const usize_a, mk_lang_types_usize_t const usize_b) mk_lang_noexcept
{
	mk_lang_types_usize_t ptr mk_lang_constexpr_init;

	mk_lang_assert(output_buff);
	mk_lang_assert(output_len);

	ptr = 0;
	mk_sl_serialization_write_usize(output_buff, *output_len, &ptr, &usize_a);
	mk_sl_serialization_write_usize(output_buff, *output_len, &ptr, &usize_b);
	*output_len += ptr;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_read_usize(mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_lang_types_usize_pt const ptr, mk_lang_types_usize_pt const usize) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[sizeof(mk_lang_types_usize_t)] mk_lang_constexpr_init;
	mk_sl_cui_mk_lib_vc_usize_t cui_usize mk_lang_constexpr_init;

	mk_lang_assert(input_buff);
	mk_lang_assert(input_len >= sizeof(mk_lang_types_usize_t));
	mk_lang_assert(ptr && *ptr <= input_len - sizeof(mk_lang_types_usize_t));
	mk_lang_assert(usize);

	n = sizeof(mk_lang_types_usize_t);
	for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&input_buff[*ptr + i], &uchars[i]); }
	mk_sl_cui_mk_lib_vc_usize_from_buis_uchar_le(&cui_usize, &uchars[0]);
	mk_sl_cui_mk_lib_vc_usize_to_bi_size(&cui_usize, usize);
	*ptr += n;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_read_mem(mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_lang_types_usize_pt const ptr, mk_sl_cui_uint8_pt* const mem) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_pt) == sizeof(mk_lang_types_usize_t));
	mk_lang_static_assert(mk_lang_alignof(mk_sl_cui_uint8_pt) == mk_lang_alignof(mk_lang_types_usize_t));

	mk_lang_types_usize_t mem_uint mk_lang_constexpr_init;

	mk_lib_vc_read_usize(input_buff, input_len, ptr, &mem_uint);
	#if mk_lang_version_at_least_cpp_20
	*mem = std::bit_cast<mk_sl_cui_uint8_pt>(mem_uint);
	#else
	*mem = ((mk_sl_cui_uint8_pt)(mem_uint));
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_say_ok(mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lib_vc_say_response_void(mk_lib_vc_response_e_ok, output_buff, output_len);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_say_wantmem(mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len, mk_lang_types_usize_t const mem_len, mk_lang_types_usize_t const mem_align) mk_lang_noexcept
{
	mk_lib_vc_say_response_usize_usize(output_buff, output_len, mk_lib_vc_response_e_wantmem, mem_len, mem_align);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_req_init(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lang_assert(vc);
	mk_lang_assert(input_len == 0);

	vc->m_data = mk_lang_null;
	mk_lib_vc_say_ok(output_buff, output_len);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_vc_data_pt mk_lib_vc_get_data(mk_lib_vc_pt const vc) mk_lang_noexcept
{
	mk_lib_vc_data_pt data mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(vc->m_data);

	data = ((mk_lib_vc_data_pt)(vc->m_data));
	return data;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_req_dowork(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lang_assert(vc);
	mk_lang_assert(input_len == 0);

	if(vc->m_data == mk_lang_null)
	{
		mk_lib_vc_say_wantmem(output_buff, output_len, sizeof(mk_lib_vc_data_t), mk_lang_alignof(mk_lib_vc_data_t));
	}
	else
	{
		/* todo */
		mk_lib_vc_say_ok(output_buff, output_len);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_req_givemem(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lang_types_usize_t ptr mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt mem mk_lang_constexpr_init;
	mk_lang_types_usize_t mem_len mk_lang_constexpr_init;

	mk_lang_assert(vc);

	if(vc->m_data == mk_lang_null)
	{
		ptr = 0;
		mk_lib_vc_read_mem(input_buff, input_len, &ptr, &mem);
		mk_lib_vc_read_usize(input_buff, input_len, &ptr, &mem_len);
		mk_lang_assert(((mk_lang_types_uintptr_t)(mem)) % mk_lang_alignof(mk_lib_vc_data_t) == 0);
		mk_lang_assert(mem_len == sizeof(mk_lib_vc_data_t));
		vc->m_data = mem;
	}
	else
	{
		/* todo */
		mk_lang_assert(0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_vc_req_dispatch(mk_lib_vc_pt const vc, mk_lang_types_uint_t const request, mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_lang_types_uint_pt const response, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lib_vc_request_t req mk_lang_constexpr_init;

	mk_lang_assert(vc);
	mk_lang_assert(request >= 0 && request < ((mk_lang_types_uint_t)(mk_lib_vc_request_e_dummy_end)));

	req = ((mk_lib_vc_request_t)(request));
	switch(req)
	{
		case mk_lib_vc_request_e_init: mk_lib_vc_req_init(vc, input_buff, input_len, response, output_buff, output_len); break;
		case mk_lib_vc_request_e_dowork: mk_lib_vc_req_dowork(vc, input_buff, input_len, response, output_buff, output_len); break;
		case mk_lib_vc_request_e_fullfill_allocmem: mk_lib_vc_req_givemem(vc, input_buff, input_len, response, output_buff, output_len); break;
		case mk_lib_vc_request_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_req(mk_lib_vc_pt const vc, mk_lang_types_uint_t const request, mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_lang_types_uint_pt const response, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept
{
	mk_lib_vc_req_dispatch(vc, request, input_buff, input_len, response, output_buff, output_len);
}


/*mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_init(mk_lib_vc_pt const vc) mk_lang_noexcept { mk_lib_vc_init_impl(vc); }
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_get_write_buff(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pt* const buff, mk_lang_types_usize_t* const buff_len) mk_lang_noexcept { mk_lib_vc_get_write_buff_(vc, buff, buff_len); }
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_get_read_buff(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pt* const buff, mk_lang_types_usize_t* const buff_len) mk_lang_noexcept { mk_lib_vc_get_read_buff_(vc, buff, buff_len); }
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_push(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept { mk_lib_vc_push_(vc, buff_len); }
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_pop(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept { mk_lib_vc_pop_(vc, buff_len); }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lib_vc_result_t mk_lib_vc_step(mk_lib_vc_pt const vc) mk_lang_noexcept { return mk_lib_vc_step_(vc); }*/
