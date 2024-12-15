mkdir corpusn && ..\x64\Debug\mkcf.exe -merge=1 corpusn corpus && copy corpus\.gitignore corpusn\.gitignore && del /q corpus\* && rmdir corpus && ren corpusn corpus
