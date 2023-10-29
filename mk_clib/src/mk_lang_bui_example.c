#define mk_lang_bui_t_name exampleuint
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"


int main(void)
{
	int tmp;
	exampleuint_t a; /* unsigned int a; */
	exampleuint_t b; /* unsigned int b; */
	exampleuint_t c; /* unsigned int c; */

	tmp = 9;
	exampleuint_from_bi_sint(&a, &tmp); /* a = tmp; */
	exampleuint_set_one(&b); /* b = 1; */
	exampleuint_shl2(&b, 4); /* b <<= 4; */
	exampleuint_add3_wrap_cid_cod(&a, &b, &c); /* c = a + b; */
	exampleuint_to_bi_sint(&c, &tmp); /* tmp = c; */

	return tmp; /* 25 */
}
