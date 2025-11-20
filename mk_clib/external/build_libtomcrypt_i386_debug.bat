@if exist "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise
@if exist "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community
@exit /b 1
:mk_enterprise
@call "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64_x86
@goto mk_next
:mk_community
@call "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64_x86
@goto mk_next
:mk_next

@pushd "%~dp0"

@mkdir build 2> nul
@cd build

@mkdir int 2> nul
@cd int
@mkdir ltc 2> nul
@cd ltc
@mkdir i386 2> nul
@cd i386
@mkdir debug 2> nul
@cd debug
@cd ..\..\..\..

@mkdir out 2> nul
@cd out
@mkdir i386 2> nul
@cd i386
@mkdir debug 2> nul
@cd debug
@cd ..\..\..

@cd int\ltc\i386\debug

@cl ^
-c ^
/D "_ALLOW_RTCc_IN_STL" ^
/D "_CRT_SECURE_NO_WARNINGS" ^
/D "_DEBUG" ^
/D "_UNICODE" ^
/D "DEBUG" ^
/D "mk_lang_external_ltc_want=1" ^
/D "mk_lang_jumbo_want=0" ^
/D "UNICODE" ^
/diagnostics:column ^
/EHsc ^
/errorReport:none ^
/FC ^
/fp:except- ^
/fp:precise ^
/FS ^
/fsanitize=address ^
/fsanitize=fuzzer ^
/Gd ^
/GF- ^
/Gm- ^
/GR- ^
/GS ^
/guard:cf ^
/guard:ehcont- ^
/Gy- ^
/JMC ^
/MDd ^
/MP ^
/nologo ^
/Ob0 ^
/Od ^
/openmp- ^
/Oy- ^
/permissive- ^
/Qpar- ^
/RTC1 ^
/sdl ^
/std:c17 ^
/W0 ^
/WX ^
/Zc:forScope ^
/Zc:inline ^
/Zc:preprocessor ^
/Zc:rvalueCast ^
/Zc:wchar_t ^
/Zi ^
/I ..\..\..\..\..\libtomcrypt\src\headers ^
..\..\..\..\..\libtomcrypt\src\hashes\blake2b.c ^
..\..\..\..\..\libtomcrypt\src\hashes\blake2s.c ^
..\..\..\..\..\libtomcrypt\src\hashes\helper\hash_memory.c ^
..\..\..\..\..\libtomcrypt\src\hashes\helper\hash_memory_multi.c ^
..\..\..\..\..\libtomcrypt\src\hashes\md2.c ^
..\..\..\..\..\libtomcrypt\src\hashes\md4.c ^
..\..\..\..\..\libtomcrypt\src\hashes\md5.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha1.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha2\sha224.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha2\sha256.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha2\sha384.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha2\sha512.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha2\sha512_224.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha2\sha512_256.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha3.c ^
..\..\..\..\..\libtomcrypt\src\hashes\sha3_test.c ^
..\..\..\..\..\libtomcrypt\src\hashes\tiger.c ^
..\..\..\..\..\libtomcrypt\src\hashes\whirl\whirl.c ^
..\..\..\..\..\libtomcrypt\src\hashes\whirl\whirltab.c ^
..\..\..\..\..\libtomcrypt\src\mac\hmac\hmac_done.c ^
..\..\..\..\..\libtomcrypt\src\mac\hmac\hmac_init.c ^
..\..\..\..\..\libtomcrypt\src\mac\hmac\hmac_memory.c ^
..\..\..\..\..\libtomcrypt\src\mac\hmac\hmac_process.c ^
..\..\..\..\..\libtomcrypt\src\misc\compare_testvector.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_argchk.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_find_hash.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_hash_descriptor.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_hash_is_valid.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_ltc_mp_descriptor.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_prng_descriptor.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_prng_is_valid.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_register_hash.c ^
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_register_prng.c ^
..\..\..\..\..\libtomcrypt\src\misc\zeromem.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\bit\der_encode_bit_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\bit\der_encode_raw_bit_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\bit\der_length_bit_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\boolean\der_encode_boolean.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\boolean\der_length_boolean.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\custom_type\der_encode_custom_type.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\custom_type\der_length_custom_type.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\general\der_asn1_maps.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\general\der_encode_asn1_identifier.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\general\der_encode_asn1_length.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\general\der_length_asn1_identifier.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\general\der_length_asn1_length.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\generalizedtime\der_encode_generalizedtime.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\generalizedtime\der_length_generalizedtime.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\ia5\der_encode_ia5_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\ia5\der_length_ia5_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\integer\der_encode_integer.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\integer\der_length_integer.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\object_identifier\der_encode_object_identifier.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\object_identifier\der_length_object_identifier.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\octet\der_encode_octet_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\octet\der_length_octet_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\printable_string\der_encode_printable_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\printable_string\der_length_printable_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\sequence\der_encode_sequence_ex.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\sequence\der_encode_sequence_multi.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\sequence\der_length_sequence.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\set\der_encode_set.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\set\der_encode_setof.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\short_integer\der_encode_short_integer.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\short_integer\der_length_short_integer.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\teletex_string\der_length_teletex_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\utctime\der_encode_utctime.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\utctime\der_length_utctime.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\utf8\der_encode_utf8_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\der\utf8\der_length_utf8_string.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\oid\pk_get.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\oid\pk_oid_str.c ^
..\..\..\..\..\libtomcrypt\src\pk\asn1\x509\x509_encode_subject_public_key_info.c ^
..\..\..\..\..\libtomcrypt\src\pk\ec25519\ec25519_crypto_ctx.c ^
..\..\..\..\..\libtomcrypt\src\pk\ec25519\ec25519_export.c ^
..\..\..\..\..\libtomcrypt\src\pk\ec25519\tweetnacl.c ^
..\..\..\..\..\libtomcrypt\src\pk\ed25519\ed25519_export.c ^
..\..\..\..\..\libtomcrypt\src\pk\ed25519\ed25519_import_raw.c ^
..\..\..\..\..\libtomcrypt\src\pk\ed25519\ed25519_make_key.c ^
..\..\..\..\..\libtomcrypt\src\pk\ed25519\ed25519_sign.c ^
..\..\..\..\..\libtomcrypt\src\pk\ed25519\ed25519_verify.c ^
..\..\..\..\..\libtomcrypt\src\prngs\chacha20.c ^
..\..\..\..\..\libtomcrypt\src\stream\chacha\chacha_crypt.c ^
..\..\..\..\..\libtomcrypt\src\stream\chacha\chacha_done.c ^
..\..\..\..\..\libtomcrypt\src\stream\chacha\chacha_ivctr64.c ^
..\..\..\..\..\libtomcrypt\src\stream\chacha\chacha_keystream.c ^
..\..\..\..\..\libtomcrypt\src\stream\chacha\chacha_setup.c ^
/Fd"..\..\..\..\out\i386\debug\ltc.pdb"
@if %errorlevel% neq 0 goto mk_bad

