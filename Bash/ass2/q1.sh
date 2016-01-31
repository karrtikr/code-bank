#!/bin/bash

if [ "$(grep '*' <(cat 1.csv | cut -d, -f 5-))" == '*' ] || [ "$(grep 'F' <(cat 1.csv | cut -d, -f 5-))" == 'F' ]; then
	echo "yes";
fi
