#ifndef __MSOCKET_H__
#define __MSOCKET_H__




typedef struct TCPServer{
    int (*Create_TCPServer)(char *,unsigned short,int);
    int (*TCPServer_Accept)(int );
    int (*TCPServer_Recv)(int,char *,int);
    int (*TCPServer_Send)(int,char *,int);
}TCPServer;


void TCPServer_Init(TCPServer *target);










#endif