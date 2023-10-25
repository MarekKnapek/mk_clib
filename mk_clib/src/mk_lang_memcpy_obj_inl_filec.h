#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#ifdef mk_lang_memcpy_obj_t_
#define mk_lang_memcpy_obj_t mk_lang_memcpy_obj_t_
#endif
#ifdef mk_lang_memcpy_obj_tn_
#define mk_lang_memcpy_obj_tn mk_lang_memcpy_obj_tn_
#endif
#define mk_lang_overlap_t mk_lang_memcpy_obj_t
#define mk_lang_overlap_name mk_lang_memcpy_obj_tn
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#define overlap mk_lang_concat(mk_lang_overlap_, mk_lang_memcpy_obj_tn)


#define mk_lang_memcpy_obj_fn mk_lang_concat(mk_lang_memcpy_obj_, mk_lang_memcpy_obj_tn)


mk_lang_constexpr mk_lang_jumbo void mk_lang_memcpy_obj_fn(mk_lang_memcpy_obj_t* const dst, mk_lang_memcpy_obj_t const* const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_memcpy_obj_t* d mk_lang_constexpr_init;
	mk_lang_memcpy_obj_t const* s mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(cnt != 0);
	mk_lang_assert(!overlap(dst, cnt, src, cnt));

	d = dst;
	s = src;
	for(i = 0; i != cnt; ++i, ++d, ++s)
	{
		*d = *s;
	}
}


#undef mk_lang_memcpy_obj_fn


#undef overlap


#undef mk_lang_memcpy_obj_tn
#undef mk_lang_memcpy_obj_t
