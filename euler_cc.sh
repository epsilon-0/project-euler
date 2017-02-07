#!/bin/bash
mkdir $1
mFile="$1/$1.cc"
echo "#include <bits/stdc++.h>" >> $mFile
echo "" >> $mFile
echo "using namespace std;" >> $mFile
echo "" >> $mFile
echo "int main() {" >> $mFile
echo "" >> $mFile
echo "}" >> $mFile
touch "$1/$1.in"
touch "$1/$1.ok"
touch "$1/$1.out"
