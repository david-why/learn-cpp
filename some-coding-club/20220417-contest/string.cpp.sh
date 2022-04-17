#!/bin/bash
g++ -Wall -Wextra "string.cpp" -o "string.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./string.cpp.out << CASE1
3
aabce
ace
abacaba
aax
ty
yyt
CASE1
)"
if [ "$v" = "1
-1
3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
