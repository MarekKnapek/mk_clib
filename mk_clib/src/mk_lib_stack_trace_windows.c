#include "mk_lib_stack_trace_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"

#define mk_sl_fixed_vector_t_name mk_lib_stack_trace_windows_funcs
#define mk_sl_fixed_vector_t_element mk_lib_stack_trace_windows_func_t
#define mk_sl_fixed_vector_t_count 62
#include "mk_sl_fixed_vector_inl_filec.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ushort_t mk_win_base_stdcall RtlCaptureStackBackTrace(mk_win_base_ulong_t const frames_to_skip, mk_win_base_ulong_t const frames_to_capture, mk_lib_stack_trace_windows_func_pt const back_trace, mk_win_base_ulong_pt const backtrace_hash) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_rw_construct_void(mk_lib_stack_trace_windows_pt const stack_trace) mk_lang_noexcept
{
	mk_lang_assert(stack_trace);

	mk_lib_stack_trace_windows_funcs_rw_construct(&stack_trace->m_funcs);
	stack_trace->m_hash = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_rw_construct_capture(mk_lib_stack_trace_windows_pt const stack_trace) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_stack_trace_windows_func_pt funcs;
	mk_win_base_ushort_t len;
	mk_win_base_ulong_t hash;

	mk_lang_assert(stack_trace);

	err = mk_lib_stack_trace_windows_rw_construct_void(stack_trace); mk_lang_check_rereturn(err);
	mk_lib_stack_trace_windows_funcs_rw_resize(&stack_trace->m_funcs, mk_lib_stack_trace_windows_funcs_len_v);
	funcs = mk_lib_stack_trace_windows_funcs_rw_data(&stack_trace->m_funcs); mk_lang_assert(funcs);
	len = RtlCaptureStackBackTrace(0, mk_lib_stack_trace_windows_funcs_len_v, funcs, &hash); mk_lang_check_return(len >= 0 && len <= mk_lib_stack_trace_windows_funcs_len_v);
	mk_lib_stack_trace_windows_funcs_rw_resize(&stack_trace->m_funcs, len);
	hash = hash == 0 ? hash + 1 : hash;
	stack_trace->m_hash = hash;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_rw_destruct(mk_lib_stack_trace_windows_pt const stack_trace) mk_lang_noexcept
{
	mk_lang_assert(stack_trace);

	((mk_lang_types_void_t)(stack_trace));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_ro_get_funcs(mk_lib_stack_trace_windows_pct const stack_trace, mk_lib_stack_trace_windows_funcs_ppct const funcs) mk_lang_noexcept
{
	mk_lang_assert(stack_trace);
	mk_lang_assert(funcs);

	*funcs = &stack_trace->m_funcs;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_ro_get_hash(mk_lib_stack_trace_windows_pct const stack_trace, mk_win_base_ulong_pt const hash) mk_lang_noexcept
{
	mk_lang_assert(stack_trace);
	mk_lang_assert(hash);

	*hash = stack_trace->m_hash;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_stack_trace_windows_ro_cmp(mk_lib_stack_trace_windows_pct const a, mk_lib_stack_trace_windows_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_ulong_t hash_a;
	mk_win_base_ulong_t hash_b;
	mk_lib_stack_trace_windows_funcs_pct funcs_a;
	mk_lib_stack_trace_windows_funcs_pct funcs_b;
	mk_lang_types_usize_t len_a;
	mk_lang_types_usize_t len_b;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_stack_trace_windows_func_t func_a;
	mk_lib_stack_trace_windows_func_t func_b;
	mk_lang_types_uintptr_t val_a;
	mk_lang_types_uintptr_t val_b;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	err = mk_lib_stack_trace_windows_ro_get_hash(a, &hash_a); mk_lang_check_rereturn(err);
	err = mk_lib_stack_trace_windows_ro_get_hash(b, &hash_b); mk_lang_check_rereturn(err);
	if(hash_a < hash_b)
	{
		*cmp = -1;
	}
	else if(hash_b < hash_a)
	{
		*cmp = +1;
	}
	else
	{
		err = mk_lib_stack_trace_windows_ro_get_funcs(a, &funcs_a); mk_lang_check_rereturn(err);
		err = mk_lib_stack_trace_windows_ro_get_funcs(b, &funcs_b); mk_lang_check_rereturn(err);
		len_a = mk_lib_stack_trace_windows_funcs_ro_size(funcs_a);
		len_b = mk_lib_stack_trace_windows_funcs_ro_size(funcs_b);
		n = mk_lang_min(len_a, len_b);
		for(i = 0; i != n; ++i)
		{
			func_a = *mk_lib_stack_trace_windows_funcs_ro_at(funcs_a, i);
			func_b = *mk_lib_stack_trace_windows_funcs_ro_at(funcs_b, i);
			val_a = ((mk_lang_types_uintptr_t)(func_a));
			val_b = ((mk_lang_types_uintptr_t)(func_b));
			if(val_a < val_b)
			{
				*cmp = -1;
				break;
			}
			else if(val_b < val_a)
			{
				*cmp = +1;
				break;
			}
		}
		if(i == n)
		{
			if(len_a < len_b)
			{
				*cmp = -1;
			}
			else if(len_b < len_a)
			{
				*cmp = +1;
			}
			else
			{
				*cmp = 0;
			}
		}
	}
	return 0;
}
