#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>


#include "TCPServer.h"




int 
Create_TCPServer(char *addr,unsigned short port,int NumberOfListen){
    
    int fd;

    struct sockaddr_in mAddr;


    fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1){
        return -1;       //
    }

    memset(&mAddr,0,sizeof(mAddr));

    mAddr.sin_family = AF_INET;
    mAddr.sin_port = htons(port);
    mAddr.sin_addr.s_addr = inet_addr(addr);


    if(bind(fd,(struct sockaddr *)&mAddr,sizeof(mAddr)) == -1 ){
        return -1;
    }

    if(listen(fd,NumberOfListen) == -1){
        return -1;
    }

    return fd;
}


int 
TCPServer_Accept(int sockethandle){
    int clienthandle;
    clienthandle = accept(sockethandle,0,0);
    return clienthandle;
}

int
TCPServer_Recv(int clienthandle,char *buffer,int wantlen){
    return recv(clienthandle,buffer,wantlen,0);
}


int
TCPServer_Send(int clienthandle,char *buffer,int wantlen){
    return send(clienthandle,buffer,wantlen,0);
}


void 
TCPServer_Init(TCPServer *target){
    target->Create_TCPServer = Create_TCPServer;
    target->TCPServer_Accept = TCPServer_Accept;
    target->TCPServer_Recv = TCPServer_Recv;
    target->TCPServer_Send = TCPServer_Send;
}