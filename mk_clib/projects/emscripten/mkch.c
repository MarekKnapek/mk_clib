#define mk_lang_jumbo_want 1


#include "../../src/mk_lang_emscripten.h"
#include "../../src/mk_lang_extern.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_wasm_hasher.h"


static mk_lib_wasm_hasher_t mkch_g;


mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_get_buffer_buf(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_get_buffer_buf(&mkch_g);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_get_buffer_len(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_get_buffer_len(&mkch_g);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_get_alg_count(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_get_alg_count(&mkch_g);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_get_alg_str_buf(mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_get_alg_str_buf(&mkch_g, idx);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_get_alg_str_len(mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_get_alg_str_len(&mkch_g, idx);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_init(mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_init(&mkch_g, idx);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_get_digest_len(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_get_digest_len(&mkch_g);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_append(mk_lang_types_uintptr_t const count) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_append(&mkch_g, count);
}

mk_lang_extern_force_c mk_lang_emscripten_keepalive mk_lang_types_uintptr_t mkch_finish(mk_lang_types_uintptr_t const xof_len) mk_lang_noexcept
{
	return mk_lib_wasm_hasher_finish(&mkch_g, xof_len);
}
