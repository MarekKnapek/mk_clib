#ifndef mk_include_guard_mk_sl_bui_h
#define mk_include_guard_mk_sl_bui_h


#include "mk_lang_jumbo.h"


#define mk_sl_bui_t_name wchar
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name uchar
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name ushort
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name uint
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name ulong
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name ullong
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name ulllong
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name uintptr
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name uintmax
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"

#define mk_sl_bui_t_name usize
#include "mk_sl_bui_inl_fileh.h"
#include "mk_sl_bui_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_sl_bui.c"
#endif
#endif
