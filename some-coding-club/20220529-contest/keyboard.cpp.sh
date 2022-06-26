#!/bin/bash
g++ -Wall -Wextra "keyboard.cpp" -o "keyboard.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./keyboard.cpp.out << CASE1
5
ababa
codedoca
abcda
zxzytyz
abcdefghijklmnopqrstuvwxyza
CASE1
)"
if [ "$v" = "YES
bacdefghijklmnopqrstuvwxyz
YES
edocabfghijklmnpqrstuvwxyz
NO
YES
xzytabcdefghijklmnopqrsuvw
NO" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
