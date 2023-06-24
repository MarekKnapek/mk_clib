#ifndef mk_include_guard_mk_lang_emscripten
#define mk_include_guard_mk_lang_emscripten


#include "mk_lang_arch.h"


#if mk_lang_arch == mk_lang_arch_emscripten
#include <emscripten.h>
#define mk_lang_emscripten_keepalive EMSCRIPTEN_KEEPALIVE
#else
#define mk_lang_emscripten_keepalive
#endif


#endif
