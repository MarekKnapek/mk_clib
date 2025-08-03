#ifndef mk_include_guard_mk_external_zlib_c
#define mk_include_guard_mk_external_zlib_c
#include "mk_external_zlib.h"

#include "mk_lang_null.h"


void* zcalloc(void*, unsigned int, unsigned int);
void zcfree(void*, void*);


void* zcalloc(void*, unsigned int, unsigned int){ return mk_lang_null; }
void zcfree(void*, void*){}


#endif
