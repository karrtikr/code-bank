#!/bin/bash
count=0
cat $1 | awk '{ sum+=$1; count+=1} END {printf("%.2f\n",sum/count);}'