#!/bin/bash
files="`grep -o -E '\w+' $1 | sort -u -f`"
prog=$2
for f in $files
do
$prog "$(< $f.args)" > result.txt
if cmp -s result.txt $f.out
then
echo "Test passed: $f"
else
echo "Test failed: $f"
echo "Args:" 
cat $f.args
echo "Expected:"
cat $f.out
echo "Actual:"
cat result.txt
fi
rm result.txt
done