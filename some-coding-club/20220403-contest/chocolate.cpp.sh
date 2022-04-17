#!/bin/bash
g++ -Wall -Wextra "chocolate.cpp" -o "chocolate.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./chocolate.cpp.out << CASE1
2 3
2 4
3 2
8 1 5
2 10 5
CASE1
)"
if [ "$v" = "Yes" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./chocolate.cpp.out << CASE2
2 2
1 1
2 2
100 1
100 1
CASE2
)"
if [ "$v" = "No" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./chocolate.cpp.out << CASE3
1 1
10
100
100
10
CASE3
)"
if [ "$v" = "No" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./chocolate.cpp.out << CASE4
1 1
10
100
10
100
CASE4
)"
if [ "$v" = "Yes" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
