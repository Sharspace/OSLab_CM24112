
#!/bin/bash

echo "Enter number:"
read n

a=1
b=1

echo "Fibonacci Series:"
echo "$a"
echo "$b"

for (( i=3; i<=n; i++ ))
do
    c=$((a + b))
    echo "$c"
    a=$b
    b=$c
done

