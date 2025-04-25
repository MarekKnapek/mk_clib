#ifndef mk_include_guard_mk_win_base_h
#define mk_include_guard_mk_win_base_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_arch.h"
#include "mk_lang_concat.h"
#include "mk_lang_inline.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_arch == mk_lang_arch_x8616
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
#define mk_win_base_proc_not_found ((mk_win_base_proc_t)(0x0100))
#define mk_win_base_handle_null ((mk_win_base_void_pct)(((mk_win_base_uintptr_t)(mk_win_base_null))))
#define mk_win_base_handle_invalid ((mk_win_base_void_pct)(((mk_win_base_sintptr_t)(-1))))
#define mk_win_base_page_4k (4ul * 1024ul)
#define mk_win_base_page_64k (64ul * 1024ul)
#define mk_win_base_page_2m (2ul * 1024ul * 1024ul)

typedef mk_lang_types_void_t mk_win_base_void_t; mk_lang_typedef(mk_win_base_void);
typedef mk_lang_types_uint_t mk_win_base_bool_t; mk_lang_typedef(mk_win_base_bool);
typedef mk_lang_types_uchar_t mk_win_base_boolean_t; mk_lang_typedef(mk_win_base_boolean);
typedef mk_lang_types_wchar_t mk_win_base_wchar_t; mk_lang_typedef(mk_win_base_wchar);
typedef mk_lang_types_pchar_t mk_win_base_pchar_t; mk_lang_typedef(mk_win_base_pchar);
typedef mk_lang_types_uchar_t mk_win_base_uchar_t; mk_lang_typedef(mk_win_base_uchar);
typedef mk_lang_types_schar_t mk_win_base_schar_t; mk_lang_typedef(mk_win_base_schar);
typedef mk_lang_types_ushort_t mk_win_base_ushort_t; mk_lang_typedef(mk_win_base_ushort);
typedef mk_lang_types_sshort_t mk_win_base_sshort_t; mk_lang_typedef(mk_win_base_sshort);
typedef mk_lang_types_uint_t mk_win_base_uint_t; mk_lang_typedef(mk_win_base_uint);
typedef mk_lang_types_sint_t mk_win_base_sint_t; mk_lang_typedef(mk_win_base_sint);
typedef mk_lang_types_ulong_t mk_win_base_ulong_t; mk_lang_typedef(mk_win_base_ulong);
typedef mk_lang_types_slong_t mk_win_base_slong_t; mk_lang_typedef(mk_win_base_slong);
typedef mk_lang_types_ullong_t mk_win_base_ullong_t; mk_lang_typedef(mk_win_base_ullong);
typedef mk_lang_types_sllong_t mk_win_base_sllong_t; mk_lang_typedef(mk_win_base_sllong);
typedef mk_lang_types_uintptr_t mk_win_base_uintptr_t; mk_lang_typedef(mk_win_base_uintptr);
typedef mk_lang_types_sintptr_t mk_win_base_sintptr_t; mk_lang_typedef(mk_win_base_sintptr);
typedef mk_lang_types_usize_t mk_win_base_usize_t; mk_lang_typedef(mk_win_base_usize);
typedef mk_lang_types_ssize_t mk_win_base_ssize_t; mk_lang_typedef(mk_win_base_ssize);
typedef mk_lang_types_ushort_t mk_win_base_word_t; mk_lang_typedef(mk_win_base_word);
typedef mk_lang_types_ulong_t mk_win_base_dword_t; mk_lang_typedef(mk_win_base_dword);
typedef mk_lang_types_slong_t mk_win_base_ntstatus_t; mk_lang_typedef(mk_win_base_ntstatus);
typedef mk_lang_types_slong_t mk_win_base_hresult_t; mk_lang_typedef(mk_win_base_hresult);

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
mk_lang_typedef(mk_win_base_large_integer);

