gcc -std=c2x -DNDEBUG -O3 -fconstexpr-ops-limit=1000000000 -Wall -Wextra -Wpedantic -o mkct.exe ../../app/mkct.c && ./mkct.exe
