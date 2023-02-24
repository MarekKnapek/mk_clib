#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_max.h"


#if mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_uchar_t * mk_lang_charbit && mk_lang_bui_to2_uchar_has && mk_lang_bui_to3_uchar_has
#define mk_sl_cui_inl_filec_div_tn uchar
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_uchar_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_uchar_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_uchar_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ushort_t * mk_lang_charbit && mk_lang_bui_to2_ushort_has && mk_lang_bui_to3_ushort_has
#define mk_sl_cui_inl_filec_div_tn ushort
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ushort_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ushort_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ushort_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_uint_t * mk_lang_charbit && mk_lang_bui_to2_uint_has && mk_lang_bui_to3_uint_has
#define mk_sl_cui_inl_filec_div_tn uint
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_uint_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_uint_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_uint_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ulong_t * mk_lang_charbit && mk_lang_bui_to2_ulong_has && mk_lang_bui_to3_ulong_has
#define mk_sl_cui_inl_filec_div_tn ulong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ulong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ulong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ulong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ullong_t * mk_lang_charbit && mk_lang_bui_to2_ullong_has && mk_lang_bui_to3_ullong_has
#define mk_sl_cui_inl_filec_div_tn ullong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ullong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ullong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ullong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit && mk_lang_bui_to2_ulllong_has && mk_lang_bui_to3_ulllong_has
#define mk_sl_cui_inl_filec_div_tn ulllong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ulllong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ulllong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ulllong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_uchar_t * mk_lang_charbit && mk_lang_bui_to2_uchar_has
#define mk_sl_cui_inl_filec_div_tn uchar
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_uchar_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_uchar_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_uchar_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 2
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ushort_t * mk_lang_charbit && mk_lang_bui_to2_ushort_has
#define mk_sl_cui_inl_filec_div_tn ushort
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ushort_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ushort_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ushort_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 2
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_uint_t * mk_lang_charbit && mk_lang_bui_to2_uint_has
#define mk_sl_cui_inl_filec_div_tn uint
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_uint_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_uint_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_uint_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 2
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ulong_t * mk_lang_charbit && mk_lang_bui_to2_ulong_has
#define mk_sl_cui_inl_filec_div_tn ulong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ulong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ulong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ulong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 2
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ullong_t * mk_lang_charbit && mk_lang_bui_to2_ullong_has
#define mk_sl_cui_inl_filec_div_tn ullong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ullong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ullong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ullong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 2
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_sl_cui_inl_defd_base_bits == mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit && mk_lang_bui_to2_ulllong_has
#define mk_sl_cui_inl_filec_div_tn ulllong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_bt mk_lang_bi_ulllong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ulllong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ulllong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_sl_cui_inl_defd_count
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 2
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_lang_bui_to2_ulllong_has && mk_lang_bui_to3_ulllong_has
#define mk_sl_cui_inl_filec_div_tn ulllong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_defd_bits, mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit))
#define mk_lang_bui_divmod_bt mk_lang_bi_ulllong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ulllong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ulllong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_lang_bui_to2_ullong_has && mk_lang_bui_to3_ullong_has
#define mk_sl_cui_inl_filec_div_tn ullong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_defd_bits, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit))
#define mk_lang_bui_divmod_bt mk_lang_bi_ullong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ullong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ullong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_lang_bui_to2_ulong_has && mk_lang_bui_to3_ulong_has
#define mk_sl_cui_inl_filec_div_tn ulong
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_defd_bits, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit))
#define mk_lang_bui_divmod_bt mk_lang_bi_ulong_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ulong_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ulong_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_lang_bui_to2_uint_has && mk_lang_bui_to3_uint_has
#define mk_sl_cui_inl_filec_div_tn uint
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_defd_bits, mk_lang_sizeof_bi_uint_t * mk_lang_charbit))
#define mk_lang_bui_divmod_bt mk_lang_bi_uint_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_uint_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_uint_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_lang_bui_to2_ushort_has && mk_lang_bui_to3_ushort_has
#define mk_sl_cui_inl_filec_div_tn ushort
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_defd_bits, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit))
#define mk_lang_bui_divmod_bt mk_lang_bi_ushort_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_ushort_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_ushort_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#elif mk_lang_bui_to2_uchar_has && mk_lang_bui_to3_uchar_has
#define mk_sl_cui_inl_filec_div_tn uchar
#define mk_sl_cui_inl_filec_div_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_filec_div_tn), _t)
#define mk_sl_cui_inl_filec_div_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_defd_bits, mk_lang_sizeof_bi_uchar_t * mk_lang_charbit))
#define mk_lang_bui_divmod_bt mk_lang_bi_uchar_t
#define mk_lang_bui_divmod_bt2 mk_lang_bui_to2_uchar_t
#define mk_lang_bui_divmod_bt3 mk_lang_bui_to3_uchar_t
#define mk_lang_bui_divmod_lena mk_sl_cui_inl_filec_div_count
#define mk_lang_bui_divmod_lenb mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_endian mk_sl_cui_inl_defd_endian
#define mk_lang_bui_divmod_alg 3
#define mk_lang_bui_divmod_name mk_sl_cui_inl_defd_name
#include "mk_lang_bui_divmod_inl_filec.h"
#endif

#define mk_sl_cui_inl_filec_div_convert_to_buis mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _to_buis_), mk_sl_cui_inl_filec_div_tn), _), mk_sl_cui_inl_defd_endian_name)
#define mk_sl_cui_inl_filec_div_convert_from_buis mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _from_buis_), mk_sl_cui_inl_filec_div_tn), _), mk_sl_cui_inl_defd_endian_name)
#define mk_sl_cui_inl_filec_div_fn mk_lang_concat(mk_lang_bui_divmod_, mk_sl_cui_inl_defd_name)
