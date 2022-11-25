#!/bin/bash
g++ -Wall -Wextra "mmin.cpp" -o "mmin.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./mmin.cpp.out << CASE1
6 2
7 8 1 4 3 2

CASE1
)"
if [ "$v" = "0
7
7
1
1
3 
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
