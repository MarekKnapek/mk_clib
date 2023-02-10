#include "mk_lang_bi.h"
#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"
#include "mk_lang_concat.h"
#include "mk_lang_endian.h"
#include "mk_lang_min.h"
#include "mk_lang_sizeof.h"


#if defined mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_inl_def_lena mk_lang_bui_divmod_lena
#elif defined mk_lang_bui_divmod_inl_lena
#define mk_lang_bui_divmod_inl_def_lena mk_lang_bui_divmod_inl_lena
#else
#define mk_lang_bui_divmod_inl_def_lena 4
#endif

#if defined mk_lang_bui_divmod_lenb
#define mk_lang_bui_divmod_inl_def_lenb mk_lang_bui_divmod_lenb
#elif defined mk_lang_bui_divmod_inl_lenb
#define mk_lang_bui_divmod_inl_def_lenb mk_lang_bui_divmod_inl_lenb
#else
#define mk_lang_bui_divmod_inl_def_lenb 4
#endif

#if defined mk_lang_bui_divmod_endian
#define mk_lang_bui_divmod_inl_def_endian mk_lang_bui_divmod_endian
#elif defined mk_lang_bui_divmod_inl_endian
#define mk_lang_bui_divmod_inl_def_endian mk_lang_bui_divmod_inl_endian
#else
#define mk_lang_bui_divmod_inl_def_endian mk_lang_endian_little
#endif
#if mk_lang_bui_divmod_inl_def_endian == mk_lang_endian_little
#define mk_lang_bui_divmod_inl_def_endian_name le
#define mk_lang_bui_divmod_inl_def_endian_idxa(x) (x)
#define mk_lang_bui_divmod_inl_def_endian_idxb(x) (x)
#elif mk_lang_bui_divmod_inl_def_endian == mk_lang_endian_big
#define mk_lang_bui_divmod_inl_def_endian_name be
#define mk_lang_bui_divmod_inl_def_endian_idxa(x) ((mk_lang_bui_divmod_inl_def_lena - 1) - (x))
#define mk_lang_bui_divmod_inl_def_endian_idxb(x) ((mk_lang_bui_divmod_inl_def_lenb - 1) - (x))
#endif

#if defined mk_lang_bui_divmod_alg
#define mk_lang_bui_divmod_inl_def_alg mk_lang_bui_divmod_alg
#elif defined mk_lang_bui_divmod_inl_alg
#define mk_lang_bui_divmod_inl_def_alg mk_lang_bui_divmod_inl_alg
#else
#define mk_lang_bui_divmod_inl_def_alg 2
#endif

#if mk_lang_bui_divmod_inl_def_alg == 2
#if defined mk_lang_bui_divmod_bt && defined mk_lang_bui_divmod_bt2
#define mk_lang_bui_divmod_inl_def_bt mk_lang_bui_divmod_bt
#define mk_lang_bui_divmod_inl_def_bt2 mk_lang_bui_divmod_bt2
#define mk_lang_bui_divmod_inl_def_bt2_has 1
#elif defined mk_lang_bui_divmod_inl_type
#define mk_lang_bui_divmod_inl_def_bt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_divmod_inl_type), _t)
#define mk_lang_bui_divmod_inl_def_bt2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_bui_divmod_inl_type), _t)
#define mk_lang_bui_divmod_inl_def_bt2_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_bui_divmod_inl_type), _has)
#else
#define mk_lang_bui_divmod_inl_def_bt mk_lang_bi_ushort_t
#define mk_lang_bui_divmod_inl_def_bt2 mk_lang_bi_ulong_t
#define mk_lang_bui_divmod_inl_def_bt2_has 1
#endif
#elif mk_lang_bui_divmod_inl_def_alg == 3
#if defined mk_lang_bui_divmod_bt && defined mk_lang_bui_divmod_bt2 && defined mk_lang_bui_divmod_bt3
#define mk_lang_bui_divmod_inl_def_bt mk_lang_bui_divmod_bt
#define mk_lang_bui_divmod_inl_def_bt2 mk_lang_bui_divmod_bt2
#define mk_lang_bui_divmod_inl_def_bt3 mk_lang_bui_divmod_bt3
#define mk_lang_bui_divmod_inl_def_bt2_has 1
#define mk_lang_bui_divmod_inl_def_bt3_has 1
#elif defined mk_lang_bui_divmod_inl_type
#define mk_lang_bui_divmod_inl_def_bt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_divmod_inl_type), _t)
#define mk_lang_bui_divmod_inl_def_bt2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_bui_divmod_inl_type), _t)
#define mk_lang_bui_divmod_inl_def_bt2_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_bui_divmod_inl_type), _has)
#define mk_lang_bui_divmod_inl_def_bt3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_bui_divmod_inl_type), _t)
#define mk_lang_bui_divmod_inl_def_bt3_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_bui_divmod_inl_type), _has)
#else
#define mk_lang_bui_divmod_inl_def_bt mk_lang_bi_uchar_t
#define mk_lang_bui_divmod_inl_def_bt2 mk_lang_bi_ushort_t
#define mk_lang_bui_divmod_inl_def_bt3 mk_lang_bi_ulong_t
#define mk_lang_bui_divmod_inl_def_bt2_has 1
#define mk_lang_bui_divmod_inl_def_bt3_has 1
#endif
#endif

