#ifndef mk_include_guard_mk_lib_mt_mutex_windows_srwl
#define mk_include_guard_mk_lib_mt_mutex_windows_srwl


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_kernel_srwl.h"


struct mk_lib_mt_mutex_windows_srwl_s
{
	mk_win_kernel_srwl_t m_mutex;
};
typedef struct mk_lib_mt_mutex_windows_srwl_s mk_lib_mt_mutex_windows_srwl_t;
typedef mk_lib_mt_mutex_windows_srwl_t const mk_lib_mt_mutex_windows_srwl_ct;
typedef mk_lib_mt_mutex_windows_srwl_t* mk_lib_mt_mutex_windows_srwl_pt;
typedef mk_lib_mt_mutex_windows_srwl_t const* mk_lib_mt_mutex_windows_srwl_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_construct(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_destruct(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_exclusive_lock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_exclusive_unlock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_shared_lock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_shared_unlock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_mutex_windows_srwl.c"
#endif
#endif
