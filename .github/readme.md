# mk_clib

Hi, welcome to my library, this is place where I put all my C stuff. There is arbitrary length unsigned integer arithmetic. Cryptographic hashes such as MD2, MD4, MD5, SHA-0, SHA-1, SHA-256, SHA-512, SHA-384, SHA-224, SHA-512/224, SHA-512/256, SHA3-224, SHA3-256, SHA3-384, SHA3-512, SHAKE128, SHAKE256, Tiger/128, Tiger/160, Tiger/192, Tiger2/128, Tiger2/160, Tiger2/192, [on-line demo](https://marekknapek.github.io/hash/).

 - [bui](#bui)
 - [cui](#cui)
 - [factorial](#factorial)
 - [flt](#flt)
 - [MD2](#md2)
 - [MD4](#md4)
 - [MD5](#md5)
 - [SHA-0](#sha-0)
 - [SHA-1](#sha-1)
 - [SHA-256](#sha-256)
 - [SHA-512](#sha-512)
 - [SHA-384](#sha-384)
 - [SHA-224](#sha-224)
 - [SHA-512/224](#sha-512224)
 - [SHA-512/256](#sha-512256)
 - [SHA3-224](#sha3-224)
 - [SHA3-256](#sha3-256)
 - [SHA3-384](#sha3-384)
 - [SHA3-512](#sha3-512)
 - [SHAKE128](#shake128)
 - [SHAKE256](#shake256)
 - [Tiger/128](#tiger128)
 - [Tiger/160](#tiger160)
 - [Tiger/192](#tiger192)
 - [Tiger2/128](#tiger2128)
 - [Tiger2/160](#tiger2160)
 - [Tiger2/192](#tiger2192)

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

## MD2

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

## MD4

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

## MD5

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

## SHA-0

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

## SHA-1

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

## SHA-256

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

## SHA-512

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

## SHA-384

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

## SHA-224

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

## SHA-512/224

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

## SHA-512/256

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

## SHA3-224

Example how to compute the SHA3-224 hash.

```c
#include "mk_lib_crypto_hash_stream_sha3_224.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha3_224_t hash;
	mk_lib_crypto_hash_block_sha3_224_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha3_224_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha3_224_init(&hash);
	mk_lib_crypto_hash_stream_sha3_224_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha3_224_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha3_224_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha3_224_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha3_224_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 5cdeca81e123f87cad96b9cba999f16f6d41549608d4e0f4681b8239 */
	assert(t == mk_lib_crypto_hash_block_sha3_224_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
5cdeca81e123f87cad96b9cba999f16f6d41549608d4e0f4681b8239
```

## SHA3-256

Example how to compute the SHA3-256 hash.

```c
#include "mk_lib_crypto_hash_stream_sha3_256.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha3_256_t hash;
	mk_lib_crypto_hash_block_sha3_256_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha3_256_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha3_256_init(&hash);
	mk_lib_crypto_hash_stream_sha3_256_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha3_256_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha3_256_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha3_256_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha3_256_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 7cab2dc765e21b241dbc1c255ce620b29f527c6d5e7f5f843e56288f0d707521 */
	assert(t == mk_lib_crypto_hash_block_sha3_256_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
7cab2dc765e21b241dbc1c255ce620b29f527c6d5e7f5f843e56288f0d707521
```

## SHA3-384

Example how to compute the SHA3-384 hash.

```c
#include "mk_lib_crypto_hash_stream_sha3_384.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha3_384_t hash;
	mk_lib_crypto_hash_block_sha3_384_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha3_384_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha3_384_init(&hash);
	mk_lib_crypto_hash_stream_sha3_384_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha3_384_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha3_384_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha3_384_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha3_384_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* fed399d2217aaf4c717ad0c5102c15589e1c990cc2b9a5029056a7f7485888d6ab65db2370077a5cadb53fc9280d278f */
	assert(t == mk_lib_crypto_hash_block_sha3_384_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
fed399d2217aaf4c717ad0c5102c15589e1c990cc2b9a5029056a7f7485888d6ab65db2370077a5cadb53fc9280d278f
```

## SHA3-512

Example how to compute the SHA3-512 hash.

```c
#include "mk_lib_crypto_hash_stream_sha3_512.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_sha3_512_t hash;
	mk_lib_crypto_hash_block_sha3_512_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_sha3_512_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_sha3_512_init(&hash);
	mk_lib_crypto_hash_stream_sha3_512_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_sha3_512_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_sha3_512_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_sha3_512_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha3_512_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* af328d17fa28753a3c9f5cb72e376b90440b96f0289e5703b729324a975ab384eda565fc92aaded143669900d761861687acdc0a5ffa358bd0571aaad80aca68 */
	assert(t == mk_lib_crypto_hash_block_sha3_512_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
af328d17fa28753a3c9f5cb72e376b90440b96f0289e5703b729324a975ab384eda565fc92aaded143669900d761861687acdc0a5ffa358bd0571aaad80aca68
```

## SHAKE128

Example how to compute the SHAKE128 XOF.

```c
#include "mk_lib_crypto_xof_stream_shake_128.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_xof_stream_shake_128_t xof;
	unsigned char digest[3000 / 8];
	int i;
	int t;
	char str[3000 / 8 * 2 + 1];

	mk_lib_crypto_xof_stream_shake_128_init(&xof);
	mk_lib_crypto_xof_stream_shake_128_append(&xof, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_xof_stream_shake_128_append(&xof, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_xof_stream_shake_128_append(&xof, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_xof_stream_shake_128_finish(&xof, 3000 / 8, ((mk_lib_crypto_xof_block_shake_128_digest_pt)(digest)));
	for(i = 0; i != 3000 / 8; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 961c919c0854576e561320e81514bf3724197d0715e16a364520384ee997f6ef3be7ad1ab687d31ebd7e6604ef2c7652932e4206113d263514e72f31f5e1df87c5f54fc43e8f857fc4a52bbb565bd6d45869df9259c09774728394e3e0c3b326410085c356e5b173d570087945b0f068e4c63a5b191fef22d93b9fd4211328d70e514fec92b1b48643495918b641eab05460d0798cbe42fda47a2375f1065d037ebc76bdceff29efa43c82793c9ff41e19834717532faa42bcc91287bbddd88efe22fb471db95463dd3d6d3dfc5079042181bc405be83321c0a51431588b98019506a1e2def66bfe45a49c2d662b547becdcecb7e87a51e1aca962f08e3a4808f6c119f471eebca33d8894219a13637464c9ef601b5ac6e21629d15a82d22a632d9b2ae535a94c9fd8ee278cab57c9599171021a2d72f07a866e8814f46daeb52d30cbf50a7bd3a71e6aff0f315637b8c0eba30b06b733e0577a72e4cd73da2ec1807978c3ea872e9ef65a127af8c7eeb7ff16c259d010 */
	assert(t == 3000 / 8 * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
961c919c0854576e561320e81514bf3724197d0715e16a364520384ee997f6ef3be7ad1ab687d31ebd7e6604ef2c7652932e4206113d263514e72f31f5e1df87c5f54fc43e8f857fc4a52bbb565bd6d45869df9259c09774728394e3e0c3b326410085c356e5b173d570087945b0f068e4c63a5b191fef22d93b9fd4211328d70e514fec92b1b48643495918b641eab05460d0798cbe42fda47a2375f1065d037ebc76bdceff29efa43c82793c9ff41e19834717532faa42bcc91287bbddd88efe22fb471db95463dd3d6d3dfc5079042181bc405be83321c0a51431588b98019506a1e2def66bfe45a49c2d662b547becdcecb7e87a51e1aca962f08e3a4808f6c119f471eebca33d8894219a13637464c9ef601b5ac6e21629d15a82d22a632d9b2ae535a94c9fd8ee278cab57c9599171021a2d72f07a866e8814f46daeb52d30cbf50a7bd3a71e6aff0f315637b8c0eba30b06b733e0577a72e4cd73da2ec1807978c3ea872e9ef65a127af8c7eeb7ff16c259d010
```

## SHAKE256

Example how to compute the SHAKE256 XOF.

```c
#include "mk_lib_crypto_xof_stream_shake_256.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_xof_stream_shake_256_t xof;
	unsigned char digest[3000 / 8];
	int i;
	int t;
	char str[3000 / 8 * 2 + 1];

	mk_lib_crypto_xof_stream_shake_256_init(&xof);
	mk_lib_crypto_xof_stream_shake_256_append(&xof, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_xof_stream_shake_256_append(&xof, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_xof_stream_shake_256_append(&xof, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_xof_stream_shake_256_finish(&xof, 3000 / 8, ((mk_lib_crypto_xof_block_shake_256_digest_pt)(digest)));
	for(i = 0; i != 3000 / 8; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* b7b78b04a3dd30a265c8886c33fda94799853de5d3d10541fd4e9f4613701c61075249bed16b0781108fcfe086dbf38a7fb8300807cea85cc649328d07d4ff2b5e8908563ff0fdcc06a8092fbfe772f80e49f87a103b2aee12990ccb4798e9ec03aa4818a4bf5abda084e1a5fe687c2cfef4406846fe47a0d07bf45055a2699c37d6b6d9cd6c4ff0a675191553f1e30bf471eba3c78fa7a52bd33c48912c0d0c6f1145d3117a472fdcd9afbb866ba1bef4f5944c09b036b3adadc317cf96c1493b8f61cd4d1dea113d9ebf8a709f0f3bc847aabe02b068e4756752696ca0e1ca89360673c323e9b3994843b8b6f73391afe5f96d8f3914e95c74a6cb0a3052a5d0c882bff936c90b6a6200d46b0a505ac494995a8de1f255c2cf371af0ed3052ead05d9d67e434234e10f8d1175136e62811b94901129a2ea4007724ff3671f7a2ed8937fefff0cdd47dce91f0b1ad251f739a99ac295b4c7af14bb68fcf8934d5d5401fe6da79ee2762ec874b166bf7bff08b5818613b */
	assert(t == 3000 / 8 * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
b7b78b04a3dd30a265c8886c33fda94799853de5d3d10541fd4e9f4613701c61075249bed16b0781108fcfe086dbf38a7fb8300807cea85cc649328d07d4ff2b5e8908563ff0fdcc06a8092fbfe772f80e49f87a103b2aee12990ccb4798e9ec03aa4818a4bf5abda084e1a5fe687c2cfef4406846fe47a0d07bf45055a2699c37d6b6d9cd6c4ff0a675191553f1e30bf471eba3c78fa7a52bd33c48912c0d0c6f1145d3117a472fdcd9afbb866ba1bef4f5944c09b036b3adadc317cf96c1493b8f61cd4d1dea113d9ebf8a709f0f3bc847aabe02b068e4756752696ca0e1ca89360673c323e9b3994843b8b6f73391afe5f96d8f3914e95c74a6cb0a3052a5d0c882bff936c90b6a6200d46b0a505ac494995a8de1f255c2cf371af0ed3052ead05d9d67e434234e10f8d1175136e62811b94901129a2ea4007724ff3671f7a2ed8937fefff0cdd47dce91f0b1ad251f739a99ac295b4c7af14bb68fcf8934d5d5401fe6da79ee2762ec874b166bf7bff08b5818613b
```

## Tiger/128

Example how to compute the Tiger/128 hash.

```c
#include "mk_lib_crypto_hash_stream_tiger_128.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_tiger_128_t hash;
	mk_lib_crypto_hash_block_tiger_128_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_tiger_128_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_tiger_128_init(&hash);
	mk_lib_crypto_hash_stream_tiger_128_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_tiger_128_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_tiger_128_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_tiger_128_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger_128_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 1714a472eee57d30040412bfcc55032a */
	assert(t == mk_lib_crypto_hash_block_tiger_128_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
1714a472eee57d30040412bfcc55032a
```

## Tiger/160

Example how to compute the Tiger/160 hash.

```c
#include "mk_lib_crypto_hash_stream_tiger_160.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_tiger_160_t hash;
	mk_lib_crypto_hash_block_tiger_160_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_tiger_160_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_tiger_160_init(&hash);
	mk_lib_crypto_hash_stream_tiger_160_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_tiger_160_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_tiger_160_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_tiger_160_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger_160_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 1714a472eee57d30040412bfcc55032a0b11602f */
	assert(t == mk_lib_crypto_hash_block_tiger_160_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
1714a472eee57d30040412bfcc55032a0b11602f
```

## Tiger/192

Example how to compute the Tiger/192 hash.

```c
#include "mk_lib_crypto_hash_stream_tiger_192.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_tiger_192_t hash;
	mk_lib_crypto_hash_block_tiger_192_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_tiger_192_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_tiger_192_init(&hash);
	mk_lib_crypto_hash_stream_tiger_192_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_tiger_192_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_tiger_192_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_tiger_192_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger_192_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* 1714a472eee57d30040412bfcc55032a0b11602ff37beee9 */
	assert(t == mk_lib_crypto_hash_block_tiger_192_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
1714a472eee57d30040412bfcc55032a0b11602ff37beee9
```

## Tiger2/128

Example how to compute the Tiger2/128 hash.

```c
#include "mk_lib_crypto_hash_stream_tiger2_128.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_tiger2_128_t hash;
	mk_lib_crypto_hash_block_tiger2_128_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_tiger2_128_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_tiger2_128_init(&hash);
	mk_lib_crypto_hash_stream_tiger2_128_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_tiger2_128_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_tiger2_128_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_tiger2_128_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger2_128_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* f5b6b6a78c405c8547e91cd8624cb8be */
	assert(t == mk_lib_crypto_hash_block_tiger2_128_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
f5b6b6a78c405c8547e91cd8624cb8be
```

## Tiger2/160

Example how to compute the Tiger2/160 hash.

```c
#include "mk_lib_crypto_hash_stream_tiger2_160.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_tiger2_160_t hash;
	mk_lib_crypto_hash_block_tiger2_160_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_tiger2_160_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_tiger2_160_init(&hash);
	mk_lib_crypto_hash_stream_tiger2_160_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_tiger2_160_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_tiger2_160_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_tiger2_160_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger2_160_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* f5b6b6a78c405c8547e91cd8624cb8be83fc804a */
	assert(t == mk_lib_crypto_hash_block_tiger2_160_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
f5b6b6a78c405c8547e91cd8624cb8be83fc804a
```

## Tiger2/192

Example how to compute the Tiger2/192 hash.

```c
#include "mk_lib_crypto_hash_stream_tiger2_192.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_tiger2_192_t hash;
	mk_lib_crypto_hash_block_tiger2_192_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_tiger2_192_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_tiger2_192_init(&hash);
	mk_lib_crypto_hash_stream_tiger2_192_append(&hash, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_tiger2_192_append(&hash, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_tiger2_192_append(&hash, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_tiger2_192_finish(&hash, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger2_192_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* f5b6b6a78c405c8547e91cd8624cb8be83fc804a474488fd */
	assert(t == mk_lib_crypto_hash_block_tiger2_192_digest_len * 2 + 1);
}
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
f5b6b6a78c405c8547e91cd8624cb8be83fc804a474488fd
```
