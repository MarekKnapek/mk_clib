#ifndef mk_include_guard_mk_win_ntdll
#define mk_include_guard_mk_win_ntdll


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_ws2_ipv4_addr_s;
typedef struct mk_win_ws2_ipv4_addr_s mk_win_ws2_ipv4_addr_t;
typedef mk_win_ws2_ipv4_addr_t const mk_win_ws2_ipv4_addr_ct;
typedef mk_win_ws2_ipv4_addr_t* mk_win_ws2_ipv4_addr_pt;
typedef mk_win_ws2_ipv4_addr_t const* mk_win_ws2_ipv4_addr_pct;

struct mk_win_ws2_ipv6_addr_s;
typedef struct mk_win_ws2_ipv6_addr_s mk_win_ws2_ipv6_addr_t;
typedef mk_win_ws2_ipv6_addr_t const mk_win_ws2_ipv6_addr_ct;
typedef mk_win_ws2_ipv6_addr_t* mk_win_ws2_ipv6_addr_pt;
typedef mk_win_ws2_ipv6_addr_t const* mk_win_ws2_ipv6_addr_pct;


typedef mk_lang_types_slong_t mk_win_ntdll_status_t;
typedef mk_win_ntdll_status_t const mk_win_ntdll_status_ct;
typedef mk_win_ntdll_status_t* mk_win_ntdll_status_pt;
typedef mk_win_ntdll_status_t const* mk_win_ntdll_status_pct;
typedef mk_win_ntdll_status_t mk_win_base_far* mk_win_ntdll_status_lpt;
typedef mk_win_ntdll_status_t mk_win_base_far const* mk_win_ntdll_status_lpct;
typedef mk_win_ntdll_status_t mk_win_base_near* mk_win_ntdll_status_npt;
typedef mk_win_ntdll_status_t mk_win_base_near const* mk_win_ntdll_status_npct;
typedef mk_win_ntdll_status_t* mk_lang_restrict mk_win_ntdll_status_prt;
typedef mk_win_ntdll_status_t const* mk_lang_restrict mk_win_ntdll_status_prct;
typedef mk_win_ntdll_status_t mk_win_base_far* mk_lang_restrict mk_win_ntdll_status_lprt;
typedef mk_win_ntdll_status_t mk_win_base_far const* mk_lang_restrict mk_win_ntdll_status_lprct;
typedef mk_win_ntdll_status_t mk_win_base_near* mk_lang_restrict mk_win_ntdll_status_nprt;
typedef mk_win_ntdll_status_t mk_win_base_near const* mk_lang_restrict mk_win_ntdll_status_nprct;


mk_lang_nodiscard mk_lang_jumbo mk_win_ntdll_status_t mk_win_ntdll_rtl_ipv4_string_to_address_a(mk_lang_types_pchar_pct const str, mk_win_base_boolean_t const strict, mk_lang_types_pchar_ppct const terminator, mk_win_ws2_ipv4_addr_pt const ipv4addr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_ntdll_status_t mk_win_ntdll_rtl_ipv6_string_to_address_a(mk_lang_types_pchar_pct const str, mk_lang_types_pchar_ppct const terminator, mk_win_ws2_ipv6_addr_pt const ipv6addr) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_ntdll.c"
#endif
#endif
