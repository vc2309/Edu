#!/bin/bash
if [ ${#} -lt 1 ] ; then
echo ${#}
echo "Wrong no. of args"
else
mult=$((${1}*2*2*2))
echo $mult
mult=$((${mult}*${mult}))
echo $mult
fi
