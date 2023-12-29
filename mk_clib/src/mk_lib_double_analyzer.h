#ifndef mk_include_guard_mk_lib_double_analyzer
#define mk_include_guard_mk_lib_double_analyzer


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"

#define mk_sl_flt_name dbl
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "mk_sl_flt_inl_fileh.h"


struct mk_lib_double_analyzer_s
{
	mk_sl_cui_uint64_t m_bytes;
	mk_lang_types_pchar_t m_bin[mk_sl_cui_uint64_strlenbin_v];
	mk_lang_types_pchar_t m_hex[mk_sl_cui_uint64_strlenhex_v];
	mk_lang_types_uchar_t m_uns_len;
	mk_lang_types_pchar_t m_uns_str[mk_sl_cui_uint64_strlendec_v];
	mk_lang_types_uchar_t m_sig_len;
	mk_lang_types_pchar_t m_sig_str[mk_sl_cui_uint64_strlendec_v + 1];
	mk_lang_types_uchar_t m_val_sgn;
	mk_lang_types_pchar_t m_exp_bin[mk_sl_cui_uint16_strlenbin_v];
	mk_lang_types_pchar_t m_exp_hex[mk_sl_cui_uint16_strlenhex_v];
	mk_lang_types_uchar_t m_exp_len;
	mk_lang_types_pchar_t m_exp_dec[mk_sl_cui_uint16_strlendec_v];
	mk_lang_types_uchar_t m_exp_le1;
	mk_lang_types_pchar_t m_exp_dcd[mk_sl_cui_uint16_strlendec_v + 1];
	mk_lang_types_uchar_t m_type;
	mk_lang_types_uchar_t m_one;
	mk_lang_types_pchar_t m_mts_bin[mk_sl_cui_uint64_strlenbin_v];
	mk_lang_types_pchar_t m_mts_hex[mk_sl_cui_uint64_strlenhex_v];
	mk_lang_types_uchar_t m_mts_len;
	mk_lang_types_pchar_t m_mts_dec[mk_sl_cui_uint64_strlendec_v];
	mk_lang_types_uchar_t m_mts_dcl;
	mk_lang_types_pchar_t m_mts_dcd[1 + 1 + 52];
	mk_lang_types_uchar_t m_val_len_lo;
	mk_lang_types_uchar_t m_val_len_hi;
	mk_lang_types_pchar_t m_val_str[mk_sl_flt_dbl_to_string_dec_basic_len_v];
};
typedef struct mk_lib_double_analyzer_s mk_lib_double_analyzer_t;
typedef mk_lib_double_analyzer_t const mk_lib_double_analyzer_ct;
typedef mk_lib_double_analyzer_t* mk_lib_double_analyzer_pt;
typedef mk_lib_double_analyzer_t const* mk_lib_double_analyzer_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_double_analyzer_analyze(mk_lib_double_analyzer_pt const double_analyzer) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_double_analyzer.c"
#endif
#endif
