#ifndef mk_include_guard_mk_external_zlib_c
#define mk_include_guard_mk_external_zlib_c
#include "mk_external_zlib.h"

#include "mk_lang_assert.h"
#include "mk_lang_null.h"


void* zcalloc(void* const opaque, unsigned int const items, unsigned int const size);
void zcfree(void* const opaque, void* const address);


void* zcalloc(void* const opaque, unsigned int const items, unsigned int const size){ ((void)(opaque)); ((void)(items)); ((void)(size)); mk_lang_assert_false(); return mk_lang_null; }
void zcfree(void* const opaque, void* const address){ ((void)(opaque)); ((void)(address)); mk_lang_assert_false(); }


#endif
