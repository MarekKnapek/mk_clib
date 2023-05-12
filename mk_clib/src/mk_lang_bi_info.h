#ifndef include_guard_mk_lang_bi_info
#define include_guard_mk_lang_bi_info


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo void mk_lang_bi_info_print_sizes(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_bi_info.c"
#endif
#endif
