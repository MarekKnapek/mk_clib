@if "%1"=="inner" goto mk_inner
@cmd.exe /c "%~f0" inner %*
@exit /b %errorlevel%
@goto mk_end

:mk_inner
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

@mkdir "%~dp0corpus_new"
@if %errorlevel% neq 0 goto mk_bad

@"%~dp0..\build\out\x64\DebugMSVC\mk_clib_fuzz.exe" -merge=1 "%~dp0corpus_new" "%~dp0corpus"
@if %errorlevel% neq 0 goto mk_bad

@copy "%~dp0corpus\.gitignore" "%~dp0corpus_new\.gitignore" > nul
@if %errorlevel% neq 0 goto mk_bad

@del /q "%~dp0corpus\*"
@if %errorlevel% neq 0 goto mk_bad

@rmdir "%~dp0corpus"
@if %errorlevel% neq 0 goto mk_bad

@rename "%~dp0corpus_new" "corpus"
@if %errorlevel% neq 0 goto mk_bad

:mk_gud
@echo Gud.
@goto mk_end

:mk_bad
@echo Bad.
@exit /b %errorlevel%
@goto mk_end

:mk_end
