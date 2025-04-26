#ifndef mk_include_guard_mk_lang_debug_trace_h
#define mk_include_guard_mk_lang_debug_trace_h


#if defined mk_lang_debug_trace_want && (mk_lang_debug_trace_want) == 1
#define mk_lang_debug_trace_have 1
#elif defined mk_lang_debug_trace_want && (mk_lang_debug_trace_want) == 0
#define mk_lang_debug_trace_have 0
#elif !defined mk_lang_debug_trace_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_debug_trace_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_debug_trace_have 0
#else
#define mk_lang_debug_trace_have 0
#endif
#endif
#else
#error xxxxxxxxxx
#endif


#include "mk_lang_jumbo.h"


#if mk_lang_debug_trace_have


#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#define mk_lang_debug_trace_has_func (mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11 || mk_lang_version_at_least_c_99)
#define mk_lang_debug_trace_str_lit(x) x, mk_lang_countstr(x)


#if mk_lang_debug_trace_has_func
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_void(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_int(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_usize_t const num) mk_lang_noexcept;
#else
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_void(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_debug_trace_impl_int(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_usize_t const num) mk_lang_noexcept;
#endif


#if mk_lang_debug_trace_has_func
#define mk_lang_debug_trace_fn() \
	do \
	{ \
		if(mk_lang_runtime_bool_fn_true) \
		{ \
			mk_lang_debug_trace_impl_void \
			( \
				mk_lang_debug_trace_str_lit \
				( \
					"trace--->" \
					__FILE__ \
					":" \
					mk_lang_stringify(__LINE__) \
					"<---trace " \
				), \
				__func__, \
				mk_lang_countstr(__func__) \
			); \
		} \
	}while(mk_lang_runtime_bool_fn_false)
#define mk_lang_debug_trace_fn_usize(x) \
	do \
	{ \
		if(mk_lang_runtime_bool_fn_true) \
		{ \
			mk_lang_debug_trace_impl_int \
			( \
				mk_lang_debug_trace_str_lit \
				( \
					"trace--->" \
					__FILE__ \
					":" \
					mk_lang_stringify(__LINE__) \
					"<---trace " \
				), \
				__func__, \
				mk_lang_countstr(__func__), \
				(x) \
			); \
		} \
	}while(mk_lang_runtime_bool_fn_false)
#else
#define mk_lang_debug_trace_fn() \
	do \
	{ \
		if(mk_lang_runtime_bool_fn_true) \
		{ \
			mk_lang_debug_trace_impl_void \
			( \
				mk_lang_debug_trace_str_lit \
				( \
					"trace--->" \
					__FILE__ \
					":" \
					mk_lang_stringify(__LINE__) \
					"<---trace" \
				) \
			); \
		} \
	}while(mk_lang_runtime_bool_fn_false)
#define mk_lang_debug_trace_fn_usize(x) \
	do \
	{ \
		if(mk_lang_runtime_bool_fn_true) \
		{ \
			mk_lang_debug_trace_impl_int \
			( \
				mk_lang_debug_trace_str_lit \
				( \
					"trace--->" \
					__FILE__ \
					":" \
					mk_lang_stringify(__LINE__) \
					"<---trace" \
				), \
				(x) \
			); \
		} \
	}while(mk_lang_runtime_bool_fn_false)
#endif


#else


#include "mk_lang_runtime_bool.h"


#define mk_lang_debug_trace_fn() do{}while(mk_lang_runtime_bool_fn_false)
#define mk_lang_debug_trace_fn_usize(x) do{}while(mk_lang_runtime_bool_fn_false)


#endif


#if mk_lang_jumbo_have
#include "mk_lang_debug_trace.c"
#endif
#endif
