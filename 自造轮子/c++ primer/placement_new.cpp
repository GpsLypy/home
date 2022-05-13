#include <iostream>
#include <string>
using namespace std;

class ADT{
    int i;
    int j;
public:
    ADT(){
        i=10;
        j=100;
        cout<<"ADT construct i="<<i<<"j="<<j<<endl;
    }
    ~ADT(){
        cout<<"ADT destruct"<<endl;
    }
};
int main(){
    
    char* p=new(nothrow) char[sizeof(ADT)+1];
    if(p==nullptr) cout<<"alloc faild"<<endl;
    
    ADT* q=new(p) ADT;

    q->ADT::~ADT();//显示调用析构函数
    delete[] p; 

    return  0;
}