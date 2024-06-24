#ifndef mk_include_guard_mk_win_base
#define mk_include_guard_mk_win_base


#include "mk_lang_arch.h"
#include "mk_lang_bitness.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_restrict.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


#define mk_win_base_arch_16 3001
#define mk_win_base_arch_32 3002
#define mk_win_base_arch_64 3003

#if mk_lang_bitness == mk_lang_bitness_16
#define mk_win_base_arch mk_win_base_arch_16
#elif mk_lang_bitness == mk_lang_bitness_32
#define mk_win_base_arch mk_win_base_arch_32
#elif mk_lang_bitness == mk_lang_bitness_64
#define mk_win_base_arch mk_win_base_arch_64
#else
#error xxxxxxxxxx
#endif

#if mk_win_base_arch == mk_win_base_arch_16
#define mk_win_base_far __far
#define mk_win_base_near __near
#else
#define mk_win_base_far
#define mk_win_base_near
#endif

#define mk_win_base_dll_export __declspec(dllexport)
#define mk_win_base_dll_import __declspec(dllimport)

#define mk_win_base_cdecl __cdecl
#define mk_win_base_clrcall __clrcall
#define mk_win_base_fastcall __fastcall
#define mk_win_base_stdcall __stdcall
#define mk_win_base_thiscall __thiscall
#define mk_win_base_vectorcall __vectorcall

#define mk_win_base_anysize_array 1
#define mk_win_base_null mk_lang_null
#define mk_win_base_false ((mk_win_base_bool_t)(0))
#define mk_win_base_true ((mk_win_base_bool_t)(1))
#define mk_win_base_infinite ((mk_win_base_dword_t)(0xfffffffful))
#define mk_win_base_proc_not_found ((mk_win_base_proc_t)(0x100))
#define mk_win_base_handle_null ((mk_win_base_void_pct)(((mk_win_base_uintptr_t)(0))))
#define mk_win_base_handle_invalid ((mk_win_base_void_pct)(((mk_win_base_sintptr_t)(-1))))
#define mk_win_base_page_4k (4ul * 1024ul)
#define mk_win_base_page_64k (64ul * 1024ul)
#define mk_win_base_page_2m (2ul * 1024ul * 1024ul)

typedef mk_lang_types_void_t mk_win_base_void_t;
typedef mk_win_base_void_t const mk_win_base_void_ct;
typedef mk_win_base_void_t* mk_win_base_void_pt;
typedef mk_win_base_void_t const* mk_win_base_void_pct;
typedef mk_win_base_void_t mk_win_base_far* mk_win_base_void_lpt;
typedef mk_win_base_void_t mk_win_base_far const* mk_win_base_void_lpct;
typedef mk_win_base_void_t mk_win_base_near* mk_win_base_void_npt;
typedef mk_win_base_void_t mk_win_base_near const* mk_win_base_void_npct;
typedef mk_win_base_void_t* mk_lang_restrict mk_win_base_void_prt;
typedef mk_win_base_void_t const* mk_lang_restrict mk_win_base_void_prct;
typedef mk_win_base_void_t mk_win_base_far* mk_lang_restrict mk_win_base_void_lprt;
typedef mk_win_base_void_t mk_win_base_far const* mk_lang_restrict mk_win_base_void_lprct;
typedef mk_win_base_void_t mk_win_base_near* mk_lang_restrict mk_win_base_void_nprt;
typedef mk_win_base_void_t mk_win_base_near const* mk_lang_restrict mk_win_base_void_nprct;

typedef mk_win_base_void_lpt* mk_win_base_void_plpt;

typedef mk_lang_types_uint_t mk_win_base_bool_t;
typedef mk_win_base_bool_t const mk_win_base_bool_ct;
typedef mk_win_base_bool_t* mk_win_base_bool_pt;
typedef mk_win_base_bool_t const* mk_win_base_bool_pct;
typedef mk_win_base_bool_t mk_win_base_far* mk_win_base_bool_lpt;
typedef mk_win_base_bool_t mk_win_base_far const* mk_win_base_bool_lpct;
typedef mk_win_base_bool_t mk_win_base_near* mk_win_base_bool_npt;
typedef mk_win_base_bool_t mk_win_base_near const* mk_win_base_bool_npct;
typedef mk_win_base_bool_t* mk_lang_restrict mk_win_base_bool_prt;
typedef mk_win_base_bool_t const* mk_lang_restrict mk_win_base_bool_prct;
typedef mk_win_base_bool_t mk_win_base_far* mk_lang_restrict mk_win_base_bool_lprt;
typedef mk_win_base_bool_t mk_win_base_far const* mk_lang_restrict mk_win_base_bool_lprct;
typedef mk_win_base_bool_t mk_win_base_near* mk_lang_restrict mk_win_base_bool_nprt;
typedef mk_win_base_bool_t mk_win_base_near const* mk_lang_restrict mk_win_base_bool_nprct;

typedef mk_lang_types_uchar_t mk_win_base_boolean_t;
typedef mk_win_base_boolean_t const mk_win_base_boolean_ct;
typedef mk_win_base_boolean_t* mk_win_base_boolean_pt;
typedef mk_win_base_boolean_t const* mk_win_base_boolean_pct;
typedef mk_win_base_boolean_t mk_win_base_far* mk_win_base_boolean_lpt;
typedef mk_win_base_boolean_t mk_win_base_far const* mk_win_base_boolean_lpct;
typedef mk_win_base_boolean_t mk_win_base_near* mk_win_base_boolean_npt;
typedef mk_win_base_boolean_t mk_win_base_near const* mk_win_base_boolean_npct;
typedef mk_win_base_boolean_t* mk_lang_restrict mk_win_base_boolean_prt;
typedef mk_win_base_boolean_t const* mk_lang_restrict mk_win_base_boolean_prct;
typedef mk_win_base_boolean_t mk_win_base_far* mk_lang_restrict mk_win_base_boolean_lprt;
typedef mk_win_base_boolean_t mk_win_base_far const* mk_lang_restrict mk_win_base_boolean_lprct;
typedef mk_win_base_boolean_t mk_win_base_near* mk_lang_restrict mk_win_base_boolean_nprt;
typedef mk_win_base_boolean_t mk_win_base_near const* mk_lang_restrict mk_win_base_boolean_nprct;

