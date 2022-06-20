#!/bin/bash
g++ -Wall -Wextra "luogu_P1213.cpp" -o "luogu_P1213.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./luogu_P1213.cpp.out << CASE1
9 9 12
6 6 6
6 3 6 

CASE1
)"
if [ "$v" = "4 5 8 9
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
