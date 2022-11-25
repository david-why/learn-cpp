#!/bin/bash
g++ -Wall -Wextra "info.cpp" -o "info.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./info.cpp.out << CASE1
5
2 4 2 3 1
CASE1
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
