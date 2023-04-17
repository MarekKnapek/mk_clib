#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_flt_parse_inl_defhd.h"


enum mk_sl_flt_parse_inl_defhd_result_e
{
	mk_sl_flt_parse_inl_defhd_result_e_ok,
	mk_sl_flt_parse_inl_defhd_result_e_invalid,
	mk_sl_flt_parse_inl_defhd_result_e_out_of_range
};
typedef enum mk_sl_flt_parse_inl_defhd_result_e mk_sl_flt_parse_inl_defhd_result_t;


mk_lang_constexpr mk_lang_jumbo void mk_sl_flt_parse_inl_defhd_uchars_from_string_dec_n(unsigned char* const x, char const* const str, int const str_len, int* const consummed, mk_sl_flt_parse_inl_defhd_result_t* const result) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_flt_parse_inl_defhd_void_from_string_dec_n(void* const x, char const* const str, int const str_len, int* const consummed, mk_sl_flt_parse_inl_defhd_result_t* const result) mk_lang_noexcept;


#include "mk_sl_flt_parse_inl_defhu.h"
