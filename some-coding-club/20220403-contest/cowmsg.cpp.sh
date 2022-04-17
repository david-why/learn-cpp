#!/bin/bash
g++ -Wall -Wextra "cowmsg.cpp" -o "cowmsg.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./cowmsg.cpp.out << CASE1
aaabb
CASE1
)"
if [ "$v" = "6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./cowmsg.cpp.out << CASE2
usaco
CASE2
)"
if [ "$v" = "1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./cowmsg.cpp.out << CASE3
lol
CASE3
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
