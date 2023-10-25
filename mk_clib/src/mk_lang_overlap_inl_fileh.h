#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if !defined(mk_lang_overlap_name) && defined(mk_lang_overlap_tn)
#define mk_lang_overlap_name mk_lang_overlap_tn
#endif
#if !defined(mk_lang_overlap_t) && defined(mk_lang_overlap_tt)
#define mk_lang_overlap_t mk_lang_overlap_tt
#endif
#define mk_lang_overlap_fn mk_lang_concat(mk_lang_overlap_, mk_lang_overlap_name)


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_overlap_fn(mk_lang_overlap_t const* const arr1, mk_lang_types_usize_t const len1, mk_lang_overlap_t const* const arr2, mk_lang_types_usize_t const len2) mk_lang_noexcept;


#undef mk_lang_overlap_fn
