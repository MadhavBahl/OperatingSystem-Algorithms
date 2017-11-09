#!/bin/bash 

# Author : Madhav Bahl
# github : https://github.com/MadhavBahlMD
# Script follows here:

name="Madhav Bahl"
readonly name
echo "Hello, $name"
# name="xyz"    ---- This will throw an error
# echo "Hello, $name"
a=10
b=40
c=$a+$b
echo "$c"

# Arrays
NAME[0]="abc"
NAME[1]="xyz"
NAME[2]="hello"
NAME[3]="man"
NAME[4]="daniel"
echo "First Index: ${NAME[0]}"
echo "Second Index: ${NAME[1]}"
echo "Third Index: ${NAME[2]}"
echo "Fourth Index: ${NAME[3]}"
echo "All names: ${NAME[*]}"

# echo $$ 
# This displays the process ID of current shell
