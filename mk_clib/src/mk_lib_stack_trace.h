#ifndef mk_include_guard_mk_lib_stack_trace
#define mk_include_guard_mk_lib_stack_trace


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51
#define mk_lib_stack_trace_has 1
#include "mk_lib_stack_trace_windows.h"
typedef mk_lib_stack_trace_windows_t mk_lib_stack_trace_impl_t;
typedef mk_lib_stack_trace_windows_hash_t mk_lib_stack_trace_impl_hash_t;
typedef mk_lib_stack_trace_windows_funcs_t mk_lib_stack_trace_impl_funcs_t;
#else
#define mk_lib_stack_trace_has 0
struct mk_lib_stack_trace_dummy_s{ mk_lang_types_sint_t m_dummy; };
typedef struct mk_lib_stack_trace_dummy_s mk_lib_stack_trace_dummy_t;
typedef mk_lib_stack_trace_dummy_t mk_lib_stack_trace_impl_t;
typedef mk_lang_types_usize_t mk_lib_stack_trace_impl_hash_t;
typedef mk_lib_stack_trace_dummy_t mk_lib_stack_trace_impl_funcs_t;
#endif

typedef mk_lib_stack_trace_impl_hash_t const mk_lib_stack_trace_impl_hash_ct;
typedef mk_lib_stack_trace_impl_hash_t* mk_lib_stack_trace_impl_hash_pt;
typedef mk_lib_stack_trace_impl_hash_t const* mk_lib_stack_trace_impl_hash_pct;
typedef mk_lib_stack_trace_impl_hash_pt const mk_lib_stack_trace_impl_hash_cpt;
typedef mk_lib_stack_trace_impl_hash_pt* mk_lib_stack_trace_impl_hash_ppt;
typedef mk_lib_stack_trace_impl_hash_pt const* mk_lib_stack_trace_impl_hash_pcpt;
typedef mk_lib_stack_trace_impl_hash_pct const mk_lib_stack_trace_impl_hash_cpct;
typedef mk_lib_stack_trace_impl_hash_pct* mk_lib_stack_trace_impl_hash_ppct;
typedef mk_lib_stack_trace_impl_hash_pct const* mk_lib_stack_trace_impl_hash_pcpct;

typedef mk_lib_stack_trace_impl_funcs_t const mk_lib_stack_trace_impl_funcs_ct;
typedef mk_lib_stack_trace_impl_funcs_t* mk_lib_stack_trace_impl_funcs_pt;
typedef mk_lib_stack_trace_impl_funcs_t const* mk_lib_stack_trace_impl_funcs_pct;
typedef mk_lib_stack_trace_impl_funcs_pt const mk_lib_stack_trace_impl_funcs_cpt;
typedef mk_lib_stack_trace_impl_funcs_pt* mk_lib_stack_trace_impl_funcs_ppt;
typedef mk_lib_stack_trace_impl_funcs_pt const* mk_lib_stack_trace_impl_funcs_pcpt;
typedef mk_lib_stack_trace_impl_funcs_pct const mk_lib_stack_trace_impl_funcs_cpct;
typedef mk_lib_stack_trace_impl_funcs_pct* mk_lib_stack_trace_impl_funcs_ppct;
typedef mk_lib_stack_trace_impl_funcs_pct const* mk_lib_stack_trace_impl_funcs_pcpct;

struct mk_lib_stack_trace_s
{
	mk_lib_stack_trace_impl_t m_stack_trace;
};
typedef struct mk_lib_stack_trace_s mk_lib_stack_trace_t;
typedef mk_lib_stack_trace_t const mk_lib_stack_trace_ct;
typedef mk_lib_stack_trace_t* mk_lib_stack_trace_pt;
typedef mk_lib_stack_trace_t const* mk_lib_stack_trace_pct;
typedef mk_lib_stack_trace_pt const mk_lib_stack_trace_cpt;
typedef mk_lib_stack_trace_pt* mk_lib_stack_trace_ppt;
typedef mk_lib_stack_trace_pt const* mk_lib_stack_trace_pcpt;
typedef mk_lib_stack_trace_pct const mk_lib_stack_trace_cpct;
typedef mk_lib_stack_trace_pct* mk_lib_stack_trace_ppct;
typedef mk_lib_stack_trace_pct const* mk_lib_stack_trace_pcpct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_rw_construct_void(mk_lib_stack_trace_pt const stack_trace) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_rw_construct_capture(mk_lib_stack_trace_pt const stack_trace) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_rw_destruct(mk_lib_stack_trace_pt const stack_trace) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_ro_get_funcs(mk_lib_stack_trace_pct const stack_trace, mk_lib_stack_trace_impl_funcs_ppct const funcs) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_ro_get_hash(mk_lib_stack_trace_pct const stack_trace, mk_lib_stack_trace_impl_hash_pt const hash) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_ro_cmp(mk_lib_stack_trace_pct const a, mk_lib_stack_trace_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_stack_trace.c"
#endif
#endif
