
# Simple Shell Project

The Simple Shell Project is a command line interpreter that mimics basic functionalities of the Unix shell. It reads user commands, executes them, and displays their outputs. This project was developed as part of the curriculum at Holberton School.


## Table of contents
* [Introduction](#Introduction)
* [Synopsis](#Synopsis)
* [Project](#Project)
* [Compilation](#Compilation)
* [Authors](#Authors)

## Introduction

 A shell is a software element that serves as a crucial interface between users and the operation system, allowing commands to be translated into machine-executable instructions.


## Synopsis
The Simple Shell Project involves building a Unix shell, serving as an interactive command line interpreter. This shell facilitates user interactions with the operating system by enabling the execution of commands and management of processes.

This project focuses on comprehending the core aspects of a shell, encompassing process IDs (PID) and parent process IDs (PPID) significance, process environment management, differentiation between functions and system calls, process creation, utilization of the PATH variable, execution of programs via the execve system call, pausing processes until child termination, and understanding the concept of "end-of-file" (EOF). Code development will follow strict coding standards, prioritizing proper formatting, memory leak prevention, and efficient system call utilization.


## Project


### Project Requirements

* Successful code compilation using provided compilation command.
- - - -
* Operational interactive mode allowing user input and output.
- - - -
* Functional non-interactive mode for command execution from external sources.
- - - -
* Accurate parsing and execution of external and built-in commands.
----
* Correct representation of command execution output.
- - - -
* Graceful error handling with informative error messages.
- - - -
* Code adherence to specified coding style (Betty style).
----
* Avoidance of memory leaks.
- - - - 
* Use of allowed functions and system calls as per project guidelines.
----
* Well-organized GitHub repository for the project.
----
* Inclusion of a README.md file with comprehensive project details and instructions.
----
* Rigorous testing of shell functionalities for correctness.
----




###    The Simple Shell Project consists of several files, each serving a specific role in the implementation of the Unix shell. Below is a brief description of the key files in this project:

FIle          | Description
------------- | -------------
simple_shell.c  | Contains code for a basic command-line interface that allows users to input commands, executes them by creating child processes, handles command execution, and includes functionalities such as searching for commands in the PATH, tokenization of input, and error handling.
execute.c  | Contains code responsible for executing commands, including searching for commands in the system's PATH, forking a child process to run the command, waiting for the child process to complete, and handling error conditions.
tokenization.c | contains code for breaking down a string into smaller substrings (tokens) using a specified delimiter, storing these tokens in an array, and providing functionalities for working with the tokenized data.
path.c | contains code for a function called path that extracts and returns the PATH environment variable from an array of environment variables by tokenizing it and handling memory management.
manpage simple_shell |  This file contains the manual page for the simple shell. It outlines the usage, options, and syntax of the shell for users who seek a comprehensive reference.|

## Compilation
To compile the Simple Shell Project files:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## Usage

### Interactive Mode
*Example*

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

### Non-Interactive Mode
*Example*

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $

## Authors

This Simple Shell project was created by @ControlYourPotatoes and @jennifferfeliciano as part of a C programming project at Holberton School, San Juan.

