#ifndef mk_include_guard_mk_win_dll_ntdll_h
#define mk_include_guard_mk_win_dll_ntdll_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_typedef.h"
#include "mk_win_base.h"


mk_lang_forward(mk_win_dll_ws2_ipv4_addr);
mk_lang_forward(mk_win_dll_ws2_ipv6_addr);


typedef mk_lang_types_slong_t mk_win_dll_ntdll_status_t;
mk_lang_typedef(mk_win_dll_ntdll_status);


mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ntdll_status_t mk_win_dll_ntdll_rtl_ipv4_string_to_address_a(mk_lang_types_pchar_pct const str, mk_win_base_boolean_t const strict, mk_lang_types_pchar_ppct const terminator, mk_win_dll_ws2_ipv4_addr_pt const ipv4addr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ntdll_status_t mk_win_dll_ntdll_rtl_ipv6_string_to_address_a(mk_lang_types_pchar_pct const str, mk_lang_types_pchar_ppct const terminator, mk_win_dll_ws2_ipv6_addr_pt const ipv6addr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_ntdll_rtl_compute_crc32(mk_win_base_dword_t const initial, mk_win_base_void_pct const data_buf, mk_win_base_sint_t const data_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_win_dll_ntdll.c"
#endif
#endif
