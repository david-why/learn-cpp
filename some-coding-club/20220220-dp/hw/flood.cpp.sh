#!/bin/bash
g++ -Wall -Wextra "flood.cpp" -o "flood.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./flood.cpp.out << CASE1
4
5 2 2 1
CASE1
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./flood.cpp.out << CASE2
8
4 5 2 2 1 3 5 5
CASE2
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./flood.cpp.out << CASE3
1
4
CASE3
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
