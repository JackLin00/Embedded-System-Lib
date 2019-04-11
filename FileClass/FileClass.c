#include "FileClass.h"



int 
FileClass_Open(char *filename,int flag){
    return open(filename,flag,S_IRWXU);
}


int 
FileClass_Read(int filehandle,char *buffer,int len){
    return read(filehandle,buffer,len);
}


int
FileClass_Write(int filehandle,char *buffer,int len){
    return write(filehandle,buffer,len);
}

int 
FileClass_Close(int filehandle){
    return close(filehandle);
}



void 
FileClass_Init(FileClass *target){
    target->open = FileClass_Open;
    target->read = FileClass_Read;
    target->write = FileClass_Write;
    target->close = FileClass_Close;
}