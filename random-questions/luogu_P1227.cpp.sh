#!/bin/bash
g++ -Wall -Wextra "luogu_P1227.cpp" -o "luogu_P1227.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./luogu_P1227.cpp.out << CASE1
8
1 10
3 6
6 8
6 2
3 -4
1 0
-2 -2
-2 4

CASE1
)"
if [ "$v" = "V.I.P. should stay at (2.0,3.0)." ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
