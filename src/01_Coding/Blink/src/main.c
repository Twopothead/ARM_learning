//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//
#include "stm32f10x.h"

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"





 

static u8 fac_us = 0;  //us延时倍乘数
static u16 fac_ms = 0; //ms

/**************************************************
Name: delay_init
功能：应用程序延时函数初始化，包括为滴答时钟准备相关数值
参数：u8 SYSCLK
返回：None
***************************************************/
// void delay_init(u8 SYSCLK)
// {
//   SysTick->CTRL &= 0xfffffffb; //设置滴答时钟的时钟源：bit 2清空，选择外部时钟HCLK/8
//   fac_us = SYSCLK / 8;
//   fac_ms = (u16)fac_us * 1000;
// }
/**************************************************
名字：delay_ms
共能：应用程序ms级别的延时实现
参数：u16 nms
返回：None
***************************************************/
// void delay_ms(u16 nms)
// {
//   u32 temp;
//   SysTick->LOAD = (u32)nms * fac_ms; //时间加载
//   SysTick->VAL = 0x00;               //清空计数器
//   SysTick->CTRL = 0x01;              //开始倒数
//   do
//   {
//     temp = SysTick->CTRL;
//   } while (temp & 0x01 && !(temp & (1 << 16))); //等待时间到达
//   SysTick->CTRL = 0x00;                         //关闭计数器
//   SysTick->VAL = 0X00;                          //清空计数器
// }

// int old_main(int argc, char *argv[])
// {
//   // 初始化时钟，默认72MHz
//   SystemInit();

//   delay_init(72);

//   // 初始化GPIO
//   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

//   GPIO_InitTypeDef gpio_init_struct;
//   gpio_init_struct.GPIO_Pin = GPIO_Pin_2;
//   gpio_init_struct.GPIO_Mode = GPIO_Mode_Out_PP;
//   gpio_init_struct.GPIO_Speed = GPIO_Speed_10MHz;
//   GPIO_Init(GPIOD, &gpio_init_struct);

//   // Infinite loop
//   while (1)
//   {
//     delay_ms(100);
//     GPIO_SetBits(GPIOD, GPIO_Pin_2);

//     delay_ms(100);


//     // 设置低
//     GPIO_ResetBits(GPIOD, GPIO_Pin_2);
//   }
// // loadbin /home/curie/stm32_pro/vscode_template_stm32f103/stm32f103rct6.hex 0x08000000
 
// }
 int main(void)
 {	
	delay_init();	    //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	while(1)
	{
		LED0=0;
		LED1=1;
		delay_ms(300);	 //延时300ms
		LED0=1;
		LED1=0;
		delay_ms(300);	//延时300ms
	}
 }