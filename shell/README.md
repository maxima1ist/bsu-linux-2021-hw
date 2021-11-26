# write an analogue of Bash (custom Shell)
Problem description:  

Each line entered by the user is read, spaced into an array, and executed by execve in the child process. Then the next command is read, etc.
<br/>
There must be an "exit" builtin command to exit the program.
<br/>
Use dynamic libraries ("lib*.so", "-shared").
<br/>
Building a program using a Makefile.
<br/>
Redirecting the output of a program to a file (from a file) using open and dup2.
