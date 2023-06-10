#include "mk_win_sl_copier_exception.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo void mk_win_sl_copier_exception_make(mk_lang_exception_pt const ex, mk_win_sl_copier_exception_id_t id) mk_lang_noexcept
{
	mk_win_sl_copier_exception_pt copier_ex;

	mk_lang_assert(ex);

	ex->m_id = mk_lang_exception_id_e_win_sl_copier;
	copier_ex = ((mk_win_sl_copier_exception_pt)(&ex->m_data));
	copier_ex->m_id = id;
}
