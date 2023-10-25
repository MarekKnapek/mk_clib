#include "mk_lang_memcpy.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_lang_memcpy(void* const mk_lang_restrict dst, void const* const mk_lang_restrict src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	unsigned char* d;
	unsigned char const* s;
	mk_lang_types_usize_t i;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(cnt != 0);

	d = ((unsigned char*)(dst));
	s = ((unsigned char const*)(src));
	mk_lang_assert(!(d >= s && d < s + cnt));
	mk_lang_assert(!(s >= d && s < d + cnt));
	for(i = 0; i != cnt; ++i, ++d, ++s)
	{
		*d = *s;
	}
}
