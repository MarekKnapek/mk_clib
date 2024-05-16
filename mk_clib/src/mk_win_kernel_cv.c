#include "mk_win_kernel_cv.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_cs.h"
#include "mk_win_kernel_srwl.h"


mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall InitializeConditionVariable(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SleepConditionVariableCS(mk_win_kernel_cv_pt const cv, mk_win_kernel_cs_pt const cs, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SleepConditionVariableSRW(mk_win_kernel_cv_pt const cv, mk_win_kernel_srwl_pt const srwl, mk_win_base_dword_t const timeout, mk_win_base_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall WakeConditionVariable(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall WakeAllConditionVariable(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;


mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_construct(mk_win_kernel_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	InitializeConditionVariable(cv);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_destroy(mk_win_kernel_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	((mk_lang_types_void_t)(cv));
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_cv_wait_cs(mk_win_kernel_cv_pt const cv, mk_win_kernel_cs_pt const cs, mk_win_base_dword_t const timeout) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(cs);

	ret = SleepConditionVariableCS(cv, cs, timeout);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_cv_wait_srwl(mk_win_kernel_cv_pt const cv, mk_win_kernel_srwl_pt const srwl, mk_win_base_dword_t const timeout, mk_win_base_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(srwl);

	ret = SleepConditionVariableSRW(cv, srwl, timeout, flags);
	return ret;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_notify_one(mk_win_kernel_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	WakeConditionVariable(cv);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_notify_all(mk_win_kernel_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	WakeAllConditionVariable(cv);
}