typedef mk_lang_types_pchar_t mk_win_base_pchar_t;
typedef mk_win_base_pchar_t const mk_win_base_pchar_ct;
typedef mk_win_base_pchar_t* mk_win_base_pchar_pt;
typedef mk_win_base_pchar_t const* mk_win_base_pchar_pct;
typedef mk_win_base_pchar_t mk_win_base_far* mk_win_base_pchar_lpt;
typedef mk_win_base_pchar_t mk_win_base_far const* mk_win_base_pchar_lpct;
typedef mk_win_base_pchar_t mk_win_base_near* mk_win_base_pchar_npt;
typedef mk_win_base_pchar_t mk_win_base_near const* mk_win_base_pchar_npct;
typedef mk_win_base_pchar_t* mk_lang_restrict mk_win_base_pchar_prt;
typedef mk_win_base_pchar_t const* mk_lang_restrict mk_win_base_pchar_prct;
typedef mk_win_base_pchar_t mk_win_base_far* mk_lang_restrict mk_win_base_pchar_lprt;
typedef mk_win_base_pchar_t mk_win_base_far const* mk_lang_restrict mk_win_base_pchar_lprct;
typedef mk_win_base_pchar_t mk_win_base_near* mk_lang_restrict mk_win_base_pchar_nprt;
typedef mk_win_base_pchar_t mk_win_base_near const* mk_lang_restrict mk_win_base_pchar_nprct;

typedef mk_lang_types_uchar_t mk_win_base_uchar_t;
typedef mk_win_base_uchar_t const mk_win_base_uchar_ct;
typedef mk_win_base_uchar_t* mk_win_base_uchar_pt;
typedef mk_win_base_uchar_t const* mk_win_base_uchar_pct;
typedef mk_win_base_uchar_t mk_win_base_far* mk_win_base_uchar_lpt;
typedef mk_win_base_uchar_t mk_win_base_far const* mk_win_base_uchar_lpct;
typedef mk_win_base_uchar_t mk_win_base_near* mk_win_base_uchar_npt;
typedef mk_win_base_uchar_t mk_win_base_near const* mk_win_base_uchar_npct;
typedef mk_win_base_uchar_t* mk_lang_restrict mk_win_base_uchar_prt;
typedef mk_win_base_uchar_t const* mk_lang_restrict mk_win_base_uchar_prct;
typedef mk_win_base_uchar_t mk_win_base_far* mk_lang_restrict mk_win_base_uchar_lprt;
typedef mk_win_base_uchar_t mk_win_base_far const* mk_lang_restrict mk_win_base_uchar_lprct;
typedef mk_win_base_uchar_t mk_win_base_near* mk_lang_restrict mk_win_base_uchar_nprt;
typedef mk_win_base_uchar_t mk_win_base_near const* mk_lang_restrict mk_win_base_uchar_nprct;

typedef mk_lang_types_schar_t mk_win_base_schar_t;
typedef mk_win_base_schar_t const mk_win_base_schar_ct;
typedef mk_win_base_schar_t* mk_win_base_schar_pt;
typedef mk_win_base_schar_t const* mk_win_base_schar_pct;
typedef mk_win_base_schar_t mk_win_base_far* mk_win_base_schar_lpt;
typedef mk_win_base_schar_t mk_win_base_far const* mk_win_base_schar_lpct;
typedef mk_win_base_schar_t mk_win_base_near* mk_win_base_schar_npt;
typedef mk_win_base_schar_t mk_win_base_near const* mk_win_base_schar_npct;
typedef mk_win_base_schar_t* mk_lang_restrict mk_win_base_schar_prt;
typedef mk_win_base_schar_t const* mk_lang_restrict mk_win_base_schar_prct;
typedef mk_win_base_schar_t mk_win_base_far* mk_lang_restrict mk_win_base_schar_lprt;
typedef mk_win_base_schar_t mk_win_base_far const* mk_lang_restrict mk_win_base_schar_lprct;
typedef mk_win_base_schar_t mk_win_base_near* mk_lang_restrict mk_win_base_schar_nprt;
typedef mk_win_base_schar_t mk_win_base_near const* mk_lang_restrict mk_win_base_schar_nprct;

typedef mk_lang_types_wchar_t mk_win_base_wchar_t;
typedef mk_win_base_wchar_t const mk_win_base_wchar_ct;
typedef mk_win_base_wchar_t* mk_win_base_wchar_pt;
typedef mk_win_base_wchar_t const* mk_win_base_wchar_pct;
typedef mk_win_base_wchar_t mk_win_base_far* mk_win_base_wchar_lpt;
typedef mk_win_base_wchar_t mk_win_base_far const* mk_win_base_wchar_lpct;
typedef mk_win_base_wchar_t mk_win_base_near* mk_win_base_wchar_npt;
typedef mk_win_base_wchar_t mk_win_base_near const* mk_win_base_wchar_npct;
typedef mk_win_base_wchar_t* mk_lang_restrict mk_win_base_wchar_prt;
typedef mk_win_base_wchar_t const* mk_lang_restrict mk_win_base_wchar_prct;
typedef mk_win_base_wchar_t mk_win_base_far* mk_lang_restrict mk_win_base_wchar_lprt;
typedef mk_win_base_wchar_t mk_win_base_far const* mk_lang_restrict mk_win_base_wchar_lprct;
typedef mk_win_base_wchar_t mk_win_base_near* mk_lang_restrict mk_win_base_wchar_nprt;
typedef mk_win_base_wchar_t mk_win_base_near const* mk_lang_restrict mk_win_base_wchar_nprct;

