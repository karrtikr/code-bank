#!/bin/bash
f=$1
val=$2
cat $f | awk 'BEGIN{count=1}{s=$0; if(count%val!=0){printf("%s\t",s);}else{printf("%s\n",s);}count+=1;}' val=$val > file2.csv