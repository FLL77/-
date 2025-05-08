#include <stdio.h>

int main()
{
    File *fon = fopen("thisfile.txt","r");
    
    if(fon == NULL){
        printf("error opening file.")
        return 1;
    }

    File *ftype = fopen("typefile.txt", "w");
    
    if(ftype == NULL){
        printf("error opening file.")
    }
    
    else{
        fprintf(fp, "hello, typing in this file!");
        fclose(ftype);
    }
    
    return 0;
}
