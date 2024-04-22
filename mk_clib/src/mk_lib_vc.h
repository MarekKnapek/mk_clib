#ifndef mk_include_guard_mk_lib_vc
#define mk_include_guard_mk_lib_vc


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_vc_msg_len 16
#define mk_lib_vc_block_len 512
#define mk_lib_vc_salt_len 64
#define mk_lib_vc_msgs_per_block (mk_lib_vc_block_len / mk_lib_vc_msg_len)

#define mk_lib_vc_offsets_magic                        0
#define mk_lib_vc_offsets_volume_header_format_version 4
#define mk_lib_vc_offsets_minimum_program_version      6
#define mk_lib_vc_offsets_crc_a                        8
#define mk_lib_vc_offsets_reserved_a                  12
#define mk_lib_vc_offsets_hidden_volume_size          28
#define mk_lib_vc_offsets_normal_volume_size          36
#define mk_lib_vc_offsets_master_key_scope_start      44
#define mk_lib_vc_offsets_master_key_scope_len        52
#define mk_lib_vc_offsets_flags                       60
#define mk_lib_vc_offsets_block_len                   64
#define mk_lib_vc_offsets_reserved_b                  68
#define mk_lib_vc_offsets_crc_b                      188
#define mk_lib_vc_offsets_keys                       192
#define mk_lib_vc_offsets_volume          (128l * 1024l)

#define mk_lib_vc_lens_magic                        4
#define mk_lib_vc_lens_volume_header_format_version 2
#define mk_lib_vc_lens_minimum_program_version      2
#define mk_lib_vc_lens_crc_a                        4
#define mk_lib_vc_lens_reserved_a                  16
#define mk_lib_vc_lens_hidden_volume_size           8
#define mk_lib_vc_lens_normal_volume_size           8
#define mk_lib_vc_lens_master_key_scope_start       8
#define mk_lib_vc_lens_master_key_scope_len         8
#define mk_lib_vc_lens_flags                        4
#define mk_lib_vc_lens_block_len                    4
#define mk_lib_vc_lens_reserved_b                 120
#define mk_lib_vc_lens_crc_b                        4
#define mk_lib_vc_lens_keys                       256


enum mk_lib_vc_kdfid_e
{
	mk_lib_vc_kdfid_e_sha512,
	mk_lib_vc_kdfid_e_whirlpool,
	mk_lib_vc_kdfid_e_sha256,
	mk_lib_vc_kdfid_e_blake2s256,
	mk_lib_vc_kdfid_e_streebog,
	mk_lib_vc_kdfid_e_dummy
};
typedef enum mk_lib_vc_kdfid_e mk_lib_vc_kdfid_t;
typedef mk_lib_vc_kdfid_t const mk_lib_vc_kdfid_ct;
typedef mk_lib_vc_kdfid_t* mk_lib_vc_kdfid_pt;
typedef mk_lib_vc_kdfid_t const* mk_lib_vc_kdfid_pct;

enum mk_lib_vc_algid_e
{
	mk_lib_vc_algid_e_aes,
	mk_lib_vc_algid_e_serpent,
	mk_lib_vc_algid_e_dummy
};
typedef enum mk_lib_vc_algid_e mk_lib_vc_algid_t;

enum mk_lib_vc_seqid_e
{
	mk_lib_vc_seqid_e_aes,
	mk_lib_vc_seqid_e_serpent,
	mk_lib_vc_seqid_e_aes_serpent,
	mk_lib_vc_seqid_e_dummy
};
typedef enum mk_lib_vc_seqid_e mk_lib_vc_seqid_t;
typedef mk_lib_vc_seqid_t const mk_lib_vc_seqid_ct;
typedef mk_lib_vc_seqid_t* mk_lib_vc_seqid_pt;
typedef mk_lib_vc_seqid_t const* mk_lib_vc_seqid_pct;


struct mk_lib_vc_salt_data_s
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_salt_len];
};
typedef struct mk_lib_vc_salt_data_s mk_lib_vc_salt_data_t;

struct mk_lib_vc_salt_s
{
	mk_lib_vc_salt_data_t m_data;
};
typedef struct mk_lib_vc_salt_s mk_lib_vc_salt_t;
typedef mk_lib_vc_salt_t const mk_lib_vc_salt_ct;
typedef mk_lib_vc_salt_t* mk_lib_vc_salt_pt;
typedef mk_lib_vc_salt_t const* mk_lib_vc_salt_pct;

struct mk_lib_vc_keys_material_data_s
{
	mk_sl_cui_uint8_t m_uint8s[2 * mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_key_len_v, mk_lib_crypto_alg_serpent_key_len_v), mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)];
};
typedef struct mk_lib_vc_keys_material_data_s mk_lib_vc_keys_material_data_t;

