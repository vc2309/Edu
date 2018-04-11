#!/bin/bash
if [ ${#} -lt 1 ] ; then
echo ${#}
echo "Wrong no. of args"
elif [ ${1} -gt 2 -a ${1} -gt 3 ]; then
echo "Condition satisfied"
else
	var=$((${1}*2*3))
if [ $var != "4" ]; then
echo "just testing"
fi
fi
