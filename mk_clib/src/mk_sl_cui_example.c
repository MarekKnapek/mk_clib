#include "mk_lang_charbit.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"

#define mk_lang_bui_t_name examplebuint
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define examplebuint_sizebits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)

#define mk_sl_cui_t_name examplecuint
#define mk_sl_cui_t_base examplebuint
#define mk_sl_cui_t_count mk_lang_div_roundup(128, examplebuint_sizebits_d)
#define mk_sl_cui_t_endian mk_lang_endian_little
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#include <stdio.h>


int main(void)
{
	int tmp;
	examplecuint_t a; /* 128bit unsigned integer implemented as */
	examplecuint_t b; /* an array of n `unsigned int` integers */
	examplecuint_t c;
	int len;
	char str[examplecuint_strlendec_v + 1];

	tmp = 9;
	examplecuint_from_bi_sint(&a, &tmp); /* a = tmp; */
	examplecuint_set_one(&b); /* b = 1; */
	examplecuint_shl2(&b, 4); /* b <<= 4; */
	examplecuint_add3_wrap_cid_cod(&a, &b, &c); /* c = a + b; */
	len = examplecuint_to_str_dec_n(&c, str, examplecuint_strlendec_v); /* sprintf(str, "%d", c) */
	str[len] = '\0';
	printf("%s\n", str); /* 25 */
}
