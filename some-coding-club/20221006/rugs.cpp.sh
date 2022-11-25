#!/bin/bash
g++ -Wall -Wextra "rugs.cpp" -o "rugs.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./rugs.cpp.out << CASE1
5 4 3
1 2 10
1 3 9
2 3 7
4 5 3
CASE1
)"
if [ "$v" = "22" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
