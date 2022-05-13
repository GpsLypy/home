#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int size=s.size();
    int KK=size-k;
    int need=k;
    string res;
    for(int ii=0;ii<size;ii++){
        char temp=s[ii];
        while(KK>0&&!res.empty()&&res[res.size()-1]<temp){
            res.pop_back();
            KK--;
        }
        res+=temp;
    }

    res=res.substr(0,need);
    cout<<res<<endl;

}