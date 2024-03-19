#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"


#include "mk_lib_flt_analyzer_inl_defd.h"


#define mk_lib_flt_analyzer_inl_fileh_flt_name mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _fltbase)
#define mk_sl_flt_name mk_lib_flt_analyzer_inl_fileh_flt_name
#define mk_sl_flt_bits mk_lib_flt_analyzer_inl_defd_flt_bits
#define mk_sl_flt_fraction_bits mk_lib_flt_analyzer_inl_defd_flt_frac
#include "mk_sl_flt_inl_fileh.h"
#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits
#define mk_lib_flt_analyzer_inl_fileh_flt_to_string_dec_basic_n mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_lib_flt_analyzer_inl_fileh_flt_name), _to_string_dec_basic_n)
#define mk_lib_flt_analyzer_inl_fileh_flt_to_string_dec_basic_len_v mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_lib_flt_analyzer_inl_fileh_flt_name), _to_string_dec_basic_len_v)


struct mk_lib_flt_analyzer_inl_defd_s
{
	mk_lang_types_uchar_t m_bytes[sizeof(mk_lib_flt_analyzer_inl_defd_uint_t)];
	mk_lang_types_pchar_t m_bin[mk_lib_flt_analyzer_inl_defd_uint_strlenbin_v];
	mk_lang_types_pchar_t m_hex[mk_lib_flt_analyzer_inl_defd_uint_strlenhex_v];
	mk_lang_types_uchar_t m_uns_len[sizeof(mk_lib_flt_analyzer_inl_defd_lent_t)];
	mk_lang_types_pchar_t m_uns_str[mk_lib_flt_analyzer_inl_defd_uint_strlendec_v];
	mk_lang_types_uchar_t m_sig_len[sizeof(mk_lib_flt_analyzer_inl_defd_lent_t)];
	mk_lang_types_pchar_t m_sig_str[mk_lib_flt_analyzer_inl_defd_uint_strlendec_v + 1];
	mk_lang_types_uchar_t m_val_sgn;
	mk_lang_types_pchar_t m_exp_bin[mk_lib_flt_analyzer_inl_defd_expuint_strlenbin_v];
	mk_lang_types_pchar_t m_exp_hex[mk_lib_flt_analyzer_inl_defd_expuint_strlenhex_v];
	mk_lang_types_uchar_t m_exp_len[sizeof(mk_lib_flt_analyzer_inl_defd_lent_t)];
	mk_lang_types_pchar_t m_exp_dec[mk_lib_flt_analyzer_inl_defd_expuint_strlendec_v];
	mk_lang_types_uchar_t m_exp_le1[sizeof(mk_lib_flt_analyzer_inl_defd_lent_t)];
	mk_lang_types_pchar_t m_exp_dcd[mk_lib_flt_analyzer_inl_defd_expuint_strlendec_v + 1];
	mk_lang_types_uchar_t m_type;
	mk_lang_types_uchar_t m_one;
	mk_lang_types_pchar_t m_mts_bin[mk_lib_flt_analyzer_inl_defd_mtsuint_strlenbin_v];
	mk_lang_types_pchar_t m_mts_hex[mk_lib_flt_analyzer_inl_defd_mtsuint_strlenhex_v];
	mk_lang_types_uchar_t m_mts_len[sizeof(mk_lib_flt_analyzer_inl_defd_lent_t)];
	mk_lang_types_pchar_t m_mts_dec[mk_lib_flt_analyzer_inl_defd_mtsuint_strlendec_v];
	mk_lang_types_uchar_t m_mts_dcl[sizeof(mk_lib_flt_analyzer_inl_defd_lent_t)];
	mk_lang_types_pchar_t m_mts_dcd[1 + 1 + mk_lib_flt_analyzer_inl_defd_flt_frac];
	mk_lang_types_uchar_t m_val_len[sizeof(mk_lib_flt_analyzer_inl_defd_mtslent_t)];
	mk_lang_types_pchar_t m_val_str[mk_lib_flt_analyzer_inl_fileh_flt_to_string_dec_basic_len_v];
};
typedef struct mk_lib_flt_analyzer_inl_defd_s mk_lib_flt_analyzer_inl_defd_t;
typedef mk_lib_flt_analyzer_inl_defd_t const mk_lib_flt_analyzer_inl_defd_ct;
typedef mk_lib_flt_analyzer_inl_defd_t* mk_lib_flt_analyzer_inl_defd_pt;
typedef mk_lib_flt_analyzer_inl_defd_t const* mk_lib_flt_analyzer_inl_defd_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_flt_analyzer_inl_defd_analyze(mk_lib_flt_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept;


#include "mk_lib_flt_analyzer_inl_defu.h"
