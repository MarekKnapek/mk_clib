#ifndef mk_include_guard_mk_lib_stack_trace_windows
#define mk_include_guard_mk_lib_stack_trace_windows


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


typedef mk_win_base_ulong_t mk_lib_stack_trace_windows_hash_t;
typedef mk_lib_stack_trace_windows_hash_t const mk_lib_stack_trace_windows_hash_ct;
typedef mk_lib_stack_trace_windows_hash_t* mk_lib_stack_trace_windows_hash_pt;
typedef mk_lib_stack_trace_windows_hash_t const* mk_lib_stack_trace_windows_hash_pct;

typedef mk_win_base_void_t(*mk_lib_stack_trace_windows_func_t)(mk_win_base_void_t);
typedef mk_lib_stack_trace_windows_func_t const mk_lib_stack_trace_windows_func_ct;
typedef mk_lib_stack_trace_windows_func_t* mk_lib_stack_trace_windows_func_pt;
typedef mk_lib_stack_trace_windows_func_t const* mk_lib_stack_trace_windows_func_pct;

#define mk_sl_fixed_vector_t_name mk_lib_stack_trace_windows_funcs
#define mk_sl_fixed_vector_t_element mk_lib_stack_trace_windows_func_t
#define mk_sl_fixed_vector_t_count 62
#include "mk_sl_fixed_vector_inl_fileh.h"
#undef mk_sl_fixed_vector_t_name
#undef mk_sl_fixed_vector_t_element
#undef mk_sl_fixed_vector_t_count

struct mk_lib_stack_trace_windows_s
{
	mk_lib_stack_trace_windows_funcs_t m_funcs;
	mk_win_base_ulong_t m_hash;
};
typedef struct mk_lib_stack_trace_windows_s mk_lib_stack_trace_windows_t;
typedef mk_lib_stack_trace_windows_t const mk_lib_stack_trace_windows_ct;
typedef mk_lib_stack_trace_windows_t* mk_lib_stack_trace_windows_pt;
typedef mk_lib_stack_trace_windows_t const* mk_lib_stack_trace_windows_pct;
typedef mk_lib_stack_trace_windows_pt const mk_lib_stack_trace_windows_cpt;
typedef mk_lib_stack_trace_windows_pt* mk_lib_stack_trace_windows_ppt;
typedef mk_lib_stack_trace_windows_pt const* mk_lib_stack_trace_windows_pcpt;
typedef mk_lib_stack_trace_windows_pct const mk_lib_stack_trace_windows_cpct;
typedef mk_lib_stack_trace_windows_pct* mk_lib_stack_trace_windows_ppct;
typedef mk_lib_stack_trace_windows_pct const* mk_lib_stack_trace_windows_pcpct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_rw_construct_void(mk_lib_stack_trace_windows_pt const stack_trace) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_rw_construct_capture(mk_lib_stack_trace_windows_pt const stack_trace) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_rw_destruct(mk_lib_stack_trace_windows_pt const stack_trace) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_ro_get_funcs(mk_lib_stack_trace_windows_pct const stack_trace, mk_lib_stack_trace_windows_funcs_ppct const funcs) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_ro_get_hash(mk_lib_stack_trace_windows_pct const stack_trace, mk_win_base_ulong_pt const hash) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_ro_cmp(mk_lib_stack_trace_windows_pct const a, mk_lib_stack_trace_windows_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_stack_trace_windows.c"
#endif
#endif
