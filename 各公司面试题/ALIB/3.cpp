#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,K;
    cin>>n>>K;
    int a,b,c;
    unordered_map<int,int> map;
    pair<int,int> p;
    vector<vector<int>> res;
    vector<int> floor(5,0);
    for(int ii=0;ii<n;ii++){
        cin>>a>>b>>c;
        if(map.find(a)!=map.end()){
            if(map[a]==1&&b==0){
                floor[c-1]--;
                res.push_back(floor);
                continue;
            }
            if(map[a]==1&&b==1) {
                res.push_back(floor);
                continue;
            }
        }
        p.first=a;
        p.second=b;
        map.insert(p);
        if(floor[c-1]<K) {
            floor[c-1]++;
            res.push_back(floor);
            continue;
        }
        res.push_back(floor);
    }
    
    int index=0;
    for(int ii=0;ii<n;ii++){
        for(auto it:res[ii]){
            cout<<it<<" ";
        }
        cout<<endl;
    }    
    return 0;
}