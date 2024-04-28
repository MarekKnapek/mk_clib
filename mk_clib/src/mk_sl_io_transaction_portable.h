#ifndef mk_include_guard_mk_sl_io_transaction_portable
#define mk_include_guard_mk_sl_io_transaction_portable


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


struct mk_sl_io_transaction_portable_s
{
	mk_lang_types_sint_t m_dummy;
};
typedef struct mk_sl_io_transaction_portable_s mk_sl_io_transaction_portable_t;
typedef mk_sl_io_transaction_portable_t const mk_sl_io_transaction_portable_ct;
typedef mk_sl_io_transaction_portable_t* mk_sl_io_transaction_portable_pt;
typedef mk_sl_io_transaction_portable_t const* mk_sl_io_transaction_portable_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_portable_create(mk_sl_io_transaction_portable_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_portable_commit(mk_sl_io_transaction_portable_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_portable_abort(mk_sl_io_transaction_portable_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_portable_close(mk_sl_io_transaction_portable_pt const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_transaction_portable_dummy(mk_sl_io_transaction_portable_pt const transaction) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_transaction_portable.c"
#endif
#endif
