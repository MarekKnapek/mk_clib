changequote(`^', `~')dnl
include(^mk_lib_crypto_hash_stream_example.c.m~)dnl
include(^mk_lib_crypto_xof_stream_example.c.m~)dnl
define(^mm_hash~, ^
^##~ $1

Example how to compute the $1 hash.

```c
mm_hash_program($1, $2, $3)dnl
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
$3
```
~)dnl
define(^mm_xof~, ^
^##~ $1

Example how to compute the $1 XOF.

```c
mm_xof_program($1, $2, $3)dnl
```
```bash
$ gcc -DNDEBUG example.c
$ ./a
$3
```
~)dnl
# mk_clib

Hi, welcome to my library, this is place where I put all my C stuff. There is arbitrary length unsigned integer arithmetic. Cryptographic hashes such as MD2, MD4, MD5, SHA-0, SHA-1, SHA-224, SHA-256, SHA-384, SHA-512, SHA-512/224, SHA-512/256, SHA3-224, SHA3-256, SHA3-384, SHA3-512, SHAKE128, SHAKE256, Tiger/128, Tiger/160, Tiger/192, Tiger2/128, Tiger2/160, Tiger2/192, BLAKE2b-256, BLAKE2b-384, BLAKE2b-512, BLAKE2s-128, BLAKE2s-160, BLAKE2s-224, BLAKE2s-256, BLAKE3, [on-line demo](https://marekknapek.github.io/hash/). Everything could be computed at constexpr time if compiled with C++ 14 or newer compiler.

 - [bui](#bui)
 - [cui](#cui)
 - [factorial](#factorial)
 - [flt](#flt)
 - [MD2](#md2), [MD4](#md4), [MD5](#md5)
 - [SHA-0](#sha-0), [SHA-1](#sha-1)
 - [SHA-224](#sha-224), [SHA-256](#sha-256)
 - [SHA-384](#sha-384), [SHA-512](#sha-512), [SHA-512/224](#sha-512224), [SHA-512/256](#sha-512256)
 - [SHA3-224](#sha3-224), [SHA3-256](#sha3-256), [SHA3-384](#sha3-384), [SHA3-512](#sha3-512)
 - [SHAKE128](#shake128), [SHAKE256](#shake256)
 - [Tiger/128](#tiger128), [Tiger/160](#tiger160), [Tiger/192](#tiger192)
 - [Tiger2/128](#tiger2128), [Tiger2/160](#tiger2160), [Tiger2/192](#tiger2192)
 - [BLAKE2s-128](#blake2s-128), [BLAKE2s-160](#blake2s-160), [BLAKE2s-224](#blake2s-224), [BLAKE2s-256](#blake2s-256)
 - [BLAKE2b-256](#blake2b-256), [BLAKE2b-384](#blake2b-384), [BLAKE2b-512](#blake2b-512)
 - [BLAKE3](#blake3)
 - [Whirlpool](#whirlpool)
 - [constexpr SHA-512](#constexpr-sha-512)
 - [constexpr AES-256 encryption and run-time decryption](#constexpr-aes-256-encryption-and-run-time-decryption)
 - [license](../mk_clib/src/license.txt)

## bui

Example usage of `mk_lang_bui` library, `bui` stands for basic unsigned integer. This is basically "just" wrapper around `unsigned char`, `unsigned short`, `unsigned int`, `unsigned long` and similar types wrapping all C language built-in operators. For example `+` becomes `add3`, `-=` becomes `sub2`, `<<` becomes `shl3` and so on.

```c
include(mk_lang_bui_example.c)dnl
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
include(mk_sl_cui_example.c)dnl
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
mm_hash(^MD2~, ^md2~, ^4e8ddff3650292ab5a4108c3aa47940b~)dnl
mm_hash(^MD4~, ^md4~, ^d79e1c308aa5bbcdeea8ed63df412da9~)dnl
mm_hash(^MD5~, ^md5~, ^c3fcd3d76192e4007dfb496cca67e13b~)dnl
mm_hash(^SHA-0~, ^sha0~, ^b40ce07a430cfd3c033039b9fe9afec95dc1bdcd~)dnl
mm_hash(^SHA-1~, ^sha1~, ^32d10c7b8cf96570ca04ce37f2a19d84240d3a89~)dnl
mm_hash(^SHA-224~, ^sha2_224~, ^45a5f72c39c5cff2522eb3429799e49e5f44b356ef926bcf390dccc2~)dnl
mm_hash(^SHA-256~, ^sha2_256~, ^71c480df93d6ae2f1efad1447c66c9525e316218cf51fc8d9ed832f2daf18b73~)dnl
mm_hash(^SHA-384~, ^sha2_384~, ^feb67349df3db6f5924815d6c3dc133f091809213731fe5c7b5f4999e463479ff2877f5f2936fa63bb43784b12f3ebb4~)dnl
mm_hash(^SHA-512~, ^sha2_512~, ^4dbff86cc2ca1bae1e16468a05cb9881c97f1753bce3619034898faa1aabe429955a1bf8ec483d7421fe3c1646613a59ed5441fb0f321389f77f48a879c7b1f1~)dnl
mm_hash(^SHA-512/224~, ^sha2_512_224~, ^ff83148aa07ec30655c1b40aff86141c0215fe2a54f767d3f38743d8~)dnl
mm_hash(^SHA-512/256~, ^sha2_512_256~, ^fc3189443f9c268f626aea08a756abe7b726b05f701cb08222312ccfd6710a26~)dnl
mm_hash(^SHA3-224~, ^sha3_224~, ^5cdeca81e123f87cad96b9cba999f16f6d41549608d4e0f4681b8239~)dnl
mm_hash(^SHA3-256~, ^sha3_256~, ^7cab2dc765e21b241dbc1c255ce620b29f527c6d5e7f5f843e56288f0d707521~)dnl
mm_hash(^SHA3-384~, ^sha3_384~, ^fed399d2217aaf4c717ad0c5102c15589e1c990cc2b9a5029056a7f7485888d6ab65db2370077a5cadb53fc9280d278f~)dnl
mm_hash(^SHA3-512~, ^sha3_512~, ^af328d17fa28753a3c9f5cb72e376b90440b96f0289e5703b729324a975ab384eda565fc92aaded143669900d761861687acdc0a5ffa358bd0571aaad80aca68~)dnl
mm_xof(^SHAKE128~, ^shake_128~, ^961c919c0854576e561320e81514bf3724197d0715e16a364520384ee997f6ef3be7ad1ab687d31ebd7e6604ef2c7652932e4206113d263514e72f31f5e1df87c5f54fc43e8f857fc4a52bbb565bd6d45869df9259c09774728394e3e0c3b326410085c356e5b173d570087945b0f068e4c63a5b191fef22d93b9fd4211328d70e514fec92b1b48643495918b641eab05460d0798cbe42fda47a2375f1065d037ebc76bdceff29efa43c82793c9ff41e19834717532faa42bcc91287bbddd88efe22fb471db95463dd3d6d3dfc5079042181bc405be83321c0a51431588b98019506a1e2def66bfe45a49c2d662b547becdcecb7e87a51e1aca962f08e3a4808f6c119f471eebca33d8894219a13637464c9ef601b5ac6e21629d15a82d22a632d9b2ae535a94c9fd8ee278cab57c9599171021a2d72f07a866e8814f46daeb52d30cbf50a7bd3a71e6aff0f315637b8c0eba30b06b733e0577a72e4cd73da2ec1807978c3ea872e9ef65a127af8c7eeb7ff16c259d010~)dnl
mm_xof(^SHAKE256~, ^shake_256~, ^b7b78b04a3dd30a265c8886c33fda94799853de5d3d10541fd4e9f4613701c61075249bed16b0781108fcfe086dbf38a7fb8300807cea85cc649328d07d4ff2b5e8908563ff0fdcc06a8092fbfe772f80e49f87a103b2aee12990ccb4798e9ec03aa4818a4bf5abda084e1a5fe687c2cfef4406846fe47a0d07bf45055a2699c37d6b6d9cd6c4ff0a675191553f1e30bf471eba3c78fa7a52bd33c48912c0d0c6f1145d3117a472fdcd9afbb866ba1bef4f5944c09b036b3adadc317cf96c1493b8f61cd4d1dea113d9ebf8a709f0f3bc847aabe02b068e4756752696ca0e1ca89360673c323e9b3994843b8b6f73391afe5f96d8f3914e95c74a6cb0a3052a5d0c882bff936c90b6a6200d46b0a505ac494995a8de1f255c2cf371af0ed3052ead05d9d67e434234e10f8d1175136e62811b94901129a2ea4007724ff3671f7a2ed8937fefff0cdd47dce91f0b1ad251f739a99ac295b4c7af14bb68fcf8934d5d5401fe6da79ee2762ec874b166bf7bff08b5818613b~)dnl
mm_hash(^Tiger/128~, ^tiger_128~, ^1714a472eee57d30040412bfcc55032a~)dnl
mm_hash(^Tiger/160~, ^tiger_160~, ^1714a472eee57d30040412bfcc55032a0b11602f~)dnl
mm_hash(^Tiger/192~, ^tiger_192~, ^1714a472eee57d30040412bfcc55032a0b11602ff37beee9~)dnl
mm_hash(^Tiger2/128~, ^tiger2_128~, ^f5b6b6a78c405c8547e91cd8624cb8be~)dnl
mm_hash(^Tiger2/160~, ^tiger2_160~, ^f5b6b6a78c405c8547e91cd8624cb8be83fc804a~)dnl
mm_hash(^Tiger2/192~, ^tiger2_192~, ^f5b6b6a78c405c8547e91cd8624cb8be83fc804a474488fd~)dnl
mm_hash(^BLAKE2s-128~, ^blake2s_128~, ^6b5da6a19a600add9fada4c0b95bf6c9~)dnl
mm_hash(^BLAKE2s-160~, ^blake2s_160~, ^d1dcf102967d7cd98323ee5208fa034f073fac8f~)dnl
mm_hash(^BLAKE2s-224~, ^blake2s_224~, ^8de6b28a9536f23725d9de3953de02ac58143fd4719adf2e11fb8a23~)dnl
mm_hash(^BLAKE2s-256~, ^blake2s_256~, ^bdf88eb1f86a0cdf0e840ba88fa118508369df186c7355b4b16cf79fa2710a12~)dnl
mm_hash(^BLAKE2b-256~, ^blake2b_256~, ^117ad6b940f5e8292c007d9c7e7350cd33cf85b5887e8da71c7957830f536e7c~)dnl
mm_hash(^BLAKE2b-384~, ^blake2b_384~, ^5cad60ce23b9dc62eabdd149a16307ef916e0637506fa10cf8c688430da6c978a0cb7857fd138977bd281e8cfd5bfd1f~)dnl
mm_hash(^BLAKE2b-512~, ^blake2b_512~, ^c68ede143e416eb7b4aaae0d8e48e55dd529eafed10b1df1a61416953a2b0a5666c761e7d412e6709e31ffe221b7a7a73908cb95a4d120b8b090a87d1fbedb4c~)dnl
mm_hash(^BLAKE3~, ^blake3~, ^2468eec8894acfb4e4df3a51ea916ba115d48268287754290aae8e9e6228e85f~)dnl
mm_hash(^Whirlpool~, ^whirlpool~, ^f1d754662636ffe92c82ebb9212a484a8d38631ead4238f5442ee13b8054e41b08bf2a9251c30b6a0b8aae86177ab4a6f68f673e7207865d5d9819a3dba4eb3b~)dnl

## constexpr SHA-512

Example how to compute the SHA-512 hash at constexpr time (C++ 14 or newer compiler needed). Everything could be computed at constexpr time, not just SHA-512.

```c++
#include "mk_lib_crypto_hash_stream_sha2_512.h"


struct employee_t
{
	int m_id;
	char m_name[64];
};


constexpr unsigned char* int_to_bytes_le(int const x, unsigned char* const bytes)
{
	unsigned char* ptr{};
	unsigned u{};
	int i{};

	ptr = bytes;
	u = ((unsigned)(x));
	for(i = 0; i != sizeof(int); ++i)
	{
		ptr[i] = ((unsigned char)(u & 0xff));
		u >>= 8;
	}
	ptr += sizeof(int);
	return ptr;
}

constexpr unsigned char* str_to_bytes(char const* const str, unsigned char* const bytes)
{
	unsigned char* ptr{};
	int str_len{};
	int i{};

	ptr = bytes;
	str_len = 0;
	while(str[str_len] != '\0')
	{
		++str_len;
	}
	ptr = int_to_bytes_le(str_len, ptr);
	for(i = 0; i != str_len; ++i)
	{
		ptr[i] = ((unsigned char)(str[i]));
	}
	ptr += str_len;
	return ptr;
}

constexpr mk_lib_crypto_hash_block_sha2_512_digest_t compute_employee_hash(employee_t const& employee)
{
	mk_lib_crypto_hash_stream_sha2_512_t hash{};
	unsigned char buff[128]{};
	unsigned char* ptr{};
	mk_lib_crypto_hash_block_sha2_512_digest_t digest{};

	mk_lib_crypto_hash_stream_sha2_512_init(&hash);
	ptr = int_to_bytes_le(employee.m_id, buff);
	mk_lib_crypto_hash_stream_sha2_512_append(&hash, buff, ptr - buff);
	ptr = str_to_bytes(employee.m_name, buff);
	mk_lib_crypto_hash_stream_sha2_512_append(&hash, buff, ptr - buff);
	mk_lib_crypto_hash_stream_sha2_512_finish(&hash, &digest);
	return digest;
}


int main()
{
	constexpr auto const marek = employee_t{ 42, "Marek" };
	constexpr auto const hash = compute_employee_hash(marek);

	static_assert(hash.m_uint8s[ 0].m_data[0] == 0xb4, "");
	static_assert(hash.m_uint8s[ 1].m_data[0] == 0xbc, "");
	static_assert(hash.m_uint8s[ 2].m_data[0] == 0xaa, "");
	static_assert(hash.m_uint8s[ 3].m_data[0] == 0x86, "");
	static_assert(hash.m_uint8s[ 4].m_data[0] == 0x1e, "");
	static_assert(hash.m_uint8s[ 5].m_data[0] == 0x09, "");
	static_assert(hash.m_uint8s[ 6].m_data[0] == 0x72, "");
	static_assert(hash.m_uint8s[ 7].m_data[0] == 0x5a, "");
	static_assert(hash.m_uint8s[ 8].m_data[0] == 0xec, "");
	static_assert(hash.m_uint8s[ 9].m_data[0] == 0xca, "");
	static_assert(hash.m_uint8s[10].m_data[0] == 0x5e, "");
	static_assert(hash.m_uint8s[11].m_data[0] == 0xec, "");
	static_assert(hash.m_uint8s[12].m_data[0] == 0x19, "");
	static_assert(hash.m_uint8s[13].m_data[0] == 0x72, "");
	static_assert(hash.m_uint8s[14].m_data[0] == 0x23, "");
	static_assert(hash.m_uint8s[15].m_data[0] == 0x27, "");
	static_assert(hash.m_uint8s[16].m_data[0] == 0x24, "");
	static_assert(hash.m_uint8s[17].m_data[0] == 0xe8, "");
	static_assert(hash.m_uint8s[18].m_data[0] == 0xd1, "");
	static_assert(hash.m_uint8s[19].m_data[0] == 0xdc, "");
	static_assert(hash.m_uint8s[20].m_data[0] == 0xd7, "");
	static_assert(hash.m_uint8s[21].m_data[0] == 0x46, "");
	static_assert(hash.m_uint8s[22].m_data[0] == 0x81, "");
	static_assert(hash.m_uint8s[23].m_data[0] == 0xeb, "");
	static_assert(hash.m_uint8s[24].m_data[0] == 0x85, "");
	static_assert(hash.m_uint8s[25].m_data[0] == 0x8f, "");
	static_assert(hash.m_uint8s[26].m_data[0] == 0x65, "");
	static_assert(hash.m_uint8s[27].m_data[0] == 0x84, "");
	static_assert(hash.m_uint8s[28].m_data[0] == 0xb9, "");
	static_assert(hash.m_uint8s[29].m_data[0] == 0x21, "");
	static_assert(hash.m_uint8s[30].m_data[0] == 0xd9, "");
	static_assert(hash.m_uint8s[31].m_data[0] == 0x18, "");
	static_assert(hash.m_uint8s[32].m_data[0] == 0x33, "");
	static_assert(hash.m_uint8s[33].m_data[0] == 0x2b, "");
	static_assert(hash.m_uint8s[34].m_data[0] == 0x7a, "");
	static_assert(hash.m_uint8s[35].m_data[0] == 0x11, "");
	static_assert(hash.m_uint8s[36].m_data[0] == 0xc7, "");
	static_assert(hash.m_uint8s[37].m_data[0] == 0xd8, "");
	static_assert(hash.m_uint8s[38].m_data[0] == 0x6a, "");
	static_assert(hash.m_uint8s[39].m_data[0] == 0xd6, "");
	static_assert(hash.m_uint8s[40].m_data[0] == 0xa0, "");
	static_assert(hash.m_uint8s[41].m_data[0] == 0xf7, "");
	static_assert(hash.m_uint8s[42].m_data[0] == 0x10, "");
	static_assert(hash.m_uint8s[43].m_data[0] == 0xab, "");
	static_assert(hash.m_uint8s[44].m_data[0] == 0x16, "");
	static_assert(hash.m_uint8s[45].m_data[0] == 0x2e, "");
	static_assert(hash.m_uint8s[46].m_data[0] == 0xdf, "");
	static_assert(hash.m_uint8s[47].m_data[0] == 0x56, "");
	static_assert(hash.m_uint8s[48].m_data[0] == 0xab, "");
	static_assert(hash.m_uint8s[49].m_data[0] == 0x59, "");
	static_assert(hash.m_uint8s[50].m_data[0] == 0xce, "");
	static_assert(hash.m_uint8s[51].m_data[0] == 0x91, "");
	static_assert(hash.m_uint8s[52].m_data[0] == 0x33, "");
	static_assert(hash.m_uint8s[53].m_data[0] == 0xdc, "");
	static_assert(hash.m_uint8s[54].m_data[0] == 0xbb, "");
	static_assert(hash.m_uint8s[55].m_data[0] == 0x1a, "");
	static_assert(hash.m_uint8s[56].m_data[0] == 0x95, "");
	static_assert(hash.m_uint8s[57].m_data[0] == 0x40, "");
	static_assert(hash.m_uint8s[58].m_data[0] == 0xf0, "");
	static_assert(hash.m_uint8s[59].m_data[0] == 0xbc, "");
	static_assert(hash.m_uint8s[60].m_data[0] == 0xb0, "");
	static_assert(hash.m_uint8s[61].m_data[0] == 0x30, "");
	static_assert(hash.m_uint8s[62].m_data[0] == 0x68, "");
	static_assert(hash.m_uint8s[63].m_data[0] == 0x0f, "");
}
```
```bash
$ g++ -DNDEBUG example.cpp
$ ./a
$ echo $?
0
```

## constexpr AES-256 encryption and run-time decryption

Do you want to encrypt something and include it into your application? Don't want to use pre-processing / pre-build steps? Encrypt it at compile-time! In order to use it, decrypt it at run-time, assuming end-user knows the key or password. Plain-text is not stored inside your binary file.

```c++
/* encrypt library begin */


#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_app.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#include <assert.h>


template<typename ptr_t, int str_lit_len>
constexpr auto append_code(ptr_t const ptr, char const(&str_lit)[str_lit_len]) noexcept
{
	static_assert(str_lit_len >= 1);
	assert(str_lit);

	auto p = ptr;
	auto const len = str_lit_len - 1;
	mk_sl_cui_uint8_from_bi_sint(&p[0], &len);
	++p;
	auto const bytes = mk_lib_cpp_constexpr_str_lit_to_u8s(str_lit);
	for(auto i = 0ull; i != bytes.size(); ++i)
	{
		p[i] = bytes[i];
	}
	p += bytes.size();
	return p;
}

template<typename ptr_t, int str_lit_len>
constexpr auto append_str_enc(ptr_t const ptr, char const(&str_lit)[str_lit_len]) noexcept
{
	mk_sl_cui_uint32_t u32{};

	static_assert(str_lit_len >= 1);
	assert(str_lit);

	auto p = ptr;
	auto const len = str_lit_len - 1;
	mk_sl_cui_uint32_from_bi_sint(&u32, &len);
	mk_sl_uint_32_to_8_le(&u32, &p[0]);
	p += 4;
	auto const bytes = mk_lib_cpp_constexpr_str_lit_to_u8s(str_lit);
	for(auto i = 0ull; i != bytes.size(); ++i)
	{
		p[i] = bytes[i];
	}
	p += bytes.size();
	return p;
}

template<typename ptr_t>
constexpr ptr_t append_num(ptr_t const ptr, int const cost) noexcept
{
	mk_sl_cui_uint32_t u32{};
	mk_sl_cui_uint8_t buff[4]{};

	assert(cost >= 1);

	auto p = ptr;
	mk_sl_cui_uint32_from_bi_sint(&u32, &cost);
	mk_sl_uint_32_to_8_le(&u32, &buff[0]);
	for(int i = 0; i != 4; ++i)
	{
		p[i] = buff[i];
	}
	p += 4;
	return p;
}

template<typename ptr_t, typename len_t>
constexpr auto append_iv_enc(ptr_t const ptr, len_t const len) noexcept
{
	auto p = ptr;
	char const chr = __TIME__[0]; /* todo better way to collect randomness at compile time */
	unsigned char uchr = ((unsigned char)(chr));
	for(auto i = 0ull; i != len; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&p[i], &uchr);
		uchr = ((unsigned char)(uchr * 11));
	}
	p += len;
	return p;
}

template<int str_lit_len>
constexpr auto encrypt(char const(&str_lit)[str_lit_len]) noexcept
{
	mk_lib_crypto_app_t app{};
	mk_sl_cui_uint8_pct iv{};
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, 16 + ((((str_lit_len - 1) / 16) + 1) * 16)> ret{};

	static_assert(str_lit_len >= 1);
	assert(str_lit);

	auto const bytes = mk_lib_cpp_constexpr_str_lit_to_u8s(str_lit);
	auto const ptr = mk_lib_crypto_app_get_data_addr(&app);
	auto p = ptr;
	assert(mk_lib_crypto_app_get_iv_size_max_m == 16);
	auto const iv_len_max = mk_lib_crypto_app_get_iv_size_max_m;
	p = append_code(p, "aes_256");
	p = append_code(p, "pkcs7");
	p = append_code(p, "cbc");
	p = append_code(p, "pbkdf2_sha2_512_256"); iv = p;
	p = append_iv_enc(p, iv_len_max);
	p = append_num(p, 42);
	p = append_str_enc(p, "Hunter2");
	p = append_str_enc(p, "cryptor");
	auto const inited = mk_lib_crypto_app_init(&app);
	assert(inited >= 0 && inited <= iv_len_max);
	for(auto i = 0ull; i != 16; ++i){ ret[i] = iv[i]; }
	for(auto i = 0ull; i != bytes.size(); ++i){ ptr[i] = bytes[i]; }
	auto const finished = mk_lib_crypto_app_encrypt_finish(&app, bytes.size());
	assert(finished >= 1 && finished <= iv_len_max);
	for(auto i = 0ull; i != bytes.size() + finished; ++i){ ret[16 + i] = ptr[i]; }
	return ret;
}


/* encrypt library end */





/* decrypt library begin */


#include <assert.h>
#include <utility> /* std::pair */
#include <string.h> /* strlen */


template<typename dst_t, typename src_t, typename len_t>
constexpr auto append_iv_dec(dst_t const dst, src_t const src, len_t const len) noexcept
{
	auto p = dst;
	for(auto i = 0ull; i != len; ++i)
	{
		p[i] = src[i];
	}
	p += len;
	return p;
}

template<typename ptr_t>
constexpr auto append_str_dec(ptr_t const ptr, char const* const str) noexcept
{
	mk_sl_cui_uint32_t u32{};

	assert(str);

	auto p = ptr;
	auto const len = ((int)(strlen(str)));
	mk_sl_cui_uint32_from_bi_sint(&u32, &len);
	mk_sl_uint_32_to_8_le(&u32, &p[0]);
	p += 4;
	for(auto i = 0ull; i != len; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&p[i], &str[i]);
	}
	p += len;
	return p;
}

template<typename encrypted_t>
auto decrypt(encrypted_t const& encrypted, char const* const password)
{
	std::pair<int, mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, encrypted_t::s_size - 16>> ret;
	mk_lib_crypto_app_t app;

	assert(password);

	auto const ptr = mk_lib_crypto_app_get_data_addr(&app);
	auto p = ptr;
	assert(mk_lib_crypto_app_get_iv_size_max_m == 16);
	auto const iv_len_max = mk_lib_crypto_app_get_iv_size_max_m;
	p = append_code(p, "aes_256");
	p = append_code(p, "pkcs7");
	p = append_code(p, "cbc");
	p = append_code(p, "pbkdf2_sha2_512_256");
	p = append_iv_dec(p, encrypted.data(), 16);
	p = append_num(p, 42);
	p = append_str_dec(p, password);
	p = append_str_enc(p, "cryptor");
	auto const inited = mk_lib_crypto_app_init(&app);
	assert(inited >= 0 && inited <= iv_len_max);
	for(auto i = 0ull; i != encrypted.size() - 16; ++i){ ptr[i] = encrypted[16 + i]; }
	auto const finished = mk_lib_crypto_app_decrypt_finish(&app, encrypted.size() - 16);
	if(!(finished >= 1 && finished <= iv_len_max))
	{
		ret.first = -1;
	}
	else
	{
		ret.first = ((int)(encrypted.size())) - 16 - finished;
		for(auto i = 0ull; i != encrypted.size() - 16 - finished; ++i){ ret.second[i] = ptr[i]; }
	}
	return ret;
}


/* decrypt library end */





/* application begin */


#include <stdio.h> /* printf putchar */
#include <stdlib.h> /* EXIT_FAILURE EXIT_SUCCESS */


template<typename decrypted_t>
void print(decrypted_t const& decrypted) noexcept
{
	for(int i = 0; i != decrypted.first; ++i)
	{
		char chr;
		mk_sl_cui_uint8_to_bi_pchar(&decrypted.second[i], &chr);
		auto const r = putchar(chr);
		assert(r != EOF);
	}
}


int main(int argc, char** argv)
{
	constexpr auto const s_encrypted = encrypt("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce sit amet orci aliquam, laoreet justo pulvinar, egestas elit.");

	if(!(argc >= 2))
	{
		printf("Please provide password.\n");
		return EXIT_FAILURE;
	}
	auto const decrypted = decrypt(s_encrypted, argv[1]);
	if(decrypted.first == -1)
	{
		printf("Failed to decrypt.\n");
		return EXIT_FAILURE;
	}
	/* Succeeded to decrypt, but might be wrong password, there is no MAC. */
	printf("Decrypted:\n");
	print(decrypted);
	printf("\n");
	return EXIT_SUCCESS;
}


/* application end */
```
```bash
$ g++ -std=c++14 -DNDEBUG -fconstexpr-ops-limit=1000000000 example.cpp
$ ./a
Please provide password.
$ echo $?
1
$ ./a Hunter
Failed to decrypt.
$ echo $?
1
$ ./a Hunter2
Decrypted:
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce sit amet orci aliquam, laoreet justo pulvinar, egestas elit.
$ echo $?
0
```
