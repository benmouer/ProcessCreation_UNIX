NAME: Benjamin Mouer

The purpose of this lab/program is to understand how to use the fork() function to create child processes. It also describes how to specify which process should do what in terms of manipulating the shared variable of a file pointer and file. 

My program first reads the input and handles any I/O exceptions. Then I define a buffer to store the line read, a pid int variable, a ssize_t variable to store the amount of chars in a line, and a long “size” to store the size of the line read. Then I fork() and if the process running is the child process, then I print the child pid, which is 0, and print the line read until there are no more lines to read. I do the same when I specify the parent process except I print the parent pid which can be found using the getpid() function. Then after the child and parent have read every line until EOF, I use a wait() call to ensure my program allows both the child and parent to fully execute before I close the file. Then, I close my file and exit the program.




