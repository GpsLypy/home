#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool isValid(int a,int b){
    int m=0,n=0;
    int temp=a*b;
    if(a<b){
        swap(a,b);
    }
    m=a*b;
    n=a%b;
    while(n!=0){
        a=b;
        b=n;
        n=a%b;
    }
    if(b==1&&m/b==temp){
        return true;
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    vector<int> nums;
    int N;
    while(T--){
        int n;
        cin>>n;
        int res=0;
        for(int ii=1;ii<sqrt(n);ii++){
            if(n%ii==0){
                int r=n/ii;
                if(r>ii){
                    if(isValid(r,ii)==1) res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}