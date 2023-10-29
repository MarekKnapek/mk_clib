define(^mm_hash_program~, ^#include "mk_lib_crypto_hash_stream_$2.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_hash_stream_$2_t hasher;
	mk_lib_crypto_hash_block_$2_digest_t digest;
	int i;
	int t;
	char str[mk_lib_crypto_hash_block_$2_digest_len * 2 + 1];

	mk_lib_crypto_hash_stream_$2_init(&hasher);
	mk_lib_crypto_hash_stream_$2_append(&hasher, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_hash_stream_$2_append(&hasher, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_hash_stream_$2_append(&hasher, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_hash_stream_$2_finish(&hasher, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_$2_digest_len; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* $3 */
	assert(t == mk_lib_crypto_hash_block_$2_digest_len * 2 + 1);
}
~)dnl
