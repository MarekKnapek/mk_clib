#ifndef mk_include_guard_win_base
#define mk_include_guard_win_base


#include "mk_lang_arch.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_null.h"
#include "mk_lang_sizet.h"

#include <stddef.h> /* wchar_t */


#define mk_win_base_arch_16 1001
#define mk_win_base_arch_32 1002
#define mk_win_base_arch_64 1003

#if mk_lang_arch == mk_lang_arch_x8616
#define mk_win_base_arch mk_win_base_arch_16
#elif mk_lang_arch == mk_lang_arch_x8632
#define mk_win_base_arch mk_win_base_arch_32
#elif mk_lang_arch == mk_lang_arch_x8664
#define mk_win_base_arch mk_win_base_arch_64
#elif mk_lang_arch == mk_lang_arch_ia64
#define mk_win_base_arch mk_win_base_arch_64
#elif mk_lang_arch == mk_lang_arch_alpha
#define mk_win_base_arch mk_win_base_arch_32
#elif mk_lang_arch == mk_lang_arch_ppc
#define mk_win_base_arch mk_win_base_arch_32
#elif mk_lang_arch == mk_lang_arch_mips
#define mk_win_base_arch mk_win_base_arch_32
#elif mk_lang_arch == mk_lang_arch_arm32
#define mk_win_base_arch mk_win_base_arch_32
#elif mk_lang_arch == mk_lang_arch_arm64
#define mk_win_base_arch mk_win_base_arch_64
#endif

#if mk_win_base_arch == mk_win_base_arch_16
#define mk_win_base_far __far
#define mk_win_base_near __near
#else
#define mk_win_base_far
#define mk_win_base_near
#endif

#if mk_win_base_arch == mk_win_base_arch_16
/* todo memory models? */
#elif mk_win_base_arch == mk_win_base_arch_32
typedef signed int mk_win_base_sintptr_t;
typedef unsigned int mk_win_base_uintptr_t;
#elif mk_win_base_arch == mk_win_base_arch_64
typedef signed long long int mk_win_base_sintptr_t;
typedef unsigned long long int mk_win_base_uintptr_t;
#endif 

#define mk_win_base_dll_export __declspec(dllexport)
#define mk_win_base_dll_import __declspec(dllimport)

#define mk_win_base_cdecl __cdecl
#define mk_win_base_stdcall __stdcall

typedef void* mk_win_base_handle_t;
struct mk_win_base_handle_instance_s; typedef struct mk_win_base_handle_instance_s mk_win_base_handle_instance_t; typedef mk_win_base_handle_instance_t const* mk_win_base_instance_t;

#define mk_win_base_false ((mk_win_base_bool_t)(0))
#define mk_win_base_true ((mk_win_base_bool_t)(1))
#define mk_win_base_null mk_lang_null

typedef void mk_win_base_void_t;
typedef unsigned int mk_win_base_bool_t;
typedef unsigned char mk_win_base_uchar_t;
typedef unsigned short int mk_win_base_ushort_t;
typedef signed short int mk_win_base_sshort_t;
typedef unsigned int mk_win_base_uint_t;
typedef unsigned long int mk_win_base_ulong_t;
typedef signed long int mk_win_base_slong_t;

typedef unsigned short int mk_win_base_word_t;
typedef unsigned int mk_win_base_dword_t;
typedef mk_win_base_uintptr_t mk_win_base_size_t;

typedef mk_win_base_bool_t const mk_win_base_bool_ct;
typedef mk_win_base_bool_t* mk_win_base_bool_pt;
typedef mk_win_base_bool_t const* mk_win_base_bool_pct;
typedef mk_win_base_bool_t mk_win_base_far* mk_win_base_bool_lpt;
typedef mk_win_base_bool_t mk_win_base_far const* mk_win_base_bool_lpct;
typedef mk_win_base_bool_t mk_win_base_near* mk_win_base_bool_npt;
typedef mk_win_base_bool_t mk_win_base_near const* mk_win_base_bool_npct;

