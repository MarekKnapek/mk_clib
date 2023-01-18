#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"


#include "mk_lang_bui_inl_def.h"


mk_lang_jumbo void mk_lang_bui_set_zero(mk_lang_bui_t* x);
mk_lang_jumbo void mk_lang_bui_set_one(mk_lang_bui_t* x);
mk_lang_jumbo void mk_lang_bui_set_bit(mk_lang_bui_t* x, int bit_idx);
mk_lang_jumbo void mk_lang_bui_set_mask(mk_lang_bui_t* x, int bits);

#include "mk_lang_bui_inl_to_bi.h"
#include "mk_lang_bui_inl_from_bi.h"
#include "mk_lang_bui_inl_to_buis_le.h"
#include "mk_lang_bui_inl_to_buis_be.h"
#include "mk_lang_bui_inl_from_buis_le.h"
#include "mk_lang_bui_inl_from_buis_be.h"


#include "mk_lang_bui_inl_undef.h"


#undef mk_lang_bui_btn
#undef mk_lang_bui_n
