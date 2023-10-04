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
