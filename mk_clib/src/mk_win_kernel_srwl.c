#include "mk_win_kernel_srwl.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall InitializeSRWLock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall AcquireSRWLockExclusive(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall ReleaseSRWLockExclusive(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall AcquireSRWLockShared(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall ReleaseSRWLockShared(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall TryAcquireSRWLockExclusive(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall TryAcquireSRWLockShared(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;


mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_construct(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_lang_assert(srwl);

	InitializeSRWLock(srwl);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_destroy(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_lang_assert(srwl);

	((mk_lang_types_void_t)(srwl));
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_exclusive_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_lang_assert(srwl);

	AcquireSRWLockExclusive(srwl);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_exclusive_unlock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_lang_assert(srwl);

	ReleaseSRWLockExclusive(srwl);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_shared_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_lang_assert(srwl);

	AcquireSRWLockShared(srwl);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_shared_unlock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_lang_assert(srwl);

	ReleaseSRWLockShared(srwl);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_srwl_exclusive_try_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(srwl);

	ret = TryAcquireSRWLockExclusive(srwl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_srwl_shared_try_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(srwl);

	ret = TryAcquireSRWLockShared(srwl);
	return ret;
}
