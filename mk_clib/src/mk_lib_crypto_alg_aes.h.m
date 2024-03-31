include(mk_lang_concat.m)dnl
define(mk_lib_crypto_alg_aes_m4_c, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), .c))dnl
define(mk_lib_crypto_alg_aes_m4_include_guard, mk_lang_concat(mk_include_guard_mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits))dnl
ifelse(mk_lib_crypto_alg_aes_t_bits, `128', `define(mk_lib_crypto_alg_aes_m4_nr_val, `10')', `ifelse(mk_lib_crypto_alg_aes_t_bits, `192', `define(mk_lib_crypto_alg_aes_m4_nr_val, `12')', `ifelse(mk_lib_crypto_alg_aes_t_bits, `256', `define(mk_lib_crypto_alg_aes_m4_nr_val, `14')', `define(mk_lib_crypto_alg_aes_m4_nr_val, `xxxxxxxxxx')')')')dnl
define(mk_lib_crypto_alg_aes_m4_decrypt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _decrypt))dnl
define(mk_lib_crypto_alg_aes_m4_encrypt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _encrypt))dnl
define(mk_lib_crypto_alg_aes_m4_expand_dec, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _expand_dec))dnl
define(mk_lib_crypto_alg_aes_m4_expand_enc, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _expand_enc))dnl
define(mk_lib_crypto_alg_aes_m4_key_ct, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_ct))dnl
define(mk_lib_crypto_alg_aes_m4_key_data_t, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_data_t))dnl
define(mk_lib_crypto_alg_aes_m4_key_data_u, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_data_u))dnl
define(mk_lib_crypto_alg_aes_m4_key_len_e, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_len_e))dnl
define(mk_lib_crypto_alg_aes_m4_key_len_m, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_len_m))dnl
define(mk_lib_crypto_alg_aes_m4_key_len_v, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_len_v))dnl
define(mk_lib_crypto_alg_aes_m4_key_pct, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_pct))dnl
define(mk_lib_crypto_alg_aes_m4_key_pt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_pt))dnl
define(mk_lib_crypto_alg_aes_m4_key_s, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_s))dnl
define(mk_lib_crypto_alg_aes_m4_key_t, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _key_t))dnl
define(mk_lib_crypto_alg_aes_m4_msg_ct, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_ct))dnl
define(mk_lib_crypto_alg_aes_m4_msg_data_t, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_data_t))dnl
define(mk_lib_crypto_alg_aes_m4_msg_data_u, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_data_u))dnl
define(mk_lib_crypto_alg_aes_m4_msg_len_e, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_len_e))dnl
define(mk_lib_crypto_alg_aes_m4_msg_len_m, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_len_m))dnl
define(mk_lib_crypto_alg_aes_m4_msg_len_v, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_len_v))dnl
define(mk_lib_crypto_alg_aes_m4_msg_pct, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_pct))dnl
define(mk_lib_crypto_alg_aes_m4_msg_pt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_pt))dnl
define(mk_lib_crypto_alg_aes_m4_msg_s, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_s))dnl
define(mk_lib_crypto_alg_aes_m4_msg_t, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _msg_t))dnl
define(mk_lib_crypto_alg_aes_m4_nr, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _nr))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_ct, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_ct))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_data_t, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_data_t))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_data_u, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_data_u))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_decrypt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_decrypt))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_encrypt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_encrypt))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_len_e, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_len_e))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_len_m, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_len_m))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_len_v, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_len_v))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_pct, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_pct))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_pt, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_pt))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_s, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_s))dnl
define(mk_lib_crypto_alg_aes_m4_schedule_t, mk_lang_concat(mk_lang_concat(mk_lib_crypto_alg_aes_, mk_lib_crypto_alg_aes_t_bits), _schedule_t))dnl
`#'ifndef mk_lib_crypto_alg_aes_m4_include_guard
`#'define mk_lib_crypto_alg_aes_m4_include_guard


/* NIST FIPS PUB 197 */


`#'include "mk_lang_alignas.h"
`#'include "mk_lang_charbit.h"
`#'include "mk_lang_constexpr.h"
`#'include "mk_lang_jumbo.h"
`#'include "mk_lang_noexcept.h"
`#'include "mk_lang_pow2.h"
`#'include "mk_lang_types.h"
`#'include "mk_sl_uint8.h"


`#'define mk_lib_crypto_alg_aes_m4_nr mk_lib_crypto_alg_aes_m4_nr_val
`#'define mk_lib_crypto_alg_aes_m4_key_len_m (mk_lib_crypto_alg_aes_t_bits / mk_lang_charbit)
`#'define mk_lib_crypto_alg_aes_m4_msg_len_m (128 / mk_lang_charbit)
`#'define mk_lib_crypto_alg_aes_m4_schedule_len_m ((mk_lib_crypto_alg_aes_m4_nr + 1) * mk_lib_crypto_alg_aes_m4_msg_len_m)
enum mk_lib_crypto_alg_aes_m4_key_len_e { mk_lib_crypto_alg_aes_m4_key_len_v = mk_lib_crypto_alg_aes_m4_key_len_m };
enum mk_lib_crypto_alg_aes_m4_msg_len_e { mk_lib_crypto_alg_aes_m4_msg_len_v = mk_lib_crypto_alg_aes_m4_msg_len_m };
enum mk_lib_crypto_alg_aes_m4_schedule_len_e { mk_lib_crypto_alg_aes_m4_schedule_len_v = mk_lib_crypto_alg_aes_m4_schedule_len_m };


union mk_lib_crypto_alg_aes_m4_key_data_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(mk_lib_crypto_alg_aes_m4_key_len_v)) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_m4_key_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_aes_m4_key_data_u mk_lib_crypto_alg_aes_m4_key_data_t;

struct mk_lib_crypto_alg_aes_m4_key_s
{
	mk_lib_crypto_alg_aes_m4_key_data_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_m4_key_s mk_lib_crypto_alg_aes_m4_key_t;
typedef mk_lib_crypto_alg_aes_m4_key_t const mk_lib_crypto_alg_aes_m4_key_ct;
typedef mk_lib_crypto_alg_aes_m4_key_t* mk_lib_crypto_alg_aes_m4_key_pt;
typedef mk_lib_crypto_alg_aes_m4_key_t const* mk_lib_crypto_alg_aes_m4_key_pct;

union mk_lib_crypto_alg_aes_m4_msg_data_u
{
	mk_lang_alignas(mk_lib_crypto_alg_aes_m4_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_m4_msg_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_aes_m4_msg_data_u mk_lib_crypto_alg_aes_m4_msg_data_t;

struct mk_lib_crypto_alg_aes_m4_msg_s
{
	mk_lib_crypto_alg_aes_m4_msg_data_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_m4_msg_s mk_lib_crypto_alg_aes_m4_msg_t;
typedef mk_lib_crypto_alg_aes_m4_msg_t const mk_lib_crypto_alg_aes_m4_msg_ct;
typedef mk_lib_crypto_alg_aes_m4_msg_t* mk_lib_crypto_alg_aes_m4_msg_pt;
typedef mk_lib_crypto_alg_aes_m4_msg_t const* mk_lib_crypto_alg_aes_m4_msg_pct;

union mk_lib_crypto_alg_aes_m4_schedule_data_u
{
	mk_lib_crypto_alg_aes_m4_msg_t m_msgs[mk_lib_crypto_alg_aes_m4_nr + 1];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_aes_m4_schedule_data_u mk_lib_crypto_alg_aes_m4_schedule_data_t;

struct mk_lib_crypto_alg_aes_m4_schedule_s
{
	mk_lib_crypto_alg_aes_m4_schedule_data_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_m4_schedule_s mk_lib_crypto_alg_aes_m4_schedule_t;
typedef mk_lib_crypto_alg_aes_m4_schedule_t const mk_lib_crypto_alg_aes_m4_schedule_ct;
typedef mk_lib_crypto_alg_aes_m4_schedule_t* mk_lib_crypto_alg_aes_m4_schedule_pt;
typedef mk_lib_crypto_alg_aes_m4_schedule_t const* mk_lib_crypto_alg_aes_m4_schedule_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_m4_schedule_encrypt`('mk_lib_crypto_alg_aes_m4_schedule_pct const schedule, mk_lib_crypto_alg_aes_m4_msg_pct const input, mk_lib_crypto_alg_aes_m4_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_m4_schedule_decrypt`('mk_lib_crypto_alg_aes_m4_schedule_pct const schedule, mk_lib_crypto_alg_aes_m4_msg_pct const input, mk_lib_crypto_alg_aes_m4_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_m4_expand_enc`('mk_lib_crypto_alg_aes_m4_key_pct const key, mk_lib_crypto_alg_aes_m4_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_m4_expand_dec`('mk_lib_crypto_alg_aes_m4_key_pct const key, mk_lib_crypto_alg_aes_m4_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_m4_encrypt`('mk_lib_crypto_alg_aes_m4_key_pct const key, mk_lib_crypto_alg_aes_m4_msg_pct const input, mk_lib_crypto_alg_aes_m4_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_m4_decrypt`('mk_lib_crypto_alg_aes_m4_key_pct const key, mk_lib_crypto_alg_aes_m4_msg_pct const input, mk_lib_crypto_alg_aes_m4_msg_pt const output) mk_lang_noexcept;


`#'if mk_lang_jumbo_want == 1
`#'include "mk_lib_crypto_alg_aes_m4_c"
`#'endif
`#'endif
