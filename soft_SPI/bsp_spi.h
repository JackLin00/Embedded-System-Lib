#ifndef __BSP_SPI_H__
#define __BSP_SPI_H__


#include "hal_types.h"



void SPI_SendByte(uint8 cmd);
uint8 SPI_ReadByte(void);
void SPI_Init(void);
void SPI_SendBytes(uint8 *data,uint16 len);
void SPI_ReadBytes(uint8 *data,uint16 len);
void EnableCS();
void DisableCS();








#endif




