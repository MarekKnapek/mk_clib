#include "mk_lib_stack_trace.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51
#include "mk_lib_stack_trace_windows.h"
#define mk_lib_stack_trace_impl_rw_construct_void    mk_lib_stack_trace_windows_rw_construct_void
#define mk_lib_stack_trace_impl_rw_construct_capture mk_lib_stack_trace_windows_rw_construct_capture
#define mk_lib_stack_trace_impl_rw_destruct          mk_lib_stack_trace_windows_rw_destruct
#define mk_lib_stack_trace_impl_ro_get_funcs         mk_lib_stack_trace_windows_ro_get_funcs
#define mk_lib_stack_trace_impl_ro_get_hash          mk_lib_stack_trace_windows_ro_get_hash
#define mk_lib_stack_trace_impl_ro_cmp               mk_lib_stack_trace_windows_ro_cmp
#else
#define mk_lib_stack_trace_impl_rw_construct_void(stack_trace) (((mk_lang_types_void_t)(stack_trace)), 0)
#define mk_lib_stack_trace_impl_rw_construct_capture(stack_trace) (((mk_lang_types_void_t)(stack_trace)), 0)
#define mk_lib_stack_trace_impl_rw_destruct(stack_trace) (((mk_lang_types_void_t)(stack_trace)), 0)
#define mk_lib_stack_trace_impl_ro_get_funcs(stack_trace, funcs) (((mk_lang_types_void_t)(stack_trace)), ((mk_lang_types_void_t)(funcs)), 0)
#define mk_lib_stack_trace_impl_ro_get_hash(stack_trace, hash) (((mk_lang_types_void_t)(stack_trace)), ((mk_lang_types_void_t)(hash)), 0)
#define mk_lib_stack_trace_impl_ro_cmp(a, b, cmp) (((mk_lang_types_void_t)(a)), ((mk_lang_types_void_t)(b)), ((mk_lang_types_void_t)(cmp)), 0)
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_rw_construct_void(mk_lib_stack_trace_pt const stack_trace) mk_lang_noexcept
{
	return mk_lib_stack_trace_impl_rw_construct_void(&stack_trace->m_stack_trace);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_rw_construct_capture(mk_lib_stack_trace_pt const stack_trace) mk_lang_noexcept
{
	return mk_lib_stack_trace_impl_rw_construct_capture(&stack_trace->m_stack_trace);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_rw_destruct(mk_lib_stack_trace_pt const stack_trace) mk_lang_noexcept
{
	return mk_lib_stack_trace_impl_rw_destruct(&stack_trace->m_stack_trace);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_ro_get_funcs(mk_lib_stack_trace_pct const stack_trace, mk_lib_stack_trace_impl_funcs_ppct const funcs) mk_lang_noexcept
{
	return mk_lib_stack_trace_impl_ro_get_funcs(&stack_trace->m_stack_trace, funcs);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_ro_get_hash(mk_lib_stack_trace_pct const stack_trace, mk_lib_stack_trace_impl_hash_pt const hash) mk_lang_noexcept
{
	return mk_lib_stack_trace_impl_ro_get_hash(&stack_trace->m_stack_trace, hash);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_ro_cmp(mk_lib_stack_trace_pct const a, mk_lib_stack_trace_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	return mk_lib_stack_trace_impl_ro_cmp(&a->m_stack_trace, &b->m_stack_trace, cmp);
}
