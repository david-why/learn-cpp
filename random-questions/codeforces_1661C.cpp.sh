#!/bin/bash
g++ -Wall -Wextra "codeforces_1661C.cpp" -o "codeforces_1661C.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1661C.cpp.out << CASE1
3
3
1 2 4
5
4 4 3 5 5
7
2 5 4 8 3 7 4
CASE1
)"
if [ "$v" = "4
3
16" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
