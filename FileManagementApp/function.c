#include<stdio.h>
#include<dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

//user manual function
void menu(){
    printf("-------USER MENU-----------\n");
    printf("1. Create Folder\n");
    printf("2. Create Nested Folder\n");
    printf("3. Create file\n");
    printf("4. List Directory Contents\n");
    printf("5. Show Current Directory\n");
    printf("6. Change Directory\n");
    printf("7. Delete File/Folder\n");
    printf("8. Rename File/Folder\n");
    printf("9. Copy file\n");
    printf("10. Move File\n");
    printf("11. File Info\n");
    printf("0. Exit\n\n");
}

//create folder function
void createFolder(){
    char folder_name[100];
    int noOfFolders;

    printf("How many folders you want to create:");
    scanf("%d", &noOfFolders);

for(int i=0 ; i<noOfFolders ; i++){
    printf("Enter folder %d name:", i+1);
    scanf("%s", folder_name);

    if(mkdir(folder_name, 0777) == 0){
        printf("%s created successfully!\n", folder_name);
    }
    else{
        printf("ERROR! could not create the folder!\n");
        return;
    }
}
}


//create nested folder/file function
void createNestedItem(){
    char parent_folder[100], child[100];
    int choice;
    // store the current directory so we can return after creating nested item
    char original_dir[100];
    getcwd(original_dir, sizeof(original_dir));
 
    printf("Enter parent folder:");
    scanf("%s", parent_folder);

    printf("To have a child Folder:1\nTo have a child File:2\n");
    printf("Enter choice:");
    scanf("%d", &choice);

    printf("Enter name:");
    scanf("%s", child);

    if(chdir(parent_folder) == 0){

        if(choice == 1){
           mkdir(child, 0777); 
        }
       
        if(choice == 2){
             FILE *f = fopen(child, "w");
            if(f != NULL){
                fclose(f);
            }
        }

    chdir(original_dir);
    printf("Nested Item created successfully!\n");
    }
    else{
        printf("This parent folder DOES NOT exist!\nTip: Try ../folder1 while entering parent folder if folder 1 is already nested inside some folder");
         return;
    }
}

//create file function
void createFile(){
    char file_name[100];
    int noOfFiles;
     FILE *f;

    printf("How many files to create:");
    scanf("%d", &noOfFiles);
 
    for(int i=0 ; i<noOfFiles ; i++){
    printf("Enter file name:");
    scanf("%s", file_name);

    f = fopen(file_name, "w");

    if(f != NULL){
        printf("%s created successfully!\n", file_name);
        fclose(f);
    }
    else{
        printf("ERROR! could not create the file!\n");
        return;
    }
}
}


//show directory function
void showDirectory(){
    
    DIR *d = opendir(".");

    if(d == NULL){
        printf("ERROR! cannot open directory!\n");
        return;
    }

    struct dirent *temp = NULL;
    while((temp = readdir(d)) != NULL){
        printf("%s\n", temp->d_name);
    }
    closedir(d);
}


//print working directory function
void showPWD (){
    char path[2000];

    getcwd(path, sizeof(path));

    printf("Current Directory:%s\n", path);
}

//change directory function
void changeDirectory(){
    char directory_name[100];

    printf("Enter the directory name:");
    scanf("%s", directory_name);

    if(chdir(directory_name) == 0){
        printf("Directory changed successfully!\n");
    }
    else{
        printf("ERROR! could not change directory\n");
        return;
    }
}


//delete file/folder function
void deleteItem(){
    char item_name[100];

    printf("Enter file/folder to delete:");
    scanf("%s", item_name);

    if(remove(item_name) == 0){
        printf("Item deleted successfully!\n");
    }
    else{
        printf("ERROR! could not delete the item!\n");
        printf("Tip: You can't delete a non-empty folder.\n  Try going ../ if the item in nested in some folder\n");
        return;
    }
}


//rename file/folder function
//OS treats moving a file as renaming so we will call the same function for both
int renameItem(){
    char old_item[100], new_item[100];

    printf("Enter the item to rename:");
    scanf("%s", old_item);

    printf("Enter the new name:");
    scanf("%s", new_item);

    if(rename(old_item, new_item) == 0){
       return 1;
    }
    else{
       return 0;
    }
}


//copy file function
void copyFile(){
    FILE *f1, *f2;
    char src[100], destn[100];

    printf("Enter the source file:");
    scanf("%s", src);

    printf("Enter the destination file:");
    scanf("%s", destn);

    f1 = fopen(src, "r");
    f2 = fopen(destn, "w");

    if(f1 == NULL || f2 == NULL){
        printf("Source/Destination file does not exist!\nCopying failed!");
        return;
    }

    int temp;

    while((temp = fgetc(f1)) != EOF){
        fputc(temp, f2);
    }

    fclose(f1);
    fclose(f2);

    printf("File copied successfully!\n");
}

//file details function
void fileDetails(){
 
    char file_name[100], path[100];
    struct stat file;

    printf("Enter file name: ");
    scanf("%s", file_name);

    if(stat(file_name, &file) == 0) {
        printf("File name: %s\n", file_name);

        getcwd(path, sizeof(path));
        printf("File Location:%s/%s\n", path, file_name); 

        printf("Size: %ld bytes\n", file.st_size);

        char *time = ctime(&file.st_mtime);
        printf("Last Modified: %s\n", time);
    }
    else
        printf("File not found\n");
    return;

}
