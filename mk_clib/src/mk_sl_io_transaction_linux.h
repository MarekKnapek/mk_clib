#ifndef mk_include_guard_mk_sl_io_transaction_linux
#define mk_include_guard_mk_sl_io_transaction_linux


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


struct mk_sl_io_transaction_linux_s
{
	mk_lang_types_sint_t m_dummy;
};
typedef struct mk_sl_io_transaction_linux_s mk_sl_io_transaction_linux_t;
typedef mk_sl_io_transaction_linux_t const mk_sl_io_transaction_linux_ct;
typedef mk_sl_io_transaction_linux_t* mk_sl_io_transaction_linux_pt;
typedef mk_sl_io_transaction_linux_t const* mk_sl_io_transaction_linux_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_create(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_commit(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_abort(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_close(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_linux_dummy(mk_sl_io_transaction_linux_pt const transaction) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_transaction_linux.c"
#endif
#endif
