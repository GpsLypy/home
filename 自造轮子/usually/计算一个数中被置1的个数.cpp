#include <iostream>
using namespace std;


int func(int n){
    int count=0;
    //计算一个整数(32位)中被置为1的个数
    for(int ii=0;ii<32;++ii){
        if( (n>>ii) & 1 ) count++;
    }
    /*
    //计算一个字节(8位)中被置为1的位的个数
    for(int ii=0;ii<8;ii++){
        if((n>>ii)& 1) count++;
    }
    */
    return count;
}
int main(){
    int n=8;
    int res=func(n);
    cout<<res<<endl;
}