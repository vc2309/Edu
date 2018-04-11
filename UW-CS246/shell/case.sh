if [ ${#} -lt 1 ] ; then
echo ${#}
echo "Wrong no. of args"
else
case ${#} in 
	"2" ) echo ${#} args;;
	"3"	) echo ${#} args;;
esac
fi