#include <bits/stdc++.h>
using namespace std;

int main(){
	double s,n,m;
    int ii;
    while(cin>>n>>m){
        s=0;
        for(ii=0;ii<m;ii++){
            s=s+n;
            n=sqrt(n);
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<s<<endl;
    }
    return 0;
}