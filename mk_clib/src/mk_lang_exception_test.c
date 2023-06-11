#include "mk_lang_exception_test.h"

#include "mk_lang_exception.h"
#include "mk_lang_exception_data.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"


mk_lang_jumbo void mk_lang_exception_test(void) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_lang_exception_data_t exdata;

	mk_lang_static_assert(sizeof(ex.m_data) >= sizeof(exdata));
}
