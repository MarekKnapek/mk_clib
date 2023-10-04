#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512.h"
#include "mk_lib_fmt.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"
#include "mk_sl_uint8.h"


enum mk_lib_vc_prf_id_e
{
	mk_lib_vc_prf_id_e_sha2_256,
	mk_lib_vc_prf_id_e_sha2_512,
	mk_lib_vc_prf_id_e_dummy_end
};
typedef enum mk_lib_vc_prf_id_e mk_lib_vc_prf_id_t;

enum mk_lib_vc_alg_id_e
{
	mk_lib_vc_alg_id_e_aes,
	mk_lib_vc_alg_id_e_serpent,
	mk_lib_vc_alg_id_e_dummy_end
};
typedef enum mk_lib_vc_alg_id_e mk_lib_vc_alg_id_t;

enum mk_lib_vc_seq_id_e
{
	mk_lib_vc_seq_id_e_aes,
	mk_lib_vc_seq_id_e_serpent,
	mk_lib_vc_seq_id_e_aes_serpent,
	mk_lib_vc_seq_id_e_dummy_end
};
typedef enum mk_lib_vc_seq_id_e mk_lib_vc_seq_id_t;

#define mk_lib_vc_alg_key_len mk_lang_max(mk_lib_crypto_alg_aes_256_key_len_m, mk_lib_crypto_alg_serpent_key_len_m)
union mk_lib_vc_alg_key_t_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_alg_key_len];
	mk_lib_crypto_alg_aes_256_key_t m_aes;
	mk_lib_crypto_alg_serpent_key_t m_serpent;
};
typedef union mk_lib_vc_alg_key_t_u mk_lib_vc_alg_key_t_t;
typedef mk_lib_vc_alg_key_t_t const mk_lib_vc_alg_key_t_ct;
typedef mk_lib_vc_alg_key_t_t* mk_lib_vc_alg_key_t_pt;
typedef mk_lib_vc_alg_key_t_t const* mk_lib_vc_alg_key_t_pct;

union mk_lib_vc_alg_key_pt_u
{
	mk_lib_crypto_alg_aes_256_key_pt m_aes;
	mk_lib_crypto_alg_serpent_key_pt m_serpent;
};
typedef union mk_lib_vc_alg_key_pt_u mk_lib_vc_alg_key_pt_t;
typedef mk_lib_vc_alg_key_pt_t const mk_lib_vc_alg_key_pt_ct;
typedef mk_lib_vc_alg_key_pt_t* mk_lib_vc_alg_key_pt_pt;
typedef mk_lib_vc_alg_key_pt_t const* mk_lib_vc_alg_key_pt_pct;

union mk_lib_vc_alg_key_pct_u
{
	mk_lib_crypto_alg_aes_256_key_pt m_aes;
	mk_lib_crypto_alg_serpent_key_pt m_serpent;
};
typedef union mk_lib_vc_alg_key_pct_u mk_lib_vc_alg_key_pct_t;
typedef mk_lib_vc_alg_key_pct_t const mk_lib_vc_alg_key_pct_ct;
typedef mk_lib_vc_alg_key_pct_t* mk_lib_vc_alg_key_pct_pt;
typedef mk_lib_vc_alg_key_pct_t const* mk_lib_vc_alg_key_pct_pct;

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

#define mk_lib_vc_salt_len 64
union mk_lib_vc_salt_aligned_u
{
	mk_lang_alignas(mk_lib_vc_salt_len) mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_salt_len];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_vc_salt_aligned_u mk_lib_vc_salt_aligned_t;

struct mk_lib_vc_salt_s
{
	mk_lib_vc_salt_aligned_t m_data;
};
typedef struct mk_lib_vc_salt_s mk_lib_vc_salt_t;
typedef mk_lib_vc_salt_t const mk_lib_vc_salt_ct;
typedef mk_lib_vc_salt_t* mk_lib_vc_salt_pt;
typedef mk_lib_vc_salt_t const* mk_lib_vc_salt_pct;

#define mk_lib_vc_block_len 512
union mk_lib_vc_block_aligned_u
{
	mk_lang_alignas(mk_lib_vc_block_len) mk_sl_cui_uint8_t m_uint8s[mk_lib_vc_block_len];
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


#if defined NDEBUG
#define mk_lib_vc_line 1
#else
#define mk_lib_vc_line __LINE__
#endif
#define mk_lib_vc_check(x) do{ if(!(x)){ mk_lang_unlikely return mk_lib_vc_line; } }while(0)
#define mk_lib_vc_check2(x) do{ mk_lang_types_sint_t err mk_lang_constexpr_init; err = ((mk_lang_types_sint_t)(x)); if(err != 0){ mk_lang_unlikely return err; } }while(0)
#define mk_lib_vc_check_continue(x) if(!(x)){ continue; } ((void)(0))


#include "mk_lib_vc_inl_defd.h"


struct mk_lib_vc_inl_defd_reader_helper_s
{
	mk_lib_vc_seq_id_t m_seq_id;
	mk_lib_vc_inl_defd_reader_pt m_reader_ctx;
	mk_lib_vc_inl_defd_reader_seek_pt m_reader_seek;
	mk_lib_vc_inl_defd_reader_read_pt m_reader_read;
	mk_lib_vc_seq_schedule_t_pct m_schedulea;
	mk_lib_vc_seq_schedule_t_pct m_scheduleb;
	mk_lang_types_ulong_t m_block_idx;
	mk_lib_vc_block_pt m_block;
};
typedef struct mk_lib_vc_inl_defd_reader_helper_s mk_lib_vc_inl_defd_reader_helper_t;
typedef mk_lib_vc_inl_defd_reader_helper_t const mk_lib_vc_inl_defd_reader_helper_ct;
typedef mk_lib_vc_inl_defd_reader_helper_t* mk_lib_vc_inl_defd_reader_helper_pt;
typedef mk_lib_vc_inl_defd_reader_helper_t const* mk_lib_vc_inl_defd_reader_helper_pct;


#define mk_lang_memcpy_obj_tn mk_lib_vc_inl_defd_prefix
#define mk_lang_memcpy_obj_t mk_sl_cui_uint8_t
#include "mk_lang_memcpy_obj_inl_fileh.h"
#include "mk_lang_memcpy_obj_inl_filec.h"
#define mk_lib_vc_seq_memcpy mk_lang_concat(mk_lang_memcpy_obj_, mk_lib_vc_inl_defd_prefix)

#define mk_lib_crypto_mode_base_t_name mk_lang_concat(mk_lib_vc_inl_defd_prefix, _aes)
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_alg_aes_256_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_vc_xor2_aes mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_, mk_lang_concat(mk_lib_vc_inl_defd_prefix, _aes)), _xor2)

