#! /bin/bash

j=1
while [[ $j -le 10 ]]
do
echo "$j"
j=$(($j+1))
done
echo "The value of j is $j"