struct mk_lib_vc_keys_material_s
{
	mk_lib_vc_keys_material_data_t m_data;
};
typedef struct mk_lib_vc_keys_material_s mk_lib_vc_keys_material_t;
typedef mk_lib_vc_keys_material_t const mk_lib_vc_keys_material_ct;
typedef mk_lib_vc_keys_material_t* mk_lib_vc_keys_material_pt;
typedef mk_lib_vc_keys_material_t const* mk_lib_vc_keys_material_pct;

struct mk_lib_vc_seq_aes_keys_s
{
	mk_lib_crypto_alg_aes_256_key_t m_pri;
	mk_lib_crypto_alg_aes_256_key_t m_sec;
};
typedef struct mk_lib_vc_seq_aes_keys_s mk_lib_vc_seq_aes_keys_t;

struct mk_lib_vc_seq_serpent_keys_s
{
	mk_lib_crypto_alg_serpent_key_t m_pri;
	mk_lib_crypto_alg_serpent_key_t m_sec;
};
typedef struct mk_lib_vc_seq_serpent_keys_s mk_lib_vc_seq_serpent_keys_t;

struct mk_lib_vc_seq_aes_serpent_keys_s
{
	mk_lib_crypto_alg_aes_256_key_t m_aes_pri;
	mk_lib_crypto_alg_serpent_key_t m_serpent_pri;
	mk_lib_crypto_alg_aes_256_key_t m_aes_sec;
	mk_lib_crypto_alg_serpent_key_t m_serpent_sec;
};
typedef struct mk_lib_vc_seq_aes_serpent_keys_s mk_lib_vc_seq_aes_serpent_keys_t;

union mk_lib_vc_seq_keys_data_u
{
	mk_lib_vc_seq_aes_keys_t m_aes;
	mk_lib_vc_seq_serpent_keys_t m_serpent;
	mk_lib_vc_seq_aes_serpent_keys_t m_aes_serpent;
};
typedef union mk_lib_vc_seq_keys_data_u mk_lib_vc_seq_keys_data_t;

struct mk_lib_vc_seq_keys_s
{
	mk_lib_vc_seq_keys_data_t m_data;
};
typedef struct mk_lib_vc_seq_keys_s mk_lib_vc_seq_keys_t;
typedef mk_lib_vc_seq_keys_t const mk_lib_vc_seq_keys_ct;
typedef mk_lib_vc_seq_keys_t* mk_lib_vc_seq_keys_pt;
typedef mk_lib_vc_seq_keys_t const* mk_lib_vc_seq_keys_pct;

union mk_lib_vc_tweak_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_msg_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aes;
	mk_lib_crypto_alg_serpent_msg_t m_serpent;
};
typedef union mk_lib_vc_tweak_data_u mk_lib_vc_tweak_data_t;

struct mk_lib_vc_tweak_s
{
	mk_lib_vc_tweak_data_t m_data;
};
typedef struct mk_lib_vc_tweak_s mk_lib_vc_tweak_t;
typedef mk_lib_vc_tweak_t const mk_lib_vc_tweak_ct;
typedef mk_lib_vc_tweak_t* mk_lib_vc_tweak_pt;
typedef mk_lib_vc_tweak_t const* mk_lib_vc_tweak_pct;

union mk_lib_vc_block_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_block_len];
	mk_lib_crypto_alg_aes_256_msg_t m_aess[mk_lib_vc_block_len / mk_lib_crypto_alg_aes_256_msg_len_v];
	mk_lib_crypto_alg_serpent_msg_t m_serpents[mk_lib_vc_block_len / mk_lib_crypto_alg_serpent_msg_len_v];
	mk_lib_vc_tweak_t m_tweaks[mk_lib_vc_block_len / mk_lib_vc_msg_len];
};
typedef union mk_lib_vc_block_data_u mk_lib_vc_block_data_t;

struct mk_lib_vc_block_s
{
	mk_lib_vc_block_data_t m_data;
};
typedef struct mk_lib_vc_block_s mk_lib_vc_block_t;
typedef mk_lib_vc_block_t const mk_lib_vc_block_ct;
typedef mk_lib_vc_block_t* mk_lib_vc_block_pt;
typedef mk_lib_vc_block_t const* mk_lib_vc_block_pct;

struct mk_lib_vc_block_oversized_data_s
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_block_len + (mk_lib_vc_block_len - 1)];
};
typedef struct mk_lib_vc_block_oversized_data_s mk_lib_vc_block_oversized_data_t;

struct mk_lib_vc_block_oversized_s
{
	mk_lib_vc_block_oversized_data_t m_data;
};
typedef struct mk_lib_vc_block_oversized_s mk_lib_vc_block_oversized_t;

union mk_lib_vc_alg_schedule_data_u
{
	mk_lib_crypto_alg_aes_256_schedule_pct m_aes;
	mk_lib_crypto_alg_serpent_schedule_pct m_serpent;
};
typedef union mk_lib_vc_alg_schedule_data_u mk_lib_vc_alg_schedule_data_t;

