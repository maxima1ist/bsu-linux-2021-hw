all: main

Runner.o: Makefile Runner.h Runner.c
	gcc Runner.c -c -o Runner.o

# dynamic library
libRunner.so: Runner.o
	gcc -shared Runner.o -o libRunner.so

main.o: Makefile main.c Runner.h
	gcc main.c -c -o main.o

main: main.o libRunner.so
	gcc main.o -L. -lRunner -Wl,-rpath -Wl,'$$ORIGIN' -o main
