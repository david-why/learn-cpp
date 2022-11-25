#!/bin/bash
g++ -Wall -Wextra "gray.cpp" -o "gray.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./gray.cpp.out << CASE1
2 3
CASE1
)"
if [ "$v" = "10" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./gray.cpp.out << CASE2
3 5
CASE2
)"
if [ "$v" = "111" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./gray.cpp.out << CASE3
44 1145141919810
CASE3
)"
if [ "$v" = "00011000111111010000001001001000000001100011" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
