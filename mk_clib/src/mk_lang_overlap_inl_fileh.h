#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#define mk_lang_overlap_fn mk_lang_concat(mk_lang_overlap_, mk_lang_overlap_tn)


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_overlap_fn(mk_lang_overlap_t const* const arr1, int const len1, mk_lang_overlap_t const* const arr2, int const len2) mk_lang_noexcept;


#undef mk_lang_overlap_fn