typedef mk_lang_types_ushort_t mk_win_base_ushort_t;
typedef mk_win_base_ushort_t const mk_win_base_ushort_ct;
typedef mk_win_base_ushort_t* mk_win_base_ushort_pt;
typedef mk_win_base_ushort_t const* mk_win_base_ushort_pct;
typedef mk_win_base_ushort_t mk_win_base_far* mk_win_base_ushort_lpt;
typedef mk_win_base_ushort_t mk_win_base_far const* mk_win_base_ushort_lpct;
typedef mk_win_base_ushort_t mk_win_base_near* mk_win_base_ushort_npt;
typedef mk_win_base_ushort_t mk_win_base_near const* mk_win_base_ushort_npct;
typedef mk_win_base_ushort_t* mk_lang_restrict mk_win_base_ushort_prt;
typedef mk_win_base_ushort_t const* mk_lang_restrict mk_win_base_ushort_prct;
typedef mk_win_base_ushort_t mk_win_base_far* mk_lang_restrict mk_win_base_ushort_lprt;
typedef mk_win_base_ushort_t mk_win_base_far const* mk_lang_restrict mk_win_base_ushort_lprct;
typedef mk_win_base_ushort_t mk_win_base_near* mk_lang_restrict mk_win_base_ushort_nprt;
typedef mk_win_base_ushort_t mk_win_base_near const* mk_lang_restrict mk_win_base_ushort_nprct;

typedef mk_lang_types_sshort_t mk_win_base_sshort_t;
typedef mk_win_base_sshort_t const mk_win_base_sshort_ct;
typedef mk_win_base_sshort_t* mk_win_base_sshort_pt;
typedef mk_win_base_sshort_t const* mk_win_base_sshort_pct;
typedef mk_win_base_sshort_t mk_win_base_far* mk_win_base_sshort_lpt;
typedef mk_win_base_sshort_t mk_win_base_far const* mk_win_base_sshort_lpct;
typedef mk_win_base_sshort_t mk_win_base_near* mk_win_base_sshort_npt;
typedef mk_win_base_sshort_t mk_win_base_near const* mk_win_base_sshort_npct;
typedef mk_win_base_sshort_t* mk_lang_restrict mk_win_base_sshort_prt;
typedef mk_win_base_sshort_t const* mk_lang_restrict mk_win_base_sshort_prct;
typedef mk_win_base_sshort_t mk_win_base_far* mk_lang_restrict mk_win_base_sshort_lprt;
typedef mk_win_base_sshort_t mk_win_base_far const* mk_lang_restrict mk_win_base_sshort_lprct;
typedef mk_win_base_sshort_t mk_win_base_near* mk_lang_restrict mk_win_base_sshort_nprt;
typedef mk_win_base_sshort_t mk_win_base_near const* mk_lang_restrict mk_win_base_sshort_nprct;

typedef mk_lang_types_uint_t mk_win_base_uint_t;
typedef mk_win_base_uint_t const mk_win_base_uint_ct;
typedef mk_win_base_uint_t* mk_win_base_uint_pt;
typedef mk_win_base_uint_t const* mk_win_base_uint_pct;
typedef mk_win_base_uint_t mk_win_base_far* mk_win_base_uint_lpt;
typedef mk_win_base_uint_t mk_win_base_far const* mk_win_base_uint_lpct;
typedef mk_win_base_uint_t mk_win_base_near* mk_win_base_uint_npt;
typedef mk_win_base_uint_t mk_win_base_near const* mk_win_base_uint_npct;
typedef mk_win_base_uint_t* mk_lang_restrict mk_win_base_uint_prt;
typedef mk_win_base_uint_t const* mk_lang_restrict mk_win_base_uint_prct;
typedef mk_win_base_uint_t mk_win_base_far* mk_lang_restrict mk_win_base_uint_lprt;
typedef mk_win_base_uint_t mk_win_base_far const* mk_lang_restrict mk_win_base_uint_lprct;
typedef mk_win_base_uint_t mk_win_base_near* mk_lang_restrict mk_win_base_uint_nprt;
typedef mk_win_base_uint_t mk_win_base_near const* mk_lang_restrict mk_win_base_uint_nprct;

typedef mk_lang_types_sint_t mk_win_base_sint_t;
typedef mk_win_base_sint_t const mk_win_base_sint_ct;
typedef mk_win_base_sint_t* mk_win_base_sint_pt;
typedef mk_win_base_sint_t const* mk_win_base_sint_pct;
typedef mk_win_base_sint_t mk_win_base_far* mk_win_base_sint_lpt;
typedef mk_win_base_sint_t mk_win_base_far const* mk_win_base_sint_lpct;
typedef mk_win_base_sint_t mk_win_base_near* mk_win_base_sint_npt;
typedef mk_win_base_sint_t mk_win_base_near const* mk_win_base_sint_npct;
typedef mk_win_base_sint_t* mk_lang_restrict mk_win_base_sint_prt;
typedef mk_win_base_sint_t const* mk_lang_restrict mk_win_base_sint_prct;
typedef mk_win_base_sint_t mk_win_base_far* mk_lang_restrict mk_win_base_sint_lprt;
typedef mk_win_base_sint_t mk_win_base_far const* mk_lang_restrict mk_win_base_sint_lprct;
typedef mk_win_base_sint_t mk_win_base_near* mk_lang_restrict mk_win_base_sint_nprt;
typedef mk_win_base_sint_t mk_win_base_near const* mk_lang_restrict mk_win_base_sint_nprct;

typedef mk_lang_types_ulong_t mk_win_base_ulong_t;
typedef mk_win_base_ulong_t const mk_win_base_ulong_ct;
typedef mk_win_base_ulong_t* mk_win_base_ulong_pt;
typedef mk_win_base_ulong_t const* mk_win_base_ulong_pct;
typedef mk_win_base_ulong_t mk_win_base_far* mk_win_base_ulong_lpt;
typedef mk_win_base_ulong_t mk_win_base_far const* mk_win_base_ulong_lpct;
typedef mk_win_base_ulong_t mk_win_base_near* mk_win_base_ulong_npt;
typedef mk_win_base_ulong_t mk_win_base_near const* mk_win_base_ulong_npct;
typedef mk_win_base_ulong_t* mk_lang_restrict mk_win_base_ulong_prt;
typedef mk_win_base_ulong_t const* mk_lang_restrict mk_win_base_ulong_prct;
typedef mk_win_base_ulong_t mk_win_base_far* mk_lang_restrict mk_win_base_ulong_lprt;
typedef mk_win_base_ulong_t mk_win_base_far const* mk_lang_restrict mk_win_base_ulong_lprct;
typedef mk_win_base_ulong_t mk_win_base_near* mk_lang_restrict mk_win_base_ulong_nprt;
typedef mk_win_base_ulong_t mk_win_base_near const* mk_lang_restrict mk_win_base_ulong_nprct;

