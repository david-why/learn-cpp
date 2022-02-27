#!/bin/bash
g++ -Wall -Wextra "liseq3.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
4 5
CASE1
)"
if [ "$v" = "135" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./a.out << CASE2
3 4
CASE2
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./a.out << CASE3
111 3
CASE3
)"
if [ "$v" = "144980434" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
