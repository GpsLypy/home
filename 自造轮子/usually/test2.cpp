#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define N 5

#define Y(n) ((N+1)*n)  //主要是要弄明白n，n两边没加括号

#define DOUBLE(x) x+x

class A{
public:
    A(int a=10):_a(a){}
    void PrintString(){
        std::cout<<"PrintString"<<std::endl;
    }
    void PrintInt(){
        std::cout<<_a<<std::endl;
    }
private:
    int _a;
};

int main(){
    A a;
    A* pA=&a;
    pA->PrintString();
    pA->PrintInt();

    A* pa=NULL;
    pa->PrintString();
    //pa->PrintInt();//Segmentation fault

    printf("%d\n",2*(N+Y(5+1)));//2*(5+(5+1)*5+1) //72

    int ii=5*DOUBLE(5);

    cout<<ii<<endl;//30

    return 0;    
}