typedef mk_lang_types_slong_t mk_win_base_slong_t;
typedef mk_win_base_slong_t const mk_win_base_slong_ct;
typedef mk_win_base_slong_t* mk_win_base_slong_pt;
typedef mk_win_base_slong_t const* mk_win_base_slong_pct;
typedef mk_win_base_slong_t mk_win_base_far* mk_win_base_slong_lpt;
typedef mk_win_base_slong_t mk_win_base_far const* mk_win_base_slong_lpct;
typedef mk_win_base_slong_t mk_win_base_near* mk_win_base_slong_npt;
typedef mk_win_base_slong_t mk_win_base_near const* mk_win_base_slong_npct;
typedef mk_win_base_slong_t* mk_lang_restrict mk_win_base_slong_prt;
typedef mk_win_base_slong_t const* mk_lang_restrict mk_win_base_slong_prct;
typedef mk_win_base_slong_t mk_win_base_far* mk_lang_restrict mk_win_base_slong_lprt;
typedef mk_win_base_slong_t mk_win_base_far const* mk_lang_restrict mk_win_base_slong_lprct;
typedef mk_win_base_slong_t mk_win_base_near* mk_lang_restrict mk_win_base_slong_nprt;
typedef mk_win_base_slong_t mk_win_base_near const* mk_lang_restrict mk_win_base_slong_nprct;

typedef mk_lang_types_ullong_t mk_win_base_ullong_t;
typedef mk_win_base_ullong_t const mk_win_base_ullong_ct;
typedef mk_win_base_ullong_t* mk_win_base_ullong_pt;
typedef mk_win_base_ullong_t const* mk_win_base_ullong_pct;
typedef mk_win_base_ullong_t mk_win_base_far* mk_win_base_ullong_lpt;
typedef mk_win_base_ullong_t mk_win_base_far const* mk_win_base_ullong_lpct;
typedef mk_win_base_ullong_t mk_win_base_near* mk_win_base_ullong_npt;
typedef mk_win_base_ullong_t mk_win_base_near const* mk_win_base_ullong_npct;
typedef mk_win_base_ullong_t* mk_lang_restrict mk_win_base_ullong_prt;
typedef mk_win_base_ullong_t const* mk_lang_restrict mk_win_base_ullong_prct;
typedef mk_win_base_ullong_t mk_win_base_far* mk_lang_restrict mk_win_base_ullong_lprt;
typedef mk_win_base_ullong_t mk_win_base_far const* mk_lang_restrict mk_win_base_ullong_lprct;
typedef mk_win_base_ullong_t mk_win_base_near* mk_lang_restrict mk_win_base_ullong_nprt;
typedef mk_win_base_ullong_t mk_win_base_near const* mk_lang_restrict mk_win_base_ullong_nprct;

typedef mk_lang_types_sllong_t mk_win_base_sllong_t;
typedef mk_win_base_sllong_t const mk_win_base_sllong_ct;
typedef mk_win_base_sllong_t* mk_win_base_sllong_pt;
typedef mk_win_base_sllong_t const* mk_win_base_sllong_pct;
typedef mk_win_base_sllong_t mk_win_base_far* mk_win_base_sllong_lpt;
typedef mk_win_base_sllong_t mk_win_base_far const* mk_win_base_sllong_lpct;
typedef mk_win_base_sllong_t mk_win_base_near* mk_win_base_sllong_npt;
typedef mk_win_base_sllong_t mk_win_base_near const* mk_win_base_sllong_npct;
typedef mk_win_base_sllong_t* mk_lang_restrict mk_win_base_sllong_prt;
typedef mk_win_base_sllong_t const* mk_lang_restrict mk_win_base_sllong_prct;
typedef mk_win_base_sllong_t mk_win_base_far* mk_lang_restrict mk_win_base_sllong_lprt;
typedef mk_win_base_sllong_t mk_win_base_far const* mk_lang_restrict mk_win_base_sllong_lprct;
typedef mk_win_base_sllong_t mk_win_base_near* mk_lang_restrict mk_win_base_sllong_nprt;
typedef mk_win_base_sllong_t mk_win_base_near const* mk_lang_restrict mk_win_base_sllong_nprct;

typedef mk_lang_types_uintptr_t mk_win_base_uintptr_t;
typedef mk_win_base_uintptr_t const mk_win_base_uintptr_ct;
typedef mk_win_base_uintptr_t* mk_win_base_uintptr_pt;
typedef mk_win_base_uintptr_t const* mk_win_base_uintptr_pct;
typedef mk_win_base_uintptr_t mk_win_base_far* mk_win_base_uintptr_lpt;
typedef mk_win_base_uintptr_t mk_win_base_far const* mk_win_base_uintptr_lpct;
typedef mk_win_base_uintptr_t mk_win_base_near* mk_win_base_uintptr_npt;
typedef mk_win_base_uintptr_t mk_win_base_near const* mk_win_base_uintptr_npct;
typedef mk_win_base_uintptr_t* mk_lang_restrict mk_win_base_uintptr_prt;
typedef mk_win_base_uintptr_t const* mk_lang_restrict mk_win_base_uintptr_prct;
typedef mk_win_base_uintptr_t mk_win_base_far* mk_lang_restrict mk_win_base_uintptr_lprt;
typedef mk_win_base_uintptr_t mk_win_base_far const* mk_lang_restrict mk_win_base_uintptr_lprct;
typedef mk_win_base_uintptr_t mk_win_base_near* mk_lang_restrict mk_win_base_uintptr_nprt;
typedef mk_win_base_uintptr_t mk_win_base_near const* mk_lang_restrict mk_win_base_uintptr_nprct;

