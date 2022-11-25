#!/bin/bash
g++ -Wall -Wextra "three.cpp" -o "three.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./three.cpp.out << CASE1
6 
5 28 16 29 27 
23 3 20 1 
8 32 26 
33 11 
12 

CASE1
)"
if [ "$v" = "1
32

" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./three.cpp.out << CASE2
8 
42 24 10 29 27 12 58 
31 8 16 26 80 6 
25 3 36 11 5 
33 20 17 13 
15 77 9 
4 50 
19 
CASE2
)"
if [ "$v" = "1
77" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
