#ifndef mk_include_guard_mk_win_kernel_cv
#define mk_include_guard_mk_win_kernel_cv


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_cs.h"
#include "mk_win_kernel_srwl.h"


struct mk_win_kernel_cv_s
{
	mk_win_base_void_pt m_cv;
};
typedef struct mk_win_kernel_cv_s mk_win_kernel_cv_t;
typedef mk_win_kernel_cv_t const mk_win_kernel_cv_ct;
typedef mk_win_kernel_cv_t* mk_win_kernel_cv_pt;
typedef mk_win_kernel_cv_t const* mk_win_kernel_cv_pct;

enum mk_win_kernel_cv_flags_e
{
	mk_win_kernel_cv_flags_e_lockmode_exclusive = 0,
	mk_win_kernel_cv_flags_e_lockmode_shared = 1,
	mk_win_kernel_cv_flags_e_dummy
};
typedef enum mk_win_kernel_cv_flags_e mk_win_kernel_cv_flags_t;


mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_construct(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_destroy(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_cv_wait_cs(mk_win_kernel_cv_pt const cv, mk_win_kernel_cs_pt const cs, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_cv_wait_srwl(mk_win_kernel_cv_pt const cv, mk_win_kernel_srwl_pt const srwl, mk_win_base_dword_t const timeout, mk_win_base_ulong_t const flags) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_notify_one(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cv_notify_all(mk_win_kernel_cv_pt const cv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_cv.c"
#endif
#endif
