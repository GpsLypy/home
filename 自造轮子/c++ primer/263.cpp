#include <iostream>
#include <string>
#include <vector>
using namespace std;

//该类型没有显示定义默认构造函数，编译器也不会为它合成一个
class Nodefault{
public:
    Nodefault(const int i){
        val=i;
    }
    int val;
};

class C{
public:
    Nodefault nd;
    //必须显示调用Nodefault的带参构造函数初始化nd
    C(int i=0):nd(i){}
};

int main(){
    C c;
    vector<Nodefault> vec1(10,10);
    for(auto a:vec1) cout<<a.val<<endl;
    vector<Nodefault> vec2(10,Nodefault(20));
    for(auto b:vec2) cout<<b.val<<endl;
    cout<<c.nd.val<<endl;
    return 0;
}