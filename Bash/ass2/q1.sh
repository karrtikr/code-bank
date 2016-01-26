#!/bin/bash

if [ "$(grep '*' <(cat 1.txt | cut -d, -f 5-))" == '*' ] || [ "$(grep 'F' <(cat 1.txt | cut -d, -f 5-))" == 'F' ]; then
	echo "yes";
fi
