#!/bin/bash
g++ -Wall -Wextra "vardig.cpp" -o "vardig.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./vardig.cpp.out << CASE1
104
2
0 1
CASE1
)"
if [ "$v" = "520" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./vardig.cpp.out << CASE2
999
4
1 2 3 4
CASE2
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./vardig.cpp.out << CASE3
1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
5
0 2 4 6 8
CASE3
)"
if [ "$v" = "397365274" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