@cd ..\..\..\..

@cd out\i386\debug

@lib ^
/NOLOGO ^
..\..\..\int\ltc\i386\debug\blake2b.obj ^
..\..\..\int\ltc\i386\debug\blake2s.obj ^
..\..\..\int\ltc\i386\debug\chacha20.obj ^
..\..\..\int\ltc\i386\debug\chacha_crypt.obj ^
..\..\..\int\ltc\i386\debug\chacha_done.obj ^
..\..\..\int\ltc\i386\debug\chacha_ivctr64.obj ^
..\..\..\int\ltc\i386\debug\chacha_keystream.obj ^
..\..\..\int\ltc\i386\debug\chacha_setup.obj ^
..\..\..\int\ltc\i386\debug\compare_testvector.obj ^
..\..\..\int\ltc\i386\debug\crypt_argchk.obj ^
..\..\..\int\ltc\i386\debug\crypt_find_hash.obj ^
..\..\..\int\ltc\i386\debug\crypt_hash_descriptor.obj ^
..\..\..\int\ltc\i386\debug\crypt_hash_is_valid.obj ^
..\..\..\int\ltc\i386\debug\crypt_ltc_mp_descriptor.obj ^
..\..\..\int\ltc\i386\debug\crypt_prng_descriptor.obj ^
..\..\..\int\ltc\i386\debug\crypt_prng_is_valid.obj ^
..\..\..\int\ltc\i386\debug\crypt_register_hash.obj ^
..\..\..\int\ltc\i386\debug\crypt_register_prng.obj ^
..\..\..\int\ltc\i386\debug\der_asn1_maps.obj ^
..\..\..\int\ltc\i386\debug\der_encode_asn1_identifier.obj ^
..\..\..\int\ltc\i386\debug\der_encode_asn1_length.obj ^
..\..\..\int\ltc\i386\debug\der_encode_bit_string.obj ^
..\..\..\int\ltc\i386\debug\der_encode_boolean.obj ^
..\..\..\int\ltc\i386\debug\der_encode_custom_type.obj ^
..\..\..\int\ltc\i386\debug\der_encode_generalizedtime.obj ^
..\..\..\int\ltc\i386\debug\der_encode_ia5_string.obj ^
..\..\..\int\ltc\i386\debug\der_encode_integer.obj ^
..\..\..\int\ltc\i386\debug\der_encode_object_identifier.obj ^
..\..\..\int\ltc\i386\debug\der_encode_octet_string.obj ^
..\..\..\int\ltc\i386\debug\der_encode_printable_string.obj ^
..\..\..\int\ltc\i386\debug\der_encode_raw_bit_string.obj ^
..\..\..\int\ltc\i386\debug\der_encode_sequence_ex.obj ^
..\..\..\int\ltc\i386\debug\der_encode_sequence_multi.obj ^
..\..\..\int\ltc\i386\debug\der_encode_set.obj ^
..\..\..\int\ltc\i386\debug\der_encode_setof.obj ^
..\..\..\int\ltc\i386\debug\der_encode_short_integer.obj ^
..\..\..\int\ltc\i386\debug\der_encode_utctime.obj ^
..\..\..\int\ltc\i386\debug\der_encode_utf8_string.obj ^
..\..\..\int\ltc\i386\debug\der_length_asn1_identifier.obj ^
..\..\..\int\ltc\i386\debug\der_length_asn1_length.obj ^
..\..\..\int\ltc\i386\debug\der_length_bit_string.obj ^
..\..\..\int\ltc\i386\debug\der_length_boolean.obj ^
..\..\..\int\ltc\i386\debug\der_length_custom_type.obj ^
..\..\..\int\ltc\i386\debug\der_length_generalizedtime.obj ^
..\..\..\int\ltc\i386\debug\der_length_ia5_string.obj ^
..\..\..\int\ltc\i386\debug\der_length_integer.obj ^
..\..\..\int\ltc\i386\debug\der_length_object_identifier.obj ^
..\..\..\int\ltc\i386\debug\der_length_octet_string.obj ^
..\..\..\int\ltc\i386\debug\der_length_printable_string.obj ^
..\..\..\int\ltc\i386\debug\der_length_sequence.obj ^
..\..\..\int\ltc\i386\debug\der_length_short_integer.obj ^
..\..\..\int\ltc\i386\debug\der_length_teletex_string.obj ^
..\..\..\int\ltc\i386\debug\der_length_utctime.obj ^
..\..\..\int\ltc\i386\debug\der_length_utf8_string.obj ^
..\..\..\int\ltc\i386\debug\ec25519_crypto_ctx.obj ^
..\..\..\int\ltc\i386\debug\ec25519_export.obj ^
..\..\..\int\ltc\i386\debug\ed25519_export.obj ^
..\..\..\int\ltc\i386\debug\ed25519_import_raw.obj ^
..\..\..\int\ltc\i386\debug\ed25519_make_key.obj ^
..\..\..\int\ltc\i386\debug\ed25519_sign.obj ^
..\..\..\int\ltc\i386\debug\ed25519_verify.obj ^
..\..\..\int\ltc\i386\debug\hash_memory.obj ^
..\..\..\int\ltc\i386\debug\hash_memory_multi.obj ^
..\..\..\int\ltc\i386\debug\hmac_done.obj ^
..\..\..\int\ltc\i386\debug\hmac_init.obj ^
..\..\..\int\ltc\i386\debug\hmac_memory.obj ^
..\..\..\int\ltc\i386\debug\hmac_process.obj ^
..\..\..\int\ltc\i386\debug\md2.obj ^
..\..\..\int\ltc\i386\debug\md4.obj ^
..\..\..\int\ltc\i386\debug\md5.obj ^
..\..\..\int\ltc\i386\debug\pk_get.obj ^
..\..\..\int\ltc\i386\debug\pk_oid_str.obj ^
..\..\..\int\ltc\i386\debug\sha1.obj ^
..\..\..\int\ltc\i386\debug\sha224.obj ^
..\..\..\int\ltc\i386\debug\sha256.obj ^
..\..\..\int\ltc\i386\debug\sha3.obj ^
..\..\..\int\ltc\i386\debug\sha384.obj ^
..\..\..\int\ltc\i386\debug\sha3_test.obj ^
..\..\..\int\ltc\i386\debug\sha512.obj ^
..\..\..\int\ltc\i386\debug\sha512_224.obj ^
..\..\..\int\ltc\i386\debug\sha512_256.obj ^
..\..\..\int\ltc\i386\debug\tiger.obj ^
..\..\..\int\ltc\i386\debug\tweetnacl.obj ^
..\..\..\int\ltc\i386\debug\whirl.obj ^
..\..\..\int\ltc\i386\debug\whirltab.obj ^
..\..\..\int\ltc\i386\debug\x509_encode_subject_public_key_info.obj ^
..\..\..\int\ltc\i386\debug\zeromem.obj ^
/out:ltc.lib
@if %errorlevel% neq 0 goto mk_bad

@cd ..\..\..\..

@popd

:mk_gud
@echo Gud.
@goto mk_end

@goto mk_end

:mk_bad
@echo Bad.
exit /b %errorlevel%
@goto mk_end

:mk_end
