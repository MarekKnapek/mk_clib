@if "%~1"=="inner" goto mk_inner
@cmd.exe /c ""%~f0" "inner" %*"
@if %errorlevel% neq 0 goto mk_outer_bad
@goto mk_outer_gud

:mk_inner
@echo off

if exist "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise
if exist "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community
goto mk_fail

:mk_enterprise
call "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
@if %errorlevel% neq 0 goto mk_bad
@echo off
goto mk_next

:mk_community
call "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
@if %errorlevel% neq 0 goto mk_bad
@echo off
goto mk_next

:mk_next
mkdir "%~dp0corpus_new"
if %errorlevel% neq 0 goto mk_bad

"%~dp0..\build\out\x64-MSVC-Debug-P\mk_clib_fuzz.exe" -merge=1 "%~dp0corpus_new" "%~dp0corpus"
if %errorlevel% neq 0 goto mk_bad

copy "%~dp0corpus\.gitignore" "%~dp0corpus_new\.gitignore" > nul
if %errorlevel% neq 0 goto mk_bad

del /q "%~dp0corpus\*"
if %errorlevel% neq 0 goto mk_bad

rmdir "%~dp0corpus"
if %errorlevel% neq 0 goto mk_bad

rename "%~dp0corpus_new" "corpus"
if %errorlevel% neq 0 goto mk_bad

goto mk_gud

:mk_fail
exit /b 1
goto mk_end

:mk_bad
exit /b %errorlevel%
goto mk_end

:mk_gud
goto mk_end

:mk_outer_gud
@echo Gud.
@goto mk_end

:mk_outer_bad
@echo Bad.
@exit /b %errorlevel%
@goto mk_end

:mk_end
