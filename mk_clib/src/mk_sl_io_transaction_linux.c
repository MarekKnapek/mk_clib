#include "mk_sl_io_transaction_linux.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_create(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_commit(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	if(transaction->m_dummy != -1)
	{
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_abort(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	if(transaction->m_dummy != -1)
	{
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_close(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	if(transaction->m_dummy != -1)
	{
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_dummy(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	transaction->m_dummy = -1;
	return 0;
}
