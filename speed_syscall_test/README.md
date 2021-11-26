# speed measurement of syscall
Problem description:  

Write a program that compares the speed of a simple system call to the speed of some non-system call operation.
<br/>
Both are supposed to run in a cycle with a large number of repetitions for more accurate timing.
<br/>
Use [gettimeofday(2)](https://man7.org/linux/man-pages/man2/settimeofday.2.html) to measure time within a program.
<br/>
P.S. Compared syscall [write(2)](https://www.man7.org/linux/man-pages/man2/write.2.html) with string reversing defined size.
