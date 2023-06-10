#ifndef mk_include_guard_mk_lang_restrict
#define mk_include_guard_mk_lang_restrict


#include "mk_lang_version.h"


#if mk_lang_version_at_least_c_99
#define mk_lang_restrict restrict
#else
#define mk_lang_restrict
#endif


#endif
