#!/bin/bash
g++ -Wall -Wextra "subseq.cpp" -o "subseq.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./subseq.cpp.out << CASE1
5 2
1
2
3
5
4
CASE1
)"
if [ "$v" = "7" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
