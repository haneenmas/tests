#!/bin/bash

SHARED_LIB_COMP="gcc -shared -fPIC -o shared_rec.so shared_rec.c"
MAIN_COMP="gcc -no-pie -o main_rec.out main_rec.c /usr/lib/shared_rec.so -Wl,-zlazy"
PRF_CMD="./prf foo main_rec.out"
EXPECTED="PRF:: run #1 returned with 6\nPRF:: run #2 returned with 99"

echo "Compiling shared lib with \"$SHARED_LIB_COMP\""
$SHARED_LIB_COMP
echo "Moving shared_rec.so to /usr/lib"
sudo mv shared_rec.so /usr/lib

echo "Compiling program with \"$MAIN_COMP\""
$MAIN_COMP

echo "Testing with \"$PRF_CMD\""
output=$($PRF_CMD)
diff -q --strip-trailing-cr <(echo -e "$EXPECTED") <(echo -e "$output") >/dev/null 2>&1
diff_stat=$?

echo -e "OUTPUT:\n$output"
if  [[ $diff_stat -eq 0 ]]
then
  echo "PASSED"
else
  echo -e "FAILED - EXPECTED:\n$EXPECTED"
fi