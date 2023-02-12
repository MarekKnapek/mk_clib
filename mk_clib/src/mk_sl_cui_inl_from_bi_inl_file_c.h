#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_clamp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_sl_cui_inl_from_bi_inl_def.h"
#define src_bits (mk_sl_cui_inl_from_bi_inl_def_sizeof_bi_t * mk_lang_charbit)
#define dst_parts (mk_lang_clamp(src_bits / mk_sl_cui_inl_def_base_bits, 1, mk_sl_cui_inl_def_count))
#define mask ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(1)) << (mk_sl_cui_inl_def_base_bits - 1))) - ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(1)))) << 1)) + ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(1))))


mk_lang_jumbo void mk_sl_cui_inl_from_bi_inl_def_fn(mk_sl_cui_inl_def_t* x, mk_sl_cui_inl_from_bi_inl_def_bi_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	#if dst_parts == 1
	x->m_data[mk_sl_cui_inl_def_idx(0)] = ((mk_sl_cui_inl_def_base_type)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(*src))));
	#else
	{
		mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t s;
		int i;

		s = ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(*src));
		x->m_data[mk_sl_cui_inl_def_idx(0)] = ((mk_sl_cui_inl_def_base_type)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(s & mask))));
		for(i = 1; i != dst_parts; ++i)
		{
			s = ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(s >> ((int)(mk_sl_cui_inl_def_base_bits))));
			x->m_data[mk_sl_cui_inl_def_idx(i)] = ((mk_sl_cui_inl_def_base_type)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bi_t)(s & mask))));
		}
	}
	#endif
}


#undef dst_bits
#undef src_parts
#undef mask
#include "mk_sl_cui_inl_from_bi_inl_undef.h"
