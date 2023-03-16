#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


#define mk_lang_memcpy_obj_fn mk_lang_concat(mk_lang_memcpy_obj_, mk_lang_memcpy_obj_tn)


mk_lang_jumbo void mk_lang_memcpy_obj_fn(mk_lang_memcpy_obj_t* const dst, mk_lang_memcpy_obj_t const* const src, mk_lang_size_t const cnt) mk_lang_noexcept
{
	mk_lang_memcpy_obj_t* d;
	mk_lang_memcpy_obj_t const* s;
	mk_lang_size_t i;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(cnt != 0);

	d = dst;
	s = src;
	mk_lang_assert(!(d >= s && d < s + cnt));
	mk_lang_assert(!(s >= d && s < d + cnt));
	for(i = 0; i != cnt; ++i, ++d, ++s)
	{
		*d = *s;
	}
}


#undef mk_lang_memcpy_obj_fn
