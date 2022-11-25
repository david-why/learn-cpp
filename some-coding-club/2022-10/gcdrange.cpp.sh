#!/bin/bash
g++ -Wall -Wextra "gcdrange.cpp" -o "gcdrange.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./gcdrange.cpp.out << CASE1
5 3
4 12 3 6 7
1 3
2 3
5 5

CASE1
)"
if [ "$v" = "1
3
7
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
