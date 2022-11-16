#!/bin/sh

filepath=$1
filename=$(basename $1 .calc)
path=$(dirname $1)

./calc3i.exe < $filepath > $filename.s

rm -f $filenarmme.s $filename

echo "
.data
formatString:
	.string	\"Number :%d\n\"
vars:
	.zero	2048
isInReg:
	.zero	2048

.text
.global	main		
    
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	\$16, %rsp" | cat - $filename.s > temp && mv temp $filename.s

echo -e "	leave
	ret\n" >> $filename.s

gcc -c $filename.s 
gcc -no-pie $filename.o ./library_functions/lib/calc_lib.a -o $path/$filename
rm $filename.o
