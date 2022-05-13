#include <iostream>
#include <vector>
using namespace std;

int fun(int m){
    static int n=0;
    m/=2;
    m*=2;
    if(m){
        n=n*m;
        return (fun(m-2));
    }else return fun(n++);
}
int main(){
    /*
    int num;
    vector<int> nums;
    while(1){
        cin>>num;
        if(num==7) break;
        nums.push_back(num);
    }
    int size=nums.size();
    int res=(size/3)*15+(size/3)*6;

    cout<<res<<endl;
    */

     int i,r;
     for(int ii=0;ii<2;ii++){
         r=fun(4+ii);
         //cout<<r<<endl;
         printf("%d\n",r);
     }
}