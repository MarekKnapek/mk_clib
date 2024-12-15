#ifndef mk_include_guard_mk_lib_mt_mutex_windows_woa
#define mk_include_guard_mk_lib_mt_mutex_windows_woa


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_lib_mt_mutex_windows_woa_s
{
	mk_win_base_slong_t m_mutex;
};
typedef struct mk_lib_mt_mutex_windows_woa_s mk_lib_mt_mutex_windows_woa_t;
typedef mk_lib_mt_mutex_windows_woa_t const mk_lib_mt_mutex_windows_woa_ct;
typedef mk_lib_mt_mutex_windows_woa_t* mk_lib_mt_mutex_windows_woa_pt;
typedef mk_lib_mt_mutex_windows_woa_t const* mk_lib_mt_mutex_windows_woa_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_woa_construct(mk_lib_mt_mutex_windows_woa_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_woa_destruct(mk_lib_mt_mutex_windows_woa_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_woa_exclusive_lock(mk_lib_mt_mutex_windows_woa_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_woa_exclusive_unlock(mk_lib_mt_mutex_windows_woa_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_woa_shared_lock(mk_lib_mt_mutex_windows_woa_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_woa_shared_unlock(mk_lib_mt_mutex_windows_woa_pt const mutex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_mutex_windows_woa.c"
#endif
#endif
