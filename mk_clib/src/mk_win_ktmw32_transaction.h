#ifndef mk_include_guard_mk_win_ktmw32_transaction
#define mk_include_guard_mk_win_ktmw32_transaction


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"


enum mk_win_ktmw32_transaction_options_e
{
	mk_win_ktmw32_transaction_options_e_do_not_promote = 1,
	mk_win_ktmw32_transaction_options_e_dummy_end
};
typedef enum mk_win_ktmw32_transaction_options_e mk_win_ktmw32_transaction_options_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_ktmw32_transaction_create(mk_win_advapi_base_security_attributes_lpct const sa, mk_win_base_guid_lpct const uow, mk_win_base_dword_t const options, mk_win_base_dword_t const isolation_level, mk_win_base_dword_t const isolation_flags, mk_win_base_dword_t const timeout, mk_win_base_wchar_lpct const description) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_ktmw32_transaction_commit(mk_win_base_handle_t const transaction) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_ktmw32_transaction_rollback(mk_win_base_handle_t const transaction) mk_lang_noexcept;


enum mk_win_ktmw32_transaction_txfs_miniversion_view_e
{
	mk_win_ktmw32_transaction_txfs_miniversion_view_e_default   = ((mk_win_base_ushort_t)(0xfffeul)),
	mk_win_ktmw32_transaction_txfs_miniversion_view_e_dirty     = ((mk_win_base_ushort_t)(0xfffful)),
	mk_win_ktmw32_transaction_txfs_miniversion_view_e_committed = ((mk_win_base_ushort_t)(0x0000ul)),
	mk_win_ktmw32_transaction_txfs_miniversion_view_e_dummy_end
};
typedef enum mk_win_ktmw32_transaction_txfs_miniversion_view_e mk_win_ktmw32_transaction_txfs_miniversion_view_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_ktmw32_transaction_a_create_file_transacted(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file, mk_win_base_handle_t const transaction, mk_win_base_ushort_lpct const mini_version, mk_win_base_void_lpt const extended) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_ktmw32_transaction_w_create_file_transacted(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file, mk_win_base_handle_t const transaction, mk_win_base_ushort_lpct const mini_version, mk_win_base_void_lpt const extended) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_ktmw32_transaction.c"
#endif
#endif
