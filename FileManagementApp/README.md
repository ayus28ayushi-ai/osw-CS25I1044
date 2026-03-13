# File Manager in C

## Overview
This project is a simple file manager program written in C. 

## Features

The program supports the following operations.

1. Create Folder  
Creates one or more folders in the current directory.

2. Create Nested Folder / File  
Creates a file or folder inside another existing folder.

3. Create File  
Creates new files in the current directory.

4. List Directory Contents  
Shows all files and folders present in the current directory.

5. Show Current Directory  
Displays the current working directory path.

6. Change Directory  
Allows the user to move into another folder.

7. Delete File / Folder  
Deletes a file or folder from the directory. (Only empty folders can be deleted.)

8. Rename File / Folder  
Renames an existing file or folder.

9. Copy File  
Copies the contents of one file into another file.

10. Move File  
Moves a file by renaming it to another location.

11. File Information  
Shows information about a file like its size, location and last modified time.

## Technologies Used

- C Programming Language
- Basic C libraries
- Some system functions for working with files and directories

## Important Libraries Used

stdio.h – input and output functions  
dirent.h – directory handling  
sys/stat.h – getting file details  
unistd.h – directory navigation  
time.h – time and date formatting

## Project Structure
 
main.c – contains the main menu and program loop  
function.c – contains all the functions for file operations  
function.h – contains function declarations

## Program Menu

-------USER MENU-----------
1. Create Folder
2. Create Nested Folder
3. Create File
4. List Directory Contents
5. Show Current Directory
6. Change Directory
7. Delete File/Folder
8. Rename File/Folder
9. Copy File
10. Move File
11. File Info
0. Exit

## How to Compile and Run

Step 1: First go inside FileManagementApp 
  cd FileManagementApp

Step 2: gcc main.c function.c -o app
       
        ./app

 
## Limitations

- Non empty folders cannot be deleted
- File copy is done character by character
- The program assumes correct user input

## Learning Outcomes

From this project I learned:

- Basic file handling in C
- Working with directories
- Using system functions for file operations
- Organizing code using multiple files

## Author

Ayushi Singh  
CS25I1044
CSE Student  
IIITDM Kanchipuram
