#!/bin/bash

# compile
g++ $1.cc -o $1 -O2 -Wall -Wextra -std=gnu++0x || exit

# check time
time ./$1 < $1.in > $1.out 

# if they differ then output difference
diff -q $1.out $1.ok || diff -y $1.out $1.ok