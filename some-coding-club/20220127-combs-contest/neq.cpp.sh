#!/bin/bash
g++ -Wall -Wextra "neq.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
2 2
CASE1
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./a.out << CASE2
2 3
CASE2
)"
if [ "$v" = "18" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./a.out << CASE3
141421 356237
CASE3
)"
if [ "$v" = "881613484" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