#define mk_win_base_make_handle(x) \
	struct mk_lang_concat(x, _s){ mk_win_base_void_pct m_data; }; \
	typedef struct mk_lang_concat(x, _s) mk_lang_concat(x, _t); \
	mk_lang_typedef(x); \
	mk_lang_nodiscard static mk_lang_inline mk_lang_concat(x, _t) mk_lang_concat(x, _get_null)(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_concat(x, _t) r; r.m_data = mk_win_base_null; return r; } \
	mk_lang_nodiscard static mk_lang_inline mk_lang_concat(x, _t) mk_lang_concat(x, _get_invalid)(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_concat(x, _t) r; r.m_data = mk_win_base_handle_invalid; return r; } \
	mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lang_concat(x, _is_null)(mk_lang_concat(x, _t) const handle) mk_lang_noexcept { mk_lang_types_bool_t r; r = handle.m_data == mk_win_base_null; return r; } \
	mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lang_concat(x, _is_invalid)(mk_lang_concat(x, _t) const handle) mk_lang_noexcept { mk_lang_types_bool_t r; r = handle.m_data == mk_win_base_handle_invalid; return r; } \
	mk_lang_nodiscard static mk_lang_inline mk_lang_concat(x, _t) mk_lang_concat(x, _from)(mk_win_base_void_pct const handle) mk_lang_noexcept { mk_lang_concat(x, _t) r; r.m_data = handle; return r; } \

mk_win_base_make_handle(mk_win_base_handle)
mk_win_base_make_handle(mk_win_base_instance)
mk_win_base_make_handle(mk_win_base_module)

#if mk_lang_version_at_least_cpp_17
#define mk_win_base_make_function(return_type, abi, type_name, arg_list) typedef return_type(abi*mk_lang_concat(type_name, _t))(arg_list) mk_lang_noexcept; mk_lang_typedef(type_name);
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_win_base_make_function(return_type, abi, type_name, arg_list) return_type abi mk_lang_concat(type_name, _dummy)(arg_list) mk_lang_noexcept; typedef decltype(&mk_lang_concat(type_name, _dummy)) mk_lang_concat(type_name, _t); mk_lang_typedef(type_name);
#else
#define mk_win_base_make_function(return_type, abi, type_name, arg_list) typedef return_type(abi*mk_lang_concat(type_name, _t))(arg_list) mk_lang_noexcept; mk_lang_typedef(type_name);
#endif

struct mk_win_base_point_s
{
	mk_win_base_slong_t m_x;
	mk_win_base_slong_t m_y;
};
typedef struct mk_win_base_point_s mk_win_base_point_t;
mk_lang_typedef(mk_win_base_point);

struct mk_win_base_sizer_s
{
	mk_win_base_slong_t m_x;
	mk_win_base_slong_t m_y;
};
typedef struct mk_win_base_sizer_s mk_win_base_sizer_t;
mk_lang_typedef(mk_win_base_sizer);

struct mk_win_base_rect_s
{
	mk_win_base_slong_t m_left;
	mk_win_base_slong_t m_top;
	mk_win_base_slong_t m_right;
	mk_win_base_slong_t m_bottom;
};
typedef struct mk_win_base_rect_s mk_win_base_rect_t;
mk_lang_typedef(mk_win_base_rect);

struct mk_win_base_guid_s
{
	mk_win_base_ulong_t m_data_1;
	mk_win_base_ushort_t m_data_2;
	mk_win_base_ushort_t m_data_3;
	mk_win_base_uchar_t m_data_4[8];
};
typedef struct mk_win_base_guid_s mk_win_base_guid_t;
mk_lang_typedef(mk_win_base_guid);

struct mk_win_base_luid_s
{
	mk_win_base_dword_t m_lo;
	mk_win_base_slong_t m_hi;
};
typedef struct mk_win_base_luid_s mk_win_base_luid_t;
mk_lang_typedef(mk_win_base_luid);

mk_lang_forward(mk_win_base_list_entry);
struct mk_win_base_list_entry_s
{
	mk_win_base_list_entry_pt m_next;
	mk_win_base_list_entry_pt m_prev;
};

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

static mk_win_base_instance_t const mk_win_base_s_instance_null = { mk_win_base_null };
static mk_win_base_handle_t const mk_win_base_s_handle_null = { mk_win_base_handle_null };
static mk_win_base_handle_t const mk_win_base_s_handle_invalid = { mk_win_base_handle_invalid };


#endif


#if mk_lang_jumbo_have
#include "mk_win_base.c"
#endif
#endif
