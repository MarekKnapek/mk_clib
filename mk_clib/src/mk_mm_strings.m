define(`mk_mm_strings_nl', `
')`'dnl
define(`mk_mm_strings_a_tab', `	')`'dnl
define(`mk_mm_strings_a_pch_nul', changequote([, ])[changequote([, ])'\0'changequote(`, ')]changequote(`, '))dnl
define(`mk_mm_strings_a_half', `ifelse(`$#', `3', ``$1'', ``'`$1', mk_mm_strings_a_half(shift(shift($@)))')')`'dnl
define(`mk_mm_strings_h_include_guard_a', ``#'ifndef mk_include_guard_`$1'_h')dnl
define(`mk_mm_strings_h_include_guard_b', ``#'define mk_include_guard_`$1'_h')dnl
define(`mk_mm_strings_h_include_source', ``#'include "`$1'.c"')dnl"
define(`mk_mm_strings_h_enum_id_e', `$1_id_e')dnl
define(`mk_mm_strings_h_enum_id_t', `$1_id_t')dnl
define(`mk_mm_strings_h_enum_id', `$1_id')dnl
define(`mk_mm_strings_h_enum_middles', ``$1'_id_e_`$2'`'`'ifelse(`$#', `3', `', ``',mk_mm_strings_nl()mk_mm_strings_a_tab()mk_mm_strings_h_enum_middles($1, shift(shift($@)))`'')')`'dnl
define(`mk_mm_strings_h_enum_last', ``$1'_id_e_dummy_end')dnl
define(`mk_mm_strings_h_get_str_buf', ``$1'_get_str_buf')dnl
define(`mk_mm_strings_h_get_str_len', ``$1'_get_str_len')dnl
dnl
dnl
dnl
define(`mk_mm_strings_generate_header_impl', `dnl
mk_mm_strings_h_include_guard_a($@)
mk_mm_strings_h_include_guard_b($@)


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


enum mk_mm_strings_h_enum_id_e($@)
{
	mk_mm_strings_h_enum_middles($@),
	mk_mm_strings_h_enum_last($@)
};
typedef enum mk_mm_strings_h_enum_id_e($@) mk_mm_strings_h_enum_id_t($@);
mk_lang_typedef(mk_mm_strings_h_enum_id($@));


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_mm_strings_h_get_str_buf($@)(mk_mm_strings_h_enum_id_t($@) const id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_mm_strings_h_get_str_len($@)(mk_mm_strings_h_enum_id_t($@) const id) mk_lang_noexcept;


#if mk_lang_jumbo_have
mk_mm_strings_h_include_source($@)
#endif
#endif
')`'dnl
define(`mk_mm_strings_generate_header', `mk_mm_strings_generate_header_impl($1, mk_mm_strings_a_half(shift($@)), `')')`'dnl
dnl
dnl
dnl
define(`mk_mm_strings_c_include_guard_a', ``#'ifndef mk_include_guard_`$1'_c')dnl
define(`mk_mm_strings_c_include_guard_b', ``#'define mk_include_guard_`$1'_c')dnl
define(`mk_mm_strings_c_include_header', ``#'include "`$1'.h"')dnl"
define(`mk_mm_strings_c_defines', ``#'define `$1'_def_`$2' "`$3'"`'`'ifelse(`$#', `4', `', ``'mk_mm_strings_nl()mk_mm_strings_c_defines($1, shift(shift(shift($@))))`'')')`'dnl
define(`mk_mm_strings_c_defs_first', ``#'define `$1'_defs \')`'dnl
define(`mk_mm_strings_c_defs_all', `mk_mm_strings_a_tab()`$1'_def_`$2' \ifelse(`$#', `4', `', ``'mk_mm_strings_nl()mk_mm_strings_c_defs_all($1, shift(shift(shift($@))))`'')')`'dnl
define(`mk_mm_strings_c_defs_last', `""')`'dnl
define(`mk_mm_strings_c_lens', ``#'`'define `$1'_len_`$2' (mk_lang_countstr(`$1'_def_`$2'))`'`'ifelse(`$#', `4', `', ``'mk_mm_strings_nl()mk_mm_strings_c_lens($1, shift(shift(shift($@))))`'')')`'dnl
define(`mk_mm_strings_c_offs_defs_first', ``#'`'define `$1'_off_`$2' (0)')`'dnl
define(`mk_mm_strings_c_offs_defs_rest', ``#'`'define `$1'_off_`$4' ((`$1'_off_`$2') + (`$1'_len_`$2'))`'`'ifelse(`$#', `6', `', ``'mk_mm_strings_nl()mk_mm_strings_c_offs_defs_rest($1, shift(shift(shift($@))))`'')')`'dnl
define(`mk_mm_strings_c_offs_arr_first', ``#'define `$1'_offs \mk_mm_strings_nl(){ \')`'dnl
define(`mk_mm_strings_c_offs_arr_all', `mk_mm_strings_a_tab()`$1'_off_`$4', \`'`'ifelse(`$#', `6', `', ``'mk_mm_strings_nl()mk_mm_strings_c_offs_arr_all($1, shift(shift(shift($@))))`'')')`'dnl
define(`mk_mm_strings_c_offs_arr_last', `}')`'dnl
define(`mk_mm_strings_c_k_buf', ``$1'_k_buf')dnl
define(`mk_mm_strings_c_k_off', ``$1'_k_off')dnl
define(`mk_mm_strings_c_defs', ``$1'_defs')dnl
define(`mk_mm_strings_c_offs', ``$1'_offs')dnl
define(`mk_mm_strings_c_get_str_off', ``$1'_get_str_off')dnl
dnl
dnl
dnl
define(`mk_mm_strings_generate_source', `dnl
mk_mm_strings_c_include_guard_a($@)
mk_mm_strings_c_include_guard_b($@)
mk_mm_strings_c_include_header($@)

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


mk_mm_strings_c_defines($@)

mk_mm_strings_c_defs_first($@)
mk_mm_strings_c_defs_all($@)
mk_mm_strings_c_defs_last($@)

mk_mm_strings_c_lens($@)

mk_mm_strings_c_offs_defs_first($@)
mk_mm_strings_c_offs_defs_rest($@)

mk_mm_strings_c_offs_arr_first($@)
mk_mm_strings_c_offs_arr_all($@)
mk_mm_strings_c_offs_arr_last($@)


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_mm_strings_c_k_buf($@)[] = mk_mm_strings_c_defs($@);
mk_lang_constexpr_static_inline mk_lang_types_ushort_t const mk_mm_strings_c_k_off($@)[] = mk_mm_strings_c_offs($@);


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_mm_strings_c_get_str_off($@)(mk_mm_strings_h_enum_id_t($@) const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(mk_mm_strings_c_k_off($@)) + 1 == mk_mm_strings_h_enum_last($@));

	mk_lang_assert(id >= 0);
	mk_lang_assert(id <= mk_mm_strings_h_enum_last($@));

	if(id == 0)
	{
		off = 0;
	}
	else if(id == mk_mm_strings_h_enum_last($@))
	{
		off = mk_lang_countstr(mk_mm_strings_c_k_buf($@));
	}
	else
	{
		off = mk_mm_strings_c_k_off($@)[id - 1];
	}
	mk_lang_assert(off >= 0);
	mk_lang_assert(off <= mk_lang_countstr(mk_mm_strings_c_k_buf($@)));
	return off;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_mm_strings_h_get_str_buf($@)(mk_mm_strings_h_enum_id_t($@) const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;
	mk_lang_types_pchar_pct buf mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_mm_strings_h_enum_last($@));

	off = mk_mm_strings_c_get_str_off($@)(id);
	buf = &mk_mm_strings_c_k_buf($@)[off];
	mk_lang_assert(buf);
	mk_lang_assert(buf[0] != mk_mm_strings_a_pch_nul());
	return buf;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_mm_strings_h_get_str_len($@)(mk_mm_strings_h_enum_id_t($@) const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off_a mk_lang_constexpr_init;
	mk_lang_types_sint_t off_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_mm_strings_h_enum_last($@));

	off_a = mk_mm_strings_c_get_str_off($@)(((mk_mm_strings_h_enum_id_t($@))(id + 0)));
	off_b = mk_mm_strings_c_get_str_off($@)(((mk_mm_strings_h_enum_id_t($@))(id + 1)));
	mk_lang_assert(off_a < off_b);
	len = off_b - off_a;
	mk_lang_assert(len >= 1);
	mk_lang_assert(len <= mk_lang_countstr(mk_mm_strings_c_k_buf($@)));
	return len;
}


#endif
')`'dnl
