#!/bin/bash
paste -d, <(cut -d, -f1,2,4 $1) <(cut -d, -f2,3 $2) > output.txt