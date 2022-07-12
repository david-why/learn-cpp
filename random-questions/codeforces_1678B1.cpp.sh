#!/bin/bash
g++ -Wall -Wextra "codeforces_1678B1.cpp" -o "codeforces_1678B1.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1678B1.cpp.out << CASE1
5
10
1110011000
8
11001111
2
00
2
11
6
100110
CASE1
)"
if [ "$v" = "3
0
0
0
3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
