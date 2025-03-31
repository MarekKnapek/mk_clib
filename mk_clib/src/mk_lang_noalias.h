#ifndef mk_include_guard_mk_lang_noalias_h
#define mk_include_guard_mk_lang_noalias_h


#include "mk_lang_msvc.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005
#define mk_lang_noalias __declspec(noalias)
#else
#define mk_lang_noalias
#endif


#endif
