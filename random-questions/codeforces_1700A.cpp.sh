#!/bin/bash
g++ -Wall -Wextra "codeforces_1700A.cpp" -o "codeforces_1700A.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1700A.cpp.out << CASE1
7
1 1
2 3
3 2
7 1
1 10
5 5
10000 10000
CASE1
)"
if [ "$v" = "1
12
13
28
55
85
500099995000" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
