#!/bin/bash

echo "1. Create File"
echo "2. Write to File"
echo "3. Append to File"
echo "4. Delete File"
echo "Enter choice:"
read ch

echo "Enter filename:"
read fname

case $ch in
1) touch $fname ;;
2) echo "Enter content:"; read text; echo $text > $fname ;;
3) echo "Enter content:"; read text; echo $text >> $fname ;;
4) rm $fname ;;
*) echo "Invalid choice" ;;
esac