typedef mk_lang_types_sintptr_t mk_win_base_sintptr_t;
typedef mk_win_base_sintptr_t const mk_win_base_sintptr_ct;
typedef mk_win_base_sintptr_t* mk_win_base_sintptr_pt;
typedef mk_win_base_sintptr_t const* mk_win_base_sintptr_pct;
typedef mk_win_base_sintptr_t mk_win_base_far* mk_win_base_sintptr_lpt;
typedef mk_win_base_sintptr_t mk_win_base_far const* mk_win_base_sintptr_lpct;
typedef mk_win_base_sintptr_t mk_win_base_near* mk_win_base_sintptr_npt;
typedef mk_win_base_sintptr_t mk_win_base_near const* mk_win_base_sintptr_npct;
typedef mk_win_base_sintptr_t* mk_lang_restrict mk_win_base_sintptr_prt;
typedef mk_win_base_sintptr_t const* mk_lang_restrict mk_win_base_sintptr_prct;
typedef mk_win_base_sintptr_t mk_win_base_far* mk_lang_restrict mk_win_base_sintptr_lprt;
typedef mk_win_base_sintptr_t mk_win_base_far const* mk_lang_restrict mk_win_base_sintptr_lprct;
typedef mk_win_base_sintptr_t mk_win_base_near* mk_lang_restrict mk_win_base_sintptr_nprt;
typedef mk_win_base_sintptr_t mk_win_base_near const* mk_lang_restrict mk_win_base_sintptr_nprct;

typedef mk_lang_types_usize_t mk_win_base_usize_t;
typedef mk_win_base_usize_t const mk_win_base_usize_ct;
typedef mk_win_base_usize_t* mk_win_base_usize_pt;
typedef mk_win_base_usize_t const* mk_win_base_usize_pct;
typedef mk_win_base_usize_t mk_win_base_far* mk_win_base_usize_lpt;
typedef mk_win_base_usize_t mk_win_base_far const* mk_win_base_usize_lpct;
typedef mk_win_base_usize_t mk_win_base_near* mk_win_base_usize_npt;
typedef mk_win_base_usize_t mk_win_base_near const* mk_win_base_usize_npct;
typedef mk_win_base_usize_t* mk_lang_restrict mk_win_base_usize_prt;
typedef mk_win_base_usize_t const* mk_lang_restrict mk_win_base_usize_prct;
typedef mk_win_base_usize_t mk_win_base_far* mk_lang_restrict mk_win_base_usize_lprt;
typedef mk_win_base_usize_t mk_win_base_far const* mk_lang_restrict mk_win_base_usize_lprct;
typedef mk_win_base_usize_t mk_win_base_near* mk_lang_restrict mk_win_base_usize_nprt;
typedef mk_win_base_usize_t mk_win_base_near const* mk_lang_restrict mk_win_base_usize_nprct;

typedef mk_lang_types_ssize_t mk_win_base_ssize_t;
typedef mk_win_base_ssize_t const mk_win_base_ssize_ct;
typedef mk_win_base_ssize_t* mk_win_base_ssize_pt;
typedef mk_win_base_ssize_t const* mk_win_base_ssize_pct;
typedef mk_win_base_ssize_t mk_win_base_far* mk_win_base_ssize_lpt;
typedef mk_win_base_ssize_t mk_win_base_far const* mk_win_base_ssize_lpct;
typedef mk_win_base_ssize_t mk_win_base_near* mk_win_base_ssize_npt;
typedef mk_win_base_ssize_t mk_win_base_near const* mk_win_base_ssize_npct;
typedef mk_win_base_ssize_t* mk_lang_restrict mk_win_base_ssize_prt;
typedef mk_win_base_ssize_t const* mk_lang_restrict mk_win_base_ssize_prct;
typedef mk_win_base_ssize_t mk_win_base_far* mk_lang_restrict mk_win_base_ssize_lprt;
typedef mk_win_base_ssize_t mk_win_base_far const* mk_lang_restrict mk_win_base_ssize_lprct;
typedef mk_win_base_ssize_t mk_win_base_near* mk_lang_restrict mk_win_base_ssize_nprt;
typedef mk_win_base_ssize_t mk_win_base_near const* mk_lang_restrict mk_win_base_ssize_nprct;

typedef mk_lang_types_ushort_t mk_win_base_word_t;
typedef mk_win_base_word_t const mk_win_base_word_ct;
typedef mk_win_base_word_t* mk_win_base_word_pt;
typedef mk_win_base_word_t const* mk_win_base_word_pct;
typedef mk_win_base_word_t mk_win_base_far* mk_win_base_word_lpt;
typedef mk_win_base_word_t mk_win_base_far const* mk_win_base_word_lpct;
typedef mk_win_base_word_t mk_win_base_near* mk_win_base_word_npt;
typedef mk_win_base_word_t mk_win_base_near const* mk_win_base_word_npct;
typedef mk_win_base_word_t* mk_lang_restrict mk_win_base_word_prt;
typedef mk_win_base_word_t const* mk_lang_restrict mk_win_base_word_prct;
typedef mk_win_base_word_t mk_win_base_far* mk_lang_restrict mk_win_base_word_lprt;
typedef mk_win_base_word_t mk_win_base_far const* mk_lang_restrict mk_win_base_word_lprct;
typedef mk_win_base_word_t mk_win_base_near* mk_lang_restrict mk_win_base_word_nprt;
typedef mk_win_base_word_t mk_win_base_near const* mk_lang_restrict mk_win_base_word_nprct;

