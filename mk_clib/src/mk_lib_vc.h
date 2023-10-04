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


/*enum mk_lib_vc_result_e
{
	mk_lib_vc_result_e_ok,
	mk_lib_vc_result_e_not_enough_input_data,
	mk_lib_vc_result_e_bad_pwd_or_pid,
	mk_lib_vc_result_e_bad_format,
	mk_lib_vc_result_e_done,
	mk_lib_vc_result_e_dummy_end
};
typedef enum mk_lib_vc_result_e mk_lib_vc_result_t;

enum mk_lib_vc_step_e
{
	mk_lib_vc_step_e_sha512,
	mk_lib_vc_step_e_sha256,
	mk_lib_vc_step_e_copy,
	mk_lib_vc_step_e_done,
	mk_lib_vc_step_e_dummy_end
};
typedef enum mk_lib_vc_step_e mk_lib_vc_step_t;

enum mk_lib_vc_seq_id_e
{
	mk_lib_vc_seq_id_e_aes,
	mk_lib_vc_seq_id_e_serpent,
	mk_lib_vc_seq_id_e_aes_serpent,
	mk_lib_vc_seq_id_e_dummy_end
};
typedef enum mk_lib_vc_seq_id_e mk_lib_vc_seq_id_t;

#define mk_lib_vc_seq_key_aes_serpent_len (mk_lib_crypto_alg_aes_256_key_len_m + mk_lib_crypto_alg_serpent_key_len_m)
struct mk_lib_vc_seq_key_aes_serpent_s
{
	mk_lib_crypto_alg_aes_256_key_t m_aes;
	mk_lib_crypto_alg_serpent_key_t m_serpent;
};
typedef struct mk_lib_vc_seq_key_aes_serpent_s mk_lib_vc_seq_key_aes_serpent_t;
typedef mk_lib_vc_seq_key_aes_serpent_t const mk_lib_vc_seq_key_aes_serpent_ct;
typedef mk_lib_vc_seq_key_aes_serpent_t* mk_lib_vc_seq_key_aes_serpent_pt;
typedef mk_lib_vc_seq_key_aes_serpent_t const* mk_lib_vc_seq_key_aes_serpent_pct;

#define mk_lib_vc_seq_key_len mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_key_len_m, mk_lib_crypto_alg_serpent_key_len_m), mk_lib_vc_seq_key_aes_serpent_len)
union mk_lib_vc_seq_key_t_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_seq_key_len];
	mk_lib_crypto_alg_aes_256_key_t m_aes;
	mk_lib_crypto_alg_serpent_key_t m_serpent;
	mk_lib_vc_seq_key_aes_serpent_t m_aes_serpent;
};
typedef union mk_lib_vc_seq_key_t_u mk_lib_vc_seq_key_t_t;
typedef mk_lib_vc_seq_key_t_t const mk_lib_vc_seq_key_t_ct;
typedef mk_lib_vc_seq_key_t_t* mk_lib_vc_seq_key_t_pt;
typedef mk_lib_vc_seq_key_t_t const* mk_lib_vc_seq_key_t_pct;

union mk_lib_vc_seq_key_pt_u
{
	mk_lib_crypto_alg_aes_256_key_pt m_aes;
	mk_lib_crypto_alg_serpent_key_pt m_serpent;
	mk_lib_vc_seq_key_aes_serpent_pt m_aes_serpent;
};
typedef union mk_lib_vc_seq_key_pt_u mk_lib_vc_seq_key_pt_t;
typedef mk_lib_vc_seq_key_pt_t const mk_lib_vc_seq_key_pt_ct;
typedef mk_lib_vc_seq_key_pt_t* mk_lib_vc_seq_key_pt_pt;
typedef mk_lib_vc_seq_key_pt_t const* mk_lib_vc_seq_key_pt_pct;

union mk_lib_vc_seq_key_pct_u
{
	mk_lib_crypto_alg_aes_256_key_pct m_aes;
	mk_lib_crypto_alg_serpent_key_pct m_serpent;
	mk_lib_vc_seq_key_aes_serpent_pct m_aes_serpent;
};
typedef union mk_lib_vc_seq_key_pct_u mk_lib_vc_seq_key_pct_t;
typedef mk_lib_vc_seq_key_pct_t const mk_lib_vc_seq_key_pct_ct;
typedef mk_lib_vc_seq_key_pct_t* mk_lib_vc_seq_key_pct_pt;
typedef mk_lib_vc_seq_key_pct_t const* mk_lib_vc_seq_key_pct_pct;

#define mk_lib_vc_alg_schedule_len mk_lang_max(mk_lib_crypto_alg_aes_256_schedule_len_m, mk_lib_crypto_alg_serpent_schedule_len_m)
union mk_lib_vc_alg_schedule_t_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_alg_schedule_len];
	mk_lib_crypto_alg_aes_256_schedule_t m_aes;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent;
};
typedef union mk_lib_vc_alg_schedule_t_u mk_lib_vc_alg_schedule_t_t;
typedef mk_lib_vc_alg_schedule_t_t const mk_lib_vc_alg_schedule_t_ct;
typedef mk_lib_vc_alg_schedule_t_t* mk_lib_vc_alg_schedule_t_pt;
typedef mk_lib_vc_alg_schedule_t_t const* mk_lib_vc_alg_schedule_t_pct;

union mk_lib_vc_alg_schedule_pt_u
{
	mk_lib_crypto_alg_aes_256_schedule_pt m_aes;
	mk_lib_crypto_alg_serpent_schedule_pt m_serpent;
};
typedef union mk_lib_vc_alg_schedule_pt_u mk_lib_vc_alg_schedule_pt_t;
typedef mk_lib_vc_alg_schedule_pt_t const mk_lib_vc_alg_schedule_pt_ct;
typedef mk_lib_vc_alg_schedule_pt_t* mk_lib_vc_alg_schedule_pt_pt;
typedef mk_lib_vc_alg_schedule_pt_t const* mk_lib_vc_alg_schedule_pt_pct;

union mk_lib_vc_alg_schedule_pct_u
{
	mk_lib_crypto_alg_aes_256_schedule_pct m_aes;
	mk_lib_crypto_alg_serpent_schedule_pct m_serpent;
};
typedef union mk_lib_vc_alg_schedule_pct_u mk_lib_vc_alg_schedule_pct_t;
typedef mk_lib_vc_alg_schedule_pct_t const mk_lib_vc_alg_schedule_pct_ct;
typedef mk_lib_vc_alg_schedule_pct_t* mk_lib_vc_alg_schedule_pct_pt;
typedef mk_lib_vc_alg_schedule_pct_t const* mk_lib_vc_alg_schedule_pct_pct;

#define mk_lib_vc_seq_schedule_aes_serpent_len (mk_lib_crypto_alg_aes_256_schedule_len_m + mk_lib_crypto_alg_serpent_schedule_len_m)
struct mk_lib_vc_seq_schedule_aes_serpent_s
{
	mk_lib_crypto_alg_aes_256_schedule_t m_aes;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent;
};
typedef struct mk_lib_vc_seq_schedule_aes_serpent_s mk_lib_vc_seq_schedule_aes_serpent_t;
typedef mk_lib_vc_seq_schedule_aes_serpent_t const mk_lib_vc_seq_schedule_aes_serpent_ct;
typedef mk_lib_vc_seq_schedule_aes_serpent_t* mk_lib_vc_seq_schedule_aes_serpent_pt;
typedef mk_lib_vc_seq_schedule_aes_serpent_t const* mk_lib_vc_seq_schedule_aes_serpent_pct;

#define mk_lib_vc_seq_schedule_len mk_lang_max(mk_lang_max(mk_lib_crypto_alg_aes_256_schedule_len_m, mk_lib_crypto_alg_serpent_schedule_len_m), mk_lib_vc_seq_schedule_aes_serpent_len)
union mk_lib_vc_seq_schedule_t_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_seq_schedule_len];
	mk_lib_crypto_alg_aes_256_schedule_t m_aes;
	mk_lib_crypto_alg_serpent_schedule_t m_serpent;
	mk_lib_vc_seq_schedule_aes_serpent_t m_aes_serpent;
};
typedef union mk_lib_vc_seq_schedule_t_u mk_lib_vc_seq_schedule_t_t;
typedef mk_lib_vc_seq_schedule_t_t const mk_lib_vc_seq_schedule_t_ct;
typedef mk_lib_vc_seq_schedule_t_t* mk_lib_vc_seq_schedule_t_pt;
typedef mk_lib_vc_seq_schedule_t_t const* mk_lib_vc_seq_schedule_t_pct;

union mk_lib_vc_seq_schedule_pt_u
{
	mk_lib_crypto_alg_aes_256_schedule_pt m_aes;
	mk_lib_crypto_alg_serpent_schedule_pt m_serpent;
	mk_lib_vc_seq_schedule_aes_serpent_pt m_aes_serpent;
};
typedef union mk_lib_vc_seq_schedule_pt_u mk_lib_vc_seq_schedule_pt_t;
typedef mk_lib_vc_seq_schedule_pt_t const mk_lib_vc_seq_schedule_pt_ct;
typedef mk_lib_vc_seq_schedule_pt_t* mk_lib_vc_seq_schedule_pt_pt;
typedef mk_lib_vc_seq_schedule_pt_t const* mk_lib_vc_seq_schedule_pt_pct;

union mk_lib_vc_seq_schedule_pct_u
{
	mk_lib_crypto_alg_aes_256_schedule_pct m_aes;
	mk_lib_crypto_alg_serpent_schedule_pct m_serpent;
	mk_lib_vc_seq_schedule_aes_serpent_pct m_aes_serpent;
};
typedef union mk_lib_vc_seq_schedule_pct_u mk_lib_vc_seq_schedule_pct_t;
typedef mk_lib_vc_seq_schedule_pct_t const mk_lib_vc_seq_schedule_pct_ct;
typedef mk_lib_vc_seq_schedule_pct_t* mk_lib_vc_seq_schedule_pct_pt;
typedef mk_lib_vc_seq_schedule_pct_t const* mk_lib_vc_seq_schedule_pct_pct;

struct mk_lib_vc_data_s
{
	mk_sl_cui_uint8_pt m_buff;
	mk_lang_types_usize_t m_buff_len;
	mk_lang_types_usize_t m_divider_a;
	mk_lang_types_usize_t m_divider_b;
	mk_lang_types_usize_t m_divider_c;
	mk_lib_vc_step_t m_step;
	mk_sl_cui_uint8_t m_password[4 * 1024];
	mk_lang_types_sint_t m_password_len;
	mk_lang_types_ulong_t m_pim;
	mk_lib_vc_seq_id_t m_seq_id;
	mk_sl_cui_uint64_t m_volume_len;
	mk_lib_vc_seq_schedule_t_t m_master_schedule_a;
	mk_lib_vc_seq_schedule_t_t m_master_schedule_b;
	mk_sl_cui_uint64_t m_block_idx;
};
typedef struct mk_lib_vc_data_s mk_lib_vc_data_t;
typedef mk_lib_vc_data_t const mk_lib_vc_data_ct;
typedef mk_lib_vc_data_t* mk_lib_vc_data_pt;
typedef mk_lib_vc_data_t const* mk_lib_vc_data_pct;*/

