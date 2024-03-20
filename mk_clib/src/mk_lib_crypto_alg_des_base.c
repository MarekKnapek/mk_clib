#include "mk_lib_crypto_alg_des_base.h"


/* NIST FIPS PUB 46-3 */


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_sl_cui_uint8_c32(x) mk_sl_cui_uint8_c(32 - (x))
#define mk_sl_cui_uint8_c56(x) mk_sl_cui_uint8_c(56 - (x))
#define mk_sl_cui_uint8_c64(x) mk_sl_cui_uint8_c(64 - (x))


union mk_lib_crypto_alg_des_base_table_32_data_u
{
	mk_sl_cui_uint8_t m_uint8s[32];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_des_base_table_32_data_u mk_lib_crypto_alg_des_base_table_32_data_t;

struct mk_lib_crypto_alg_des_base_table_32_s
{
	mk_lib_crypto_alg_des_base_table_32_data_t m_data;
};
typedef struct mk_lib_crypto_alg_des_base_table_32_s mk_lib_crypto_alg_des_base_table_32_t;
typedef mk_lib_crypto_alg_des_base_table_32_t const* mk_lib_crypto_alg_des_base_table_32_pct;


union mk_lib_crypto_alg_des_base_table_48_data_u
{
	mk_sl_cui_uint8_t m_uint8s[48];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_des_base_table_48_data_u mk_lib_crypto_alg_des_base_table_48_data_t;

struct mk_lib_crypto_alg_des_base_table_48_s
{
	mk_lib_crypto_alg_des_base_table_48_data_t m_data;
};
typedef struct mk_lib_crypto_alg_des_base_table_48_s mk_lib_crypto_alg_des_base_table_48_t;
typedef mk_lib_crypto_alg_des_base_table_48_t const* mk_lib_crypto_alg_des_base_table_48_pct;


union mk_lib_crypto_alg_des_base_table_56_data_u
{
	mk_sl_cui_uint8_t m_uint8s[56];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_des_base_table_56_data_u mk_lib_crypto_alg_des_base_table_56_data_t;

struct mk_lib_crypto_alg_des_base_table_56_s
{
	mk_lib_crypto_alg_des_base_table_56_data_t m_data;
};
typedef struct mk_lib_crypto_alg_des_base_table_56_s mk_lib_crypto_alg_des_base_table_56_t;
typedef mk_lib_crypto_alg_des_base_table_56_t const* mk_lib_crypto_alg_des_base_table_56_pct;


union mk_lib_crypto_alg_des_base_table_64_data_u
{
	mk_sl_cui_uint8_t m_uint8s[64];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_des_base_table_64_data_u mk_lib_crypto_alg_des_base_table_64_data_t;

struct mk_lib_crypto_alg_des_base_table_64_s
{
	mk_lib_crypto_alg_des_base_table_64_data_t m_data;
};
typedef struct mk_lib_crypto_alg_des_base_table_64_s mk_lib_crypto_alg_des_base_table_64_t;
typedef mk_lib_crypto_alg_des_base_table_64_t const* mk_lib_crypto_alg_des_base_table_64_pct;


mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_56_t const s_mk_lib_crypto_alg_des_base_pc1 =
{{{
	mk_sl_cui_uint8_c64(57), mk_sl_cui_uint8_c64(49), mk_sl_cui_uint8_c64(41), mk_sl_cui_uint8_c64(33), mk_sl_cui_uint8_c64(25), mk_sl_cui_uint8_c64(17), mk_sl_cui_uint8_c64( 9),
	mk_sl_cui_uint8_c64( 1), mk_sl_cui_uint8_c64(58), mk_sl_cui_uint8_c64(50), mk_sl_cui_uint8_c64(42), mk_sl_cui_uint8_c64(34), mk_sl_cui_uint8_c64(26), mk_sl_cui_uint8_c64(18),
	mk_sl_cui_uint8_c64(10), mk_sl_cui_uint8_c64( 2), mk_sl_cui_uint8_c64(59), mk_sl_cui_uint8_c64(51), mk_sl_cui_uint8_c64(43), mk_sl_cui_uint8_c64(35), mk_sl_cui_uint8_c64(27),
	mk_sl_cui_uint8_c64(19), mk_sl_cui_uint8_c64(11), mk_sl_cui_uint8_c64( 3), mk_sl_cui_uint8_c64(60), mk_sl_cui_uint8_c64(52), mk_sl_cui_uint8_c64(44), mk_sl_cui_uint8_c64(36),
	mk_sl_cui_uint8_c64(63), mk_sl_cui_uint8_c64(55), mk_sl_cui_uint8_c64(47), mk_sl_cui_uint8_c64(39), mk_sl_cui_uint8_c64(31), mk_sl_cui_uint8_c64(23), mk_sl_cui_uint8_c64(15),
	mk_sl_cui_uint8_c64( 7), mk_sl_cui_uint8_c64(62), mk_sl_cui_uint8_c64(54), mk_sl_cui_uint8_c64(46), mk_sl_cui_uint8_c64(38), mk_sl_cui_uint8_c64(30), mk_sl_cui_uint8_c64(22),
	mk_sl_cui_uint8_c64(14), mk_sl_cui_uint8_c64( 6), mk_sl_cui_uint8_c64(61), mk_sl_cui_uint8_c64(53), mk_sl_cui_uint8_c64(45), mk_sl_cui_uint8_c64(37), mk_sl_cui_uint8_c64(29),
	mk_sl_cui_uint8_c64(21), mk_sl_cui_uint8_c64(13), mk_sl_cui_uint8_c64( 5), mk_sl_cui_uint8_c64(28), mk_sl_cui_uint8_c64(20), mk_sl_cui_uint8_c64(12), mk_sl_cui_uint8_c64( 4),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_48_t const s_mk_lib_crypto_alg_des_base_pc2 =
{{{
	mk_sl_cui_uint8_c56(14), mk_sl_cui_uint8_c56(17), mk_sl_cui_uint8_c56(11), mk_sl_cui_uint8_c56(24), mk_sl_cui_uint8_c56( 1), mk_sl_cui_uint8_c56( 5),
	mk_sl_cui_uint8_c56( 3), mk_sl_cui_uint8_c56(28), mk_sl_cui_uint8_c56(15), mk_sl_cui_uint8_c56( 6), mk_sl_cui_uint8_c56(21), mk_sl_cui_uint8_c56(10),
	mk_sl_cui_uint8_c56(23), mk_sl_cui_uint8_c56(19), mk_sl_cui_uint8_c56(12), mk_sl_cui_uint8_c56( 4), mk_sl_cui_uint8_c56(26), mk_sl_cui_uint8_c56( 8),
	mk_sl_cui_uint8_c56(16), mk_sl_cui_uint8_c56( 7), mk_sl_cui_uint8_c56(27), mk_sl_cui_uint8_c56(20), mk_sl_cui_uint8_c56(13), mk_sl_cui_uint8_c56( 2),
	mk_sl_cui_uint8_c56(41), mk_sl_cui_uint8_c56(52), mk_sl_cui_uint8_c56(31), mk_sl_cui_uint8_c56(37), mk_sl_cui_uint8_c56(47), mk_sl_cui_uint8_c56(55),
	mk_sl_cui_uint8_c56(30), mk_sl_cui_uint8_c56(40), mk_sl_cui_uint8_c56(51), mk_sl_cui_uint8_c56(45), mk_sl_cui_uint8_c56(33), mk_sl_cui_uint8_c56(48),
	mk_sl_cui_uint8_c56(44), mk_sl_cui_uint8_c56(49), mk_sl_cui_uint8_c56(39), mk_sl_cui_uint8_c56(56), mk_sl_cui_uint8_c56(34), mk_sl_cui_uint8_c56(53),
	mk_sl_cui_uint8_c56(46), mk_sl_cui_uint8_c56(42), mk_sl_cui_uint8_c56(50), mk_sl_cui_uint8_c56(36), mk_sl_cui_uint8_c56(29), mk_sl_cui_uint8_c56(32),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_64_t const s_mk_lib_crypto_alg_des_base_ip =
{{{
	mk_sl_cui_uint8_c64(58), mk_sl_cui_uint8_c64(50), mk_sl_cui_uint8_c64(42), mk_sl_cui_uint8_c64(34), mk_sl_cui_uint8_c64(26), mk_sl_cui_uint8_c64(18), mk_sl_cui_uint8_c64(10), mk_sl_cui_uint8_c64( 2),
	mk_sl_cui_uint8_c64(60), mk_sl_cui_uint8_c64(52), mk_sl_cui_uint8_c64(44), mk_sl_cui_uint8_c64(36), mk_sl_cui_uint8_c64(28), mk_sl_cui_uint8_c64(20), mk_sl_cui_uint8_c64(12), mk_sl_cui_uint8_c64( 4),
	mk_sl_cui_uint8_c64(62), mk_sl_cui_uint8_c64(54), mk_sl_cui_uint8_c64(46), mk_sl_cui_uint8_c64(38), mk_sl_cui_uint8_c64(30), mk_sl_cui_uint8_c64(22), mk_sl_cui_uint8_c64(14), mk_sl_cui_uint8_c64( 6),
	mk_sl_cui_uint8_c64(64), mk_sl_cui_uint8_c64(56), mk_sl_cui_uint8_c64(48), mk_sl_cui_uint8_c64(40), mk_sl_cui_uint8_c64(32), mk_sl_cui_uint8_c64(24), mk_sl_cui_uint8_c64(16), mk_sl_cui_uint8_c64( 8),
	mk_sl_cui_uint8_c64(57), mk_sl_cui_uint8_c64(49), mk_sl_cui_uint8_c64(41), mk_sl_cui_uint8_c64(33), mk_sl_cui_uint8_c64(25), mk_sl_cui_uint8_c64(17), mk_sl_cui_uint8_c64( 9), mk_sl_cui_uint8_c64( 1),
	mk_sl_cui_uint8_c64(59), mk_sl_cui_uint8_c64(51), mk_sl_cui_uint8_c64(43), mk_sl_cui_uint8_c64(35), mk_sl_cui_uint8_c64(27), mk_sl_cui_uint8_c64(19), mk_sl_cui_uint8_c64(11), mk_sl_cui_uint8_c64( 3),
	mk_sl_cui_uint8_c64(61), mk_sl_cui_uint8_c64(53), mk_sl_cui_uint8_c64(45), mk_sl_cui_uint8_c64(37), mk_sl_cui_uint8_c64(29), mk_sl_cui_uint8_c64(21), mk_sl_cui_uint8_c64(13), mk_sl_cui_uint8_c64( 5),
	mk_sl_cui_uint8_c64(63), mk_sl_cui_uint8_c64(55), mk_sl_cui_uint8_c64(47), mk_sl_cui_uint8_c64(39), mk_sl_cui_uint8_c64(31), mk_sl_cui_uint8_c64(23), mk_sl_cui_uint8_c64(15), mk_sl_cui_uint8_c64( 7),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_64_t const s_mk_lib_crypto_alg_des_base_pi =
{{{
	mk_sl_cui_uint8_c64(40), mk_sl_cui_uint8_c64( 8), mk_sl_cui_uint8_c64(48), mk_sl_cui_uint8_c64(16), mk_sl_cui_uint8_c64(56), mk_sl_cui_uint8_c64(24), mk_sl_cui_uint8_c64(64), mk_sl_cui_uint8_c64(32),
	mk_sl_cui_uint8_c64(39), mk_sl_cui_uint8_c64( 7), mk_sl_cui_uint8_c64(47), mk_sl_cui_uint8_c64(15), mk_sl_cui_uint8_c64(55), mk_sl_cui_uint8_c64(23), mk_sl_cui_uint8_c64(63), mk_sl_cui_uint8_c64(31),
	mk_sl_cui_uint8_c64(38), mk_sl_cui_uint8_c64( 6), mk_sl_cui_uint8_c64(46), mk_sl_cui_uint8_c64(14), mk_sl_cui_uint8_c64(54), mk_sl_cui_uint8_c64(22), mk_sl_cui_uint8_c64(62), mk_sl_cui_uint8_c64(30),
	mk_sl_cui_uint8_c64(37), mk_sl_cui_uint8_c64( 5), mk_sl_cui_uint8_c64(45), mk_sl_cui_uint8_c64(13), mk_sl_cui_uint8_c64(53), mk_sl_cui_uint8_c64(21), mk_sl_cui_uint8_c64(61), mk_sl_cui_uint8_c64(29),
	mk_sl_cui_uint8_c64(36), mk_sl_cui_uint8_c64( 4), mk_sl_cui_uint8_c64(44), mk_sl_cui_uint8_c64(12), mk_sl_cui_uint8_c64(52), mk_sl_cui_uint8_c64(20), mk_sl_cui_uint8_c64(60), mk_sl_cui_uint8_c64(28),
	mk_sl_cui_uint8_c64(35), mk_sl_cui_uint8_c64( 3), mk_sl_cui_uint8_c64(43), mk_sl_cui_uint8_c64(11), mk_sl_cui_uint8_c64(51), mk_sl_cui_uint8_c64(19), mk_sl_cui_uint8_c64(59), mk_sl_cui_uint8_c64(27),
	mk_sl_cui_uint8_c64(34), mk_sl_cui_uint8_c64( 2), mk_sl_cui_uint8_c64(42), mk_sl_cui_uint8_c64(10), mk_sl_cui_uint8_c64(50), mk_sl_cui_uint8_c64(18), mk_sl_cui_uint8_c64(58), mk_sl_cui_uint8_c64(26),
	mk_sl_cui_uint8_c64(33), mk_sl_cui_uint8_c64( 1), mk_sl_cui_uint8_c64(41), mk_sl_cui_uint8_c64( 9), mk_sl_cui_uint8_c64(49), mk_sl_cui_uint8_c64(17), mk_sl_cui_uint8_c64(57), mk_sl_cui_uint8_c64(25),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_48_t const s_mk_lib_crypto_alg_des_base_e =
{{{
	mk_sl_cui_uint8_c32(32), mk_sl_cui_uint8_c32( 1), mk_sl_cui_uint8_c32( 2), mk_sl_cui_uint8_c32( 3), mk_sl_cui_uint8_c32( 4), mk_sl_cui_uint8_c32( 5),
	mk_sl_cui_uint8_c32( 4), mk_sl_cui_uint8_c32( 5), mk_sl_cui_uint8_c32( 6), mk_sl_cui_uint8_c32( 7), mk_sl_cui_uint8_c32( 8), mk_sl_cui_uint8_c32( 9),
	mk_sl_cui_uint8_c32( 8), mk_sl_cui_uint8_c32( 9), mk_sl_cui_uint8_c32(10), mk_sl_cui_uint8_c32(11), mk_sl_cui_uint8_c32(12), mk_sl_cui_uint8_c32(13),
	mk_sl_cui_uint8_c32(12), mk_sl_cui_uint8_c32(13), mk_sl_cui_uint8_c32(14), mk_sl_cui_uint8_c32(15), mk_sl_cui_uint8_c32(16), mk_sl_cui_uint8_c32(17),
	mk_sl_cui_uint8_c32(16), mk_sl_cui_uint8_c32(17), mk_sl_cui_uint8_c32(18), mk_sl_cui_uint8_c32(19), mk_sl_cui_uint8_c32(20), mk_sl_cui_uint8_c32(21),
	mk_sl_cui_uint8_c32(20), mk_sl_cui_uint8_c32(21), mk_sl_cui_uint8_c32(22), mk_sl_cui_uint8_c32(23), mk_sl_cui_uint8_c32(24), mk_sl_cui_uint8_c32(25),
	mk_sl_cui_uint8_c32(24), mk_sl_cui_uint8_c32(25), mk_sl_cui_uint8_c32(26), mk_sl_cui_uint8_c32(27), mk_sl_cui_uint8_c32(28), mk_sl_cui_uint8_c32(29),
	mk_sl_cui_uint8_c32(28), mk_sl_cui_uint8_c32(29), mk_sl_cui_uint8_c32(30), mk_sl_cui_uint8_c32(31), mk_sl_cui_uint8_c32(32), mk_sl_cui_uint8_c32( 1),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_32_t const s_mk_lib_crypto_alg_des_base_p =
{{{
	mk_sl_cui_uint8_c32(16), mk_sl_cui_uint8_c32( 7), mk_sl_cui_uint8_c32(20), mk_sl_cui_uint8_c32(21),
	mk_sl_cui_uint8_c32(29), mk_sl_cui_uint8_c32(12), mk_sl_cui_uint8_c32(28), mk_sl_cui_uint8_c32(17),
	mk_sl_cui_uint8_c32( 1), mk_sl_cui_uint8_c32(15), mk_sl_cui_uint8_c32(23), mk_sl_cui_uint8_c32(26),
	mk_sl_cui_uint8_c32( 5), mk_sl_cui_uint8_c32(18), mk_sl_cui_uint8_c32(31), mk_sl_cui_uint8_c32(10),
	mk_sl_cui_uint8_c32( 2), mk_sl_cui_uint8_c32( 8), mk_sl_cui_uint8_c32(24), mk_sl_cui_uint8_c32(14),
	mk_sl_cui_uint8_c32(32), mk_sl_cui_uint8_c32(27), mk_sl_cui_uint8_c32( 3), mk_sl_cui_uint8_c32( 9),
	mk_sl_cui_uint8_c32(19), mk_sl_cui_uint8_c32(13), mk_sl_cui_uint8_c32(30), mk_sl_cui_uint8_c32( 6),
	mk_sl_cui_uint8_c32(22), mk_sl_cui_uint8_c32(11), mk_sl_cui_uint8_c32( 4), mk_sl_cui_uint8_c32(25),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_des_base_table_64_t const s_mk_lib_crypto_alg_des_base_ss[8] =
{
	{{{
		mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 7),
		mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 8),
		mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 0),
		mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(13),
	}}},
	{{{
		mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(10),
		mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 5),
		mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(15),
		mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 9),
	}}},
	{{{
		mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8),
		mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 1),
		mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 7),
		mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(12),
	}}},
	{{{
		mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(15),
		mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 9),
		mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 4),
		mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(14),
	}}},
	{{{
		mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 9),
		mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 6),
		mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(14),
		mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 3),
	}}},
	{{{
		mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(11),
		mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 8),
		mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 6),
		mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(13),
	}}},
	{{{
		mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 1),
		mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 6),
		mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 2),
		mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(12),
	}}},
	{{{
		mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 7),
		mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 2),
		mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c(11), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 8),
		mk_sl_cui_uint8_c( 2), mk_sl_cui_uint8_c( 1), mk_sl_cui_uint8_c(14), mk_sl_cui_uint8_c( 7), mk_sl_cui_uint8_c( 4), mk_sl_cui_uint8_c(10), mk_sl_cui_uint8_c( 8), mk_sl_cui_uint8_c(13), mk_sl_cui_uint8_c(15), mk_sl_cui_uint8_c(12), mk_sl_cui_uint8_c( 9), mk_sl_cui_uint8_c( 0), mk_sl_cui_uint8_c( 3), mk_sl_cui_uint8_c( 5), mk_sl_cui_uint8_c( 6), mk_sl_cui_uint8_c(11),
	}}},
};


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_alg_des_base_is_28_bit(mk_sl_cui_uint32_pct const x) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_cui_uint32_shr3(x, 28, &ta);
	ret = mk_sl_cui_uint32_is_zero(&ta);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_alg_des_base_is_48_bit(mk_sl_cui_uint64_pct const x) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_cui_uint64_shr3(x, 48, &ta);
	ret = mk_sl_cui_uint64_is_zero(&ta);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_alg_des_base_is_56_bit(mk_sl_cui_uint64_pct const x) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_cui_uint64_shr3(x, 56, &ta);
	ret = mk_sl_cui_uint64_is_zero(&ta);
	return ret;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_u64_to_u32(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u32);

