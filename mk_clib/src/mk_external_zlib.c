#ifndef mk_include_guard_mk_external_zlib_c
#define mk_include_guard_mk_external_zlib_c
#include "mk_external_zlib.h"

#include "mk_lang_assert.h"
#include "mk_lang_null.h"


void* zcalloc(void* opaque, unsigned int items, unsigned int size);
void zcfree(void* opaque, void* address);


#include "mk_lang_warning_msvc_push_c4702.h"
void* zcalloc(void* const opaque, unsigned int const items, unsigned int const size){ ((void)(opaque)); ((void)(items)); ((void)(size)); mk_lang_assert_false(); return mk_lang_null; }
void zcfree(void* const opaque, void* const address){ ((void)(opaque)); ((void)(address)); mk_lang_assert_false(); }
#include "mk_lang_warning_msvc_pop.h"


#endif
