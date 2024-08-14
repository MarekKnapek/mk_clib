#ifndef mk_include_guard_mk_lib_mt_cv_posix
#define mk_include_guard_mk_lib_mt_cv_posix


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"


#if mk_lang_platform_is_posix_at_least_1


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_posix.h"

#include <pthread.h> /* pthread_cond_t */


struct mk_lib_mt_cv_posix_s
{
	pthread_cond_t m_cv;
};
typedef struct mk_lib_mt_cv_posix_s mk_lib_mt_cv_posix_t;
typedef mk_lib_mt_cv_posix_t const mk_lib_mt_cv_posix_ct;
typedef mk_lib_mt_cv_posix_t* mk_lib_mt_cv_posix_pt;
typedef mk_lib_mt_cv_posix_t const* mk_lib_mt_cv_posix_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_construct(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_destruct(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_exclusive(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_exclusive_posix_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_exclusive_for(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_exclusive_posix_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_shared(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_shared_posix_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_shared_for(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_shared_posix_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_notify_one(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_notify_all(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_cv_posix.c"
#endif
#endif