	mk_sl_cui_uint64_to_bi_ulong(u64, &tul);
	mk_sl_cui_uint32_from_bi_ulong(u32, &tul);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_u32_to_u64(mk_sl_cui_uint32_pct const u32, mk_sl_cui_uint64_pt const u64) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;

	mk_lang_assert(u32);
	mk_lang_assert(u64);

	mk_sl_cui_uint32_to_bi_ulong(u32, &tul);
	mk_sl_cui_uint64_from_bi_ulong(u64, &tul);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_perm_32_to_32(mk_lib_crypto_alg_des_base_table_32_pct const table, mk_sl_cui_uint32_pct const a, mk_sl_cui_uint32_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint32_t one mk_lang_constexpr_init;
	mk_sl_cui_uint32_t aa mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t bit mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(table);
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint32_set_one(&one);
	aa = *a;
	idx = 0;
	mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
	mk_lang_assert(bit >= 0 && bit < 32);
	mk_sl_cui_uint32_shr3(&aa, bit, &ta);
	mk_sl_cui_uint32_and3(&ta, &one, &bb);
	for(i = 1; i != 32; ++i)
	{
		mk_sl_cui_uint32_shl2(&bb, 1);
		idx = i;
		mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
		mk_lang_assert(bit >= 0 && bit < 32);
		mk_sl_cui_uint32_shr3(&aa, bit, &ta);
		mk_sl_cui_uint32_and2(&ta, &one);
		mk_sl_cui_uint32_or2(&bb, &ta);
	}
	*b = bb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_perm_32_to_48(mk_lib_crypto_alg_des_base_table_48_pct const table, mk_sl_cui_uint32_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint32_t one mk_lang_constexpr_init;
	mk_sl_cui_uint32_t aa mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t bit mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

	mk_lang_assert(table);
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint32_set_one(&one);
	aa = *a;
	idx = 0;
	mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
	mk_lang_assert(bit >= 0 && bit < 32);
	mk_sl_cui_uint32_shr3(&aa, bit, &ta);
	mk_sl_cui_uint32_and2(&ta, &one);
	mk_lib_crypto_alg_des_base_u32_to_u64(&ta, &bb);
	for(i = 1; i != 48; ++i)
	{
		mk_sl_cui_uint64_shl2(&bb, 1);
		idx = i;
		mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
		mk_lang_assert(bit >= 0 && bit < 32);
		mk_sl_cui_uint32_shr3(&aa, bit, &ta);
		mk_sl_cui_uint32_and2(&ta, &one);
		mk_lib_crypto_alg_des_base_u32_to_u64(&ta, &tb);
		mk_sl_cui_uint64_or2(&bb, &tb);
	}
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_48_bit(&bb));
	*b = bb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_perm_56_to_48(mk_lib_crypto_alg_des_base_table_48_pct const table, mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint64_t one mk_lang_constexpr_init;
	mk_sl_cui_uint64_t aa mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t bit mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(table);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_56_bit(a));

	mk_sl_cui_uint64_set_one(&one);
	aa = *a;
	idx = 0;
	mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
	mk_lang_assert(bit >= 0 && bit < 56);
	mk_sl_cui_uint64_shr3(&aa, bit, &ta);
	mk_sl_cui_uint64_and3(&ta, &one, &bb);
	for(i = 1; i != 48; ++i)
	{
		mk_sl_cui_uint64_shl2(&bb, 1);
		idx = i;
		mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
		mk_lang_assert(bit >= 0 && bit < 56);
		mk_sl_cui_uint64_shr3(&aa, bit, &ta);
		mk_sl_cui_uint64_and2(&ta, &one);
		mk_sl_cui_uint64_or2(&bb, &ta);
	}
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_48_bit(&bb));
	*b = bb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_perm_64_to_56(mk_lib_crypto_alg_des_base_table_56_pct const table, mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint64_t one mk_lang_constexpr_init;
	mk_sl_cui_uint64_t aa mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t bit mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(table);
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint64_set_one(&one);
	aa = *a;
	idx = 0;
	mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
	mk_lang_assert(bit >= 0 && bit < 64);
	mk_sl_cui_uint64_shr3(&aa, bit, &ta);
	mk_sl_cui_uint64_and3(&ta, &one, &bb);
	for(i = 1; i != 56; ++i)
	{
		mk_sl_cui_uint64_shl2(&bb, 1);
		idx = i;
		mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
		mk_lang_assert(bit >= 0 && bit < 64);
		mk_sl_cui_uint64_shr3(&aa, bit, &ta);
		mk_sl_cui_uint64_and2(&ta, &one);
		mk_sl_cui_uint64_or2(&bb, &ta);
	}
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_56_bit(&bb));
	*b = bb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_perm_64_to_64(mk_lib_crypto_alg_des_base_table_64_pct const table, mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint64_t one mk_lang_constexpr_init;
	mk_sl_cui_uint64_t aa mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t bit mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(table);
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint64_set_one(&one);
	aa = *a;
	idx = 0;
	mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
	mk_lang_assert(bit >= 0 && bit < 64);
	mk_sl_cui_uint64_shr3(&aa, bit, &ta);
	mk_sl_cui_uint64_and3(&ta, &one, &bb);
	for(i = 1; i != 64; ++i)
	{
		mk_sl_cui_uint64_shl2(&bb, 1);
		idx = i;
		mk_sl_cui_uint8_to_bi_sint(&table->m_data.m_uint8s[idx], &bit);
		mk_lang_assert(bit >= 0 && bit < 64);
		mk_sl_cui_uint64_shr3(&aa, bit, &ta);
		mk_sl_cui_uint64_and2(&ta, &one);
		mk_sl_cui_uint64_or2(&bb, &ta);
	}
	*b = bb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_pc1(mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_pc1.m_data.m_uint8s) == 56);

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_des_base_perm_64_to_56(&s_mk_lib_crypto_alg_des_base_pc1, a, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_pc2(mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_pc2.m_data.m_uint8s) == 48);

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_des_base_perm_56_to_48(&s_mk_lib_crypto_alg_des_base_pc2, a, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_ip(mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_ip.m_data.m_uint8s) == 64);

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_des_base_perm_64_to_64(&s_mk_lib_crypto_alg_des_base_ip, a, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_pi(mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_pi.m_data.m_uint8s) == 64);

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_des_base_perm_64_to_64(&s_mk_lib_crypto_alg_des_base_pi, a, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_e(mk_sl_cui_uint32_pct const a, mk_sl_cui_uint64_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_e.m_data.m_uint8s) == 48);

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_des_base_perm_32_to_48(&s_mk_lib_crypto_alg_des_base_e, a, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_p(mk_sl_cui_uint32_pct const a, mk_sl_cui_uint32_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(a);

	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_p.m_data.m_uint8s) == 32);

