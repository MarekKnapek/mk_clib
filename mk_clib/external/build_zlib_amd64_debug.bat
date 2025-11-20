@if exist "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise
@if exist "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community
@exit /b 1
:mk_enterprise
@call "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
@goto mk_next
:mk_community
@call "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
@goto mk_next
:mk_next

@pushd "%~dp0"

@mkdir build 2> nul
@cd build

@mkdir int 2> nul
@cd int
@mkdir zlib 2> nul
@cd zlib
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

@cd int\zlib\amd64\debug

@cl ^
-c ^
/D "_ALLOW_RTCc_IN_STL" ^
/D "_CRT_SECURE_NO_WARNINGS" ^
/D "_DEBUG" ^
/D "_UNICODE" ^
/D "DEBUG" ^
/D "mk_lang_external_zlib_want=1" ^
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
/I ..\..\..\..\..\zlib ^
..\..\..\..\..\zlib\adler32.c ^
..\..\..\..\..\zlib\compress.c ^
..\..\..\..\..\zlib\crc32.c ^
..\..\..\..\..\zlib\deflate.c ^
..\..\..\..\..\zlib\infback.c ^
..\..\..\..\..\zlib\inffast.c ^
..\..\..\..\..\zlib\inflate.c ^
..\..\..\..\..\zlib\inftrees.c ^
..\..\..\..\..\zlib\trees.c ^
..\..\..\..\..\zlib\uncompr.c ^
..\..\..\..\..\zlib\zutil.c ^
/Fd"..\..\..\..\out\amd64\debug\zlib.pdb"
@if %errorlevel% neq 0 goto mk_bad

@cd ..\..\..\..

@cd out\amd64\debug

@lib ^
/NOLOGO ^
..\..\..\int\zlib\amd64\debug\adler32.obj ^
..\..\..\int\zlib\amd64\debug\compress.obj ^
..\..\..\int\zlib\amd64\debug\crc32.obj ^
..\..\..\int\zlib\amd64\debug\deflate.obj ^
..\..\..\int\zlib\amd64\debug\infback.obj ^
..\..\..\int\zlib\amd64\debug\inffast.obj ^
..\..\..\int\zlib\amd64\debug\inflate.obj ^
..\..\..\int\zlib\amd64\debug\inftrees.obj ^
..\..\..\int\zlib\amd64\debug\trees.obj ^
..\..\..\int\zlib\amd64\debug\uncompr.obj ^
..\..\..\int\zlib\amd64\debug\zutil.obj ^
/out:zlib.lib
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