#if defined mk_lang_bui_divmod_name
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_name)
#elif defined mk_lang_bui_divmod_inl_type && !defined mk_lang_bui_divmod_inl_type_default && defined mk_lang_bui_divmod_inl_lena && !defined mk_lang_bui_divmod_inl_lena_default && defined mk_lang_bui_divmod_inl_lenb && !defined mk_lang_bui_divmod_inl_lenb_default && defined mk_lang_bui_divmod_inl_endian && !defined mk_lang_bui_divmod_inl_endian_default && defined mk_lang_bui_divmod_inl_alg && !defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_type), _), mk_lang_bui_divmod_inl_lena), _), mk_lang_bui_divmod_inl_lenb), _), mk_lang_bui_divmod_inl_def_endian_name), _), mk_lang_bui_divmod_inl_alg)
#elif defined mk_lang_bui_divmod_inl_type && defined mk_lang_bui_divmod_inl_type_default && defined mk_lang_bui_divmod_inl_lena && !defined mk_lang_bui_divmod_inl_lena_default && defined mk_lang_bui_divmod_inl_lenb && !defined mk_lang_bui_divmod_inl_lenb_default && defined mk_lang_bui_divmod_inl_endian && !defined mk_lang_bui_divmod_inl_endian_default && defined mk_lang_bui_divmod_inl_alg && !defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_zzzzzzzzzz_type_, mk_lang_bui_divmod_inl_type), _), mk_lang_bui_divmod_inl_lena), _), mk_lang_bui_divmod_inl_lenb), _), mk_lang_bui_divmod_inl_def_endian_name), _), mk_lang_bui_divmod_inl_alg)
#elif !defined mk_lang_bui_divmod_inl_type && !defined mk_lang_bui_divmod_inl_type_default && defined mk_lang_bui_divmod_inl_lena && defined mk_lang_bui_divmod_inl_lena_default && defined mk_lang_bui_divmod_inl_lenb && !defined mk_lang_bui_divmod_inl_lenb_default && defined mk_lang_bui_divmod_inl_endian && !defined mk_lang_bui_divmod_inl_endian_default && defined mk_lang_bui_divmod_inl_alg && !defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_zzzzzzzzzz_lena_, zzzzzzzzzz), _), mk_lang_bui_divmod_inl_lena), _), mk_lang_bui_divmod_inl_lenb), _), mk_lang_bui_divmod_inl_def_endian_name), _), mk_lang_bui_divmod_inl_alg)
#elif !defined mk_lang_bui_divmod_inl_type && !defined mk_lang_bui_divmod_inl_type_default && !defined mk_lang_bui_divmod_inl_lena && !defined mk_lang_bui_divmod_inl_lena_default && defined mk_lang_bui_divmod_inl_lenb && defined mk_lang_bui_divmod_inl_lenb_default && defined mk_lang_bui_divmod_inl_endian && !defined mk_lang_bui_divmod_inl_endian_default && defined mk_lang_bui_divmod_inl_alg && !defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_zzzzzzzzzz_lenb_, zzzzzzzzzz), _), zzzzzzzzzz), _), _), mk_lang_bui_divmod_inl_def_endian_name), _), mk_lang_bui_divmod_inl_alg)
#elif !defined mk_lang_bui_divmod_inl_type && !defined mk_lang_bui_divmod_inl_type_default && !defined mk_lang_bui_divmod_inl_lena && !defined mk_lang_bui_divmod_inl_lena_default && !defined mk_lang_bui_divmod_inl_lenb && !defined mk_lang_bui_divmod_inl_lenb_default && defined mk_lang_bui_divmod_inl_endian && defined mk_lang_bui_divmod_inl_endian_default && defined mk_lang_bui_divmod_inl_alg && !defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_zzzzzzzzzz_endian_, zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), mk_lang_bui_divmod_inl_def_endian_name), _), mk_lang_bui_divmod_inl_alg)
#elif !defined mk_lang_bui_divmod_inl_type && !defined mk_lang_bui_divmod_inl_type_default && !defined mk_lang_bui_divmod_inl_lena && !defined mk_lang_bui_divmod_inl_lena_default && !defined mk_lang_bui_divmod_inl_lenb && !defined mk_lang_bui_divmod_inl_lenb_default && !defined mk_lang_bui_divmod_inl_endian && !defined mk_lang_bui_divmod_inl_endian_default && defined mk_lang_bui_divmod_inl_alg && defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_zzzzzzzzzz_alg_, zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), mk_lang_bui_divmod_inl_alg)
#elif !defined mk_lang_bui_divmod_inl_type && !defined mk_lang_bui_divmod_inl_type_default && !defined mk_lang_bui_divmod_inl_lena && !defined mk_lang_bui_divmod_inl_lena_default && !defined mk_lang_bui_divmod_inl_lenb && !defined mk_lang_bui_divmod_inl_lenb_default && !defined mk_lang_bui_divmod_inl_endian && !defined mk_lang_bui_divmod_inl_endian_default && !defined mk_lang_bui_divmod_inl_alg && !defined mk_lang_bui_divmod_inl_alg_default
#define mk_lang_bui_divmod_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_zzzzzzzzzz_inl_, zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz)
#endif

