#!/bin/bash
g++ -Wall -Wextra "hw-nut.cpp" -o "hw-nut.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./hw-nut.cpp.out << CASE1
3
4 4 8
1 5 0
5 2 10
CASE1
)"
if [ "$v" = "9" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./hw-nut.cpp.out << CASE2
4
6 2 4
1 6 2
2 4 3
5 3 8
CASE2
)"
if [ "$v" = "10" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
