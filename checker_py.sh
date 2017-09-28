#!/bin/bash

# run
time python3 $1.py < $1.in > $1.out || exit

# if they differ then output difference
diff -q $1.out $1.ok || diff -y $1.out $1.ok