struct mk_lib_vc_data_s;
typedef struct mk_lib_vc_data_s mk_lib_vc_data_t;
typedef mk_lib_vc_data_t const mk_lib_vc_data_ct;
typedef mk_lib_vc_data_t* mk_lib_vc_data_pt;
typedef mk_lib_vc_data_t const* mk_lib_vc_data_pct;

struct mk_lib_vc_s
{
	mk_lib_vc_data_pt m_data;
};
typedef struct mk_lib_vc_s mk_lib_vc_t;
typedef mk_lib_vc_t const mk_lib_vc_ct;
typedef mk_lib_vc_t* mk_lib_vc_pt;
typedef mk_lib_vc_t const* mk_lib_vc_pct;

enum mk_lib_vc_request_e
{
	mk_lib_vc_request_e_init,
	mk_lib_vc_request_e_dowork,
	mk_lib_vc_request_e_fullfill_allocmem,
	mk_lib_vc_request_e_fullfill_readargc,
	mk_lib_vc_request_e_fullfill_freemem,

	mk_lib_vc_request_e_fullfill_readargv,
	mk_lib_vc_request_e_fullfill_openfilerb,
	mk_lib_vc_request_e_fullfill_openfilewb,
	mk_lib_vc_request_e_fullfill_closefile,
	mk_lib_vc_request_e_fullfill_read,
	mk_lib_vc_request_e_fullfill_write,
	mk_lib_vc_request_e_fullfill_wait,
	mk_lib_vc_request_e_dummy_end
};
typedef enum mk_lib_vc_request_e mk_lib_vc_request_t;
typedef mk_lib_vc_request_t const mk_lib_vc_request_ct;
typedef mk_lib_vc_request_t* mk_lib_vc_request_pt;
typedef mk_lib_vc_request_t const* mk_lib_vc_request_pct;