	mk_lib_crypto_alg_des_base_perm_32_to_32(&s_mk_lib_crypto_alg_des_base_p, a, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_get_lr(mk_sl_cui_uint64_pct const lr, mk_sl_cui_uint32_prt const l, mk_sl_cui_uint32_prt const r) mk_lang_noexcept
{
	mk_sl_cui_uint64_t lrlr mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ll mk_lang_constexpr_init;
	mk_sl_cui_uint64_t rr mk_lang_constexpr_init;
	mk_sl_cui_uint32_t lll mk_lang_constexpr_init;
	mk_sl_cui_uint32_t rrr mk_lang_constexpr_init;

	mk_lang_assert(lr);
	mk_lang_assert(l);
	mk_lang_assert(r);
	mk_lang_assert(l != r);

	lrlr = *lr;
	mk_sl_cui_uint64_shr3(&lrlr, 32, &ll);
	rr = lrlr;
	mk_lib_crypto_alg_des_base_u64_to_u32(&ll, &lll);
	mk_lib_crypto_alg_des_base_u64_to_u32(&rr, &rrr);
	*l = lll;
	*r = rrr;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_set_lr(mk_sl_cui_uint64_pt const lr, mk_sl_cui_uint32_prct const l, mk_sl_cui_uint32_prct const r) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ll mk_lang_constexpr_init;
	mk_sl_cui_uint64_t rr mk_lang_constexpr_init;

	mk_lang_assert(lr);
	mk_lang_assert(l);
	mk_lang_assert(r);
	mk_lang_assert(l != r);

	mk_lib_crypto_alg_des_base_u32_to_u64(l, &ll);
	mk_lib_crypto_alg_des_base_u32_to_u64(r, &rr);
	mk_sl_cui_uint64_shl2(&ll, 32);
	mk_sl_cui_uint64_or3(&ll, &rr, lr);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_get_cd(mk_sl_cui_uint64_pct const key, mk_sl_cui_uint32_prt const c, mk_sl_cui_uint32_prt const d) mk_lang_noexcept
{
	mk_sl_cui_uint64_t k mk_lang_constexpr_init;
	mk_sl_cui_uint64_t cc mk_lang_constexpr_init;
	mk_sl_cui_uint64_t dd mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ccc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ddd mk_lang_constexpr_init;
	mk_sl_cui_uint32_t mask mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_56_bit(key));

	k = *key;
	mk_sl_cui_uint64_shr3(&k, 28, &cc);
	dd = k;
	mk_lib_crypto_alg_des_base_u64_to_u32(&cc, &ccc);
	mk_lib_crypto_alg_des_base_u64_to_u32(&dd, &ddd);
	mk_sl_cui_uint32_set_mask(&mask, 28);
	mk_sl_cui_uint32_and2(&ccc, &mask);
	mk_sl_cui_uint32_and2(&ddd, &mask);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_28_bit(&ccc));
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_28_bit(&ddd));
	*c = ccc;
	*d = ddd;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_set_cd(mk_sl_cui_uint64_pt const key, mk_sl_cui_uint32_prct const c, mk_sl_cui_uint32_prct const d) mk_lang_noexcept
{
	mk_sl_cui_uint64_t cc mk_lang_constexpr_init;
	mk_sl_cui_uint64_t dd mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_28_bit(c));
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_28_bit(d));

	mk_lib_crypto_alg_des_base_u32_to_u64(c, &cc);
	mk_lib_crypto_alg_des_base_u32_to_u64(d, &dd);
	mk_sl_cui_uint64_shl2(&cc, 28);
	mk_sl_cui_uint64_or3(&cc, &dd, key);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_56_bit(key));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_rot_28_one(mk_sl_cui_uint32_pct const a, mk_lang_types_bool_t const b, mk_sl_cui_uint32_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t mask mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b == mk_lang_false || b == mk_lang_true);
	mk_lang_assert(c);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_28_bit(a));

	ta = *a;
	mk_sl_cui_uint32_set_mask(&mask, 28);
	n = (b == mk_lang_false ? 0 : 1) + 1;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint32_shr3(&ta, 28 - 1, &tb);
		mk_lang_assert(mk_sl_cui_uint32_is_zero(&tb) || mk_sl_cui_uint32_is_one(&tb));
		mk_sl_cui_uint32_shl2(&ta, 1);
		mk_sl_cui_uint32_or2(&ta, &tb);
		mk_sl_cui_uint32_and2(&ta, &mask);
	}
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_28_bit(&ta));
	*c = ta;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_rot_28_two(mk_sl_cui_uint32_pct const cin, mk_sl_cui_uint32_pct const din, mk_lang_types_bool_t const shift, mk_sl_cui_uint32_pt const cout, mk_sl_cui_uint32_pt const dout) mk_lang_noexcept
{
	mk_lang_assert(cin);
	mk_lang_assert(din);
	mk_lang_assert(shift == mk_lang_false || shift == mk_lang_true);
	mk_lang_assert(cout);
	mk_lang_assert(dout);
	mk_lang_assert(cin != din);
	mk_lang_assert(cout != dout);

	mk_lib_crypto_alg_des_base_rot_28_one(cin, shift, cout);
	mk_lib_crypto_alg_des_base_rot_28_one(din, shift, dout);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_expand(mk_lib_crypto_alg_des_base_key_pct const key, mk_lib_crypto_alg_des_base_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_types_ushort_t rot_cnts mk_lang_constexpr_init;
	mk_sl_cui_uint64_t k mk_lang_constexpr_init;
	mk_sl_cui_uint32_t c mk_lang_constexpr_init;
	mk_sl_cui_uint32_t d mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_bool_t rot_cnt mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	rot_cnts = 0x7efcu; /* 1 1 2 2 2 2 2 2 1 2 2 2 2 2 2 1 */
	mk_sl_uint_64_from_8_be(&k, &key->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_des_base_pc1(&k, &k);
	mk_lib_crypto_alg_des_base_get_cd(&k, &c, &d);
	n = mk_lib_crypto_alg_des_base_nr;
	for(i = 0; i != n; ++i)
	{
		rot_cnt = ((rot_cnts & 0x1) == 0x0) ? mk_lang_false : mk_lang_true;
		mk_lib_crypto_alg_des_base_rot_28_two(&c, &d, rot_cnt, &c, &d);
		mk_lib_crypto_alg_des_base_set_cd(&k, &c, &d);
		mk_lib_crypto_alg_des_base_pc2(&k, &schedule->m_data.m_uint64s[i]);
		rot_cnts >>= 1;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_s_one(mk_lang_types_sint_t const s_idx, mk_sl_cui_uint32_pct const a, mk_sl_cui_uint32_pt const b) mk_lang_noexcept
{
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_uint_t row mk_lang_constexpr_init;
	mk_lang_types_uint_t col mk_lang_constexpr_init;
	mk_lang_types_uint_t idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_t val mk_lang_constexpr_init;

	mk_lang_assert(s_idx >= 0 && s_idx < 8);
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint32_to_bi_uint(a, &tui);
	mk_lang_assert(tui >> 6 == 0u);
	row = ((tui >> 5) << 1) | (tui & 1u);
	col = (tui >> 1) & 0xfu;
	idx = (row << 4) | col;
	mk_lang_assert(idx >> 6 == 0u);
	val = s_mk_lib_crypto_alg_des_base_ss[s_idx].m_data.m_uint8s[idx];
	mk_sl_cui_uint8_to_bi_uint(&val, &tui);
	mk_lang_assert(tui >> 4 == 0u);
	mk_sl_cui_uint32_from_bi_uint(b, &tui);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_s_all(mk_sl_cui_uint64_pct const a, mk_sl_cui_uint32_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint64_t aa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t mask mk_lang_constexpr_init;
	mk_sl_cui_uint32_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(s_mk_lib_crypto_alg_des_base_ss) == 8);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_48_bit(a));

	aa = *a;
	mk_sl_cui_uint32_set_mask(&mask, 6);
	mk_sl_cui_uint32_set_zero(&bb);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint64_shr3(&aa, i * 6, &ta);
		mk_lib_crypto_alg_des_base_u64_to_u32(&ta, &tb);
		mk_sl_cui_uint32_and2(&tb, &mask);
		mk_lib_crypto_alg_des_base_s_one((8 - 1) - i, &tb, &tb);
		mk_sl_cui_uint32_shl2(&tb, i * 4);
		mk_sl_cui_uint32_or2(&bb, &tb);
	}
	*b = bb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_f(mk_sl_cui_uint32_pct const r, mk_sl_cui_uint64_pct const k, mk_sl_cui_uint32_pt const f) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(r);
	mk_lang_assert(k);
	mk_lang_assert(f);
	mk_lang_assert(mk_lib_crypto_alg_des_base_is_48_bit(k));

	mk_lib_crypto_alg_des_base_e(r, &ta);
	mk_sl_cui_uint64_xor2(&ta, k);
	mk_lib_crypto_alg_des_base_s_all(&ta, &tb);
	mk_lib_crypto_alg_des_base_p(&tb, &tb);
	*f = tb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_schedule_crypt_one(mk_lib_crypto_alg_des_base_schedule_pct const schedule, mk_lib_crypto_alg_des_base_msg_pct const input, mk_lib_crypto_alg_des_base_msg_pt const output) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t l mk_lang_constexpr_init;
	mk_sl_cui_uint32_t r mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_sl_uint_64_from_8_be(&ta, &input->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_des_base_ip(&ta, &ta);
	mk_lib_crypto_alg_des_base_get_lr(&ta, &l, &r);
	n = mk_lib_crypto_alg_des_base_nr;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_des_base_f(&r, &schedule->m_data.m_uint64s[i], &tb);
		mk_sl_cui_uint32_xor2(&tb, &l);
		l = r;
		r = tb;
	}
	mk_lib_crypto_alg_des_base_set_lr(&ta, &r, &l);
	mk_lib_crypto_alg_des_base_pi(&ta, &ta);
	mk_sl_uint_64_to_8_be(&ta, &output->m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_des_base_schedule_crypt_all(mk_lib_crypto_alg_des_base_schedule_pct const schedule, mk_lib_crypto_alg_des_base_msg_pct const input, mk_lib_crypto_alg_des_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_des_base_msg_len_m);

	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_des_base_schedule_crypt_one(schedule, &input[i], &output[i]);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_des_base_schedule_encrypt(mk_lib_crypto_alg_des_base_schedule_pct const schedule, mk_lib_crypto_alg_des_base_msg_pct const input, mk_lib_crypto_alg_des_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_des_base_msg_len_m);

	mk_lib_crypto_alg_des_base_schedule_crypt_all(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_des_base_schedule_decrypt(mk_lib_crypto_alg_des_base_schedule_pct const schedule, mk_lib_crypto_alg_des_base_msg_pct const input, mk_lib_crypto_alg_des_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_des_base_msg_len_m);

	mk_lib_crypto_alg_des_base_schedule_crypt_all(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_des_base_expand_enc(mk_lib_crypto_alg_des_base_key_pct const key, mk_lib_crypto_alg_des_base_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_des_base_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_des_base_expand_dec(mk_lib_crypto_alg_des_base_key_pct const key, mk_lib_crypto_alg_des_base_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_des_base_expand(key, schedule);
	for(i = 0; i != mk_lib_crypto_alg_des_base_nr / 2; ++i)
	{
		ta = schedule->m_data.m_uint64s[i];
		schedule->m_data.m_uint64s[i] = schedule->m_data.m_uint64s[(mk_lib_crypto_alg_des_base_nr - 1) - i];
		schedule->m_data.m_uint64s[(mk_lib_crypto_alg_des_base_nr - 1) - i] = ta;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_des_base_encrypt(mk_lib_crypto_alg_des_base_key_pct const key, mk_lib_crypto_alg_des_base_msg_pct const input, mk_lib_crypto_alg_des_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_des_base_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_des_base_expand_enc(key, &schedule);
	mk_lib_crypto_alg_des_base_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_des_base_decrypt(mk_lib_crypto_alg_des_base_key_pct const key, mk_lib_crypto_alg_des_base_msg_pct const input, mk_lib_crypto_alg_des_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_des_base_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_des_base_expand_dec(key, &schedule);
	mk_lib_crypto_alg_des_base_schedule_decrypt(&schedule, input, output, 1);
}


#undef mk_sl_cui_uint8_c32
#undef mk_sl_cui_uint8_c56
#undef mk_sl_cui_uint8_c64
