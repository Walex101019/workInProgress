# Simple Shell

Simple Shell is a minimalistic Unix-like command-line interpreter implemented in C. 
It provides basic command execution and built-in functionality.

## Features

- Execute external commands.
- Implement built-in shell commands like `cd`, `env`, `exit`, and more.
- Handle environment variables.
- Define and manage aliases.
- Handle logical operators (`&&` and `||`).
- Support variable replacement (e.g., `$?` and `$$`).
- Process comments (lines starting with `#`).

## Usage

To compile and run Simple Shell, follow these steps:

1. Clone the repository:
   git clone https://github.com/walex101019/simple_shell.git
   cd simple-shell

2. Compile the shell:
   gcc -Wall -Werro -Wextra -pedantic *.c -o simple_shell

3. Run the shell:
   ./simple_shell


## Built-In Commands

The following built-in commands are supported:

cd [DIRECTORY]: 		Change the current directory.

env: 				Display the current environment.

exit [STATUS]: 			Exit the shell with an optional status code.

setenv VARIABLE VALUE: 		Initialize or modify an environment variable.

unsetenv VARIABLE: 		Remove an environment variable.

alias [name[='value'] ...]: 	Define and manage aliases.

alias name [name2 ...]: 	Display aliases.

?: 				Display the exit status of the last command.

$$: 				Display the shell's process ID.

 #:				comment
