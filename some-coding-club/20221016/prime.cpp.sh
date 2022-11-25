#!/bin/bash
g++ -Wall -Wextra "prime.cpp" -o "prime.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./prime.cpp.out << CASE1
2 11
CASE1
)"
if [ "$v" = "5" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
