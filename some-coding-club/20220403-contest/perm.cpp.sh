#!/bin/bash
g++ -Wall -Wextra "perm.cpp" -o "perm.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./perm.cpp.out << CASE1
3 2
2 1 3
CASE1
)"
if [ "$v" = "5 2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./perm.cpp.out << CASE2
5 5
2 1 5 3 4
CASE2
)"
if [ "$v" = "15 1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./perm.cpp.out << CASE3
7 3
2 7 3 1 5 4 6
CASE3
)"
if [ "$v" = "18 6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
