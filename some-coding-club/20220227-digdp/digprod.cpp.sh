#!/bin/bash
g++ -Wall -Wextra "digprod.cpp" -o "digprod.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./digprod.cpp.out << CASE1
13 2
CASE1
)"
if [ "$v" = "5" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./digprod.cpp.out << CASE2
100 80
CASE2
)"
if [ "$v" = "99" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./digprod.cpp.out << CASE3
1000000000000000000 1000000000
CASE3
)"
if [ "$v" = "841103275147365677" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
