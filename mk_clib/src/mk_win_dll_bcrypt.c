#ifndef mk_include_guard_mk_win_dll_bcrypt_c
#define mk_include_guard_mk_win_dll_bcrypt_c
#include "mk_win_dll_bcrypt.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#if mk_lang_msvc_ver != 0
#pragma comment(lib, "bcrypt.lib")
#endif


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptOpenAlgorithmProvider(mk_win_dll_bcrypt_provider_pt const provider, mk_win_base_wchar_pct const alg_id, mk_win_base_wchar_pct const implementation, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptCloseAlgorithmProvider(mk_win_dll_bcrypt_provider_t const provider, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptGetProperty(mk_win_dll_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_void_pt const data_buf, mk_lang_types_ulong_t const data_len_provided, mk_lang_types_ulong_pt const data_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptSetProperty(mk_win_dll_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_void_pct const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptCreateHash(mk_win_dll_bcrypt_provider_t const provider, mk_win_dll_bcrypt_hash_pt const hasher, mk_lang_types_void_pt const obj_buf, mk_lang_types_ulong_t const obj_len, mk_lang_types_void_pct const secret_buf, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptDestroyHash(mk_win_dll_bcrypt_hash_t const hasher) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptHashData(mk_win_dll_bcrypt_hash_t const hasher, mk_lang_types_void_pct const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptFinishHash(mk_win_dll_bcrypt_hash_t const hasher, mk_lang_types_void_pt const digest_buf, mk_lang_types_ulong_t const digest_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptGenerateSymmetricKey(mk_win_dll_bcrypt_provider_t const provider, mk_win_dll_bcrypt_key_pt const key_obj, mk_lang_types_void_pt const key_buf, mk_lang_types_ulong_t const key_len, mk_lang_types_void_pct const secret_buf, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptDestroyKey(mk_win_dll_bcrypt_key_t const key) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptKeyDerivation(mk_win_dll_bcrypt_key_t const key, mk_win_dll_bcrypt_buffers_descriptions_pt const parameter_list, mk_lang_types_void_pt const key_buf, mk_lang_types_ulong_t const key_len, mk_lang_types_ulong_pt const out_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptDeriveKeyPBKDF2(mk_win_dll_bcrypt_provider_t const prf, mk_win_base_void_pct const password_buf, mk_win_base_ulong_t const password_len, mk_win_base_void_pct const salt_buf, mk_win_base_ulong_t const salt_len, mk_win_base_ullong_t const iterations, mk_win_base_void_pt const key_buf, mk_win_base_ulong_t const key_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptEncrypt(mk_win_dll_bcrypt_key_t const key, mk_lang_types_void_pct const msg_buf, mk_lang_types_ulong_t const msg_len, mk_lang_types_void_pct const padding, mk_lang_types_void_pt const iv_buf, mk_lang_types_ulong_t const iv_len, mk_lang_types_void_pt const out_buf, mk_lang_types_ulong_t const out_len_provided, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ntstatus_t mk_win_base_stdcall BCryptDecrypt(mk_win_dll_bcrypt_key_t const key, mk_lang_types_void_pct const msg_buf, mk_lang_types_ulong_t const msg_len, mk_lang_types_void_pct const padding, mk_lang_types_void_pt const iv_buf, mk_lang_types_ulong_t const iv_len, mk_lang_types_void_pt const out_buf, mk_lang_types_ulong_t const out_len_provided, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_open_algorithm_provider(mk_win_dll_bcrypt_provider_pt const provider, mk_win_base_wchar_pct const alg_id, mk_win_base_wchar_pct const implementation, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptOpenAlgorithmProvider(provider, alg_id, implementation, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_close_algorithm_provider(mk_win_dll_bcrypt_provider_t const provider, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptCloseAlgorithmProvider(provider, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_get_property(mk_win_dll_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_void_pt const data_buf, mk_lang_types_ulong_t const data_len_provided, mk_lang_types_ulong_pt const data_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptGetProperty(handle, property, data_buf, data_len_provided, data_len_real, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_set_property(mk_win_dll_bcrypt_handle_t const handle, mk_win_base_wchar_pct const property, mk_lang_types_void_pct const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptSetProperty(handle, property, data_buf, data_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_create_hash(mk_win_dll_bcrypt_provider_t const provider, mk_win_dll_bcrypt_hash_pt const hasher, mk_lang_types_void_pt const obj_buf, mk_lang_types_ulong_t const obj_len, mk_lang_types_void_pct const secret_buf, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptCreateHash(provider, hasher, obj_buf, obj_len, secret_buf, secret_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_destroy_hash(mk_win_dll_bcrypt_hash_t const hasher) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptDestroyHash(hasher);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_hash_data(mk_win_dll_bcrypt_hash_t const hasher, mk_lang_types_void_pct const data_buf, mk_lang_types_ulong_t const data_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptHashData(hasher, data_buf, data_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_finish_hash(mk_win_dll_bcrypt_hash_t const hasher, mk_lang_types_void_pt const digest_buf, mk_lang_types_ulong_t const digest_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptFinishHash(hasher, digest_buf, digest_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_generate_symmetric_key(mk_win_dll_bcrypt_provider_t const provider, mk_win_dll_bcrypt_key_pt const key_obj, mk_lang_types_void_pt const key_buf, mk_lang_types_ulong_t const key_len, mk_lang_types_void_pct const secret_buf, mk_lang_types_ulong_t const secret_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptGenerateSymmetricKey(provider, key_obj, key_buf, key_len, secret_buf, secret_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_destroy_key(mk_win_dll_bcrypt_key_t const key) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptDestroyKey(key);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_key_derivation(mk_win_dll_bcrypt_key_t const key, mk_win_dll_bcrypt_buffers_descriptions_pt const parameter_list, mk_lang_types_void_pt const key_buf, mk_lang_types_ulong_t const key_len, mk_lang_types_ulong_pt const out_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptKeyDerivation(key, parameter_list, key_buf, key_len, out_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_pbkdf2(mk_win_dll_bcrypt_provider_t const prf, mk_win_base_void_pct const password_buf, mk_win_base_ulong_t const password_len, mk_win_base_void_pct const salt_buf, mk_win_base_ulong_t const salt_len, mk_win_base_ullong_t const iterations, mk_win_base_void_pt const key_buf, mk_win_base_ulong_t const key_len, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptDeriveKeyPBKDF2(prf, password_buf, password_len, salt_buf, salt_len, iterations, key_buf, key_len, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_encrypt(mk_win_dll_bcrypt_key_t const key, mk_lang_types_void_pct const msg_buf, mk_lang_types_ulong_t const msg_len, mk_lang_types_void_pct const padding, mk_lang_types_void_pt const iv_buf, mk_lang_types_ulong_t const iv_len, mk_lang_types_void_pt const out_buf, mk_lang_types_ulong_t const out_len_provided, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptEncrypt(key, msg_buf, msg_len, padding, iv_buf, iv_len, out_buf, out_len_provided, out_len_real, flags);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ntstatus_t mk_win_dll_bcrypt_decrypt(mk_win_dll_bcrypt_key_t const key, mk_lang_types_void_pct const msg_buf, mk_lang_types_ulong_t const msg_len, mk_lang_types_void_pct const padding, mk_lang_types_void_pt const iv_buf, mk_lang_types_ulong_t const iv_len, mk_lang_types_void_pt const out_buf, mk_lang_types_ulong_t const out_len_provided, mk_lang_types_ulong_pt const out_len_real, mk_lang_types_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_ntstatus_t res;

	res = BCryptDecrypt(key, msg_buf, msg_len, padding, iv_buf, iv_len, out_buf, out_len_provided, out_len_real, flags);
	return res;
}


#else
static void mk_win_dll_bcrypt_dummy(void){}
#endif
#endif
