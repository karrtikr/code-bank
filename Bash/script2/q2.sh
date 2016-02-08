#!/bin/bash
e=0
a=0
b=0
c=0
d=0
f=0

while IFS= read -r LINE || [[ -n "$LINE" ]]; do
      if [ "$LINE" == '*' ]; then
      	let e=e+1
      elif [ "$LINE" == 'A' ]; then
      	let a=a+1
      elif [ "$LINE" == 'B' ]; then
      	let b=b+1
      elif [ "$LINE" == 'C' ]; then
      	let c=c+1
      elif [ "$LINE" == 'D' ]; then
      	let d=d+1
      elif [ "$LINE" == 'F' ]; then
      	let f=f+1
      fi

done < <(cat 1.csv | cut -d, -f 5-)

echo "*: $e"
echo "A: $a"
echo "B: $b"
echo "C: $c"
echo "D: $d"
echo "F: $f"
