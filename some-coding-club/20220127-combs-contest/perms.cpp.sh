#!/bin/bash
g++ -Wall -Wextra "perms.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
3
1 1
2 2
3 1
CASE1
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./a.out << CASE2
4
2 3
2 2
2 1
2 4
CASE2
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./a.out << CASE3
3
1 1
1 1
2 3
CASE3
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
