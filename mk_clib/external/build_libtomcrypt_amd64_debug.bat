@if exist "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise
@if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community
@exit /b 1
:mk_enterprise
@call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
@goto mk_next
:mk_community
@call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
@goto mk_next
:mk_next

@pushd "%~dp0"

@mkdir build 2> nul
@cd build

@mkdir int 2> nul
@cd int
@mkdir ltc 2> nul
@cd ltc
@mkdir amd64 2> nul
@cd amd64
@mkdir debug 2> nul
@cd debug
@cd ..\..\..\..

@mkdir out 2> nul
@cd out
@mkdir amd64 2> nul
@cd amd64
@mkdir debug 2> nul
@cd debug
@cd ..\..\..

@cd int\ltc\amd64\debug

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
..\..\..\..\..\libtomcrypt\src\misc\crypt\crypt_register_hash.c ^
..\..\..\..\..\libtomcrypt\src\misc\zeromem.c ^
/Fd"..\..\..\..\out\amd64\debug\ltc.pdb"
@if %errorlevel% neq 0 goto mk_bad

@cd ..\..\..\..

@cd out\amd64\debug

@lib ^
/NOLOGO ^
..\..\..\int\ltc\amd64\debug\blake2b.obj ^
..\..\..\int\ltc\amd64\debug\blake2s.obj ^
..\..\..\int\ltc\amd64\debug\compare_testvector.obj ^
..\..\..\int\ltc\amd64\debug\crypt_argchk.obj ^
..\..\..\int\ltc\amd64\debug\crypt_find_hash.obj ^
..\..\..\int\ltc\amd64\debug\crypt_hash_descriptor.obj ^
..\..\..\int\ltc\amd64\debug\crypt_hash_is_valid.obj ^
..\..\..\int\ltc\amd64\debug\crypt_register_hash.obj ^
..\..\..\int\ltc\amd64\debug\hash_memory.obj ^
..\..\..\int\ltc\amd64\debug\hmac_done.obj ^
..\..\..\int\ltc\amd64\debug\hmac_init.obj ^
..\..\..\int\ltc\amd64\debug\hmac_memory.obj ^
..\..\..\int\ltc\amd64\debug\hmac_process.obj ^
..\..\..\int\ltc\amd64\debug\md2.obj ^
..\..\..\int\ltc\amd64\debug\md4.obj ^
..\..\..\int\ltc\amd64\debug\md5.obj ^
..\..\..\int\ltc\amd64\debug\sha1.obj ^
..\..\..\int\ltc\amd64\debug\sha224.obj ^
..\..\..\int\ltc\amd64\debug\sha256.obj ^
..\..\..\int\ltc\amd64\debug\sha3.obj ^
..\..\..\int\ltc\amd64\debug\sha384.obj ^
..\..\..\int\ltc\amd64\debug\sha3_test.obj ^
..\..\..\int\ltc\amd64\debug\sha512.obj ^
..\..\..\int\ltc\amd64\debug\sha512_224.obj ^
..\..\..\int\ltc\amd64\debug\sha512_256.obj ^
..\..\..\int\ltc\amd64\debug\tiger.obj ^
..\..\..\int\ltc\amd64\debug\whirl.obj ^
..\..\..\int\ltc\amd64\debug\whirltab.obj ^
..\..\..\int\ltc\amd64\debug\zeromem.obj ^
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
