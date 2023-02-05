#if defined mk_sl_cui_inl_def_t && defined mk_sl_cui_inl_from_bi_inl_btn


#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_assert.h"
#include "mk_lang_clamp.h"


#include "mk_sl_cui_inl_from_bi_inl_def.h"


mk_lang_jumbo void mk_sl_cui_inl_from_bi_inl_def_fn(mk_sl_cui_inl_def_t* x, mk_sl_cui_inl_from_bi_inl_def_bit const* src)
{
	#define src_bits (mk_sl_cui_inl_from_bi_inl_def_sizeof_bit * mk_lang_charbit)
	#define dst_parts (mk_lang_clamp(src_bits / mk_sl_cui_inl_def_base_bits, 1, mk_sl_cui_inl_def_count))

	mk_lang_assert(x);
	mk_lang_assert(src);

	#if dst_parts == 1
	x->m_data[mk_sl_cui_inl_def_idx(0)] = ((mk_sl_cui_inl_def_base_type)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(*src))));
	#else
	{
		mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit s;
		mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit mask;
		int i;
		s = ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(*src));
		mask = ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(1)) << (mk_sl_cui_inl_def_base_bits - 1))) - ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(1)))) << 1)) + ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(1))));
		x->m_data[mk_sl_cui_inl_def_idx(0)] = ((mk_sl_cui_inl_def_base_type)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(s & mask))));
		for(i = 1; i != dst_parts; ++i)
		{
			s = ((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(s >> ((int)(mk_sl_cui_inl_def_base_bits))));
			x->m_data[mk_sl_cui_inl_def_idx(i)] = ((mk_sl_cui_inl_def_base_type)(((mk_sl_cui_inl_from_bi_inl_def_to_unsigned_bit)(s & mask))));
		}
	}
	#endif
	{
		int i;
		for(i = dst_parts; i != mk_sl_cui_inl_def_count; ++i)
		{
			mk_sl_cui_inl_def_base_set_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
		}
	}

	#undef src_bits
	#undef dst_parts
}


#include "mk_sl_cui_inl_from_bi_inl_undef.h"


#elif defined mk_sl_cui_inl_from_bi_inl_btn


#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_lang_concat(mk_lang_concat(mk_sl_cui_inl_from_bi_inl_, zzzzzzzzzz), mk_sl_cui_inl_from_bi_inl_btn)(void)
{
}


#else


#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_sl_cui_inl_from_bi_inl_zzzzzzzzzz2(void)
{
}


#endif


#undef mk_sl_cui_inl_from_bi_inl_btn
