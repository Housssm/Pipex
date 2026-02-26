*This project has been created as part of the 42 curriculum by **hoel-har**.*

## Description

Pipex is a project that aims to reproduce the behavior of the shell pipe mechanism in C. The goal is to replicate the functionality of the following shell command: < file1 cmd1 | cmd2 > file2
The program reads from an input file (`file1`), passes the output of `cmd1` as input to `cmd2` through a pipe, and writes the final result into an output file (`file2`).

As a bonus, the project also handles:
- **Multiple pipes**: chaining an arbitrary number of commands (`cmd1 | cmd2 | cmd3 ... | cmdn`).
- **Here_doc**: reproducing the behavior of the `<<` (heredoc) and `>>` (append) shell operators.

## Instructions

### Execution

**Mandatory usage (2 commands):**

./pipex file1 "cmd1" "cmd2" file2

Equivalent to: `< file1 cmd1 | cmd2 > file2`

**Examples:**

./pipex infile "ls -l" "wc -l" outfile
./pipex infile "grep a1" "wc -w" outfile

**Bonus — Multiple pipes:**

./pipex file1 "cmd1" "cmd2" "cmd3" ... "cmdn" file2

Equivalent to: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

**Bonus — Here_doc:**

./pipex here_doc LIMITER "cmd" "cmd1" file

Equivalent to: `cmd << LIMITER | cmd1 >> file`

## Resources

- **[CodeVault — Unix Processes in C (YouTube)](https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=nLRgE17Fk33p6UJN)**: Video series that helped me understand the overall functioning of `pipe`, `fork`, `dup2`, `execve`, and other system calls used in this project.
- **[Developpez.net](https://www.developpez.net/)**: French developer forum used to find answers to more specific and complex situations not covered by the general approach of the video tutorials.