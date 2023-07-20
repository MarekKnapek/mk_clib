#ifndef mk_include_guard_mk_win_base
#define mk_include_guard_mk_win_base


#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"

#include <stddef.h> /* wchar_t */


#define mk_win_base_make_handle(x) \
	struct mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _hs); \
	typedef struct mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _hs) mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _ht); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _ht) const mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _hct); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _ht)* mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _hpt); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _ht) const* mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _hpct); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _hpct) mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _t); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _t) const mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _ct); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _t)* mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _pt); \
	typedef mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _t) const* mk_lang_concat(mk_lang_concat(mk_win_handle_, x), _pct)


#define mk_win_base_dllimport __declspec(dllimport)
#define mk_win_base_dllexport __declspec(dllexport)

#define mk_win_base_cdecl      __cdecl
#define mk_win_base_clrcall    __clrcall
#define mk_win_base_stdcall    __stdcall
#define mk_win_base_fastcall   __fastcall
#define mk_win_base_thiscall   __thiscall
#define mk_win_base_vectorcall __vectorcall

#define mk_win_base_false 0
#define mk_win_base_true  1


typedef mk_lang_types_uint_t mk_win_base_bool_t;
typedef mk_win_base_bool_t const mk_win_base_bool_ct;
typedef mk_win_base_bool_t* mk_win_base_bool_pt;
typedef mk_win_base_bool_t const* mk_win_base_bool_pct;

typedef mk_lang_types_ushort_t mk_win_base_word_t;
typedef mk_win_base_word_t const mk_win_base_word_ct;
typedef mk_win_base_word_t* mk_win_base_word_pt;
typedef mk_win_base_word_t const* mk_win_base_word_pct;

typedef mk_lang_types_ulong_t mk_win_base_dword_t;
typedef mk_win_base_dword_t const mk_win_base_dword_ct;
typedef mk_win_base_dword_t* mk_win_base_dword_pt;
typedef mk_win_base_dword_t const* mk_win_base_dword_pct;

typedef mk_lang_types_slong_t mk_win_base_ntstatus_t;
typedef mk_win_base_ntstatus_t const mk_win_base_ntstatus_ct;
typedef mk_win_base_ntstatus_t* mk_win_base_ntstatus_pt;
typedef mk_win_base_ntstatus_t const* mk_win_base_ntstatus_pct;

typedef wchar_t mk_win_base_wchar_t;
typedef mk_win_base_wchar_t const mk_win_base_wchar_ct;
typedef mk_win_base_wchar_t* mk_win_base_wchar_pt;
typedef mk_win_base_wchar_t const* mk_win_base_wchar_pct;


#if mk_lang_jumbo_want == 1
#include "mk_win_base.c"
#endif
#endif
