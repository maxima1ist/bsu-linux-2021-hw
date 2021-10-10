#!/bin/bash

gcc main.c -o main
./main -n 3 --descriptor 2 "smth"

#strace ./main -n 3 --descriptor 2 "smth" > /dev/null