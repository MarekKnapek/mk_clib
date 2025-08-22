#ifndef mk_include_guard_mk_win_dll_ntdll_c
#define mk_include_guard_mk_win_dll_ntdll_c
#include "mk_win_dll_ntdll.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#if mk_lang_msvc_ver != 0
#pragma comment(lib, "ntdll.lib")
#endif


mk_lang_extern_force_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall RtlZeroMemory(mk_lang_types_void_pt const dst, mk_lang_types_usize_t const cnt) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_lang_types_usize_t mk_win_base_stdcall RtlCompareMemory(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b, mk_lang_types_usize_t const c) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ntdll_status_t mk_win_base_stdcall RtlIpv4StringToAddressA(mk_lang_types_pchar_pct const str, mk_win_base_boolean_t const strict, mk_lang_types_pchar_ppct const terminator, mk_win_dll_ws2_ipv4_addr_pt const ipv4addr) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ntdll_status_t mk_win_base_stdcall RtlIpv6StringToAddressA(mk_lang_types_pchar_pct const str, mk_lang_types_pchar_ppct const terminator, mk_win_dll_ws2_ipv6_addr_pt const ipv6addr) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall RtlComputeCrc32(mk_win_base_dword_t const initial, mk_win_base_void_pct const data_buf, mk_win_base_sint_t const data_len) mk_lang_noexcept;


mk_lang_jumbo mk_lang_types_void_t mk_win_dll_ntdll_rtl_zero_memory(mk_lang_types_void_pt const dst, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	RtlZeroMemory(dst, cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_win_dll_ntdll_rtl_compare_memory(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b, mk_lang_types_usize_t const c) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = RtlCompareMemory(a, b, c);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ntdll_status_t mk_win_dll_ntdll_rtl_ipv4_string_to_address_a(mk_lang_types_pchar_pct const str, mk_win_base_boolean_t const strict, mk_lang_types_pchar_ppct const terminator, mk_win_dll_ws2_ipv4_addr_pt const ipv4addr) mk_lang_noexcept
{
	mk_win_dll_ntdll_status_t ret;

	ret = RtlIpv4StringToAddressA(str, strict, terminator, ipv4addr);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ntdll_status_t mk_win_dll_ntdll_rtl_ipv6_string_to_address_a(mk_lang_types_pchar_pct const str, mk_lang_types_pchar_ppct const terminator, mk_win_dll_ws2_ipv6_addr_pt const ipv6addr) mk_lang_noexcept
{
	mk_win_dll_ntdll_status_t ret;

	ret = RtlIpv6StringToAddressA(str, terminator, ipv6addr);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_ntdll_rtl_compute_crc32(mk_win_base_dword_t const initial, mk_win_base_void_pct const data_buf, mk_win_base_sint_t const data_len) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = RtlComputeCrc32(initial, data_buf, data_len);
	return ret;
}


#else
static void mk_win_dll_ntdll_dummy(void){}
#endif
#endif
