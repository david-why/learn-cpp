#!/bin/bash
g++ -Wall -Wextra "parse.cpp" -o "parse.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./parse.cpp.out << CASE1
AC[3FUN]
CASE1
)"
if [ "$v" = "ACFUNFUNFUN" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
