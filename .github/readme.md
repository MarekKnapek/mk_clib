# mk_clib

Hi, welcome to my library, this is place where I put all my C stuff. There is currently arbitrary length unsigned integer arithmetic stuff only.

 - [bui](#bui)
 - [cui](#cui)
 - [factorial](#factorial)
 - [flt](#flt)

## bui

Example usage of `mk_lang_bui` library, `bui` stands for basic unsigned integer. This is basically "just" wrapper around `unsigned char`, `unsigned short`, `unsigned int`, `unsigned long` and similar types wrapping all C language built-in operators. For example `+` becomes `add3`, `-=` becomes `sub2`, `<<` becomes `shl3` and so on.

```c
#include "mk_lang_bi.h"
#include "mk_lang_sizeof.h"

#define mk_lang_bui_name example
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"


int main(void)
{
	int tmp;
	mk_lang_bi_uint_t a; /* unsigned int a; */
	mk_lang_bi_uint_t b; /* unsigned int b; */
	mk_lang_bi_uint_t c; /* unsigned int c; */

	tmp = 9;
	mk_lang_bui_example_from_bi_sint(&a, &tmp); /* a = tmp; */
	mk_lang_bui_example_set_one(&b); /* b = 1; */
	mk_lang_bui_example_shl2(&b, 4); /* b <<= 4; */
	mk_lang_bui_example_add3_wrap_cid_cod(&a, &b, &c); /* c = a + b; */

	return ((int)(c)); /* 25 */
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
$ echo $?
25
```

## cui

Example usage of `mk_sl_cui` library, `cui` stands for composite unsigned integer. This is basically "just" an array of `n` `unsigned char`s, `unsigned short`s, `unsigned int`s, `unsigned long`s and similar types re-implementing all C language built-in operators. For example `+` becomes `add3`, `-=` becomes `sub2`, `<<` becomes `shl3` and so on.

```c
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"

#define mk_lang_bui_name exmpl
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name example
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_exmpl
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(128, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#include <stdio.h>


int main(void)
{
	int tmp;
	mk_sl_cui_example_t a; /* 128bit unsigned integer implemented as */
	mk_sl_cui_example_t b; /* an array of n `unsigned int` integers */
	mk_sl_cui_example_t c;
	int len;
	char buff[mk_sl_cui_example_to_str_dec_len + 1];

	tmp = 9;
	mk_sl_cui_example_from_bi_sint(&a, &tmp); /* a = tmp; */
	mk_sl_cui_example_set_one(&b); /* b = 1; */
	mk_sl_cui_example_shl2(&b, 4); /* b <<= 4; */
	mk_sl_cui_example_add3_wrap_cid_cod(&a, &b, &c); /* c = a + b; */
	len = mk_sl_cui_example_to_str_dec_n(&c, buff, mk_sl_cui_example_to_str_dec_len); /* sprintf(buff, "%d", c) */
	buff[len] = '\0';
	printf("%s\n", buff); /* 25 */
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
25
```

## factorial

This is a factorial program implemented by using the `cui` library. It can compute any factorial between 1 and 2000.

```bash
$ git clone https://github.com/MarekKnapek/mk_clib.git
$ cd mk_clib/mk_clib/app/
$ gcc -DNDEBUG -O2 mkcfct.c
$ ./a 42
1405006117752879898543142606244511569936384000000000
```

## flt

This program prints contents of a floating point variable (assumed to be in ieee754 binary32 or binary64 format) using "basic" format. Basic format means non-scientific format. It prints all the decimal digits that could be extracted from the floating point representation, even if they are not necessary to round-trip the number back. It uses integer math from the `cui` library, no floating point math is performed.

```bash
$ git clone https://github.com/MarekKnapek/mk_clib.git
$ cd mk_clib/mk_clib/app/
$ gcc -DNDEBUG mkcflt.c
$ ./a -123.456
-123.4560000000000030695446184836328029632568359375
```
