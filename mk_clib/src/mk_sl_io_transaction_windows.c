#include "mk_sl_io_transaction_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_ktmw32_transaction.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_create(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept
{
	mk_win_base_handle_t h;

	mk_lang_assert(transaction);

	h = mk_win_ktmw32_transaction_create(mk_win_base_null, mk_win_base_null, mk_win_ktmw32_transaction_options_e_do_not_promote, 0, 0, 0, mk_win_base_null); mk_lang_check_return(h.m_data != mk_win_base_handle_invalid);
	transaction->m_transaction = h;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_commit(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(transaction);

	if(transaction->m_transaction.m_data != mk_win_base_handle_invalid)
	{
		b = mk_win_ktmw32_transaction_commit(transaction->m_transaction); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_abort(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(transaction);

	if(transaction->m_transaction.m_data != mk_win_base_handle_invalid)
	{
		b = mk_win_ktmw32_transaction_rollback(transaction->m_transaction); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_close(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(transaction);

	if(transaction->m_transaction.m_data != mk_win_base_handle_invalid)
	{
		b = mk_win_kernel_handle_close_handle(transaction->m_transaction); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_dummy(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	transaction->m_transaction.m_data = mk_win_base_handle_invalid;
	return 0;
}
