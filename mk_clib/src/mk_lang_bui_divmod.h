#ifndef mk_include_guard_lang_bui_divmod
#define mk_include_guard_lang_bui_divmod


#define mk_lang_bui_divmod_inl_type uchar
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type ushort
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type uint
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type ulong
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type ullong
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type ulllong
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type uintptr
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type uintmax
#include "mk_lang_bui_divmod_inl_type.h"

#define mk_lang_bui_divmod_inl_type size
#include "mk_lang_bui_divmod_inl_type.h"


#if mk_lang_jumbo_want == 1
#include "mk_lang_bui_divmod.c"
#endif
#endif
