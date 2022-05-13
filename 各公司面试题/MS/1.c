#include <stdio.h>

int func1(){
    func2();
    printf("1\n");
}

int func2(){
    sleep(1);
    printf("2\n");
    func1();
}

int main(){
    func1();
    return;
}