typedef mk_lang_types_ulong_t mk_win_base_dword_t;
typedef mk_win_base_dword_t const mk_win_base_dword_ct;
typedef mk_win_base_dword_t* mk_win_base_dword_pt;
typedef mk_win_base_dword_t const* mk_win_base_dword_pct;
typedef mk_win_base_dword_t mk_win_base_far* mk_win_base_dword_lpt;
typedef mk_win_base_dword_t mk_win_base_far const* mk_win_base_dword_lpct;
typedef mk_win_base_dword_t mk_win_base_near* mk_win_base_dword_npt;
typedef mk_win_base_dword_t mk_win_base_near const* mk_win_base_dword_npct;
typedef mk_win_base_dword_t* mk_lang_restrict mk_win_base_dword_prt;
typedef mk_win_base_dword_t const* mk_lang_restrict mk_win_base_dword_prct;
typedef mk_win_base_dword_t mk_win_base_far* mk_lang_restrict mk_win_base_dword_lprt;
typedef mk_win_base_dword_t mk_win_base_far const* mk_lang_restrict mk_win_base_dword_lprct;
typedef mk_win_base_dword_t mk_win_base_near* mk_lang_restrict mk_win_base_dword_nprt;
typedef mk_win_base_dword_t mk_win_base_near const* mk_lang_restrict mk_win_base_dword_nprct;

typedef mk_lang_types_slong_t mk_win_base_ntstatus_t;
typedef mk_win_base_ntstatus_t const mk_win_base_ntstatus_ct;
typedef mk_win_base_ntstatus_t* mk_win_base_ntstatus_pt;
typedef mk_win_base_ntstatus_t const* mk_win_base_ntstatus_pct;
typedef mk_win_base_ntstatus_t mk_win_base_far* mk_win_base_ntstatus_lpt;
typedef mk_win_base_ntstatus_t mk_win_base_far const* mk_win_base_ntstatus_lpct;
typedef mk_win_base_ntstatus_t mk_win_base_near* mk_win_base_ntstatus_npt;
typedef mk_win_base_ntstatus_t mk_win_base_near const* mk_win_base_ntstatus_npct;
typedef mk_win_base_ntstatus_t* mk_lang_restrict mk_win_base_ntstatus_prt;
typedef mk_win_base_ntstatus_t const* mk_lang_restrict mk_win_base_ntstatus_prct;
typedef mk_win_base_ntstatus_t mk_win_base_far* mk_lang_restrict mk_win_base_ntstatus_lprt;
typedef mk_win_base_ntstatus_t mk_win_base_far const* mk_lang_restrict mk_win_base_ntstatus_lprct;
typedef mk_win_base_ntstatus_t mk_win_base_near* mk_lang_restrict mk_win_base_ntstatus_nprt;
typedef mk_win_base_ntstatus_t mk_win_base_near const* mk_lang_restrict mk_win_base_ntstatus_nprct;

struct mk_win_base_large_integer_data_a_s
{
	mk_win_base_dword_t m_lo;
	mk_win_base_slong_t m_hi;
};
typedef struct mk_win_base_large_integer_data_a_s mk_win_base_large_integer_data_a_t;

typedef mk_win_base_ullong_t mk_win_base_large_integer_data_b_t;

union mk_win_base_large_integer_data_u
{
	mk_win_base_large_integer_data_a_t m_data_a;
	mk_win_base_large_integer_data_b_t m_data_b;
};
typedef union mk_win_base_large_integer_data_u mk_win_base_large_integer_data_t;

struct mk_win_base_large_integer_s
{
	mk_win_base_large_integer_data_t m_data;
};
typedef struct mk_win_base_large_integer_s mk_win_base_large_integer_t;
typedef mk_win_base_large_integer_t const mk_win_base_large_integer_ct;
typedef mk_win_base_large_integer_t* mk_win_base_large_integer_pt;
typedef mk_win_base_large_integer_t const* mk_win_base_large_integer_pct;
typedef mk_win_base_large_integer_t mk_win_base_far* mk_win_base_large_integer_lpt;
typedef mk_win_base_large_integer_t mk_win_base_far const* mk_win_base_large_integer_lpct;
typedef mk_win_base_large_integer_t mk_win_base_near* mk_win_base_large_integer_npt;
typedef mk_win_base_large_integer_t mk_win_base_near const* mk_win_base_large_integer_npct;
typedef mk_win_base_large_integer_t* mk_lang_restrict mk_win_base_large_integer_prt;
typedef mk_win_base_large_integer_t const* mk_lang_restrict mk_win_base_large_integer_prct;
typedef mk_win_base_large_integer_t mk_win_base_far* mk_lang_restrict mk_win_base_large_integer_lprt;
typedef mk_win_base_large_integer_t mk_win_base_far const* mk_lang_restrict mk_win_base_large_integer_lprct;
typedef mk_win_base_large_integer_t mk_win_base_near* mk_lang_restrict mk_win_base_large_integer_nprt;
typedef mk_win_base_large_integer_t mk_win_base_near const* mk_lang_restrict mk_win_base_large_integer_nprct;

#define mk_win_base_make_handle(x) \
	struct mk_lang_concat(x, _s){ mk_win_base_void_pct m_data; }; \
	typedef struct mk_lang_concat(x, _s) mk_lang_concat(x, _t); \
	typedef mk_lang_concat(x, _t) const mk_lang_concat(x, _ct); \
	typedef mk_lang_concat(x, _t)* mk_lang_concat(x, _pt); \
	typedef mk_lang_concat(x, _t) const* mk_lang_concat(x, _pct); \
	typedef mk_lang_concat(x, _t) mk_win_base_far* mk_lang_concat(x, _lpt); \
	typedef mk_lang_concat(x, _t) mk_win_base_far const* mk_lang_concat(x, _lpct); \
	typedef mk_lang_concat(x, _t) mk_win_base_near* mk_lang_concat(x, _npt); \
	typedef mk_lang_concat(x, _t) mk_win_base_near const* mk_lang_concat(x, _npct); \
	typedef mk_lang_concat(x, _t)* mk_lang_restrict mk_lang_concat(x, _prt); \
	typedef mk_lang_concat(x, _t) const* mk_lang_restrict mk_lang_concat(x, _prct); \
	typedef mk_lang_concat(x, _t) mk_win_base_far* mk_lang_restrict mk_lang_concat(x, _lprt); \
	typedef mk_lang_concat(x, _t) mk_win_base_far const* mk_lang_restrict mk_lang_concat(x, _lprct); \
	typedef mk_lang_concat(x, _t) mk_win_base_near* mk_lang_restrict mk_lang_concat(x, _nprt); \
	typedef mk_lang_concat(x, _t) mk_win_base_near const* mk_lang_restrict mk_lang_concat(x, _nprct); \
	mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_concat(x, _t) mk_lang_concat(x, _get_null)(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_concat(x, _t) r mk_lang_constexpr_init; r.m_data = mk_win_base_null; return r; } \
	mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_concat(x, _t) mk_lang_concat(x, _from)(mk_win_base_void_pct const handle) mk_lang_noexcept { mk_lang_concat(x, _t) r mk_lang_constexpr_init; r.m_data = handle; return r; } \

