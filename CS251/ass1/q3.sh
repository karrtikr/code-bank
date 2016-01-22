#!/bin/bash

sum=0
count=0
while read num;
do
    let sum=sum+num;
    let count=count+1;
done < $1
let sum=sum+num;
RESULT=$(echo "scale=2; $sum/$count" | bc -l)
echo $RESULT
