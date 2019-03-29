#include "bsp_spi.h"
#include "ioCC2541.h"  
#include <hal_types.h>

#define SPI_CS                          P1_4   
#define SPI_CLK                         P1_5
#define SPI_MOSI                        P1_6 
#define SPI_MISO                        P1_7


void SPI_DLY_us(unsigned int us)
{                         
    unsigned int a;
    while(us)
    {
//        a=2;
//        while(a--);
        us--;
    }
    return;
}

void SPI_SendBytes(uint8 *data,uint16 len)
{
  uint8 i,temp;
  uint16 j;
  
  for(j = 0;j < len;j++){
    for(i = 0;i < 8;i++){
      SPI_CLK = 1;
      temp = data[j] & 0x80;
      if(temp == 0){
        SPI_MOSI = 0;
      }else{
        SPI_MOSI = 1;
      }
      data[j] <<= 1;
      SPI_CLK = 0;
    }
    SPI_CLK = 0;
  }
  SPI_CLK = 0;
}

void SPI_ReadBytes(uint8 *data,uint16 len)
{
  uint8 i,temp,in;
  
  uint16 j;
  
  SPI_CLK = 1;
  for(j = 0;j < len;j++){
    in = 0;
    for(i = 0;i < 8;i++){
      in = (in << 1);
      SPI_CLK = 0;
      temp = SPI_MISO;
      if(temp == 1){
        in = in | 0x01;
      }
      SPI_CLK = 1;
    }
//    SPI_CLK = 0;
    data[j] = in;
  }
  SPI_CLK = 0;
  
}



//对应的SPI模式为CPHA = 1,CPOL = 0,高位先发

void SPI_SendByte(uint8 cmd){
 
    unsigned char i=8, temp=0;
   
    for(i=0;i<8;i++){
        SPI_CLK = 1;
         
        temp = cmd&0x80;
        if (temp == 0)
        {
            SPI_MOSI = 0;
        }
        else
        {
            SPI_MOSI = 1;
        }
        cmd <<= 1;             
        SPI_CLK = 0; 
        //SPI_DLY_us(1);
    }
//    SPI_CLK = 1; 
//    NOP();NOP();NOP();NOP();NOP();
//    NOP();NOP();NOP();NOP();NOP();
//    NOP();NOP();NOP();NOP();NOP();
//    NOP();NOP();NOP();NOP();NOP();
    SPI_CLK = 0;
}

//发送一个字节, 基本上先拉低使能CS脚, 然后不断的时钟高低, 在时钟的后变化沿, 就是所谓clock tailing edge, 读MISO值. 
//注意：多字节读请不要用这个函数，因为它会拉多一个时序，对后面的数据会影响,而对应单个读时序是不影响的。
uint8 SPI_ReadByte(void){
    unsigned char i=0, in=0, temp=0;

    //先拉高, 然后拉低的时候, 读取MISO
    SPI_CLK = 1;
    for(i=0;i<8;i++){
        in = (in << 1);
        SPI_CLK = 0; 
        //SPI_DLY_us(1);
        temp = SPI_MISO;
        if (temp == 1){
            in = in | 0x01;
        }
        SPI_CLK = 1;
        //SPI_DLY_us(1);   
    }
    SPI_CLK = 0;
    return in;
}


void EnableCS()
{
  SPI_CS = 0;
}


void DisableCS()
{
  SPI_CS = 1;
}

void SPI_Init(void)
{  
    P1SEL &= 0x0F; //将 P1.4 P1.5 P1.6 P1.7 设置为GPIO引脚          00001111
    P1DIR |= 0x70; //设置 P1.4 P1.5, p1.6 引脚为输出, P1.7 为输入   01110000
    
    SPI_CLK = 0;        //拉低时钟线
//    SPI_SendByte(0xff);
}





