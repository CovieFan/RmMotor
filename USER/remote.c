#include "remote.h"
#include "usart.h"

uint8_t dbus_rx_buf[18]={0};
volatile Remote_t remote={0};


void Remote_Unpack(uint8_t *buff)
{
remote.ch0 =((buff[0]|buff[1]<<8)&0x07FF)-1024;
remote.ch1=((buff[1]>>3|buff[2]<<5)&0x07FF)-1024;
remote.ch2=((buff[2]>>6|buff[3]<<2|buff[4]<<10)&0x07FF)-1024;
remote.ch3=((buff[4]>>1|buff[5]<<7)&0x07FF)-1024;
remote.sw1=((buff[5]>>4)&0x000C)>>2;
remote.sw2=(buff[5]>>4)&0x0003;
}
void Remote_Init(void)
{
HAL_UARTEx_ReceiveToIdle_IT(&huart1, dbus_rx_buf, 18);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size)
{
if(huart!=&huart1) return ;
if(Size==18)
{
Remote_Unpack(dbus_rx_buf);
}
HAL_UARTEx_ReceiveToIdle_IT(&huart1, dbus_rx_buf, 18);   

}

