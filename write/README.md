# syscall 'write'
Problem description:  
Write a command line utility demonstrating:
* The [write(2)](https://www.man7.org/linux/man-pages/man2/write.2.html) System Call;
* Working with command line arguments.

On normal startup, the program should print the string "Hello world" to the console.
<br/>
If you specify one positional argument, then the specified text should be displayed instead of "Hello, world".
<br/>
There should be a short command line option "-n", which specifies the number of repetitions of text output (default 1).
<br/>
There must also be a long command line option that specifies the file descriptor to output (default 1).
