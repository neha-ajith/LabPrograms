#!/bin/bash
 echo -n -e "Enter decimal number: "
 read num
arr=0
for(( i=0;$num>0;i++ ))
do
arr[i]=`expr $num % 2`
num=`expr $num / 2`
done
for(( i=i-1;i>=0;i-- ))
do
echo ${arr[i]}
done
