#!/bin/bash
g++ -Wall -Wextra "english.cpp" -o "english.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./english.cpp.out << CASE1
5208


CASE1
)"
if [ "$v" = "five thousand two hundred and eight

" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./english.cpp.out << CASE2
5280
CASE2
)"
if [ "$v" = "five thousand two hundred eighty" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./english.cpp.out << CASE3
5000
CASE3
)"
if [ "$v" = "five thousand" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./english.cpp.out << CASE4
5028
CASE4
)"
if [ "$v" = "five thousand and twenty eight
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
