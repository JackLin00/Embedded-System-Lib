#include "mPthread.h"
#include <pthread.h>
#include <sched.h>




int
mPthread_Create(pthread_t *handle,void (*entry)(void *),int priority,void *args){
    int ret;
    pthread_attr_t attr;
    struct sched_param sch;


    pthread_attr_init(&attr);
    pthread_attr_getschedparam(&attr,&sch);
    sch.sched_priority = priority;
    pthread_attr_setschedparam(&attr,&sch);

    ret = pthread_create(handle,&attr,entry,args);

    return ret;
}