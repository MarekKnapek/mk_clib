# mk_clib

Hi, welcome to my library, this is place where I put all my C stuff. There is arbitrary length unsigned integer arithmetic. Cryptographic hashes such as MD2, MD4, MD5, SHA-0, SHA-1, SHA-256, SHA-512, SHA-384, SHA-224, SHA-512/224 and SHA-512/256.

 - [bui](#bui)
 - [cui](#cui)
 - [factorial](#factorial)
 - [flt](#flt)
 - [MD2](#md2)
 - [MD4](#md4)
 - [MD5](#md5)
 - [SHA-0](#sha0)
 - [SHA-1](#sha1)
 - [SHA-256](#sha256)
 - [SHA-512](#sha512)
 - [SHA-384](#sha384)
 - [SHA-224](#sha224)
 - [SHA-512/224](#sha512224)
 - [SHA-512/256](#sha512256)

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

## md2

Example how to compute the MD2 hash.

```c
#include "mk_lib_crypto_hash_stream_md2.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_md2_t hash;
	mk_lib_crypto_hash_block_md2_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_md2_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_md2_init(&hash);
	mk_lib_crypto_hash_stream_md2_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_md2_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_md2_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_md2_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_md2_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 4e8ddff3650292ab5a4108c3aa47940b */
	assert(t == mk_lib_crypto_hash_block_md2_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
4e8ddff3650292ab5a4108c3aa47940b
```

## md4

Example how to compute the MD4 hash.

```c
#include "mk_lib_crypto_hash_stream_md4.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_md4_t hash;
	mk_lib_crypto_hash_block_md4_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_md4_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_md4_init(&hash);
	mk_lib_crypto_hash_stream_md4_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_md4_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_md4_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_md4_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_md4_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* d79e1c308aa5bbcdeea8ed63df412da9 */
	assert(t == mk_lib_crypto_hash_block_md4_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
d79e1c308aa5bbcdeea8ed63df412da9
```

## md5

Example how to compute the MD5 hash.

```c
#include "mk_lib_crypto_hash_stream_md5.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_md5_t hash;
	mk_lib_crypto_hash_block_md5_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_md5_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_md5_init(&hash);
	mk_lib_crypto_hash_stream_md5_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_md5_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_md5_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_md5_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_md5_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* c3fcd3d76192e4007dfb496cca67e13b */
	assert(t == mk_lib_crypto_hash_block_md5_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
c3fcd3d76192e4007dfb496cca67e13b
```

## sha0

Example how to compute the SHA-0 hash.

```c
#include "mk_lib_crypto_hash_stream_sha0.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha0_t hash;
	mk_lib_crypto_hash_block_sha0_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha0_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha0_init(&hash);
	mk_lib_crypto_hash_stream_sha0_append(&hash, ((unsigned char const*)("abcdbcdecdefdefgef")), 18);
	mk_lib_crypto_hash_stream_sha0_append(&hash, ((unsigned char const*)("ghfghighijhijkijkl")), 18);
	mk_lib_crypto_hash_stream_sha0_append(&hash, ((unsigned char const*)("jklmklmnlmnomnopnopq")), 20);
	mk_lib_crypto_hash_stream_sha0_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha0_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* d2516ee1acfa5baf33dfc1c471e438449ef134c8 */
	assert(t == mk_lib_crypto_hash_block_sha0_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
d2516ee1acfa5baf33dfc1c471e438449ef134c8
```

## sha1

Example how to compute the SHA-1 hash.

```c
#include "mk_lib_crypto_hash_stream_sha1.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha1_t hash;
	mk_lib_crypto_hash_block_sha1_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha1_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha1_init(&hash);
	mk_lib_crypto_hash_stream_sha1_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha1_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha1_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha1_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha1_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 32d10c7b8cf96570ca04ce37f2a19d84240d3a89 */
	assert(t == mk_lib_crypto_hash_block_sha1_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
32d10c7b8cf96570ca04ce37f2a19d84240d3a89
```

## sha256

Example how to compute the SHA-256 hash.

```c
#include "mk_lib_crypto_hash_stream_sha2_256.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha2_256_t hash;
	mk_lib_crypto_hash_block_sha2_256_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha2_256_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha2_256_init(&hash);
	mk_lib_crypto_hash_stream_sha2_256_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha2_256_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha2_256_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha2_256_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_256_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 71c480df93d6ae2f1efad1447c66c9525e316218cf51fc8d9ed832f2daf18b73 */
	assert(t == mk_lib_crypto_hash_block_sha2_256_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
71c480df93d6ae2f1efad1447c66c9525e316218cf51fc8d9ed832f2daf18b73
```

## sha512

Example how to compute the SHA-512 hash.

```c
#include "mk_lib_crypto_hash_stream_sha2_512.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha2_512_t hash;
	mk_lib_crypto_hash_block_sha2_512_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha2_512_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha2_512_init(&hash);
	mk_lib_crypto_hash_stream_sha2_512_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha2_512_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha2_512_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha2_512_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_512_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 4dbff86cc2ca1bae1e16468a05cb9881c97f1753bce3619034898faa1aabe429955a1bf8ec483d7421fe3c1646613a59ed5441fb0f321389f77f48a879c7b1f1 */
	assert(t == mk_lib_crypto_hash_block_sha2_512_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
4dbff86cc2ca1bae1e16468a05cb9881c97f1753bce3619034898faa1aabe429955a1bf8ec483d7421fe3c1646613a59ed5441fb0f321389f77f48a879c7b1f1
```

## sha384

Example how to compute the SHA-384 hash.

```c
#include "mk_lib_crypto_hash_stream_sha2_384.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha2_384_t hash;
	mk_lib_crypto_hash_block_sha2_384_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha2_384_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha2_384_init(&hash);
	mk_lib_crypto_hash_stream_sha2_384_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha2_384_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha2_384_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha2_384_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_384_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* feb67349df3db6f5924815d6c3dc133f091809213731fe5c7b5f4999e463479ff2877f5f2936fa63bb43784b12f3ebb4 */
	assert(t == mk_lib_crypto_hash_block_sha2_384_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
feb67349df3db6f5924815d6c3dc133f091809213731fe5c7b5f4999e463479ff2877f5f2936fa63bb43784b12f3ebb4
```

## sha224

Example how to compute the SHA-224 hash.

```c
#include "mk_lib_crypto_hash_stream_sha2_224.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha2_224_t hash;
	mk_lib_crypto_hash_block_sha2_224_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha2_224_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha2_224_init(&hash);
	mk_lib_crypto_hash_stream_sha2_224_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha2_224_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha2_224_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha2_224_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_224_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 45a5f72c39c5cff2522eb3429799e49e5f44b356ef926bcf390dccc2 */
	assert(t == mk_lib_crypto_hash_block_sha2_224_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
45a5f72c39c5cff2522eb3429799e49e5f44b356ef926bcf390dccc2
```

## sha512224

Example how to compute the SHA-512/224 hash.

```c
#include "mk_lib_crypto_hash_stream_sha2_512_224.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha2_512_224_t hash;
	mk_lib_crypto_hash_block_sha2_512_224_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha2_512_224_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha2_512_224_init(&hash);
	mk_lib_crypto_hash_stream_sha2_512_224_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha2_512_224_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha2_512_224_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha2_512_224_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_512_224_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* ff83148aa07ec30655c1b40aff86141c0215fe2a54f767d3f38743d8 */
	assert(t == mk_lib_crypto_hash_block_sha2_512_224_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
ff83148aa07ec30655c1b40aff86141c0215fe2a54f767d3f38743d8
```

## sha512256

Example how to compute the SHA-512/256 hash.

```c
#include "mk_lib_crypto_hash_stream_sha2_512_256.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha2_512_256_t hash;
	mk_lib_crypto_hash_block_sha2_512_256_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha2_512_256_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha2_512_256_init(&hash);
	mk_lib_crypto_hash_stream_sha2_512_256_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha2_512_256_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha2_512_256_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha2_512_256_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_512_256_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* fc3189443f9c268f626aea08a756abe7b726b05f701cb08222312ccfd6710a26 */
	assert(t == mk_lib_crypto_hash_block_sha2_512_256_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
fc3189443f9c268f626aea08a756abe7b726b05f701cb08222312ccfd6710a26
```
