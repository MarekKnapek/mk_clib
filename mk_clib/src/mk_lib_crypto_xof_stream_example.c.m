define(^mm_xof_program~, ^#include "mk_lib_crypto_xof_stream_$2.h"

#include <assert.h> /* assert */
#include <stdio.h> /* printf sprintf */


int main(void)
{
	mk_lib_crypto_xof_stream_$2_t xofer;
	unsigned char digest[3000 / 8];
	int i;
	int t;
	char str[3000 / 8 * 2 + 1];

	mk_lib_crypto_xof_stream_$2_init(&xofer);
	mk_lib_crypto_xof_stream_$2_append(&xofer, ((unsigned char const*)("abcdef")), 6);
	mk_lib_crypto_xof_stream_$2_append(&xofer, ((unsigned char const*)("ghijklmnopqrstuvw")), 17);
	mk_lib_crypto_xof_stream_$2_append(&xofer, ((unsigned char const*)("xyz")), 3);
	mk_lib_crypto_xof_stream_$2_finish(&xofer, 3000 / 8, ((mk_lib_crypto_xof_block_$2_digest_pt)(digest)));
	for(i = 0; i != 3000 / 8; ++i)
	{
		t = sprintf(str + 2 * i, "%02x", ((unsigned char const*)(&digest))[i]);
		assert(t == 2);
	}
	t = printf("%s\n", str); /* $3 */
	assert(t == 3000 / 8 * 2 + 1);
}
~)dnl
