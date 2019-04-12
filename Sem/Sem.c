#include "Sem.h"


union semun{                         //信号量操作的联合结构
    int                    val;      //整型变量
    struct semid_ds        *buf;     //semid_ds结构指针
    unsigned short         *array;   //数组类型
}arg;     



sem_t 
CreateSem(key_t key,int value){
    union semun sem;

    sem_t semid;

    sem.val = value;

    semid = semget(key,0,IPC_CREAT | 0666);

    if(semid == -1){
        return -1;
    }

    semctl(semid,0,SETVAL,sem);

    return semid;
}

int
Sem_P(sem_t semid){
    struct sembuf sops = {0,+1,IPC_NOWAIT};          //第三个参数如果填0，就为阻塞，现为非阻塞

    return semop(semid,&sops,1);
}



int
Sem_V(sem_t semid){
    struct sembuf sops = {0,-1,IPC_NOWAIT};          //第三个参数如果填0，就为阻塞，现为非阻塞

    return semop(semid,&sops,1);
}


void
SetvalueSem(sem_t semid,int value){
    union semun sem;

    sem.val = value;

    semctl(semid,0,SETVAL,sem);
}


int
GetvalueSem(sem_t semid){
    union semun sem;

    return semctl(semid,0,GETVAL,sem);
}


void
DestroySem(sem_t semid){
    union semun sem;
    sem.val = 0;
    semctl(semid,0,IPC_RMID,sem);
}



