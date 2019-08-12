#ifndef __TIMESTAMP_H__
#define __TIMESTAMP_H__

#include "project.h"


void praseTimestamp(uint32_t ts,int16_t timeZone,uint32_t *buffer);
uint32_t makeTimestamp(int16_t timeZone,uint32_t *buffer);







#endif