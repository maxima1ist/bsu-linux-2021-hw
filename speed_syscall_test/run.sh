#!/bin/bash

gcc syscalls.c -o syscalls
gcc nonsyscalls.c -o nonsyscalls

for i in {1..10}
do
	echo 'test '${i}
	./syscalls
	./nonsyscalls
	echo $'\n'
done