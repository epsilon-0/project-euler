#!/bin/bash
mkdir $1
mFile="$1/$1.py"
echo "numTests = int(input())" >> $mFile
echo "" >> $mFile
echo "for tt in range(numTests):" >> $mFile
echo "  " >> $mFile
touch "$1/$1.in"
touch "$1/$1.ok"
touch "$1/$1.out"
