#include <bits/stdc++.h>

using namespace std;

void func(shared_ptr<int> &sp2){
    cout<<sp2.use_count()<<endl;
    
}
int main(){
     shared_ptr<int> sp1(new int(1));
     cout<<sp1.use_count()<<endl;
     //子函数形参里有 shared_ptr，主函数里定义一个shared_ptr，
     //这个shared_ptr作为参数传入子函数中时，智能指针的计数count变化过程
     //引用传递不变，值传递会+1
     func(sp1);
     return 0;
}