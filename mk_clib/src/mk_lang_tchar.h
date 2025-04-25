#ifndef mk_include_guard_mk_lang_tchar_h
#define mk_include_guard_mk_lang_tchar_h


#include "mk_lang_concat.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#if defined mk_lang_tchar_wchar_want
#if (mk_lang_tchar_wchar_want) == 0
#define mk_lang_tchar_wchar_have 0
#elif (mk_lang_tchar_wchar_want) == 1
#define mk_lang_tchar_wchar_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if mk_lang_entry_point_have
#define mk_lang_tchar_wchar_have 1
#else
#define mk_lang_tchar_wchar_have 0
#endif
#endif


#if mk_lang_tchar_wchar_have


typedef mk_lang_types_wchar_t mk_lang_tchar_t;
mk_lang_typedef(mk_lang_tchar);
#define mk_lang_tchar_c(x) L ## x
#define mk_lang_tchar_suffix w
#define mk_lang_tchar_dispatch(x) mk_lang_concat(x, mk_lang_tchar_suffix)


#else


typedef mk_lang_types_pchar_t mk_lang_tchar_t;
mk_lang_typedef(mk_lang_tchar);
#define mk_lang_tchar_c(x) x
#define mk_lang_tchar_suffix n
#define mk_lang_tchar_dispatch(x) mk_lang_concat(x, mk_lang_tchar_suffix)


#endif


#if mk_lang_jumbo_have
#include "mk_lang_tchar.c"
#endif
#endif
