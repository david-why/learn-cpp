#!/bin/bash
g++ -Wall -Wextra "almzero.cpp" -o "almzero.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./almzero.cpp.out << CASE1
100
1
CASE1
)"
if [ "$v" = "19" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./almzero.cpp.out << CASE2
25
2
CASE2
)"
if [ "$v" = "14" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./almzero.cpp.out << CASE3
314159
2
CASE3
)"
if [ "$v" = "937" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./almzero.cpp.out << CASE4
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
3
CASE4
)"
if [ "$v" = "117879300" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
