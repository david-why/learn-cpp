#!/bin/bash
g++ -Wall -Wextra "codeforces_1665D.cpp" -o "codeforces_1665D.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1665D.cpp.out << CASE1
2

1

8


1
CASE1
)"
if [ "$v" = "? 1 2

? 12 4

! 4
? 2000000000 1999999999

! 1000000000" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
