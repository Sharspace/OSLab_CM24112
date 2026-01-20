#!/bin/bash

echo "1. Display Calendar"
echo "2. Display Date and Time"
echo "3. Display Logged in Users"
echo "4. Display Terminal Number"
echo "Enter choice:"
read ch

case $ch in
1) cal ;;
2) date ;;
3) who ;;
4) tty ;;
*) echo "Invalid choice" ;;
esac

