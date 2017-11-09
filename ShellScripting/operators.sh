#!/bin/bash 

# Author : Madhav Bahl
# github : https://github.com/MadhavBahlMD
# Script follows here:

# Arithatic operators

val=`expr 2 + 2`
echo "2+2=$val"
read -p "Enter the value of a: " a
read -p "Enter the value of b: " b 
c=`expr $a + $b`
echo "a+b=$c"

read -p "Enter the value of x: " x
read -p "Enter the value of y: " y
c=$(( x-y ))
echo "x-y=$c"

# Relational operators

echo "Truth value for 10 == 10 is: $[ 10 == 10 ]"
echo "Truth value for 12 <= 10 is: $[ 12 <= 10 ]"
