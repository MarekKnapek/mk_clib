#ifndef mk_include_guard_mk_lang_entry_point_h
#define mk_include_guard_mk_lang_entry_point_h


#if defined mk_lang_entry_point_want
#if (mk_lang_entry_point_want) == 1
#define mk_lang_entry_point_have 1
#elif (mk_lang_entry_point_want) == 0
#define mk_lang_entry_point_have 0
#else
#error xxxxxxxxxx
#endif
#else
#define mk_lang_entry_point_have 0
#endif


#endif
