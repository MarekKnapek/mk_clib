#define mk_lang_jumbo_want 1


#include "../../src/mk_lang_emscripten.h"
#include "../../src/mk_lang_extern.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_wasm_info.h"


mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_void_t majn(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_wasm_info_main();
}
