#!/bin/bash
g++ -Wall -Wextra "codeforces_1690A.cpp" -o "codeforces_1690A.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1690A.cpp.out << CASE1
6
11
6
10
100000
7
8
CASE1
)"
if [ "$v" = "4 5 2
2 3 1
4 5 1
33334 33335 33331
2 4 1
3 4 1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
