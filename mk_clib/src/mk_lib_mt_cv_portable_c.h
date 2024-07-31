#ifndef mk_include_guard_mk_lib_mt_cv_portable_c
#define mk_include_guard_mk_lib_mt_cv_portable_c


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_portable_c.h"

#include <threads.h> /* cnd_t */


struct mk_lib_mt_cv_portable_c_s
{
	cnd_t m_cv;
};
typedef struct mk_lib_mt_cv_portable_c_s mk_lib_mt_cv_portable_c_t;
typedef mk_lib_mt_cv_portable_c_t const mk_lib_mt_cv_portable_c_ct;
typedef mk_lib_mt_cv_portable_c_t* mk_lib_mt_cv_portable_c_pt;
typedef mk_lib_mt_cv_portable_c_t const* mk_lib_mt_cv_portable_c_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_construct(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_destruct(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_exclusive(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_c_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_exclusive_for(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_c_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_shared(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_shared_portable_c_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_shared_for(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_shared_portable_c_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_notify_one(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_notify_all(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_cv_portable_c.c"
#endif
#endif
