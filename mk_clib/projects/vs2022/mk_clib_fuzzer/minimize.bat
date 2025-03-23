mkdir corpus_new
if %errorlevel% neq 0 exit /b %errorlevel%

..\x64\Debug\mk_clib_fuzzer.exe -merge=1 corpus_new corpus ..\..\clang\corpus
if %errorlevel% neq 0 exit /b %errorlevel%

copy corpus\.gitignore corpus_new\.gitignore
if %errorlevel% neq 0 exit /b %errorlevel%

del /q corpus\*
if %errorlevel% neq 0 exit /b %errorlevel%

rmdir corpus
if %errorlevel% neq 0 exit /b %errorlevel%

rename corpus_new corpus
if %errorlevel% neq 0 exit /b %errorlevel%
