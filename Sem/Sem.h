#ifndef __SEM_H__
#define __SEM_H__

#include "Sem.h"
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>


typedef int sem_t;


sem_t CreateSem(key_t key,int value);
int Sem_P(sem_t semid);
int Sem_V(sem_t semid);
void SetvalueSem(sem_t semid,int value);
int GetvalueSem(sem_t semid);
void DestroySem(sem_t semid);


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*---------------------------------------Need modify befor use--------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/




/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*---------------------------------------Need modify befor use--------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/


#endif