#define mk_lib_crypto_mode_base_t_name mk_lang_concat(mk_lib_vc_inl_defd_prefix, _serpent)
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_alg_serpent_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_vc_xor2_serpent mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_, mk_lang_concat(mk_lib_vc_inl_defd_prefix, _serpent)), _xor2)


mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_schedule_encrypt(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_schedule_pct_t const schedule, mk_lib_vc_alg_msg_t_pct const input, mk_lib_vc_alg_msg_t_pt const output) mk_lang_noexcept
{
	mk_lang_assert(input);
	mk_lang_assert(output);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_lang_assert(schedule.m_aes    ); mk_lib_crypto_alg_aes_256_schedule_encrypt(schedule.m_aes    , &input->m_aes    , &output->m_aes    ); break;
		case mk_lib_vc_alg_id_e_serpent: mk_lang_assert(schedule.m_serpent); mk_lib_crypto_alg_serpent_schedule_encrypt(schedule.m_serpent, &input->m_serpent, &output->m_serpent); break;
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
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_msg_xor_2(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_msg_t_pt const a, mk_lib_vc_alg_msg_t_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_lib_vc_xor2_aes    (&a->m_aes    .m_data.m_uint8s[0], &b->m_aes    .m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_serpent: mk_lib_vc_xor2_serpent(&a->m_serpent.m_data.m_uint8s[0], &b->m_serpent.m_data.m_uint8s[0]); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_idx_to_tweak(mk_lib_vc_alg_id_t const alg_id, mk_lang_types_ulong_t const block_idx, mk_lib_vc_alg_msg_t_pt const tweak) mk_lang_noexcept
{
	mk_sl_cui_uint128_t u128 mk_lang_constexpr_init;

	mk_lang_assert(tweak);

	mk_sl_cui_uint128_from_bi_ulong(&u128, &block_idx);
	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : mk_sl_uint_128_to_8_le(&u128, &tweak->m_aes    .m_data.m_uint8s[0]); break;
		case mk_lib_vc_alg_id_e_serpent: mk_sl_uint_128_to_8_le(&u128, &tweak->m_serpent.m_data.m_uint8s[0]); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_xts_tweak_shift(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_msg_t_pt const tweak) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint8_t const s_carry = mk_sl_cui_uint8_c(0x87);

	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_vc_alg_msg_t_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t carry_a mk_lang_constexpr_init;
	mk_sl_cui_uint8_t carry_b mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_v == 128 / mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_v == 128 / mk_lang_charbit);

	mk_lang_assert(tweak);

	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ ta.m_uint8s[i] = tweak->m_aes    .m_data.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ ta.m_uint8s[i] = tweak->m_serpent.m_data.m_uint8s[i]; } break;
		default: mk_lang_assert(0); break;
	}
	mk_sl_cui_uint8_set_zero(&carry_a);
	for(i = 0; i != mk_lib_vc_alg_msg_len; ++i)
	{
		mk_sl_cui_uint8_shr3(&ta.m_uint8s[i], 7, &carry_b);
		mk_sl_cui_uint8_shl2(&ta.m_uint8s[i], 1);
		mk_sl_cui_uint8_or2(&ta.m_uint8s[i], &carry_a);
		carry_a = carry_b;
	}
	tb = s_carry;
	if(!mk_sl_cui_uint8_is_zero(&carry_b))
	{
		mk_sl_cui_uint8_xor2(&ta.m_uint8s[0], &tb);
	}
	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ tweak->m_aes    .m_data.m_uint8s[i] = ta.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ tweak->m_serpent.m_data.m_uint8s[i] = ta.m_uint8s[i]; } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_to_msgs(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_block_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_vc_block_len % mk_lib_crypto_alg_aes_256_msg_len_v) == 0);
	mk_lang_static_assert((mk_lib_vc_block_len % mk_lib_crypto_alg_serpent_msg_len_v) == 0);

	mk_lang_assert(input);
	mk_lang_assert(output);

	tb = *input;
	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_alg_msgs[i / mk_lib_crypto_alg_aes_256_msg_len_v].m_aes    .m_data.m_uint8s[i % mk_lib_crypto_alg_aes_256_msg_len_v] = tb.m_data.m_uint8s[i]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_alg_msgs[i / mk_lib_crypto_alg_serpent_msg_len_v].m_serpent.m_data.m_uint8s[i % mk_lib_crypto_alg_serpent_msg_len_v] = tb.m_data.m_uint8s[i]; } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_block_from_msgs(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_block_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_vc_block_len % mk_lib_crypto_alg_aes_256_msg_len_v) == 0);
	mk_lang_static_assert((mk_lib_vc_block_len % mk_lib_crypto_alg_serpent_msg_len_v) == 0);

	mk_lang_assert(input);
	mk_lang_assert(output);

	tb = *input;
	switch(alg_id)
	{
		case mk_lib_vc_alg_id_e_aes    : for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_uint8s[i] = tb.m_data.m_alg_msgs[i / mk_lib_crypto_alg_aes_256_msg_len_v].m_aes    .m_data.m_uint8s[i % mk_lib_crypto_alg_aes_256_msg_len_v]; } break;
		case mk_lib_vc_alg_id_e_serpent: for(i = 0; i != mk_lib_vc_block_len; ++i){ output->m_data.m_uint8s[i] = tb.m_data.m_alg_msgs[i / mk_lib_crypto_alg_serpent_msg_len_v].m_serpent.m_data.m_uint8s[i % mk_lib_crypto_alg_serpent_msg_len_v]; } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_alg_xts_decrypt_block(mk_lib_vc_alg_id_t const alg_id, mk_lib_vc_alg_schedule_pct_t const schedulea, mk_lib_vc_alg_schedule_pct_t const scheduleb, mk_lang_types_ulong_t const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_alg_msg_t_t tweak mk_lang_constexpr_init;
	mk_lib_vc_alg_msg_t_pt msg mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_m == mk_lib_vc_alg_msg_len);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_m == mk_lib_vc_alg_msg_len);
	mk_lang_static_assert((mk_lib_vc_block_len % mk_lib_vc_alg_msg_len) == 0);

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

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block_aes(mk_lib_vc_seq_schedule_pct_t const schedulea, mk_lib_vc_seq_schedule_pct_t const scheduleb, mk_lang_types_ulong_t const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_alg_id_t alg_id mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t scha mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t schb mk_lang_constexpr_init;

	alg_id = mk_lib_vc_alg_id_e_aes;
	scha.m_aes = schedulea.m_aes;
	schb.m_aes = scheduleb.m_aes;
	mk_lib_vc_alg_xts_decrypt_block(alg_id, scha, schb, block_idx, input, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block_serpent(mk_lib_vc_seq_schedule_pct_t const schedulea, mk_lib_vc_seq_schedule_pct_t const scheduleb, mk_lang_types_ulong_t const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_alg_id_t alg_id mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t scha mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_pct_t schb mk_lang_constexpr_init;

	alg_id = mk_lib_vc_alg_id_e_serpent;
	scha.m_serpent = schedulea.m_serpent;
	schb.m_serpent = scheduleb.m_serpent;
	mk_lib_vc_alg_xts_decrypt_block(alg_id, scha, schb, block_idx, input, output);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block_aes_serpent(mk_lib_vc_seq_schedule_pct_t const schedulea, mk_lib_vc_seq_schedule_pct_t const scheduleb, mk_lang_types_ulong_t const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_xts_decrypt_block(mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_schedule_t_pct const schedulea, mk_lib_vc_seq_schedule_t_pct const scheduleb, mk_lang_types_ulong_t const block_idx, mk_lib_vc_block_pct const input, mk_lib_vc_block_pt const output) mk_lang_noexcept
{
	mk_lib_vc_seq_schedule_pct_t scha mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_pct_t schb mk_lang_constexpr_init;

	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes        : scha.m_aes         = &schedulea->m_aes        ; schb.m_aes         = &scheduleb->m_aes        ; mk_lib_vc_seq_xts_decrypt_block_aes        (scha, schb, block_idx, input, output); break;
		case mk_lib_vc_seq_id_e_serpent    : scha.m_serpent     = &schedulea->m_serpent    ; schb.m_serpent     = &scheduleb->m_serpent    ; mk_lib_vc_seq_xts_decrypt_block_serpent    (scha, schb, block_idx, input, output); break;
		case mk_lib_vc_seq_id_e_aes_serpent: scha.m_aes_serpent = &schedulea->m_aes_serpent; schb.m_aes_serpent = &scheduleb->m_aes_serpent; mk_lib_vc_seq_xts_decrypt_block_aes_serpent(scha, schb, block_idx, input, output); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_vc_inl_defd_reader_helper_read(mk_lib_vc_inl_defd_reader_helper_pt const reader, mk_lang_types_ulong_t const offset, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const dst) mk_lang_noexcept
{
	mk_lang_types_ulong_t offset_a mk_lang_constexpr_init;
	mk_lang_types_usize_t len_a mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt dst_a mk_lang_constexpr_init;
	mk_lang_types_ulong_t block_idx mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_usize_t tus mk_lang_constexpr_init;
	mk_lang_types_sint_t offset_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;

	mk_lang_assert(reader);
	mk_lang_assert(offset >= mk_lib_vc_salt_len);
	mk_lang_assert(dst);

	offset_a = offset - mk_lib_vc_salt_len;
	len_a = len;
	dst_a = dst;
	block_idx = offset_a / mk_lib_vc_block_len;
	while(len_a != 0)
	{
		if(reader->m_block_idx != block_idx)
		{
			if(reader->m_block_idx + 1 != block_idx)
			{
				tsi = reader->m_reader_seek(reader->m_reader_ctx, mk_lib_vc_salt_len + block_idx * mk_lib_vc_block_len); mk_lib_vc_check2(tsi);
			}
			reader->m_block_idx = block_idx;
			tus = reader->m_reader_read(reader->m_reader_ctx, mk_lib_vc_block_len, &reader->m_block->m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_block_len);
			mk_lib_vc_seq_xts_decrypt_block(reader->m_seq_id, reader->m_schedulea, reader->m_scheduleb, reader->m_block_idx, reader->m_block, reader->m_block);
		}
		offset_b = ((mk_lang_types_sint_t)(offset_a % mk_lib_vc_block_len));
		len_b = ((mk_lang_types_sint_t)(mk_lang_min(len_a, ((mk_lang_types_usize_t)(mk_lib_vc_block_len - offset_b)))));
		mk_lib_vc_seq_memcpy(dst_a, &reader->m_block->m_data.m_uint8s[offset_b], len_b);
		offset_a += len_b;
		len_a -= len_b;
		dst_a += len_b;
	}
	return 0;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_expand_enc(mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_key_t_pct const key, mk_lib_vc_seq_schedule_t_pt const schedule) mk_lang_noexcept
{
	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes: mk_lib_crypto_alg_aes_256_expand_enc(&key->m_aes, &schedule->m_aes); break;
		case mk_lib_vc_seq_id_e_serpent: mk_lib_crypto_alg_serpent_expand_enc(&key->m_serpent, &schedule->m_serpent); break;
		case mk_lib_vc_seq_id_e_aes_serpent: mk_lib_crypto_alg_aes_256_expand_enc(&key->m_aes_serpent.m_aes, &schedule->m_aes_serpent.m_aes); mk_lib_crypto_alg_serpent_expand_enc(&key->m_aes_serpent.m_serpent, &schedule->m_aes_serpent.m_serpent); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_seq_expand_dec(mk_lib_vc_seq_id_t const seq_id, mk_lib_vc_seq_key_t_pct const key, mk_lib_vc_seq_schedule_t_pt const schedule) mk_lang_noexcept
{
	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes: mk_lib_crypto_alg_aes_256_expand_dec(&key->m_aes, &schedule->m_aes); break;
		case mk_lib_vc_seq_id_e_serpent: mk_lib_crypto_alg_serpent_expand_dec(&key->m_serpent, &schedule->m_serpent); break;
		case mk_lib_vc_seq_id_e_aes_serpent: mk_lib_crypto_alg_aes_256_expand_dec(&key->m_aes_serpent.m_aes, &schedule->m_aes_serpent.m_aes); mk_lib_crypto_alg_serpent_expand_dec(&key->m_aes_serpent.m_serpent, &schedule->m_aes_serpent.m_serpent); break;
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
		case mk_lib_vc_seq_id_e_aes: mk_lib_vc_seq_memcpy(&key->m_aes.m_data.m_uint8s[0], &keys_data[idx * mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_aes_256_key_len_v); break;
		case mk_lib_vc_seq_id_e_serpent: mk_lib_vc_seq_memcpy(&key->m_serpent.m_data.m_uint8s[0], &keys_data[idx * mk_lib_crypto_alg_serpent_key_len_v], mk_lib_crypto_alg_serpent_key_len_v); break;
		case mk_lib_vc_seq_id_e_aes_serpent: mk_lib_vc_seq_memcpy(&key->m_aes_serpent.m_aes.m_data.m_uint8s[0], &keys_data[idx * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v); mk_lib_vc_seq_memcpy(&key->m_aes_serpent.m_serpent.m_data.m_uint8s[0], &keys_data[idx * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v) + mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_serpent_key_len_v); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_pchar_pct mk_lib_vc_seq_get_name(mk_lib_vc_seq_id_t const seq_id) mk_lang_noexcept
{
	switch(seq_id)
	{
		case mk_lib_vc_seq_id_e_aes: return "AES"; break;
		case mk_lib_vc_seq_id_e_serpent: return "Serpent"; break;
		case mk_lib_vc_seq_id_e_aes_serpent: return "Serpent(AES)"; break;
		default: mk_lang_assert(0); break;
	}
	return mk_lang_null;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_pbkdf2(mk_lib_vc_prf_id_t const prf_id, mk_sl_cui_uint8_pct const password, int const password_len, mk_sl_cui_uint8_pct const salt, int const slt_len, mk_lang_types_ulong_t const cost, int const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	switch(prf_id)
	{
		case mk_lib_vc_prf_id_e_sha2_256: mk_lib_crypto_kdf_pbkdf2_sha2_256_u8(password, password_len, salt, slt_len, cost, key_len, key); break;
		case mk_lib_vc_prf_id_e_sha2_512: mk_lib_crypto_kdf_pbkdf2_sha2_512_u8(password, password_len, salt, slt_len, cost, key_len, key); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_pchar_pct mk_lib_vc_prf_get_name(mk_lib_vc_prf_id_t const prf_id) mk_lang_noexcept
{
	switch(prf_id)
	{
		case mk_lib_vc_prf_id_e_sha2_256: return mk_lib_crypto_hash_block_sha2_256_name_str; break;
		case mk_lib_vc_prf_id_e_sha2_512: return mk_lib_crypto_hash_block_sha2_512_name_str; break;
		default: mk_lang_assert(0); break;
	}
	return mk_lang_null;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_inl_defd_decrypt_singlethreaded(mk_lib_vc_seq_id_t const seq_id, mk_sl_cui_uint64_pct const size_volume, mk_lib_vc_seq_schedule_t_pct const master_schedulea, mk_lib_vc_seq_schedule_t_pct const master_scheduleb, mk_lib_vc_inl_defd_reader_pt const reader_ctx, mk_lib_vc_inl_defd_reader_read_pt const reader_read, mk_lib_vc_inl_defd_writer_pt const writer_ctx, mk_lib_vc_inl_defd_writer_write_pt const writer_write) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t block_idx mk_lang_constexpr_init;
	mk_sl_cui_uint64_t n mk_lang_constexpr_init;
	mk_sl_cui_uint64_t i mk_lang_constexpr_init;
	mk_lib_vc_block_t block mk_lang_constexpr_init;
	mk_lang_types_usize_t tus mk_lang_constexpr_init;
	mk_lang_types_ulong_t block_idx_ mk_lang_constexpr_init;

	mk_lang_assert(size_volume);
	mk_lang_assert(master_schedulea);
	mk_lang_assert(master_scheduleb);
	mk_lang_assert(reader_ctx);
	mk_lang_assert(reader_read);
	mk_lang_assert(writer_ctx);
	mk_lang_assert(writer_write);

	tsi = mk_lib_vc_data_offset / mk_lib_vc_block_len;
	mk_sl_cui_uint64_from_bi_sint(&block_idx, &tsi);
	tsi = mk_lib_vc_block_len;
	mk_sl_cui_uint64_from_bi_sint(&n, &tsi);
	mk_sl_cui_uint64_div3_wrap(size_volume, &n, &n);
	for(mk_sl_cui_uint64_set_zero(&i); mk_sl_cui_uint64_ne(&i, &n); mk_sl_cui_uint64_inc1(&i), mk_sl_cui_uint64_inc1(&block_idx))
	{
		tus = reader_read(reader_ctx, mk_lib_vc_block_len, &block.m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_block_len);
		mk_sl_cui_uint64_to_bi_ulong(&block_idx, &block_idx_); /* todo convert to 64bit */
		mk_lib_vc_seq_xts_decrypt_block(seq_id, master_schedulea, master_scheduleb, block_idx_, &block, &block);
		tus = writer_write(writer_ctx, mk_lib_vc_block_len, &block.m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_block_len);
	}
	return 0;
}

#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14

#define mk_lib_vc_chunk_size (4 * 1024)
#define mk_lib_vc_chunk_count (1 * 1024)

struct mk_lib_vc_chunk_data_s
{
	mk_lib_vc_block_t m_blocks[mk_lib_vc_chunk_size / mk_lib_vc_block_len];
};
typedef struct mk_lib_vc_chunk_data_s mk_lib_vc_chunk_data_t;
typedef mk_lib_vc_chunk_data_t const mk_lib_vc_chunk_data_ct;
typedef mk_lib_vc_chunk_data_t* mk_lib_vc_chunk_data_pt;
typedef mk_lib_vc_chunk_data_t const* mk_lib_vc_chunk_data_pct;

struct mk_lib_vc_chunk_info_s
{
	int m_chunk_id;
	mk_lang_types_ulong_t m_chunk_idx;
};
typedef struct mk_lib_vc_chunk_info_s mk_lib_vc_chunk_info_t;
typedef mk_lib_vc_chunk_info_t const mk_lib_vc_chunk_info_ct;
typedef mk_lib_vc_chunk_info_t* mk_lib_vc_chunk_info_pt;
typedef mk_lib_vc_chunk_info_t const* mk_lib_vc_chunk_info_pct;

#include "mk_lang_exception.h"
#include "mk_lib_cpp_tl_ring.hpp"
#include "mk_sl_mallocator_lang.h"

#define mk_sl_ring_t_name mk_lib_vc
#define mk_sl_ring_t_elem_t mk_lib_vc_chunk_info_t
#define mk_sl_ring_t_capacity mk_lib_vc_chunk_count
#include "mk_sl_ring_inl_fileh.h"
#include "mk_sl_ring_inl_filec.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <thread>

typedef mk::tl::ring_t
<
	mk::wrapper::ring_t
	<
		mk_sl_ring_mk_lib_vc_t,
		mk_lib_vc_chunk_info_t,
		&mk_sl_ring_mk_lib_vc_ro_is_empty,
		&mk_sl_ring_mk_lib_vc_ro_is_full,
		&mk_sl_ring_mk_lib_vc_ro_get_size,
		&mk_sl_ring_mk_lib_vc_ro_get_capacity,
		&mk_sl_ring_mk_lib_vc_ro_get_free,
		&mk_sl_ring_mk_lib_vc_ro_get_elem,
		&mk_sl_ring_mk_lib_vc_ro_get_head,
		&mk_sl_ring_mk_lib_vc_ro_get_tail,
		&mk_sl_ring_mk_lib_vc_rw_is_empty,
		&mk_sl_ring_mk_lib_vc_rw_is_full,
		&mk_sl_ring_mk_lib_vc_rw_get_size,
		&mk_sl_ring_mk_lib_vc_rw_get_capacity,
		&mk_sl_ring_mk_lib_vc_rw_get_free,
		&mk_sl_ring_mk_lib_vc_rw_get_elem,
		&mk_sl_ring_mk_lib_vc_rw_get_head,
		&mk_sl_ring_mk_lib_vc_rw_get_tail,
		&mk_sl_ring_mk_lib_vc_rw_construct,
		&mk_sl_ring_mk_lib_vc_rw_push_void,
		&mk_sl_ring_mk_lib_vc_rw_push_elem,
		&mk_sl_ring_mk_lib_vc_rw_pop
	>
>
mk_lib_vc_ring_t;
typedef mk_lib_vc_ring_t const mk_lib_vc_ring_ct;
typedef mk_lib_vc_ring_t* mk_lib_vc_ring_pt;
typedef mk_lib_vc_ring_t const* mk_lib_vc_ring_pct;

typedef std::array<mk_lib_vc_chunk_data_t, mk_lib_vc_chunk_count> mk_lib_vc_chunks_t;
typedef mk_lib_vc_chunks_t* mk_lib_vc_chunks_pt;

typedef std::array<mk_lib_vc_chunk_info_t, mk_lib_vc_chunk_count> mk_lib_vc_chunk_infos_t;
typedef mk_lib_vc_chunk_infos_t* mk_lib_vc_chunk_infos_pt;

	struct mk_lib_vc_thread_param_s
{
	std::atomic<bool>* m_keep_running;
	mk_lib_vc_seq_id_t m_seq_id;
	mk_lib_vc_seq_schedule_t_pct m_master_schedulea;
	mk_lib_vc_seq_schedule_t_pct m_master_scheduleb;
	mk_lib_vc_chunks_pt m_chunks;
	mk_lib_vc_ring_pt m_ring_crypt;
	mk_lib_vc_ring_pt m_ring_io;
};
typedef struct mk_lib_vc_thread_param_s mk_lib_vc_thread_param_t;
typedef mk_lib_vc_thread_param_t const mk_lib_vc_thread_param_ct;
typedef mk_lib_vc_thread_param_t* mk_lib_vc_thread_param_pt;
typedef mk_lib_vc_thread_param_t const* mk_lib_vc_thread_param_pct;

static mk_lang_inline void mk_lib_vc_thread_process_chunk(mk_lib_vc_thread_param_pt const param, mk_lib_vc_chunk_info_t const chunk_info) mk_lang_noexcept
{
	mk_lang_types_ulong_t blocks_per_chunk;
	mk_lang_types_ulong_t msgs_per_block;
	mk_lang_types_ulong_t block_idx;
	mk_lang_types_ulong_t iblock;
	mk_lib_vc_block_pt output;
	mk_lib_vc_block_pct input;

	mk_lang_static_assert((mk_lib_vc_chunk_size >= mk_lib_vc_block_len) && ((mk_lib_vc_chunk_size % mk_lib_vc_block_len) == 0));
	mk_lang_static_assert((mk_lib_vc_data_offset >= mk_lib_vc_block_len) && ((mk_lib_vc_data_offset % mk_lib_vc_block_len) ==0 ));
	mk_lang_static_assert((mk_lib_vc_block_len >= mk_lib_vc_seq_msg_len) && ((mk_lib_vc_block_len % mk_lib_vc_seq_msg_len) == 0));

	mk_lang_assert(param);

	blocks_per_chunk = (mk_lib_vc_chunk_size / mk_lib_vc_block_len);
	msgs_per_block = (mk_lib_vc_block_len / mk_lib_vc_seq_msg_len);
	block_idx = (mk_lib_vc_data_offset / mk_lib_vc_block_len) + (chunk_info.m_chunk_idx * blocks_per_chunk);
	for(iblock = 0; iblock != blocks_per_chunk; ++iblock, ++block_idx)
	{
		output = &(*param->m_chunks)[chunk_info.m_chunk_id].m_blocks[iblock];
		input = output;
		mk_lib_vc_seq_xts_decrypt_block(param->m_seq_id, param->m_master_schedulea, param->m_master_scheduleb, block_idx, input, output);
	}
	param->m_ring_io->push(chunk_info);
}

static mk_lang_inline void mk_lib_vc_thread_proc(mk_lib_vc_thread_param_pt const param) mk_lang_noexcept
{
	mk_lib_vc_chunk_info_t chunk_info;

	mk_lang_assert(param);
	mk_lang_assert(param->m_keep_running);
	mk_lang_assert(param->m_master_schedulea);
	mk_lang_assert(param->m_master_scheduleb);
	mk_lang_assert(param->m_chunks);
	mk_lang_assert(param->m_ring_crypt);
	mk_lang_assert(param->m_ring_io);

	for(;;)
	{
		chunk_info = param->m_ring_crypt->pop();
		if(!param->m_keep_running->load(std::memory_order_relaxed))
		{
			break;
		}
		mk_lib_vc_thread_process_chunk(param, chunk_info);
	}
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_inl_defd_decrypt_multithreaded(mk_lib_vc_seq_id_t const seq_id, mk_sl_cui_uint64_pct const size_volume, mk_lib_vc_seq_schedule_t_pct const master_schedulea, mk_lib_vc_seq_schedule_t_pct const master_scheduleb, mk_lib_vc_inl_defd_reader_pt const reader_ctx, mk_lib_vc_inl_defd_reader_read_pt const reader_read, mk_lib_vc_inl_defd_writer_pt const writer_ctx, mk_lib_vc_inl_defd_writer_write_pt const writer_write) mk_lang_noexcept
{
	struct big_things_s
	{
		mk_lib_vc_chunks_t m_chunks;
		mk_lib_vc_ring_t m_ring_crypt;
		mk_lib_vc_ring_t m_ring_io;
		mk_lib_vc_chunk_infos_t m_chunk_infos;
	};
	typedef struct big_things_s big_things_t;
	typedef big_things_t const big_things_ct;
	typedef big_things_t* big_things_pt;
	typedef big_things_t const* big_things_pct;

	mk_lang_types_slong_t tsl;
	mk_sl_cui_uint64_t tu64;
	mk_lang_exception_t ex;
	big_things_pt big_things;
	mk_lib_vc_chunks_pt chunks;
	mk_lib_vc_ring_pt ring_crypt;
	mk_lib_vc_ring_pt ring_io;
	mk_lib_vc_chunk_infos_pt chunk_infos;
	std::atomic<bool> keep_running;
	mk_lib_vc_thread_param_t param;
	mk_lang_types_uint_t hw_threads;
	std::thread* threads;
	mk_lang_types_uint_t ihw_thread;
	mk_lang_types_ulong_t size_volume_ul;
	mk_lang_types_ulong_t nchunks_actual;
	mk_lang_types_ulong_t nchunks_min;
	mk_lang_types_ulong_t ichunk;
	mk_lang_types_ulong_t chunk_idx_to_write;
	mk_lang_types_usize_t tus;
	mk_lib_vc_chunk_info_t chunk_info;
	mk_lang_types_sint_t chunk_infos_cnt;

	mk_lang_assert(size_volume);
	mk_lang_assert(master_schedulea);
	mk_lang_assert(master_scheduleb);
	mk_lang_assert(reader_ctx);
	mk_lang_assert(reader_read);
	mk_lang_assert(writer_ctx);
	mk_lang_assert(writer_write);

	tsl = mk_lang_limits_slong_max;
	mk_sl_cui_uint64_from_bi_slong(&tu64, &tsl);
	mk_lang_assert(mk_sl_cui_uint64_le(size_volume, &tu64));
	tsl = mk_lib_vc_chunk_size;
	mk_sl_cui_uint64_from_bi_slong(&tu64, &tsl);
	mk_lang_assert(mk_sl_cui_uint64_ge(size_volume, &tu64));
	mk_sl_cui_uint64_mod3_wrap(size_volume, &tu64, &tu64);
	mk_lang_assert(mk_sl_cui_uint64_is_zero(&tu64));
	mk_lang_exception_make_none(&ex);
	mk_sl_mallocator_lang_allocate(&ex, sizeof(*big_things), ((void**)(&big_things))); mk_lib_vc_check(!mk_lang_exception_is(&ex)); mk_lang_assert(big_things);
	chunks = &big_things->m_chunks;
	ring_crypt = &big_things->m_ring_crypt;
	ring_io = &big_things->m_ring_io;
	chunk_infos = &big_things->m_chunk_infos;
	::new(chunks)(mk_lib_vc_chunks_t);
	::new(ring_crypt)(mk_lib_vc_ring_t);
	::new(ring_io)(mk_lib_vc_ring_t);
	::new(chunk_infos)(mk_lib_vc_chunk_infos_t);
	keep_running.store(true);
	param.m_keep_running = &keep_running;
	param.m_seq_id = seq_id;
	param.m_master_schedulea = master_schedulea;
	param.m_master_scheduleb = master_scheduleb;
	param.m_chunks = chunks;
	param.m_ring_crypt = ring_crypt;
	param.m_ring_io = ring_io;
	hw_threads = std::thread::hardware_concurrency(); mk_lib_vc_check(hw_threads != 0);
	mk_sl_mallocator_lang_allocate(&ex, hw_threads * sizeof(*threads), ((void**)(&threads))); mk_lib_vc_check(!mk_lang_exception_is(&ex)); mk_lang_assert(threads);
	for(ihw_thread = 0; ihw_thread != hw_threads; ++ihw_thread)
	{
		::new(&threads[ihw_thread])(std::thread)(&mk_lib_vc_thread_proc, &param);
	}
	mk_sl_cui_uint64_to_bi_ulong(size_volume, &size_volume_ul);
	nchunks_actual = size_volume_ul / mk_lib_vc_chunk_size;
	nchunks_min = mk_lang_min(mk_lib_vc_chunk_count, nchunks_actual);
	for(ichunk = 0; ichunk != nchunks_min; ++ichunk)
	{
		tus = reader_read(reader_ctx, mk_lib_vc_chunk_size, &(*chunks)[ichunk].m_blocks[0].m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_chunk_size);
		chunk_info.m_chunk_id = ((int)(ichunk));
		chunk_info.m_chunk_idx = ichunk;
		ring_crypt->push(chunk_info);
	}
	chunk_infos_cnt = 0;
	for(; ichunk != nchunks_actual; ++ichunk)
	{
		chunk_idx_to_write = ichunk - nchunks_min;
		auto const f = std::find_if(std::begin(*chunk_infos), std::begin(*chunk_infos) + chunk_infos_cnt, [&](mk_lib_vc_chunk_info_t const& ci){ return ci.m_chunk_idx == chunk_idx_to_write; });
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
		tus = writer_write(writer_ctx, mk_lib_vc_chunk_size, &(*chunks)[chunk_info.m_chunk_id].m_blocks[0].m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_chunk_size);
		tus = reader_read(reader_ctx, mk_lib_vc_chunk_size, &(*chunks)[chunk_info.m_chunk_id].m_blocks[0].m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_chunk_size);
		chunk_info.m_chunk_idx = ichunk;
		ring_crypt->push(chunk_info);
	}
	for(; ichunk != nchunks_actual + nchunks_min; ++ichunk)
	{
		chunk_idx_to_write = ichunk - nchunks_min;
		auto const f = std::find_if(std::begin(*chunk_infos), std::begin(*chunk_infos) + chunk_infos_cnt, [&](mk_lib_vc_chunk_info_t const& ci){ return ci.m_chunk_idx == chunk_idx_to_write; });
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
		tus = writer_write(writer_ctx, mk_lib_vc_chunk_size, &(*chunks)[chunk_info.m_chunk_id].m_blocks[0].m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_chunk_size);
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
	chunks->~mk_lib_vc_chunks_t();
	ring_crypt->~mk_lib_vc_ring_t();
	ring_io->~mk_lib_vc_ring_t();
	chunk_infos->~mk_lib_vc_chunk_infos_t();
	mk_sl_mallocator_lang_deallocate(big_things, sizeof(*big_things));
	return EXIT_SUCCESS;
}

#endif

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_inl_defd_decrypt(mk_lib_vc_inl_defd_reader_pt const reader_ctx, mk_lib_vc_inl_defd_reader_seek_pt const reader_seek, mk_lib_vc_inl_defd_reader_read_pt const reader_read, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lang_types_ulong_t const pim, mk_lib_vc_logger_ctx_pt const logger_ctx, mk_lib_vc_logger_fnc_pt const logger_fnc, mk_lib_vc_inl_defd_writer_pt const writer_ctx, mk_lib_vc_inl_defd_writer_write_pt const writer_write) mk_lang_noexcept
{
	mk_lang_types_usize_t tus mk_lang_constexpr_init;
	mk_lib_vc_salt_t salt mk_lang_constexpr_init;
	mk_lang_types_ulong_t cost mk_lang_constexpr_init;
	mk_lib_vc_prf_id_t prf_id mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint8_t keys_data[2 * mk_lib_vc_seq_key_len] mk_lang_constexpr_init;
	mk_lib_vc_seq_id_t seq_id mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t keya mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t keyb mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t schedulea mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t scheduleb mk_lang_constexpr_init;
	mk_lib_vc_inl_defd_reader_helper_t reader mk_lang_constexpr_init;
	mk_lib_vc_block_t block mk_lang_constexpr_init;
	mk_sl_cui_uint8_t magic_bytes[mk_lib_vc_magic_len] mk_lang_constexpr_init;
	mk_lang_types_pchar_t tpc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ver_bytes[mk_lib_vc_ver_len] mk_lang_constexpr_init;
	mk_sl_cui_uint16_t ver mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_sl_cui_uint8_t min_ver_maj_bytes[mk_lib_vc_min_ver_maj_len] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t min_ver_maj mk_lang_constexpr_init;
	mk_sl_cui_uint8_t min_ver_min_bytes[mk_lib_vc_min_ver_min_len] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t min_ver_min mk_lang_constexpr_init;
	mk_sl_cui_uint8_t size_volume_bytes[mk_lib_vc_size_volume_len] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t size_volume mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64 mk_lang_constexpr_init;
	mk_lang_types_slong_t tsl mk_lang_constexpr_init;
	mk_sl_cui_uint8_t master_key_scope1_bytes[mk_lib_vc_master_key_scope1_len] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t master_key_scope1 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_sl_cui_uint8_t master_key_scope2_bytes[mk_lib_vc_master_key_scope2_len] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t master_key_scope2 mk_lang_constexpr_init;
	mk_sl_cui_uint8_t sector_size_bytes[mk_lib_vc_sector_size_len] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t sector_size mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t master_keya mk_lang_constexpr_init;
	mk_lib_vc_seq_key_t_t master_keyb mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t master_schedulea mk_lang_constexpr_init;
	mk_lib_vc_seq_schedule_t_t master_scheduleb mk_lang_constexpr_init;
	mk_lang_types_bool_t tba mk_lang_constexpr_init;
	mk_lang_types_bool_t tbb mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_vc_block_len >= mk_lib_vc_seq_msg_len) && ((mk_lib_vc_block_len % mk_lib_vc_seq_msg_len) == 0));

	mk_lang_assert(reader_seek);
	mk_lang_assert(reader_read);
	mk_lang_assert(password);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(writer_write);

	tus = reader_read(reader_ctx, mk_lib_vc_salt_len, &salt.m_data.m_uint8s[0]); mk_lib_vc_check(tus == mk_lib_vc_salt_len);
	cost = (pim == 0ul) ? (500ul * 1000ul) : ((15ul * 1000ul) + (pim * (1ul * 1000ul)));
	for(prf_id = ((mk_lib_vc_prf_id_t)(0)); prf_id != mk_lib_vc_prf_id_e_dummy_end; prf_id = ((mk_lib_vc_prf_id_t)(((mk_lang_types_sint_t)(prf_id)) + 1)))
	{
		if(logger_fnc)
		{
			mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
			tsi = mk_lib_fmt_sprintf(&buff[0], "Deriving keys from salt, password and PIM using the %s algorithm.\n", mk_lib_vc_prf_get_name(prf_id)); mk_lib_vc_check(tsi > 0);
			logger_fnc(logger_ctx, &buff[0]);
		}
		mk_lib_vc_pbkdf2(prf_id, password, password_len, &salt.m_data.m_uint8s[0], mk_lib_vc_salt_len, cost, 2 * mk_lib_vc_seq_key_len, &keys_data[0]);
		if(logger_fnc)
		{
			logger_fnc(logger_ctx, "Keys derived.\n");
		}
		for(seq_id = ((mk_lib_vc_seq_id_t)(0)); seq_id != mk_lib_vc_seq_id_e_dummy_end; seq_id = ((mk_lib_vc_seq_id_t)(((mk_lang_types_sint_t)(seq_id)) + 1)))
		{
			if(logger_fnc)
			{
				mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
				tsi = mk_lib_fmt_sprintf(&buff[0], "Trying the %s cipher.\n", mk_lib_vc_seq_get_name(seq_id)); mk_lib_vc_check(tsi > 0);
				logger_fnc(logger_ctx, &buff[0]);
			}
			mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 0, &keya);
			mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 1, &keyb);
			mk_lib_vc_seq_expand_dec(seq_id, &keya, &schedulea);
			mk_lib_vc_seq_expand_enc(seq_id, &keyb, &scheduleb);
			reader.m_seq_id = seq_id;
			reader.m_reader_ctx = reader_ctx;
			reader.m_reader_seek = reader_seek;
			reader.m_reader_read = reader_read;
			reader.m_schedulea = &schedulea;
			reader.m_scheduleb = &scheduleb;
			reader.m_block_idx = 1;
			reader.m_block = &block;
			tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_magic_offset, mk_lib_vc_magic_len, &magic_bytes[0]); mk_lib_vc_check2(tsi);
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[0], &tpc); mk_lib_vc_check_continue(tpc == 'V');
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[1], &tpc); mk_lib_vc_check_continue(tpc == 'E');
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[2], &tpc); mk_lib_vc_check_continue(tpc == 'R');
			mk_sl_cui_uint8_to_bi_pchar(&magic_bytes[3], &tpc); mk_lib_vc_check_continue(tpc == 'A');
			break;
		}
		mk_lib_vc_check_continue(seq_id != mk_lib_vc_seq_id_e_dummy_end);
		break;
	}
	mk_lib_vc_check(prf_id != mk_lib_vc_prf_id_e_dummy_end);
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_ver_offset, mk_lib_vc_ver_len, &ver_bytes[0]); mk_lib_vc_check2(tsi);
	mk_sl_uint_16_from_8_be(&ver, &ver_bytes[0]);
	if(logger_fnc)
	{
		mk_lang_types_pchar_t ver_str[mk_sl_cui_uint16_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint16_to_str_dec_n(&ver, &ver_str[0], mk_sl_cui_uint16_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint16_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], "Volume header format version: %.*s\n", tsi, &ver_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	mk_sl_cui_uint16_to_bi_uint(&ver, &tui);
	mk_lib_vc_check(tui == 5);
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_min_ver_maj_offset, mk_lib_vc_min_ver_maj_len, &min_ver_maj_bytes[0]); mk_lib_vc_check2(tsi);
	min_ver_maj = min_ver_maj_bytes[0];
	if(logger_fnc)
	{
		mk_lang_types_pchar_t min_ver_maj_str[mk_sl_cui_uint8_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint8_to_str_dec_n(&min_ver_maj, &min_ver_maj_str[0], mk_sl_cui_uint8_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint8_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], "Minimum program version required to open the volume: %.*s", tsi, &min_ver_maj_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	mk_sl_cui_uint8_to_bi_sint(&min_ver_maj, &tsi);
	mk_lib_vc_check(tsi == 1);
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_min_ver_min_offset, mk_lib_vc_min_ver_min_len, &min_ver_min_bytes[0]); mk_lib_vc_check2(tsi);
	min_ver_min = min_ver_min_bytes[0];
	if(logger_fnc)
	{
		mk_lang_types_pchar_t min_ver_min_str[mk_sl_cui_uint8_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint8_to_str_dec_n(&min_ver_min, &min_ver_min_str[0], mk_sl_cui_uint8_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint8_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], ".%.*s\n", tsi, &min_ver_min_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	mk_sl_cui_uint8_to_bi_sint(&min_ver_min, &tsi);
	mk_lib_vc_check(tsi == 11);
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_size_volume_offset, mk_lib_vc_size_volume_len, &size_volume_bytes[0]); mk_lib_vc_check2(tsi);
	mk_sl_uint_64_from_8_be(&size_volume, &size_volume_bytes[0]);
	if(logger_fnc)
	{
		mk_lang_types_pchar_t size_volume_str[mk_sl_cui_uint64_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint64_to_str_dec_n(&size_volume, &size_volume_str[0], mk_sl_cui_uint64_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint64_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], "Size of volume: %.*s\n", tsi, &size_volume_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	tsi = mk_lib_vc_block_len;
	mk_sl_cui_uint64_from_bi_sint(&tu64, &tsi);
	mk_sl_cui_uint64_mod3_wrap(&size_volume, &tu64, &tu64);
	mk_lib_vc_check(mk_sl_cui_uint64_is_zero(&tu64));
	tsl = mk_lang_limits_slong_max;
	mk_sl_cui_uint64_from_bi_slong(&tu64, &tsl);
	mk_lib_vc_check(mk_sl_cui_uint64_le(&size_volume, &tu64));
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_master_key_scope1_offset, mk_lib_vc_master_key_scope1_len, &master_key_scope1_bytes[0]); mk_lib_vc_check2(tsi);
	mk_sl_uint_64_from_8_be(&master_key_scope1, &master_key_scope1_bytes[0]);
	if(logger_fnc)
	{
		mk_lang_types_pchar_t master_key_scope1_str[mk_sl_cui_uint64_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint64_to_str_dec_n(&master_key_scope1, &master_key_scope1_str[0], mk_sl_cui_uint64_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint64_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], "Byte offset of the start of the master key scope: %.*s\n", tsi, &master_key_scope1_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	tul = mk_lib_vc_data_offset;
	mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul);
	mk_lib_vc_check(mk_sl_cui_uint64_eq(&master_key_scope1, &tu64));
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_master_key_scope2_offset, mk_lib_vc_master_key_scope2_len, &master_key_scope2_bytes[0]); mk_lib_vc_check2(tsi);
	mk_sl_uint_64_from_8_be(&master_key_scope2, &master_key_scope2_bytes[0]);
	if(logger_fnc)
	{
		mk_lang_types_pchar_t master_key_scope2_str[mk_sl_cui_uint64_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint64_to_str_dec_n(&master_key_scope2, &master_key_scope2_str[0], mk_sl_cui_uint64_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint64_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], "Size of the encrypted area within the master key scope: %.*s\n", tsi, &master_key_scope2_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	mk_lib_vc_check(mk_sl_cui_uint64_eq(&master_key_scope2, &size_volume));
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_sector_size_offset, mk_lib_vc_sector_size_len, &sector_size_bytes[0]); mk_lib_vc_check2(tsi);
	mk_sl_uint_32_from_8_be(&sector_size, &sector_size_bytes[0]);
	if(logger_fnc)
	{
		mk_lang_types_pchar_t sector_size_str[mk_sl_cui_uint32_to_str_dec_len] mk_lang_constexpr_init;
		mk_lang_types_pchar_t buff[128] mk_lang_constexpr_init;
		tsi = mk_sl_cui_uint32_to_str_dec_n(&sector_size, &sector_size_str[0], mk_sl_cui_uint32_to_str_dec_len); mk_lib_vc_check(tsi != 0 && tsi >= 1 && tsi <= mk_sl_cui_uint32_to_str_dec_len);
		tsi = mk_lib_fmt_sprintf(&buff[0], "Sector size: %.*s\n", tsi, &sector_size_str[0]); mk_lib_vc_check(tsi > 0);
		logger_fnc(logger_ctx, &buff[0]);
	}
	mk_sl_cui_uint32_to_bi_ulong(&sector_size, &tul);
	mk_lib_vc_check(tul == mk_lib_vc_block_len);
	tsi = mk_lib_vc_inl_defd_reader_helper_read(&reader, mk_lib_vc_master_keys_offset, 2 * mk_lib_vc_seq_key_len, &keys_data[0]); mk_lib_vc_check2(tsi);
	mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 0, &master_keya);
	mk_lib_vc_seq_key_init(seq_id, &keys_data[0], 1, &master_keyb);
	mk_lib_vc_seq_expand_dec(seq_id, &master_keya, &master_schedulea);
	mk_lib_vc_seq_expand_enc(seq_id, &master_keyb, &master_scheduleb);
	tsi = reader_seek(reader_ctx, mk_lib_vc_data_offset); mk_lib_vc_check2(tsi);
	#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14
	tsl = mk_lib_vc_chunk_size;
	mk_sl_cui_uint64_from_bi_slong(&tu64, &tsl);
	tba = mk_sl_cui_uint64_ge(&size_volume, &tu64);
	mk_sl_cui_uint64_mod3_wrap(&size_volume, &tu64, &tu64);
	tbb = mk_sl_cui_uint64_is_zero(&tu64);
	#if !mk_lang_constexpr_is_constant_evaluated
	if(tba && tbb)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && tba && tbb)
	#endif
	{
		tsi = mk_lib_vc_inl_defd_decrypt_multithreaded(seq_id, &size_volume, &master_schedulea, &master_scheduleb, reader_ctx, reader_read, writer_ctx, writer_write); mk_lib_vc_check2(tsi);
	}
	else
	#endif
	{
		tsi = mk_lib_vc_inl_defd_decrypt_singlethreaded(seq_id, &size_volume, &master_schedulea, &master_scheduleb, reader_ctx, reader_read, writer_ctx, writer_write); mk_lib_vc_check2(tsi);
	}
	return 0;
}


#undef mk_lib_vc_seq_memcpy
#undef mk_lib_vc_xor2_aes
#undef mk_lib_vc_xor2_serpent


#include "mk_lib_vc_inl_defu.h"


#undef mk_lib_vc_t_name
#undef mk_lib_vc_t_reader
#undef mk_lib_vc_t_writer
