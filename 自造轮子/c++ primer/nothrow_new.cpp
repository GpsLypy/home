#include <iostream>
#include <string>
using namespace std;

int main(){
    
    char* p=new(nothrow) char[10^1000000000000];
    if(p==nullptr) cout<<"alloc faild"<<endl;

    delete p;    
    return  0;
}