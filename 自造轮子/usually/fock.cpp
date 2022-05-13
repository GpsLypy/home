#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    fork();
    cout<<"hello"<<endl;

    fork();
    cout<<"hello"<<endl;

    while(1);
    return 0;
}