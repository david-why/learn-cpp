#!/bin/bash
g++ -Wall -Wextra "palin.cpp" -o "palin.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./palin.cpp.out << CASE1
44
CASE1
)"
if [ "$v" = "55" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
