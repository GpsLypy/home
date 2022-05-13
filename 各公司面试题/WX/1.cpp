#include <iostream>
#include <vector>
using namespace std;

int fun(int x){
    int count=0;
    while(x){
        count++;
        x=x&(x-1);
        
    }
    return count;
}

int main(){
    int res=fun(500);
    cout<<res<<endl;
}