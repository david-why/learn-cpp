#!/bin/bash
g++ -Wall -Wextra "codeforces_2B.cpp" -o "codeforces_2B.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_2B.cpp.out << CASE1
3
1 2 3
4 5 6
7 8 9
CASE1
)"
if [ "$v" = "0
DDRR" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
