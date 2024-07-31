#ifndef mk_include_guard_mk_lib_mt_cv_windows_cs
#define mk_include_guard_mk_lib_mt_cv_windows_cs


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_windows_cs.h"
#include "mk_win_kernel_cv.h"


struct mk_lib_mt_cv_windows_cs_s
{
	mk_win_kernel_cv_t m_cv;
};
typedef struct mk_lib_mt_cv_windows_cs_s mk_lib_mt_cv_windows_cs_t;
typedef mk_lib_mt_cv_windows_cs_t const mk_lib_mt_cv_windows_cs_ct;
typedef mk_lib_mt_cv_windows_cs_t* mk_lib_mt_cv_windows_cs_pt;
typedef mk_lib_mt_cv_windows_cs_t const* mk_lib_mt_cv_windows_cs_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_construct(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_destruct(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_exclusive(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_exclusive_windows_cs_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_exclusive_for(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_exclusive_windows_cs_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_shared(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_shared_windows_cs_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_shared_for(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_shared_windows_cs_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_notify_one(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_notify_all(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_cv_windows_cs.c"
#endif
#endif
