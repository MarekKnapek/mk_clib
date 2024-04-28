#ifndef mk_include_guard_mk_sl_io_transaction_windows
#define mk_include_guard_mk_sl_io_transaction_windows


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_sl_io_transaction_windows_s
{
	mk_win_base_handle_t m_transaction;
};
typedef struct mk_sl_io_transaction_windows_s mk_sl_io_transaction_windows_t;
typedef mk_sl_io_transaction_windows_t const mk_sl_io_transaction_windows_ct;
typedef mk_sl_io_transaction_windows_t* mk_sl_io_transaction_windows_pt;
typedef mk_sl_io_transaction_windows_t const* mk_sl_io_transaction_windows_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_create(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_commit(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_abort(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_close(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_windows_dummy(mk_sl_io_transaction_windows_pt const transaction) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_transaction_windows.c"
#endif
#endif
