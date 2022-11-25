#!/bin/bash
g++ -Wall -Wextra "neko.cpp" -o "neko.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./neko.cpp.out << CASE1
6 10
CASE1
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./neko.cpp.out << CASE2
21 31
CASE2
)"
if [ "$v" = "9" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./neko.cpp.out << CASE3
5 10
CASE3
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
