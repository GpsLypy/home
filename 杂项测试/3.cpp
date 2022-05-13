#include <stdio.h>

void abc(char* str){
    int a,b;
    for(a=b=0;str[a]!='\0';a++){
        if(str[a]!='c'){
            str[b++]=str[a];
            str[b]='\0';
        }
    }
}


int main(){
    char str[]="abcdef";
    abc(str);
    printf("str[]=%s\n",str);
}