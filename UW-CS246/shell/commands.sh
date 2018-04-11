#CD
cd directory/subdir
cd ~
cd .
cd ..
cd - #Toggles between current and last

history N
#returns a numbered list of last N commands
# !N runs the Nth command
# !xyz matches the command

type (csh which)
#tells how the command is interpretted

time ./myprog
# real	0m7.896s	-- actual wall clock time accounted with interleaves
# user	0m4.521s	-- CPU time used during a program run
# sys	0m1.029s	-- CPU time used actually executing the program

sh/csh/bash/tcsh
#runs subshell

#Globbing
#Wildcards
*	0-more
+	1/more
?	1
[...]	Match at least one char 
{...,...,...} Match at least one of them
[a-zA-Z]	Ranges
Hidden files dont match unless
.[!.]


#Find
find [directory] [expr] -name(restricts the Globbing to the name) -type


#egrep
egrep -flag expr file-list
# -i ignore case
# -r use recursive
# -n return numbers of list
# -v invert the egrep (pic opposite)

# I/O redirection
3 std files 0,stdin 1,stdout 2,stderr
./a < infile > output 2>&1 #stderr goes to output
./a < infile 2>&1 1>output #stderr goes to stdout, stdout goes to output

