# create child process using fork syscall
Problem description:  

Write a program to demonstrate the use of the system calls [fork(2)](https://man7.org/linux/man-pages/man2/fork.2.html), [wait(2)](https://man7.org/linux/man-pages/man2/wait.2.html), [getpid(2)](https://man7.org/linux/man-pages/man2/getpid.2.html), [getppid(2)](https://man7.org/linux/man-pages/man3/getppid.3p.html).
<ol>
  <li>Print the number of the current process and parent process.</li>
  <li>Make a fork call.</li>
  <li>Once again display the number of the current and parent process</li>
  <li>Additionally, output different lines from the child and from the parent process, given the return value from fork.</li>
  <li>In the parent process, wait for the child process to finish and print the return code.</li>
</ol>