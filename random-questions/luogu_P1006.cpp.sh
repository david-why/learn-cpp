#!/bin/bash
g++ -Wall -Wextra "luogu_P1006.cpp" -o "luogu_P1006.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./luogu_P1006.cpp.out << CASE1
3 3
0 3 9
2 8 5
5 7 0

CASE1
)"
if [ "$v" = "34" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
