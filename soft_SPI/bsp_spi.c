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



//��Ӧ��SPIģʽΪCPHA = 1,CPOL = 0,��λ�ȷ�

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

//����һ���ֽ�, ������������ʹ��CS��, Ȼ�󲻶ϵ�ʱ�Ӹߵ�, ��ʱ�ӵĺ�仯��, ������νclock tailing edge, ��MISOֵ. 
//ע�⣺���ֽڶ��벻Ҫ�������������Ϊ��������һ��ʱ�򣬶Ժ�������ݻ�Ӱ��,����Ӧ������ʱ���ǲ�Ӱ��ġ�
uint8 SPI_ReadByte(void){
    unsigned char i=0, in=0, temp=0;

    //������, Ȼ�����͵�ʱ��, ��ȡMISO
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
    P1SEL &= 0x0F; //�� P1.4 P1.5 P1.6 P1.7 ����ΪGPIO����          00001111
    P1DIR |= 0x70; //���� P1.4 P1.5, p1.6 ����Ϊ���, P1.7 Ϊ����   01110000
    
    SPI_CLK = 0;        //����ʱ����
//    SPI_SendByte(0xff);
}





