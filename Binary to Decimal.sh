#!/bin/bash

echo -n -e "Enter a binary no:"
read num
bin=$num
dec=0
base=1

while [ $num -gt 0 ]
do
rem=`expr $num % 10`
dec=`expr $dec + $rem \* $base`
num=`expr $num / 10`
base=`expr $base \* 2`
done
echo "Binary num is $bin"
echo "Decimal num is $dec"
