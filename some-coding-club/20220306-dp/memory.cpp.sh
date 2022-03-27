#!/bin/bash
g++ -Wall -Wextra "memory.cpp" -o "memory.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./memory.cpp.out << CASE1
1 2 2 1
CASE1
)"
if [ "$v" = "6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./memory.cpp.out << CASE2
1 1 1 2
CASE2
)"
if [ "$v" = "31" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./memory.cpp.out << CASE3
2 12 3 1
CASE3
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
