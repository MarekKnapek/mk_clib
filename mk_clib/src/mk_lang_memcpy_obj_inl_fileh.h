#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


#define mk_lang_memcpy_obj_fn mk_lang_concat(mk_lang_memcpy_obj_, mk_lang_memcpy_obj_tn)


mk_lang_constexpr mk_lang_jumbo void mk_lang_memcpy_obj_fn(mk_lang_memcpy_obj_t* const dst, mk_lang_memcpy_obj_t const* const src, mk_lang_size_t const cnt) mk_lang_noexcept;


#undef mk_lang_memcpy_obj_fn