typedef mk_win_base_uchar_t const mk_win_base_uchar_ct;
typedef mk_win_base_uchar_t* mk_win_base_uchar_pt;
typedef mk_win_base_uchar_t const mk_win_base_uchar_ct;
typedef mk_win_base_uchar_t* mk_win_base_uchar_pt;
typedef mk_win_base_uchar_t const* mk_win_base_uchar_pct;
typedef mk_win_base_uchar_t mk_win_base_far* mk_win_base_uchar_lpt;
typedef mk_win_base_uchar_t mk_win_base_far const* mk_win_base_uchar_lpct;
typedef mk_win_base_uchar_t mk_win_base_near* mk_win_base_uchar_npt;
typedef mk_win_base_uchar_t mk_win_base_near const* mk_win_base_uchar_npct;

typedef mk_win_base_ushort_t const mk_win_base_ushort_ct;
typedef mk_win_base_ushort_t* mk_win_base_ushort_pt;
typedef mk_win_base_ushort_t const mk_win_base_ushort_ct;
typedef mk_win_base_ushort_t* mk_win_base_ushort_pt;
typedef mk_win_base_ushort_t const* mk_win_base_ushort_pct;
typedef mk_win_base_ushort_t mk_win_base_far* mk_win_base_ushort_lpt;
typedef mk_win_base_ushort_t mk_win_base_far const* mk_win_base_ushort_lpct;
typedef mk_win_base_ushort_t mk_win_base_near* mk_win_base_ushort_npt;
typedef mk_win_base_ushort_t mk_win_base_near const* mk_win_base_ushort_npct;

typedef mk_win_base_ulong_t const mk_win_base_ulong_ct;
typedef mk_win_base_ulong_t* mk_win_base_ulong_pt;
typedef mk_win_base_ulong_t const mk_win_base_ulong_ct;
typedef mk_win_base_ulong_t* mk_win_base_ulong_pt;
typedef mk_win_base_ulong_t const* mk_win_base_ulong_pct;
typedef mk_win_base_ulong_t mk_win_base_far* mk_win_base_ulong_lpt;
typedef mk_win_base_ulong_t mk_win_base_far const* mk_win_base_ulong_lpct;
typedef mk_win_base_ulong_t mk_win_base_near* mk_win_base_ulong_npt;
typedef mk_win_base_ulong_t mk_win_base_near const* mk_win_base_ulong_npct;

typedef mk_win_base_sintptr_t* mk_win_base_sintptr_pt;
typedef mk_win_base_sintptr_t const mk_win_base_sintptr_ct;
typedef mk_win_base_sintptr_t* mk_win_base_sintptr_pt;
typedef mk_win_base_sintptr_t const* mk_win_base_sintptr_pct;
typedef mk_win_base_sintptr_t mk_win_base_far* mk_win_base_sintptr_lpt;
typedef mk_win_base_sintptr_t mk_win_base_far const* mk_win_base_sintptr_lpct;
typedef mk_win_base_sintptr_t mk_win_base_near* mk_win_base_sintptr_npt;
typedef mk_win_base_sintptr_t mk_win_base_near const* mk_win_base_sintptr_npct;

typedef mk_win_base_void_t* mk_win_base_void_pt;
typedef mk_win_base_void_t const mk_win_base_void_ct;
typedef mk_win_base_void_t* mk_win_base_void_pt;
typedef mk_win_base_void_t const* mk_win_base_void_pct;
typedef mk_win_base_void_t mk_win_base_far* mk_win_base_void_lpt;
typedef mk_win_base_void_t mk_win_base_far const* mk_win_base_void_lpct;
typedef mk_win_base_void_t mk_win_base_near* mk_win_base_void_npt;
typedef mk_win_base_void_t mk_win_base_near const* mk_win_base_void_npct;

