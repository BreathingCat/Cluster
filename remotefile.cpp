#include "remotefile.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

remotefile::remotefile()
{

}

void remotefile::readfile(char *filename, char **buff, unsigned long int* bufflen)
{

    FILE* file = fopen(filename, "r");

    if(file == NULL){
        *buff = NULL;
        *bufflen = 0;

    }else{
        unsigned long int flen = 0;

        fseek(file,0,SEEK_END); // Locate file at the end of the file
        flen = ftell(file); // ftell will return the position of file, which tells us the size f the file in bytes
        fseek(file,0,SEEK_SET);

        *buff = new char[flen];
        fread(*buff,1,flen,file);

        *bufflen = flen;
        (*buff)[*bufflen - 1] = '\0';
        fclose(file);

    }

}
