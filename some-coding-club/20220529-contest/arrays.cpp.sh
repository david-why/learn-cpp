#!/bin/bash
g++ -Wall -Wextra "arrays.cpp" -o "arrays.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./arrays.cpp.out << CASE1
2
1 1
2 3
CASE1
)"
if [ "$v" = "5" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./arrays.cpp.out << CASE2
3
2 2 2
2 2 2
CASE2
)"
if [ "$v" = "1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./arrays.cpp.out << CASE3
10
1 2 3 4 5 6 7 8 9 10
1 4 9 16 25 36 49 64 81 100
CASE3
)"
if [ "$v" = "978222082" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
