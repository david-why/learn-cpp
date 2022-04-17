#!/bin/bash
g++ -Wall -Wextra "choose.cpp" -o "choose.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./choose.cpp.out << CASE1
5 4
9 8 3 7 2
1 6 2 9 5
CASE1
)"
if [ "$v" = "Yes" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./choose.cpp.out << CASE2
4 90
1 1 1 100
1 2 3 100
CASE2
)"
if [ "$v" = "No" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./choose.cpp.out << CASE3
4 1000000000
1 1 1000000000 1000000000
1 1000000000 1 1000000000
CASE3
)"
if [ "$v" = "Yes" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
