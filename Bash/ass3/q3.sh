#!/bin/bash
f=$1
awk 'BEGIN{FS=","}{for(i=NF;i>1;i--){printf("%s,",$i);}printf("%s\n",$1);}' $f