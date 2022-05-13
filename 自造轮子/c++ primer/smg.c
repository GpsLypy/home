/* ************************************************************************
> File Name:     smg.c
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Wed 02 Jun 2021 08:42:14 PM CST
> Description:   
 ************************************************************************/
#include<stdio.h>

void smg_display(unsigned int number)
{
   // int *smg_num = (int*)SMG_CONTROLLER_0_BASE;
    int i;
    unsigned int j=100000;
    unsigned char display[6];
    for (i=5;i>=0;i--)
    {
        display[i]= number / j;
        printf("%c\n",display[i]);
        number -= j * display[i];
        j /= 10;
    }
}

int main(){
    smg_display(123456);
    return 0;
}