mk_win_base_make_handle(mk_win_base_handle)
mk_win_base_make_handle(mk_win_base_instance)

typedef mk_win_base_sint_t(mk_win_base_far mk_win_base_stdcall*mk_win_base_proc_t)(mk_win_base_sint_t);
typedef mk_win_base_proc_t const mk_win_base_proc_ct;
typedef mk_win_base_proc_t* mk_win_base_proc_pt;
typedef mk_win_base_proc_t const* mk_win_base_proc_pct;
typedef mk_win_base_proc_t mk_win_base_far* mk_win_base_proc_lpt;
typedef mk_win_base_proc_t mk_win_base_far const* mk_win_base_proc_lpct;
typedef mk_win_base_proc_t mk_win_base_near* mk_win_base_proc_npt;
typedef mk_win_base_proc_t mk_win_base_near const* mk_win_base_proc_npct;
typedef mk_win_base_proc_t* mk_lang_restrict mk_win_base_proc_prt;
typedef mk_win_base_proc_t const* mk_lang_restrict mk_win_base_proc_prct;
typedef mk_win_base_proc_t mk_win_base_far* mk_lang_restrict mk_win_base_proc_lprt;
typedef mk_win_base_proc_t mk_win_base_far const* mk_lang_restrict mk_win_base_proc_lprct;
typedef mk_win_base_proc_t mk_win_base_near* mk_lang_restrict mk_win_base_proc_nprt;
typedef mk_win_base_proc_t mk_win_base_near const* mk_lang_restrict mk_win_base_proc_nprct;

struct mk_win_base_point_s
{
	mk_win_base_slong_t m_x;
	mk_win_base_slong_t m_y;
};
typedef struct mk_win_base_point_s mk_win_base_point_t;
typedef mk_win_base_point_t const mk_win_base_point_ct;
typedef mk_win_base_point_t* mk_win_base_point_pt;
typedef mk_win_base_point_t const* mk_win_base_point_pct;
typedef mk_win_base_point_t mk_win_base_far* mk_win_base_point_lpt;
typedef mk_win_base_point_t mk_win_base_far const* mk_win_base_point_lpct;
typedef mk_win_base_point_t mk_win_base_near* mk_win_base_point_npt;
typedef mk_win_base_point_t mk_win_base_near const* mk_win_base_point_npct;
typedef mk_win_base_point_t* mk_lang_restrict mk_win_base_point_prt;
typedef mk_win_base_point_t const* mk_lang_restrict mk_win_base_point_prct;
typedef mk_win_base_point_t mk_win_base_far* mk_lang_restrict mk_win_base_point_lprt;
typedef mk_win_base_point_t mk_win_base_far const* mk_lang_restrict mk_win_base_point_lprct;
typedef mk_win_base_point_t mk_win_base_near* mk_lang_restrict mk_win_base_point_nprt;
typedef mk_win_base_point_t mk_win_base_near const* mk_lang_restrict mk_win_base_point_nprct;

struct mk_win_base_sizer_s
{
	mk_win_base_slong_t m_x;
	mk_win_base_slong_t m_y;
};
typedef struct mk_win_base_sizer_s mk_win_base_sizer_t;
typedef mk_win_base_sizer_t const mk_win_base_sizer_ct;
typedef mk_win_base_sizer_t* mk_win_base_sizer_pt;
typedef mk_win_base_sizer_t const* mk_win_base_sizer_pct;
typedef mk_win_base_sizer_t mk_win_base_far* mk_win_base_sizer_lpt;
typedef mk_win_base_sizer_t mk_win_base_far const* mk_win_base_sizer_lpct;
typedef mk_win_base_sizer_t mk_win_base_near* mk_win_base_sizer_npt;
typedef mk_win_base_sizer_t mk_win_base_near const* mk_win_base_sizer_npct;
typedef mk_win_base_sizer_t* mk_lang_restrict mk_win_base_sizer_prt;
typedef mk_win_base_sizer_t const* mk_lang_restrict mk_win_base_sizer_prct;
typedef mk_win_base_sizer_t mk_win_base_far* mk_lang_restrict mk_win_base_sizer_lprt;
typedef mk_win_base_sizer_t mk_win_base_far const* mk_lang_restrict mk_win_base_sizer_lprct;
typedef mk_win_base_sizer_t mk_win_base_near* mk_lang_restrict mk_win_base_sizer_nprt;
typedef mk_win_base_sizer_t mk_win_base_near const* mk_lang_restrict mk_win_base_sizer_nprct;

struct mk_win_base_rect_s
{
	mk_win_base_slong_t m_left;
	mk_win_base_slong_t m_top;
	mk_win_base_slong_t m_right;
	mk_win_base_slong_t m_bottom;
};
typedef struct mk_win_base_rect_s mk_win_base_rect_t;
typedef mk_win_base_rect_t const mk_win_base_rect_ct;
typedef mk_win_base_rect_t* mk_win_base_rect_pt;
typedef mk_win_base_rect_t const* mk_win_base_rect_pct;
typedef mk_win_base_rect_t mk_win_base_far* mk_win_base_rect_lpt;
typedef mk_win_base_rect_t mk_win_base_far const* mk_win_base_rect_lpct;
typedef mk_win_base_rect_t mk_win_base_near* mk_win_base_rect_npt;
typedef mk_win_base_rect_t mk_win_base_near const* mk_win_base_rect_npct;
typedef mk_win_base_rect_t* mk_lang_restrict mk_win_base_rect_prt;
typedef mk_win_base_rect_t const* mk_lang_restrict mk_win_base_rect_prct;
typedef mk_win_base_rect_t mk_win_base_far* mk_lang_restrict mk_win_base_rect_lprt;
typedef mk_win_base_rect_t mk_win_base_far const* mk_lang_restrict mk_win_base_rect_lprct;
typedef mk_win_base_rect_t mk_win_base_near* mk_lang_restrict mk_win_base_rect_nprt;
typedef mk_win_base_rect_t mk_win_base_near const* mk_lang_restrict mk_win_base_rect_nprct;

