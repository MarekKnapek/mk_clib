#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_clamp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_sl_cui_inl_to_bi_inl_def.h"
#define dst_bits (mk_sl_cui_inl_to_bi_inl_def_sizeof_bi_t * mk_lang_charbit)
#define src_parts (mk_lang_clamp(dst_bits / mk_sl_cui_inl_def_base_bits, 1, mk_sl_cui_inl_def_count))


mk_lang_jumbo void mk_sl_cui_inl_to_bi_inl_def_fn(mk_sl_cui_inl_def_t const* x, mk_sl_cui_inl_to_bi_inl_def_bi_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	#if src_parts == 1
	*dst = ((mk_sl_cui_inl_to_bi_inl_def_bi_t)(((mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bi_t)(x->m_data[mk_sl_cui_inl_def_idx(0)]))));
	#else
	{
		mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bi_t d;
		int i;

		d = ((mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bi_t)(x->m_data[mk_sl_cui_inl_def_idx(src_parts - 1 - 0)]));
		for(i = 1; i != src_parts; ++i)
		{
			d = ((mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bi_t)(d << ((int)(mk_sl_cui_inl_def_base_bits))));
			d = ((mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bi_t)(d | ((mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bi_t)(x->m_data[mk_sl_cui_inl_def_idx(src_parts - 1 - i)]))));
		}
		*dst = ((mk_sl_cui_inl_to_bi_inl_def_bi_t)(d));
	}
	#endif
}


#undef dst_bits
#undef src_parts
#include "mk_sl_cui_inl_to_bi_inl_undef.h"
