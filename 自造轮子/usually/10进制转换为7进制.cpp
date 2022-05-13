#include <iostream>
#include <algorithm>
using namespace std;

//算法思想：
//运用辗转相除法，当被除数被除到0时，把取出的余数按从后至前的顺序排列，就可以得到进制转换后的数
//对于负数，可以先将负数转换为相反数进行运算，最后再加回负号。

string convertToBase7(int num){
    int flag=false;
    //处理负数
    if(num<0){
        num*=-1;
        flag=true;
    }

    int remainder=0;//余数
    string ret("");

    //算法至少要执行一次7/7
    do{
        remainder=num%7;//取余
        num=num/7;//取整
        ret+=to_string(remainder);
    }while(num);

    //注意排列顺序
    reverse(ret.begin(),ret.end());

    //如果num为负数的话，加回负号
    return flag==true? "-"+ret : ret;
}

int main(){
    string res=convertToBase7(8543);
    cout<<res<<endl;
}