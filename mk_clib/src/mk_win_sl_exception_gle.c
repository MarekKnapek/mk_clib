#include "mk_win_sl_exception_gle.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_kernel_errors.h"


mk_lang_jumbo void mk_win_sl_exception_gle_make_from_id(mk_lang_exception_pt const ex, mk_win_kernel_errors_id_t err_id) mk_lang_noexcept
{
	mk_win_sl_exception_gle_pt win32;

	mk_lang_assert(ex);

	ex->m_id = mk_lang_exception_id_e_win_gle;
	win32 = ((mk_win_sl_exception_gle_pt)(&ex->m_data));
	win32->m_err_id = err_id;
}

mk_lang_jumbo void mk_win_sl_exception_gle_make_from_current(mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_sl_exception_gle_make_from_id(ex, ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last())));
}
