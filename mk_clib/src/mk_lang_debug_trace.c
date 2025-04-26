#ifndef mk_include_guard_mk_lang_debug_trace_c
#define mk_include_guard_mk_lang_debug_trace_c
#include "mk_lang_debug_trace.h"


#if mk_lang_debug_trace_have


#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_stdout.h"
#include "mk_lang_types.h"


#if mk_lang_debug_trace_has_func
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_void(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len) mk_lang_noexcept
#else
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_void(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
#endif
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(str_buf[0] != '\0');
	mk_lang_assert(str_len >= 1);
	#if mk_lang_debug_trace_has_func
	mk_lang_assert(func_buf);
	mk_lang_assert(func_buf[0] != '\0');
	mk_lang_assert(func_len >= 1);
	#endif

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		#if mk_lang_debug_trace_has_func
		err = mk_lang_stdout_print_n(str_buf, str_len); mk_lang_check_recrash(err);
		err = mk_lang_stdout_println_n(func_buf, func_len); mk_lang_check_recrash(err);
		#else
		err = mk_lang_stdout_println_n(str_buf, str_len); mk_lang_check_recrash(err);
		#endif
	}
}

#if mk_lang_debug_trace_has_func
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_int(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_usize_t const num) mk_lang_noexcept
#else
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_int(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_usize_t const num) mk_lang_noexcept
#endif
{
	mk_lang_types_sint_t len_num mk_lang_constexpr_init;
	mk_lang_types_pchar_t buf_num[1 + mk_lang_bui_usize_strlen_dec_v + 1] mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(str_buf[0] != '\0');
	mk_lang_assert(str_len >= 1);
	#if mk_lang_debug_trace_has_func
	mk_lang_assert(func_buf);
	mk_lang_assert(func_buf[0] != '\0');
	mk_lang_assert(func_len >= 1);
	#endif
	mk_lang_assert(num != 0 || num == 0);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		buf_num[0] = '(';
		len_num = mk_lang_bui_usize_to_str_dec_n(&num, &buf_num[1], mk_lang_bui_usize_strlen_dec_v); mk_lang_assert(len_num >= 1); mk_lang_assert(len_num <= mk_lang_bui_usize_strlen_dec_v);
		buf_num[1 + len_num] = ')';
		#if mk_lang_debug_trace_has_func
		err = mk_lang_stdout_print_n(str_buf, str_len); mk_lang_check_recrash(err);
		err = mk_lang_stdout_print_n(func_buf, func_len); mk_lang_check_recrash(err);
		#else
		err = mk_lang_stdout_print_n(str_buf, str_len); mk_lang_check_recrash(err);
		#endif
		err = mk_lang_stdout_println_n(&buf_num[0], 1 + len_num + 1); mk_lang_check_recrash(err);
	}
}


#endif
static void mk_lang_debug_trace_dummy(void){}
#endif
