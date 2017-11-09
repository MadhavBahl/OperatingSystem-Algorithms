#!/bin/bash 

# Author : Madhav Bahl
# github : https://github.com/MadhavBahlMD
# Script follows here:

read -p "Please enter a number: " n
echo "You just entered: $n"
echo "Now we count from 1 to $n"
for((i=1;i<=n;i++))
{
    if [ $i != $n ];
    then
        echo "$i"
        echo "|"
    else
        echo "$i"
    fi
}
echo "Thanks"
read -p "What is your name?" name
echo " a. Hello"
echo " b. Good morning"
echo " c. Good night"
echo " d. Bye"

read -p "Enter a choice: " ch

case "$ch" in 
    "a") echo "Hello, $name"
    ;;
    "b") echo "Good morning, $name"
    ;;
    "c") echo "Good night, $name"
    ;;
    "d") echo "Bye, $name"
    ;;
    *) echo "YOU REBEL!!!!!"
    ;;
esac