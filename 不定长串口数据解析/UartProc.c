/*
Proc_Data(uint8_t data)是接收来自串口数据后处理的函数。必须让串口数据一个一个的进入。
可以放在常用的串口中断函数中。
假设要解析的串口不定长数据为：
typedef struct
{
    unsigned char   headone;             //数据头1
    unsigned char   headtwo;             //数据头2
    unsigned char   cmd;                 //命令
    unsigned int    datalen;             //数据长度
    char            chData[0];           //数据（这个对可以动态分配内存的系统增加方便）
} BOSMA_SUB_ONE_PROTOCOL;
这个数据结构可以增加一个CRC数据位
proIPCData函数为串口数据解析函数
*/
#include <stdint.h>

void Proc_Data(uint8_t data)
{
  //接收真实需要处理的数据
  static uint8 RxBuffer[40];
  //真实数据的index
  static uint8  _data_cnt = 0;
  //接收的状态
  static uint8 state = 0;
  //要接收数据的长度
  static uint8 wantedlen = 0;

  if(state == 0 && data == BOSMA_HEADONE){
    state = 1;
  }else if(state == 1 && data == BOSMA_HEADTWO){
    state = 2;
  }else if(state == 2){
    RxBuffer[_data_cnt++] = data;               //cmdÎ»
    state = 3;
  }else if(state == 3){
    RxBuffer[_data_cnt++] = data;               //datalenÎ»
    wantedlen = data;
    state = 4;
  }else if(state == 4){
    RxBuffer[_data_cnt++] = data;
    if(_data_cnt >= wantedlen + 2){
      proIPCData(RxBuffer,wantedlen + 2);
      state = 0;
      _data_cnt = 0;
      wantedlen = 0;
    }
  }else{
    state = 0;
  }
}