typedef mk_win_base_word_t* mk_win_base_word_pt;
typedef mk_win_base_word_t const mk_win_base_word_ct;
typedef mk_win_base_word_t* mk_win_base_word_pt;
typedef mk_win_base_word_t const* mk_win_base_word_pct;
typedef mk_win_base_word_t mk_win_base_far* mk_win_base_word_lpt;
typedef mk_win_base_word_t mk_win_base_far const* mk_win_base_word_lpct;
typedef mk_win_base_word_t mk_win_base_near* mk_win_base_word_npt;
typedef mk_win_base_word_t mk_win_base_near const* mk_win_base_word_npct;

typedef char mk_win_base_pchar_t;
typedef mk_win_base_pchar_t const mk_win_base_pchar_ct;
typedef mk_win_base_pchar_t* mk_win_base_pchar_pt;
typedef mk_win_base_pchar_t const* mk_win_base_pchar_pct;
typedef mk_win_base_pchar_t mk_win_base_far* mk_win_base_pchar_lpt;
typedef mk_win_base_pchar_t mk_win_base_far const* mk_win_base_pchar_lpct;
typedef mk_win_base_pchar_t mk_win_base_near* mk_win_base_pchar_npt;
typedef mk_win_base_pchar_t mk_win_base_near const* mk_win_base_pchar_npct;

typedef wchar_t mk_win_base_wchar_t;
typedef mk_win_base_wchar_t const mk_win_base_wchar_ct;
typedef mk_win_base_wchar_t* mk_win_base_wchar_pt;
typedef mk_win_base_wchar_t const* mk_win_base_wchar_pct;
typedef mk_win_base_wchar_t mk_win_base_far* mk_win_base_wchar_lpt;
typedef mk_win_base_wchar_t mk_win_base_far const* mk_win_base_wchar_lpct;
typedef mk_win_base_wchar_t mk_win_base_near* mk_win_base_wchar_npt;
typedef mk_win_base_wchar_t mk_win_base_near const* mk_win_base_wchar_npct;

typedef int(mk_win_base_far mk_win_base_stdcall*mk_win_base_proc_t)(int);
#define mk_win_base_proc_not_found ((mk_win_base_proc_t)(0x100))

struct mk_win_base_point_s
{
	signed long int m_x;
	signed long int m_y;
};
typedef struct mk_win_base_point_s mk_win_base_point_t;
typedef mk_win_base_point_t const mk_win_base_point_ct;
typedef mk_win_base_point_t* mk_win_base_point_pt;
typedef mk_win_base_point_t const* mk_win_base_point_pct;
typedef mk_win_base_point_t mk_win_base_far* mk_win_base_point_lpt;
typedef mk_win_base_point_t mk_win_base_far const* mk_win_base_point_lpct;
typedef mk_win_base_point_t mk_win_base_near* mk_win_base_point_npt;
typedef mk_win_base_point_t mk_win_base_near const* mk_win_base_point_npct;

struct mk_win_base_rect_s
{
	signed long int m_left;
	signed long int m_top;
	signed long int m_right;
	signed long int m_bottom;
};
typedef struct mk_win_base_rect_s mk_win_base_rect_t;
typedef mk_win_base_rect_t const mk_win_base_rect_ct;
typedef mk_win_base_rect_t* mk_win_base_rect_pt;
typedef mk_win_base_rect_t const* mk_win_base_rect_pct;
typedef mk_win_base_rect_t mk_win_base_far* mk_win_base_rect_lpt;
typedef mk_win_base_rect_t mk_win_base_far const* mk_win_base_rect_lpct;
typedef mk_win_base_rect_t mk_win_base_near* mk_win_base_rect_npt;
typedef mk_win_base_rect_t mk_win_base_near const* mk_win_base_rect_npct;


#define s_mk_win_base_handle_invalid ((mk_win_base_handle_t)(((mk_win_base_sintptr_t)(-1))))


#if mk_lang_jumbo_want == 1
/*#include "mk_win_base.c"*/
#endif
#endif
