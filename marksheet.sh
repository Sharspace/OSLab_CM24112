#!/bin/bash

echo "Enter Student Name:"
read name

echo "Enter marks of Subject 1:"
read m1
echo "Enter marks of Subject 2:"
read m2
echo "Enter marks of Subject 3:"
read m3

total=$((m1 + m2 + m3))
percentage=$((total / 3))

echo "------------------------"
echo "Student Name: $name"
echo "Total Marks: $total"
echo "Percentage: $percentage%"

if [ $percentage -ge 60 ]
then
    echo "Class: First Class"
elif [ $percentage -ge 50 ]
then
    echo "Class: Second Class"
elif [ $percentage -ge 40 ]
then
    echo "Class: Pass"
else
    echo "Class: Fail"
fi


