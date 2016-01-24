#!/bin/bash

if [ "$(grep '*' <(cat 1.csv| cut -d, -f 5-))" == '*' ] || [ "$(grep 'F' <(cat 1.csv | cut -d, -f 5-))" == 'F' ]; then
      sed -i -e 's/C$/Average/g' 1.csv
      sed -i -e 's/B$/Average/g' 1.csv
      sed -i -e 's/*$/Good/g' 1.csv
      sed -i -e 's/A$/Good/g' 1.csv
      sed -i -e 's/D$/Poor/g' 1.csv
      sed -i -e 's/F$/Fail/g' 1.csv
fi