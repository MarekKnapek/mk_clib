#include "mk_lang_exception.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_lang_exception_make_none(mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(ex);

	ex->m_id = mk_lang_exception_id_e_none;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_exception_is(mk_lang_exception_pct const ex) mk_lang_noexcept
{
	mk_lang_assert(ex);

	return ex->m_id != mk_lang_exception_id_e_none;
}
