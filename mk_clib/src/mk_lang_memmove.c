#include "mk_lang_memmove.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_lang_memmove(void* const dst, void const* const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	unsigned char* d;
	unsigned char const* s;
	mk_lang_types_usize_t i;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(cnt != 0);

	d = ((unsigned char*)(dst));
	s = ((unsigned char const*)(src));
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
