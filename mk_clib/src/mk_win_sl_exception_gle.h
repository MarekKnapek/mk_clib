#ifndef mk_include_guard_mk_win_sl_exception_gle
#define mk_include_guard_mk_win_sl_exception_gle


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_kernel_errors.h"


struct mk_win_sl_exception_gle_s
{
	mk_win_kernel_errors_id_t m_err_id;
};
typedef struct mk_win_sl_exception_gle_s mk_win_sl_exception_gle_t;
typedef mk_win_sl_exception_gle_t const mk_win_sl_exception_gle_ct;
typedef mk_win_sl_exception_gle_t* mk_win_sl_exception_gle_pt;
typedef mk_win_sl_exception_gle_t const* mk_win_sl_exception_gle_pct;


mk_lang_jumbo void mk_win_sl_exception_gle_make_from_id(mk_lang_exception_pt const ex, mk_win_kernel_errors_id_t err_id) mk_lang_noexcept;
mk_lang_jumbo void mk_win_sl_exception_gle_make_from_current(mk_lang_exception_pt const ex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_sl_exception_gle.c"
#endif
#endif
