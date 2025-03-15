# pipex
Redirections and pipes

# NOTES

- perror: stdio.h | print a system error message.

- strerror: string.h | return string describing error number.

- access: unistd.h | check user's permissions for a file.

- dup: unistd.h | creates a copy of the file descriptor, using the lowest-numbered unused file descriptor for the new descriptor.

- dup2: unistd.h | performs the same as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the specified file descriptor number.

- execve: unistd.h | execute program.

- fork: sys/types.h, unistd.h | creates a new process by duplicating the calling process.

- pipe: unistd.h | creates a pipe, a unidirectional data channel that can be used for interprocess communication.

- unlink: unistd.h, fcntl.h |  delete a name and possibly the file it refers to.

- wait sys/types.h, sys/wait.h | suspends execution of the calling thread until one of its children terminates.

- waitpid sys/types.h, sys/wait.h | suspends execution of the calling thread until a child specified by pid argument has changed state.

# MAIN FLOW

"open": get FD of infile, if outfile exists, get FD of outfile, else crete outfile and get FD.

"access": check file permissions.

[...]

(I forgot to updated it💀)
