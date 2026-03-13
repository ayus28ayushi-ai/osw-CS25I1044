#include<stdio.h>
#include<stdlib.h>
#include "function.h"

int main(){
    int option;

    printf("**********************************");
    printf("\n   Welcome to File Manager\n ");
    printf("**********************************\n\n");

      menu();
    while(1){
     
        printf("\n\nEnter your choice(0-11):");
        scanf("%d", &option);

        switch(option){
            case 1: createFolder(); break;
            case 2: createNestedItem(); break;
            case 3: createFile(); break;
            case 4: showDirectory(); break;
            case 5: showPWD(); break;
            case 6: changeDirectory(); break;
            case 7: deleteItem(); break;

            case 8: if(renameItem() == 1){
                     printf("Item renamed successfully!\n");
                    }
                    else{
                      printf("ERROR! could not rename the item\n");
                    }
                    break;

            case 9: copyFile(); break;

            case 10: if(renameItem() == 1){                           //OS treats moving as renaming
                     printf("Item moved successfully!\n");
                    }
                    else{
                      printf("ERROR! could not move the item\n");
                    }
                    break;

            case 11: fileDetails(); break;
            case 0: printf("****GoodBye!😊****\n\n"); exit(0);
            default: printf("Invalid Choice. TRY AGAIN\n"); break;
        }
    }

}


