#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class C{
public:
    void func(){}
};

struct A{
    char a;
    int b;
    int* c;
    long long d;
};

int main(){
    ofstream File1("text.txt");
    string d("20160314");
    string y=d.substr(0,4);

    int k=d.find("2");//返回下标位置
    int i=d.find("3");
    
    string m=d.substr(k+2,i-k);
    string dd=d.substr(i+1,2);

    string n=dd+m+y;
    File1<<n<<endl;//14160312016

    File1.close();

    int a[8];
    cout<<sizeof(a)<<endl;//！！！32，因为是int型，不是char型啊啊啊啊

    cout<<sizeof(C)<<endl;//1
    cout<<sizeof(A)<<endl;//24
    cout<<sizeof(long)<<endl;//8
    cout<<sizeof(long long)<<endl;//8
    cout<<sizeof(short)<<endl;//2
}