enum mk_lib_vc_response_e
{
	mk_lib_vc_response_e_ok,
	mk_lib_vc_response_e_allocmem,
	mk_lib_vc_response_e_readargc,
	mk_lib_vc_response_e_done,
	mk_lib_vc_response_e_readargv,
	mk_lib_vc_response_e_freemem,
	mk_lib_vc_response_e_openfilerb,
	mk_lib_vc_response_e_openfilewb,
	mk_lib_vc_response_e_closefile,
	mk_lib_vc_response_e_read,
	mk_lib_vc_response_e_write,
	mk_lib_vc_response_e_wait,
	mk_lib_vc_response_e_dummy_end
};
typedef enum mk_lib_vc_response_e mk_lib_vc_response_t;
typedef mk_lib_vc_response_t const mk_lib_vc_response_ct;
typedef mk_lib_vc_response_t* mk_lib_vc_response_pt;
typedef mk_lib_vc_response_t const* mk_lib_vc_response_pct;


struct mk_lib_vc_request_type_fullfill_allocmem_s
{
	mk_sl_cui_uint8_pt m_mem;
};
typedef struct mk_lib_vc_request_type_fullfill_allocmem_s mk_lib_vc_request_type_fullfill_allocmem_t;
typedef mk_lib_vc_request_type_fullfill_allocmem_t const mk_lib_vc_request_type_fullfill_allocmem_ct;
typedef mk_lib_vc_request_type_fullfill_allocmem_t* mk_lib_vc_request_type_fullfill_allocmem_pt;
typedef mk_lib_vc_request_type_fullfill_allocmem_t const* mk_lib_vc_request_type_fullfill_allocmem_pct;

