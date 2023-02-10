#ifndef mk_include_guard_lang_bui
#define mk_include_guard_lang_bui


#define mk_lang_bui_btn uchar
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn ushort
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn uint
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn ulong
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn ullong
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn ulllong
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn uintptr
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn uintmax
#include "mk_lang_bui_inl.h"

#define mk_lang_bui_btn size
#include "mk_lang_bui_inl.h"


#if mk_lang_jumbo_want == 1
#include "mk_lang_bui.c"
#endif
#endif