struct mk_win_base_guid_s
{
	mk_win_base_ulong_t m_data_1;
	mk_win_base_ushort_t m_data_2;
	mk_win_base_ushort_t m_data_3;
	mk_win_base_uchar_t m_data_4[8];
};
typedef struct mk_win_base_guid_s mk_win_base_guid_t;
typedef mk_win_base_guid_t const mk_win_base_guid_ct;
typedef mk_win_base_guid_t* mk_win_base_guid_pt;
typedef mk_win_base_guid_t const* mk_win_base_guid_pct;
typedef mk_win_base_guid_t mk_win_base_far* mk_win_base_guid_lpt;
typedef mk_win_base_guid_t mk_win_base_far const* mk_win_base_guid_lpct;
typedef mk_win_base_guid_t mk_win_base_near* mk_win_base_guid_npt;
typedef mk_win_base_guid_t mk_win_base_near const* mk_win_base_guid_npct;
typedef mk_win_base_guid_t* mk_lang_restrict mk_win_base_guid_prt;
typedef mk_win_base_guid_t const* mk_lang_restrict mk_win_base_guid_prct;
typedef mk_win_base_guid_t mk_win_base_far* mk_lang_restrict mk_win_base_guid_lprt;
typedef mk_win_base_guid_t mk_win_base_far const* mk_lang_restrict mk_win_base_guid_lprct;
typedef mk_win_base_guid_t mk_win_base_near* mk_lang_restrict mk_win_base_guid_nprt;
typedef mk_win_base_guid_t mk_win_base_near const* mk_lang_restrict mk_win_base_guid_nprct;

struct mk_win_base_luid_s
{
	mk_win_base_dword_t m_lo;
	mk_win_base_slong_t m_hi;
};
typedef struct mk_win_base_luid_s mk_win_base_luid_t;
typedef mk_win_base_luid_t const mk_win_base_luid_ct;
typedef mk_win_base_luid_t* mk_win_base_luid_pt;
typedef mk_win_base_luid_t const* mk_win_base_luid_pct;
typedef mk_win_base_luid_t mk_win_base_far* mk_win_base_luid_lpt;
typedef mk_win_base_luid_t mk_win_base_far const* mk_win_base_luid_lpct;
typedef mk_win_base_luid_t mk_win_base_near* mk_win_base_luid_npt;
typedef mk_win_base_luid_t mk_win_base_near const* mk_win_base_luid_npct;
typedef mk_win_base_luid_t* mk_lang_restrict mk_win_base_luid_prt;
typedef mk_win_base_luid_t const* mk_lang_restrict mk_win_base_luid_prct;
typedef mk_win_base_luid_t mk_win_base_far* mk_lang_restrict mk_win_base_luid_lprt;
typedef mk_win_base_luid_t mk_win_base_far const* mk_lang_restrict mk_win_base_luid_lprct;
typedef mk_win_base_luid_t mk_win_base_near* mk_lang_restrict mk_win_base_luid_nprt;
typedef mk_win_base_luid_t mk_win_base_near const* mk_lang_restrict mk_win_base_luid_nprct;

struct mk_win_base_list_entry_s;
typedef struct mk_win_base_list_entry_s mk_win_base_list_entry_t;
typedef mk_win_base_list_entry_t const mk_win_base_list_entry_ct;
typedef mk_win_base_list_entry_t* mk_win_base_list_entry_pt;
typedef mk_win_base_list_entry_t const* mk_win_base_list_entry_pct;
typedef mk_win_base_list_entry_t mk_win_base_far* mk_win_base_list_entry_lpt;
typedef mk_win_base_list_entry_t mk_win_base_far const* mk_win_base_list_entry_lpct;
typedef mk_win_base_list_entry_t mk_win_base_near* mk_win_base_list_entry_npt;
typedef mk_win_base_list_entry_t mk_win_base_near const* mk_win_base_list_entry_npct;
typedef mk_win_base_list_entry_t* mk_lang_restrict mk_win_base_list_entry_prt;
typedef mk_win_base_list_entry_t const* mk_lang_restrict mk_win_base_list_entry_prct;
typedef mk_win_base_list_entry_t mk_win_base_far* mk_lang_restrict mk_win_base_list_entry_lprt;
typedef mk_win_base_list_entry_t mk_win_base_far const* mk_lang_restrict mk_win_base_list_entry_lprct;
typedef mk_win_base_list_entry_t mk_win_base_near* mk_lang_restrict mk_win_base_list_entry_nprt;
typedef mk_win_base_list_entry_t mk_win_base_near const* mk_lang_restrict mk_win_base_list_entry_nprct;
struct mk_win_base_list_entry_s
{
	mk_win_base_list_entry_pt m_next;
	mk_win_base_list_entry_pt m_prev;
};


static mk_win_base_instance_t const mk_win_base_instance_null_g = { mk_win_base_null };
static mk_win_base_handle_t const mk_win_base_handle_null_g = { mk_win_base_handle_null };
static mk_win_base_handle_t const mk_win_base_handle_invalid_g = { mk_win_base_handle_invalid };


#define mk_win_base_make_word(hi, lo) \
((mk_win_base_word_t)( \
	((mk_win_base_word_t)( \
		((mk_win_base_word_t)(((mk_win_base_uchar_t)(((mk_win_base_ullong_t)(lo)) & ((mk_win_base_ullong_t)(0xff)))))) \
		<< \
		8 \
	)) \
	| \
	((mk_win_base_word_t)(((mk_win_base_uchar_t)(((mk_win_base_ullong_t)(hi)) & ((mk_win_base_ullong_t)(0xff)))))) \
))


#if mk_lang_jumbo_want == 1
#include "mk_win_base.c"
#endif
#endif
