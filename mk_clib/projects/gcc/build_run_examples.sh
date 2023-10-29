pushd ../../src > /dev/null
gcc -DNDEBUG ./mk_lang_bui_example.c
./a
echo $?
rm ./a
popd > /dev/null

pushd ../../src > /dev/null
gcc -DNDEBUG ./mk_sl_cui_example.c
./a
rm ./a
popd > /dev/null

pushd ../../app > /dev/null
gcc -DNDEBUG -O2 ./mkcfct.c
./a 42
rm ./a
popd > /dev/null

pushd ../../app > /dev/null
gcc -DNDEBUG ./mkcflt.c
./a -123.456
rm ./a
popd > /dev/null

pushd ../../src > /dev/null
function example_hash()
{
	echo "changequote(\`^', \`~')include(mk_lib_crypto_hash_stream_example.c.m)mm_hash_program(^~, ^$1~, ^~)" > ./example.m4
	m4 ./example.m4 > ./example.c
	gcc -DNDEBUG ./example.c
	./a
	rm ./example.m4
	rm ./example.c
	rm ./a
}
function example_xof()
{
	echo "changequote(\`^', \`~')include(mk_lib_crypto_xof_stream_example.c.m)mm_xof_program(^~, ^$1~, ^~)" > ./example.m4
	m4 ./example.m4 > ./example.c
	gcc -DNDEBUG ./example.c
	./a
	rm ./example.m4
	rm ./example.c
	rm ./a
}
example_hash md2
example_hash md4
example_hash md5
example_hash sha0
example_hash sha1
example_hash sha2_224
example_hash sha2_256
example_hash sha2_384
example_hash sha2_512
example_hash sha2_512_224
example_hash sha2_512_256
example_hash sha3_224
example_hash sha3_256
example_hash sha3_384
example_hash sha3_512
example_hash tiger_128
example_hash tiger_160
example_hash tiger_192
example_hash tiger2_128
example_hash tiger2_160
example_hash tiger2_192
example_hash blake2s_128
example_hash blake2s_160
example_hash blake2s_224
example_hash blake2s_256
example_hash blake2b_256
example_hash blake2b_384
example_hash blake2b_512
example_hash blake3
example_xof shake_128
example_xof shake_256
popd > /dev/null
