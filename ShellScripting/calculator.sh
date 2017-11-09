#!/bin/bash 

# Author : Madhav Bahl
# github : https://github.com/MadhavBahlMD
# Script follows here:

echo "This is a simple calculator!"
read -p "Enter the number n1: " n1
read -p "Enter the number n1: " n2
echo " a. ADD"
add="ADD"
echo " b. SUBRACT"
sub="SUBTRACT"
echo " c. DIVIDE"
div="DIVIDE"
echo " d. MULTIPLY"
mult="MULTIPLY"
read -p "Please enter your choice: " ch

if [ $ch == "a" ];
then 
	echo "You chose '$ch' $add"
	echo "The sum is $(( n1+n2 ))"
elif [ $ch == "b" ];
then 
	echo "You chose '$ch' $sub"
	echo "The difference is $(( n1-n2 ))"
elif [ $ch == "c" ];
then 
	echo "You chose '$ch' $div"
	echo "The quotient is $(( n1/n2 ))"
elif [ $ch == "d" ];
then 
	echo "You chose '$ch' $mult"
	echo "The product is $(( n1*n2 ))"
else
    echo "Wrong Choice"
fi