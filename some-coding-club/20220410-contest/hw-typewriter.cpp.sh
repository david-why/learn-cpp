#!/bin/bash
g++ -Wall -Wextra "hw-typewriter.cpp" -o "hw-typewriter.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./hw-typewriter.cpp.out << CASE1
2 2
ab
ac
CASE1
)"
if [ "$v" = "7" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./hw-typewriter.cpp.out << CASE2
4 3
abcdefg
hijklmnop
qrstuv
wxyz
CASE2
)"
if [ "$v" = "1352" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./hw-typewriter.cpp.out << CASE3
5 1000000000
abc
acde
cefg
abcfh
dghi
CASE3
)"
if [ "$v" = "346462871" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
