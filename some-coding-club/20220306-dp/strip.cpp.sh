#!/bin/bash
g++ -Wall -Wextra "strip.cpp" -o "strip.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./strip.cpp.out << CASE1
3 998244353
CASE1
)"
if [ "$v" = "5" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./strip.cpp.out << CASE2
5 998244353
CASE2
)"
if [ "$v" = "25" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./strip.cpp.out << CASE3
42 998244353
CASE3
)"
if [ "$v" = "793019428" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
