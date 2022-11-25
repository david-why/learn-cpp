#!/bin/bash
g++ -Wall -Wextra "list.cpp" -o "list.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./list.cpp.out << CASE1
  3 100
CASE1
)"
if [ "$v" = "981" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
