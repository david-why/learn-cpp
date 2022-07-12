#!/bin/bash
g++ -Wall -Wextra "codeforces_1667A.cpp" -o "codeforces_1667A.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1667A.cpp.out << CASE1
5
1 2 3 4 5
CASE1
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./codeforces_1667A.cpp.out << CASE2
7
1 2 1 2 1 2 1
CASE2
)"
if [ "$v" = "10" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./codeforces_1667A.cpp.out << CASE3
8
1 8 2 7 3 6 4 5
CASE3
)"
if [ "$v" = "16" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
