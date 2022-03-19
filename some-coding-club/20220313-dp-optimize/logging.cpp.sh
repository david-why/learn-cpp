#!/bin/bash
g++ -Wall -Wextra "logging.cpp" -o "logging.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./logging.cpp.out << CASE1
5
1 2 3 4 5
5 4 3 2 0
CASE1
)"
if [ "$v" = "25" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./logging.cpp.out << CASE2
6
1 2 3 10 20 30
6 5 4 3 2 0
CASE2
)"
if [ "$v" = "138" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
