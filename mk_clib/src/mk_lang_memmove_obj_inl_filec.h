#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


#define mk_lang_memmove_obj_fn mk_lang_concat(mk_lang_memmove_obj_, mk_lang_memmove_obj_tn)


mk_lang_jumbo void mk_lang_memmove_obj_fn(mk_lang_memmove_obj_t* const dst, mk_lang_memmove_obj_t const* const src, mk_lang_size_t const cnt) mk_lang_noexcept
{
	mk_lang_memmove_obj_t* d;
	mk_lang_memmove_obj_t const* s;
	mk_lang_size_t i;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(cnt != 0);

	d = dst;
	s = src;
	if(d >= s && d < s + cnt)
	{
		d = d + (cnt - 1);
		s = s + (cnt - 1);
		for(i = 0; i != cnt; ++i, --d, --s)
		{
			*d = *s;
		}
	}
	else
	{
		for(i = 0; i != cnt; ++i, ++d, ++s)
		{
			*d = *s;
		}
	}
}


#undef mk_lang_memmove_obj_fn