struct mk_lib_vc_alg_schedule_s
{
	mk_lib_vc_alg_schedule_data_t m_data;
};
typedef struct mk_lib_vc_alg_schedule_s mk_lib_vc_alg_schedule_t;

struct mk_lib_vc_seq_aes_schedules_s
{
	mk_lib_crypto_alg_aes_256_schedule_t m_pri;
	mk_lib_crypto_alg_aes_256_schedule_t m_sec;
};
typedef struct mk_lib_vc_seq_aes_schedules_s mk_lib_vc_seq_aes_schedules_t;

struct mk_lib_vc_seq_serpent_schedules_s
{
	mk_lib_crypto_alg_serpent_schedule_t m_pri;
	mk_lib_crypto_alg_serpent_schedule_t m_sec;
};
typedef struct mk_lib_vc_seq_serpent_schedules_s mk_lib_vc_seq_serpent_schedules_t;

struct mk_lib_vc_seq_aes_serpent_schedules_s
{
	mk_lib_crypto_alg_aes_256_schedule_t m_aes_pri;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent_pri;
	mk_lib_crypto_alg_aes_256_schedule_t m_aes_sec;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent_sec;
};
typedef struct mk_lib_vc_seq_aes_serpent_schedules_s mk_lib_vc_seq_aes_serpent_schedules_t;

union mk_lib_vc_seq_schedules_data_u
{
	mk_lib_vc_seq_aes_schedules_t m_aes;
	mk_lib_vc_seq_serpent_schedules_t m_serpent;
	mk_lib_vc_seq_aes_serpent_schedules_t m_aes_serpent;
};
typedef union mk_lib_vc_seq_schedules_data_u mk_lib_vc_seq_schedules_data_t;

struct mk_lib_vc_seq_schedules_s
{
	mk_lib_vc_seq_schedules_data_t m_data;
};
typedef struct mk_lib_vc_seq_schedules_s mk_lib_vc_seq_schedules_t;
typedef mk_lib_vc_seq_schedules_t const mk_lib_vc_seq_schedules_ct;
typedef mk_lib_vc_seq_schedules_t* mk_lib_vc_seq_schedules_pt;
typedef mk_lib_vc_seq_schedules_t const* mk_lib_vc_seq_schedules_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_tweak_next(mk_lib_vc_tweak_pct const curr, mk_lib_vc_tweak_pt const next) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_alg_encrypt_tweak(mk_lib_vc_algid_t const algid, mk_lib_vc_alg_schedule_t const schedule, mk_lib_vc_tweak_pct const in, mk_lib_vc_tweak_pt const out) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_alg_decrypt_block(mk_lib_vc_algid_t const algid, mk_lib_vc_alg_schedule_t const schedule, mk_lib_vc_block_pct const in, mk_lib_vc_block_pt const out) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_xts_decrypt_block(mk_lib_vc_algid_t const algid, mk_lib_vc_alg_schedule_t const schedule_pri, mk_lib_vc_alg_schedule_t const schedule_sec, mk_sl_cui_uint64_pct const block_id, mk_lib_vc_block_pct const in, mk_lib_vc_block_pt const out) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_seq_decrypt_block(mk_lib_vc_seqid_t const seqid, mk_lib_vc_seq_schedules_pct const schedules, mk_sl_cui_uint64_pct const block_id, mk_lib_vc_block_pct const in, mk_lib_vc_block_pt const out) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_seq_expand_dec(mk_lib_vc_seqid_t const seqid, mk_lib_vc_seq_keys_pct const keys, mk_lib_vc_seq_schedules_pt const schedules) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_keys_init(mk_lib_vc_seqid_t const seqid, mk_lib_vc_keys_material_pct const keys_material, mk_lib_vc_seq_keys_pt const keys) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_derive_keys(mk_lib_vc_kdfid_t const kdfid, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_ulong_t const cost, mk_lib_vc_keys_material_pt const key_material) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_parse_cost(mk_lang_types_pchar_pct const str_pim, mk_lang_types_ulong_pt const cost) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_try_decrypt_header_seq(mk_lib_vc_seqid_t const seqid, mk_lib_vc_keys_material_pct const keys_material, mk_lib_vc_block_pct const block, mk_lib_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_try_decrypt_header_kdf(mk_lib_vc_kdfid_t const kdfid, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lib_vc_salt_pct const salt, mk_lang_types_ulong_t const cost, mk_lib_vc_block_pct const block, mk_lib_vc_seqid_pt const seqid_out, mk_lib_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_try_decrypt_header(mk_lib_vc_kdfid_t const kdf_hint, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lib_vc_salt_pct const salt, mk_lang_types_ulong_t const cost, mk_lib_vc_block_pct const block, mk_lib_vc_seqid_pt const seqid_out, mk_lib_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_vc.c"
#endif
#endif
