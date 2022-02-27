#!/bin/bash
g++ -Wall -Wextra "digsum.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
30
4
CASE1
)"
if [ "$v" = "6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./a.out << CASE2
1000000009
1
CASE2
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./a.out << CASE3
98765432109876543210
58
CASE3
)"
if [ "$v" = "635270834" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
