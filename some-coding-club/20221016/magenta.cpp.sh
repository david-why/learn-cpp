#!/bin/bash
g++ -Wall -Wextra "magenta.cpp" -o "magenta.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./magenta.cpp.out << CASE1
5 7
2 2 3 4 5
2 1 5
1 3 -3
2 1 5
2 3 3
1 1 100000
1 2 100000
2 1 2
CASE1
)"
if [ "$v" = "240
20
1
Too large" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
