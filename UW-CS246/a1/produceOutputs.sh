#!bin/bash
if [ "$# -lt 2" ]
	then
	echo "incorrect no. of args" >&2
	exit
fi
f=$1
prog=$2
names=`cat $f`
for filename in names
do
	infile="$filename.args"
	outfile="$filename.out"
./$prog < $infile > $outfile
done
