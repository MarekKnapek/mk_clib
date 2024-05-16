#include "mk_win_kernel_cs.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall InitializeCriticalSection(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall DeleteCriticalSection(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall EnterCriticalSection(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall LeaveCriticalSection(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall TryEnterCriticalSection(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;


mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_construct(mk_win_kernel_cs_pt const cs) mk_lang_noexcept
{
	mk_lang_assert(cs);

	InitializeCriticalSection(cs);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_destroy(mk_win_kernel_cs_pt const cs) mk_lang_noexcept
{
	mk_lang_assert(cs);

	DeleteCriticalSection(cs);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_lock(mk_win_kernel_cs_pt const cs) mk_lang_noexcept
{
	mk_lang_assert(cs);

	EnterCriticalSection(cs);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_unlock(mk_win_kernel_cs_pt const cs) mk_lang_noexcept
{
	mk_lang_assert(cs);

	LeaveCriticalSection(cs);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_cs_try_lock(mk_win_kernel_cs_pt const cs) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cs);

	ret = TryEnterCriticalSection(cs);
	return ret;
}
