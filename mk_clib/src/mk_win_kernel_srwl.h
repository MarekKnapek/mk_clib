#ifndef mk_include_guard_mk_win_kernel_srwl
#define mk_include_guard_mk_win_kernel_srwl


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_kernel_srwl_s
{
	mk_win_base_void_pt m_srwl;
};
typedef struct mk_win_kernel_srwl_s mk_win_kernel_srwl_t;
typedef mk_win_kernel_srwl_t const mk_win_kernel_srwl_ct;
typedef mk_win_kernel_srwl_t* mk_win_kernel_srwl_pt;
typedef mk_win_kernel_srwl_t const* mk_win_kernel_srwl_pct;


mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_construct(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_destroy(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_exclusive_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_exclusive_unlock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_shared_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_srwl_shared_unlock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_srwl_exclusive_try_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_srwl_shared_try_lock(mk_win_kernel_srwl_pt const srwl) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_srwl.c"
#endif
#endif
