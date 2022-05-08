#!/bin/bash
g++ -Wall -Wextra "dicesum.cpp" -o "dicesum.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./dicesum.cpp.out << CASE1
2 3 4
CASE1
)"
if [ "$v" = "6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./dicesum.cpp.out << CASE2
31 41 592
CASE2
)"
if [ "$v" = "798416518" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
