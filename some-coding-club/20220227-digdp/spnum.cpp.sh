#!/bin/bash
g++ -Wall -Wextra "spnum.cpp" -o "spnum.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./spnum.cpp.out << CASE1
110
2
CASE1
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./spnum.cpp.out << CASE2
111111011
2
CASE2
)"
if [ "$v" = "169" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