struct mk_lib_vc_request_type_fullfill_readargc_s
{
	mk_lang_types_sint_t m_argc;
};
typedef struct mk_lib_vc_request_type_fullfill_readargc_s mk_lib_vc_request_type_fullfill_readargc_t;
typedef mk_lib_vc_request_type_fullfill_readargc_t const mk_lib_vc_request_type_fullfill_readargc_ct;
typedef mk_lib_vc_request_type_fullfill_readargc_t* mk_lib_vc_request_type_fullfill_readargc_pt;
typedef mk_lib_vc_request_type_fullfill_readargc_t const* mk_lib_vc_request_type_fullfill_readargc_pct;

union mk_lib_vc_request_type_u
{
	mk_lib_vc_request_type_fullfill_allocmem_t m_fullfill_allocmem;
	mk_lib_vc_request_type_fullfill_readargc_t m_fullfill_readargc;
};
typedef union mk_lib_vc_request_type_u mk_lib_vc_request_type_t;
typedef mk_lib_vc_request_type_t const mk_lib_vc_request_type_ct;
typedef mk_lib_vc_request_type_t* mk_lib_vc_request_type_pt;
typedef mk_lib_vc_request_type_t const* mk_lib_vc_request_type_pct;

struct mk_lib_vc_response_type_allocmem_s
{
	mk_lang_types_usize_t m_memlen;
	mk_lang_types_usize_t m_memalign;
};
typedef struct mk_lib_vc_response_type_allocmem_s mk_lib_vc_response_type_allocmem_t;
typedef mk_lib_vc_response_type_allocmem_t const mk_lib_vc_response_type_allocmem_ct;
typedef mk_lib_vc_response_type_allocmem_t* mk_lib_vc_response_type_allocmem_pt;
typedef mk_lib_vc_response_type_allocmem_t const* mk_lib_vc_response_type_allocmem_pct;