#define mk_lang_bui_divmod_inl_def_lenc mk_lang_bui_divmod_inl_def_lena
#define mk_lang_bui_divmod_inl_def_lend mk_lang_min(mk_lang_bui_divmod_inl_def_lena, mk_lang_bui_divmod_inl_def_lenb)
#define mk_lang_bui_divmod_inl_def_endian_idxc mk_lang_bui_divmod_inl_def_endian_idxa
#if mk_lang_bui_divmod_inl_def_endian == mk_lang_endian_little
#define mk_lang_bui_divmod_inl_def_endian_idxd(x) (x)
#elif mk_lang_bui_divmod_inl_def_endian == mk_lang_endian_big
#define mk_lang_bui_divmod_inl_def_endian_name be
#define mk_lang_bui_divmod_inl_def_endian_idxd(x) ((mk_lang_bui_divmod_inl_def_lend - 1) - (x))
#endif

#if mk_lang_bui_divmod_inl_def_lena == 1 && mk_lang_bui_divmod_inl_def_lenb == 1
#define mk_lang_bui_divmod_inl_def_valid 1
#elif mk_lang_bui_divmod_inl_def_alg == 2 && mk_lang_bui_divmod_inl_def_bt2_has == 1
#define mk_lang_bui_divmod_inl_def_valid 1
#elif mk_lang_bui_divmod_inl_def_alg == 3 && mk_lang_bui_divmod_inl_def_bt3_has == 1
#define mk_lang_bui_divmod_inl_def_valid 1
#else
#define mk_lang_bui_divmod_inl_def_valid 0
#endif
