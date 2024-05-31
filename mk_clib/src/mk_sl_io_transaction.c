#include "mk_sl_io_transaction.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_io_transaction_windows.h"
#define mk_sl_io_transaction_impl_create mk_sl_io_transaction_windows_create
#define mk_sl_io_transaction_impl_commit mk_sl_io_transaction_windows_commit
#define mk_sl_io_transaction_impl_abort  mk_sl_io_transaction_windows_abort
#define mk_sl_io_transaction_impl_close  mk_sl_io_transaction_windows_close
#define mk_sl_io_transaction_impl_dummy  mk_sl_io_transaction_windows_dummy
#elif mk_lang_platform == mk_lang_platform_linux
#include "mk_sl_io_transaction_linux.h"
#define mk_sl_io_transaction_impl_create mk_sl_io_transaction_linux_create
#define mk_sl_io_transaction_impl_commit mk_sl_io_transaction_linux_commit
#define mk_sl_io_transaction_impl_abort  mk_sl_io_transaction_linux_abort
#define mk_sl_io_transaction_impl_close  mk_sl_io_transaction_linux_close
#define mk_sl_io_transaction_impl_dummy  mk_sl_io_transaction_linux_dummy
#elif mk_lang_platform == mk_lang_platform_portable
#include "mk_sl_io_transaction_portable.h"
#define mk_sl_io_transaction_impl_create mk_sl_io_transaction_portable_create
#define mk_sl_io_transaction_impl_commit mk_sl_io_transaction_portable_commit
#define mk_sl_io_transaction_impl_abort  mk_sl_io_transaction_portable_abort
#define mk_sl_io_transaction_impl_close  mk_sl_io_transaction_portable_close
#define mk_sl_io_transaction_impl_dummy  mk_sl_io_transaction_portable_dummy
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_create(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	return mk_sl_io_transaction_impl_create(&transaction->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_commit(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	return mk_sl_io_transaction_impl_commit(&transaction->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_abort(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	return mk_sl_io_transaction_impl_abort(&transaction->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_close(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	return mk_sl_io_transaction_impl_close(&transaction->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_dummy(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept
{
	mk_lang_assert(transaction);

	return mk_sl_io_transaction_impl_dummy(&transaction->m_data);
}
