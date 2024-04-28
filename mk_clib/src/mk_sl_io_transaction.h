#ifndef mk_include_guard_mk_sl_io_transaction
#define mk_include_guard_mk_sl_io_transaction


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_os.h"


#if mk_lang_os == mk_lang_os_windows
#include "mk_sl_io_transaction_windows.h"
struct mk_sl_io_transaction_s
{
	mk_sl_io_transaction_windows_t m_data;
};
#elif mk_lang_os == mk_lang_os_c
#include "mk_sl_io_transaction_portable.h"
struct mk_sl_io_transaction_s
{
	mk_sl_io_transaction_portable_t m_data;
};
#else
#error xxxxxxxxxx todo
#endif
typedef struct mk_sl_io_transaction_s mk_sl_io_transaction_t;
typedef mk_sl_io_transaction_t const mk_sl_io_transaction_ct;
typedef mk_sl_io_transaction_t* mk_sl_io_transaction_pt;
typedef mk_sl_io_transaction_t const* mk_sl_io_transaction_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_create(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_commit(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_abort(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_close(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_dummy(mk_sl_io_transaction_pt const transaction) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_transaction.c"
#endif
#endif