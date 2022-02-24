#!/bin/bash
g++ -Wall -Wextra "rudolf.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
5
01011
11001
CASE1
)"
if [ "$v" = "5
01011
11001" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./a.out << CASE2
5
01011
11001
CASE2
)"
if [ "$v" = "5
01011
11001" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
