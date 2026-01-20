#!/bin/bash

echo "Enter number:"
read n

count=0
num=2

while [ $count -lt $n ]
do
    flag=1
    for (( i=2; i<=num/2; i++ ))
    do
        if [ $((num % i)) -eq 0 ]
        then
            flag=0
            break
        fi
    done

    if [ $flag -eq 1 ]
    then
        echo $num
        count=$((count + 1))
    fi
    num=$((num + 1))
done


