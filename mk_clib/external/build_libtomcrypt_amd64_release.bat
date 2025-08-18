@if "%1"=="inner" goto mk_inner
@cmd.exe /c "%~f0" inner %*
@if %errorlevel% neq 0 goto mk_bad
@goto mk_gud
:mk_gud
@echo Gud.
@exit /b 0
@goto mk_end
:mk_bad
@echo Bad. %errorlevel%
@pause
@exit /b %errorlevel%
@goto mk_end

:mk_inner
@echo off
if "%2"=="" goto mk_all
if "%2"=="build" goto mk_build
exit /b 1
goto mk_end

:mk_all
cmd.exe /c "%~f0 inner build" || goto mk_fail
goto mk_end

:mk_build
if exist "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_msvs_enterprise
if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_msvs_community
exit /b 1
:mk_msvs_enterprise
call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64 > nul || goto mk_fail
goto mk_msvs_next
:mk_msvs_community
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64 > nul || goto mk_fail
goto mk_msvs_next
:mk_msvs_next
mkdir build 2> nul
cd build || goto mk_fail
mkdir int 2> nul
cd int || goto mk_fail
mkdir ltc 2> nul
cd ltc || goto mk_fail
mkdir amd64 2> nul
cd amd64 || goto mk_fail
mkdir release 2> nul
cd release || goto mk_fail
cd ..\..\..\.. || goto mk_fail
mkdir out 2> nul
cd out || goto mk_fail
mkdir amd64 2> nul
cd amd64 || goto mk_fail
mkdir release 2> nul
cd release || goto mk_fail
cd ..\..\.. || goto mk_fail
cd int\ltc\amd64\release || goto mk_fail
cl ^
-c ^
/D "_ALLOW_RTCc_IN_STL" ^
/D "_CRT_SECURE_NO_WARNINGS" ^
/D "_NDEBUG" ^
/D "ARGTYPE=3" ^
/D "NDEBUG" ^
/diagnostics:column ^
/errorReport:none ^
/FC ^
/fp:except- ^
/fp:precise ^
/Gd ^
/GF ^
/GL ^
/Gm- ^
/GR- ^
/GS- ^
/GT ^
/guard:cf- ^
/guard:ehcont- ^
/Gy ^
/MP ^
/MT ^
/nologo ^
/O2 ^
/Ob2 ^
/Oi ^
/openmp- ^
/Ot ^
/Oy ^
/permissive- ^
/Qpar- ^
/sdl- ^
/std:c17 ^
/TC ^
/Zc:forScope ^
/Zc:inline ^
/Zc:preprocessor ^
/Zc:rvalueCast ^
/Zc:wchar_t ^
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
/I ..\..\..\..\..\libtomcrypt\src\headers > nul || goto mk_fail
cd ..\..\..\.. || goto mk_fail
cd out\amd64\release || goto mk_fail
lib ^
/nologo ^
..\..\..\int\ltc\amd64\release\blake2b.obj ^
..\..\..\int\ltc\amd64\release\blake2s.obj ^
..\..\..\int\ltc\amd64\release\chacha20.obj ^
..\..\..\int\ltc\amd64\release\chacha_crypt.obj ^
..\..\..\int\ltc\amd64\release\chacha_done.obj ^
..\..\..\int\ltc\amd64\release\chacha_ivctr64.obj ^
..\..\..\int\ltc\amd64\release\chacha_keystream.obj ^
..\..\..\int\ltc\amd64\release\chacha_setup.obj ^
..\..\..\int\ltc\amd64\release\compare_testvector.obj ^
..\..\..\int\ltc\amd64\release\crypt_argchk.obj ^
..\..\..\int\ltc\amd64\release\crypt_find_hash.obj ^
..\..\..\int\ltc\amd64\release\crypt_hash_descriptor.obj ^
..\..\..\int\ltc\amd64\release\crypt_hash_is_valid.obj ^
..\..\..\int\ltc\amd64\release\crypt_ltc_mp_descriptor.obj ^
..\..\..\int\ltc\amd64\release\crypt_prng_descriptor.obj ^
..\..\..\int\ltc\amd64\release\crypt_prng_is_valid.obj ^
..\..\..\int\ltc\amd64\release\crypt_register_hash.obj ^
..\..\..\int\ltc\amd64\release\crypt_register_prng.obj ^
..\..\..\int\ltc\amd64\release\der_asn1_maps.obj ^
..\..\..\int\ltc\amd64\release\der_encode_asn1_identifier.obj ^
..\..\..\int\ltc\amd64\release\der_encode_asn1_length.obj ^
..\..\..\int\ltc\amd64\release\der_encode_bit_string.obj ^
..\..\..\int\ltc\amd64\release\der_encode_boolean.obj ^
..\..\..\int\ltc\amd64\release\der_encode_custom_type.obj ^
..\..\..\int\ltc\amd64\release\der_encode_generalizedtime.obj ^
..\..\..\int\ltc\amd64\release\der_encode_ia5_string.obj ^
..\..\..\int\ltc\amd64\release\der_encode_integer.obj ^
..\..\..\int\ltc\amd64\release\der_encode_object_identifier.obj ^
..\..\..\int\ltc\amd64\release\der_encode_octet_string.obj ^
..\..\..\int\ltc\amd64\release\der_encode_printable_string.obj ^
..\..\..\int\ltc\amd64\release\der_encode_raw_bit_string.obj ^
..\..\..\int\ltc\amd64\release\der_encode_sequence_ex.obj ^
..\..\..\int\ltc\amd64\release\der_encode_sequence_multi.obj ^
..\..\..\int\ltc\amd64\release\der_encode_set.obj ^
..\..\..\int\ltc\amd64\release\der_encode_setof.obj ^
..\..\..\int\ltc\amd64\release\der_encode_short_integer.obj ^
..\..\..\int\ltc\amd64\release\der_encode_utctime.obj ^
..\..\..\int\ltc\amd64\release\der_encode_utf8_string.obj ^
..\..\..\int\ltc\amd64\release\der_length_asn1_identifier.obj ^
..\..\..\int\ltc\amd64\release\der_length_asn1_length.obj ^
..\..\..\int\ltc\amd64\release\der_length_bit_string.obj ^
..\..\..\int\ltc\amd64\release\der_length_boolean.obj ^
..\..\..\int\ltc\amd64\release\der_length_custom_type.obj ^
..\..\..\int\ltc\amd64\release\der_length_generalizedtime.obj ^
..\..\..\int\ltc\amd64\release\der_length_ia5_string.obj ^
..\..\..\int\ltc\amd64\release\der_length_integer.obj ^
..\..\..\int\ltc\amd64\release\der_length_object_identifier.obj ^
..\..\..\int\ltc\amd64\release\der_length_octet_string.obj ^
..\..\..\int\ltc\amd64\release\der_length_printable_string.obj ^
..\..\..\int\ltc\amd64\release\der_length_sequence.obj ^
..\..\..\int\ltc\amd64\release\der_length_short_integer.obj ^
..\..\..\int\ltc\amd64\release\der_length_teletex_string.obj ^
..\..\..\int\ltc\amd64\release\der_length_utctime.obj ^
..\..\..\int\ltc\amd64\release\der_length_utf8_string.obj ^
..\..\..\int\ltc\amd64\release\ec25519_crypto_ctx.obj ^
..\..\..\int\ltc\amd64\release\ec25519_export.obj ^
..\..\..\int\ltc\amd64\release\ed25519_export.obj ^
..\..\..\int\ltc\amd64\release\ed25519_import_raw.obj ^
..\..\..\int\ltc\amd64\release\ed25519_make_key.obj ^
..\..\..\int\ltc\amd64\release\ed25519_sign.obj ^
..\..\..\int\ltc\amd64\release\ed25519_verify.obj ^
..\..\..\int\ltc\amd64\release\hash_memory.obj ^
..\..\..\int\ltc\amd64\release\hash_memory_multi.obj ^
..\..\..\int\ltc\amd64\release\hmac_done.obj ^
..\..\..\int\ltc\amd64\release\hmac_init.obj ^
..\..\..\int\ltc\amd64\release\hmac_memory.obj ^
..\..\..\int\ltc\amd64\release\hmac_process.obj ^
..\..\..\int\ltc\amd64\release\md2.obj ^
..\..\..\int\ltc\amd64\release\md4.obj ^
..\..\..\int\ltc\amd64\release\md5.obj ^
..\..\..\int\ltc\amd64\release\pk_get.obj ^
..\..\..\int\ltc\amd64\release\pk_oid_str.obj ^
..\..\..\int\ltc\amd64\release\sha1.obj ^
..\..\..\int\ltc\amd64\release\sha224.obj ^
..\..\..\int\ltc\amd64\release\sha256.obj ^
..\..\..\int\ltc\amd64\release\sha3.obj ^
..\..\..\int\ltc\amd64\release\sha384.obj ^
..\..\..\int\ltc\amd64\release\sha3_test.obj ^
..\..\..\int\ltc\amd64\release\sha512.obj ^
..\..\..\int\ltc\amd64\release\sha512_224.obj ^
..\..\..\int\ltc\amd64\release\sha512_256.obj ^
..\..\..\int\ltc\amd64\release\tiger.obj ^
..\..\..\int\ltc\amd64\release\tweetnacl.obj ^
..\..\..\int\ltc\amd64\release\whirl.obj ^
..\..\..\int\ltc\amd64\release\whirltab.obj ^
..\..\..\int\ltc\amd64\release\x509_encode_subject_public_key_info.obj ^
..\..\..\int\ltc\amd64\release\zeromem.obj ^
/out:ltc.lib || goto mk_fail
goto mk_end

:mk_fail
@exit /b %errorlevel%
@goto mk_end

:mk_end
