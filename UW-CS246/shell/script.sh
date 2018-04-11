#At the beginning we give the path to the shell

#!/bin/bash
#If not there then the shell which invoked this is used

#Arguments
# ${#} Number of args
# ${n} Nth arg - 0 is always the script
# ${@} / ${*} - all of them

cat demo.sh 
#!/bin/bash
if [ ${#} -lt 1 ] ; then
echo ${#}
echo "Wrong no. of args"
else
echo ${1}
fi

####
./demo.sh "Hello World"
Hello World

###
./demo.sh Hello World
Hello

#Shift N destructively shifts N left args

#Arithmetic 
#All variables are strings, so to do arithmetic we use $(())
var=3
square=$((${var}*${var}))

#Testing conditions
[ var1 -gt var2 ]
#can use logical operators
[ var1 -gt var2 -a var1 -gt var3 ]
#Code in conditons.sh

#-gt/-lt/-eq/-ne/-ge/-le
[ -f filename ] #isfile
# -d dir?
# -e exists?
# -s size is not 0?
# -x/-r/-w

#Case
#check case.sh

#Looping
while [[ condition ]]; do
	#statements
done

for (( i = 0; i < 10; i++ )); do
	#statements
done