#include "mk_win_ktmw32_transaction.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateTransaction(mk_win_advapi_base_security_attributes_lpct const sa, mk_win_base_guid_lpct const uow, mk_win_base_dword_t const options, mk_win_base_dword_t const isolation_level, mk_win_base_dword_t const isolation_flags, mk_win_base_dword_t const timeout, mk_win_base_wchar_lpct const description) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CommitTransaction(mk_win_base_handle_t const transaction) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall RollbackTransaction(mk_win_base_handle_t const transaction) mk_lang_noexcept;

mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFileTransactedA(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file, mk_win_base_handle_t const transaction, mk_win_base_ushort_lpct const mini_version, mk_win_base_void_lpt const extended) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFileTransactedW(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file, mk_win_base_handle_t const transaction, mk_win_base_ushort_lpct const mini_version, mk_win_base_void_lpt const extended) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_ktmw32_transaction_create(mk_win_advapi_base_security_attributes_lpct const sa, mk_win_base_guid_lpct const uow, mk_win_base_dword_t const options, mk_win_base_dword_t const isolation_level, mk_win_base_dword_t const isolation_flags, mk_win_base_dword_t const timeout, mk_win_base_wchar_lpct const description) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateTransaction(sa, uow, options, isolation_level, isolation_flags, timeout, description);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_ktmw32_transaction_commit(mk_win_base_handle_t const transaction) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CommitTransaction(transaction);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_ktmw32_transaction_rollback(mk_win_base_handle_t const transaction) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = RollbackTransaction(transaction);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_ktmw32_transaction_a_create_file_transacted(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file, mk_win_base_handle_t const transaction, mk_win_base_ushort_lpct const mini_version, mk_win_base_void_lpt const extended) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFileTransactedA(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file, transaction, mini_version, extended);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_ktmw32_transaction_w_create_file_transacted(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file, mk_win_base_handle_t const transaction, mk_win_base_ushort_lpct const mini_version, mk_win_base_void_lpt const extended) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFileTransactedW(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file, transaction, mini_version, extended);
	return ret;
}
