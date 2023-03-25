# Double-Linked-List-For-Embedded-SW
Double Linked List implementation for Embedded SW

Description:
The use of dynamic memory allocation is not recommended in embedded SW 
(MISRA C++ 2008, 18-4-1 - Dynamic heap memory allocation shall not be used), 
so this implementation uses static memory allocation of all the available list items.

The double linked list is encapsulated in a static library.

An example application which implements a team member directory is included to provide info
of how the double linked list can be used.

Tools: 
 - Development environment: Visual Studio Code 
 - Build utility: GNU Make 
 - Compiler: G++/GCC 
 - Debugger: GDB

Instructions: 
Rename all vscode folders to .vscode

Note:
Tested on Linux Mint
