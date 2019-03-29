#include <stdint.h>



uint16_t CalcCRC16(uint8_t *data, uint8_t len)
{
    uint16_t crc = 0xFFFF;
    uint8_t i,k;
    for(i = 0;i < len;i++)
    {
        // printf("%d\r\n",data[i]);
        crc ^= data[i];
        for(k = 0;k < 8;k++)
        {
            if(crc & 0x0001)
            {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else
            {
                crc >>= 1;
            }
        }
    }
    return crc;
}