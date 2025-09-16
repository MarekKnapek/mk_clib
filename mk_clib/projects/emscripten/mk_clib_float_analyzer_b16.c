#define mk_lang_jumbo_want 1


#include "../../src/mk_lang_emscripten.h"
#include "../../src/mk_lang_extern.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_wasm_float_analyzer_b16.h"


static mk_lib_float_analyzer_b16_t mk_lib_float_analyzer_b16_g;


mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t majn(mk_lang_types_uintptr_t const fnc, mk_lang_types_uintptr_t const arg) mk_lang_noexcept
{
	return mk_lib_wasm_float_analyzer_b16_main(&mk_lib_float_analyzer_b16_g, fnc, arg);
}