struct mk_lib_vc_response_type_freemem_s
{
	mk_lang_types_void_pt m_mem;
	mk_lang_types_usize_t m_memlen;
	mk_lang_types_usize_t m_memalign;
};
typedef struct mk_lib_vc_response_type_freemem_s mk_lib_vc_response_type_freemem_t;
typedef mk_lib_vc_response_type_freemem_t const mk_lib_vc_response_type_freemem_ct;
typedef mk_lib_vc_response_type_freemem_t* mk_lib_vc_response_type_freemem_pt;
typedef mk_lib_vc_response_type_freemem_t const* mk_lib_vc_response_type_freemem_pct;

struct mk_lib_vc_response_type_done_s
{
	mk_lang_types_sint_t m_exit_code;
};
typedef struct mk_lib_vc_response_type_done_s mk_lib_vc_response_type_done_t;
typedef mk_lib_vc_response_type_done_t const mk_lib_vc_response_type_done_ct;
typedef mk_lib_vc_response_type_done_t* mk_lib_vc_response_type_done_pt;
typedef mk_lib_vc_response_type_done_t const* mk_lib_vc_response_type_done_pct;

union mk_lib_vc_response_type_u
{
	mk_lib_vc_response_type_allocmem_t m_allocmem;
	mk_lib_vc_response_type_freemem_t m_freemem;
	mk_lib_vc_response_type_done_t m_done;
};
typedef union mk_lib_vc_response_type_u mk_lib_vc_response_type_t;
typedef mk_lib_vc_response_type_t const mk_lib_vc_response_type_ct;
typedef mk_lib_vc_response_type_t* mk_lib_vc_response_type_pt;
typedef mk_lib_vc_response_type_t const* mk_lib_vc_response_type_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_req(mk_lib_vc_pt const vc, mk_lang_types_uint_t const request, mk_sl_cui_uint8_pct const input_buff, mk_lang_types_usize_t const input_len, mk_lang_types_uint_pt const response, mk_sl_cui_uint8_pt const output_buff, mk_lang_types_usize_pt const output_len) mk_lang_noexcept;
/*mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_init(mk_lib_vc_pt const vc) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_get_write_buff(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pt* const buff, mk_lang_types_usize_t* const buff_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_get_read_buff(mk_lib_vc_pt const vc, mk_sl_cui_uint8_pt* const buff, mk_lang_types_usize_t* const buff_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_push(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_pop(mk_lib_vc_pt const vc, mk_lang_types_usize_t const buff_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lib_vc_result_t mk_lib_vc_step(mk_lib_vc_pt const vc) mk_lang_noexcept;*/


#if mk_lang_jumbo_want == 1
#include "mk_lib_vc.c"
#endif
#endif
