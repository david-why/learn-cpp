#!/bin/bash
g++ -Wall -Wextra "pa.cpp" -o "pa.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./pa.cpp.out << CASE1
2
4059 -1782

CASE1
)"
if [ "$v" = "99" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
