# write an analogue of Bash (custom Shell)
Problem description:  

Write a program that, using the system calls [open(2)](https://man7.org/linux/man-pages/man2/open.2.html), [close(2)](https://man7.org/linux/man-pages/man2/close.2.html), [read(2)](https://man7.org/linux/man-pages/man2/read.2.html), [write(2)](https://man7.org/linux/man-pages/man2/write.2.html), and [lseek(2)](https://man7.org/linux/man-pages/man2/lseek.2.html), opens and swaps the contents of two files.
<br/>
Errors returned by system calls should be handled correctly. The code should take into account the possibility of "short reads / short writes".
<br/>
Change data in blocks.