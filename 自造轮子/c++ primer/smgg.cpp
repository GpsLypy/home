/* ************************************************************************
> File Name:     smgg.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Wed 09 Jun 2021 01:02:08 PM CST
> Description:   
 ************************************************************************/
#include <sys/unistd.h>
#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "sys/alt_irq.h"

int hour = 23,minute = 59,second = 50;
int hour1 = 0,minute1 = 0,n =0;
int segtab[12]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83};
int model_flag = 0,S_flag = 0,BEEP = 0,beep_flag = 0,beep_flag1 = 0;
int key_set = 1,key_add = 1,key_sub = 1,key_rst = 1;
int a[6]={0,0,0,0,0,0,};

void write_data(){
    IOWR(DIG_1_BASE,0,a[5]);
    IOWR(DIG_2_BASE,0,a[4]);
    IOWR(DIG_3_BASE,0,a[3]);
    IOWR(DIG_4_BASE,0,a[2]);
    IOWR(DIG_5_BASE,0,a[1]);
    IOWR(DIG_6_BASE,0,a[0]);
}
void rst(){
     if(key_rst==0){
        key_rst =1;
        a[0]=2;  a[1]=3; a[2]=5; a[3]=9; a[4]=5; a[5]=9;
        write_data();
     }
}
void set_led(int led_flag, int state){
    if ( led_flag == 1) {
        IOWR(LED_BASE,0,0xff);
    }
    else if ( led_flag == 2){
        IOWR(LED_BASE,0,state);
    }
    else {
        IOWR(LED_BASE,0,0x00);
    }
}


void delay(int us)// 延时函数
{

    int i,j;
    for ( i = us; i > us; i--) {
        for ( j = 50; j > 0; j--);
    }
}

int read_key(){
    int status = 0;
    status = IORD(KEY_BASE,0);
    return status;
}

int tmp = 0;
void check_key(){
    delay(10);
    int status = IORD(KEY_BASE,0);
    if ( status) {
        tmp ++;
        if ( tmp == 50) {
            if ( status & 0x01) {
                    key_set = 0;
                    set_led(2,0x01);
                }
                else if ( status & 0x01 << 1) {
                    key_add =0;
                    set_led(2,0x02);
                }
                else if ( status & 0x01<< 2){
                    key_sub = 0;
                    set_led(2,0x04);
                }
                else if ( status & 0x01<< 3){
                    key_rst = 0;
                    set_led(2,0x08);
                }
                else{
                    tmp = 0;
                }
       }
   }
   else {
        tmp = 0;
    }
}

void delay(int us)// 延时函数
{
    int i,j;
    for ( i = us; i > us; i--) {
        for ( j = 50; j > 0; j--);
    }
}

int flag = 0,ss_add = 0;

void ISR_timer(void * context, alt_u32 id)
{
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_1S_BASE, 0);
    ss_add++;
    if(ss_add >= 500){
        ss_add = 0;
        S_flag =! S_flag;         //闪烁标志位
    }
    flag = 1;
}
void display(){
    switch(model_flag){
    case 0:
        {
            a[0]=segtab[hour/10];
            a[1]=segtab[hour%10];
            a[2]=segtab[minute/10];
            a[3]=segtab[minute%10];
            a[4]=segtab[second/10];
            a[5]=segtab[second%10];
            write_data();
        }break;
    case 1:
        {
            if(S_flag==1){
                a[0]=segtab[hour/10];
                a[1]=segtab[hour%10];
            }
            else{
                a[0]=segtab[11];
                a[1]=segtab[11];
            }
            a[2]=segtab[minute/10];
            a[3]=segtab[minute%10];
            a[4]=segtab[second/10];
            a[5]=segtab[second%10];
            write_data();
        }
        break;
    case 2:
        {
            a[0]=segtab[hour/10];
            a[1]=segtab[hour%10];
            if(S_flag==1){
                a[2]=segtab[minute/10];
                a[3]=segtab[minute%10];
            }
            else{
                a[3]=segtab[11];
                a[4]=segtab[11];
            }
            a[4]=segtab[second/10];
            a[5]=segtab[second%10];
            write_data();
        }break;
    case 3:
        {
            a[0]=segtab[hour/10];
            a[1]=segtab[hour%10];
            a[2]=segtab[minute/10];
            a[3]=segtab[minute%10];
            if(S_flag==1){
                a[4]=segtab[second/10];
                a[5]=segtab[second%10];
            write_data();
        }break;
}
void key_model(){
   if(key_set==0){
            key_set = 1;
            model_flag++;
            if(model_flag==6)
            model_flag=0;    
   }

   if(model_flag!=0){
     switch(model_flag){

          case 1:          //模式——调时
          {
            if(key_add==0){
                    key_add = 1;
                    if(hour<23) hour++;
                    else hour=0;
            }
            if(key_sub==0){
                    key_sub = 1;
                    if(hour> 0) hour--;
                    else hour=23;
            }
          } break;

          case 2:         //模式——调分
          {
            if(key_add==0)
            {
                    key_add = 1;
                    if(minute<59) minute++;
                    else minute=0;
            }
            if(key_sub==0)
            {
                    key_sub = 1;
                    if(minute>0) minute--;
                    else minute=59;
            }
        } break;
         case 3:          //模式——调秒
          {
            if(key_add==0)
            {
                    key_add = 1;
                    if(second<59) second++;
                    else second=0;
            }
            if(key_sub==0)
            {
                    key_sub = 1;
                    if(second>0) second--;
                    else second=59;
            }
        } break;



int main()
{
    alt_irq_register(TIMER_1S_IRQ,0,ISR_timer);
    flag = 0;
    while(1){
        check_key();
        key_model();
        if (flag){
            rst();
            flag = 0;
            n++;
            if(n == 1000){
                n = 0;
                second++;
                if(second >= 60){
                    minute++;
                    second = 0;
                }
                if(minute >= 60){
                    hour++;
                    minute = 0;
                }
                if(hour >= 24){
                    hour = 0;
                }
            }
            display();
        }
    }
    return 0;
}




