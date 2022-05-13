#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class mycmp{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};
int main(){
    vector<int> nums;
    unordered_map<int,int> map;
    int val=0;
    while(1){
        cin>>val;
        nums.push_back(val);
        if(cin.get()=='\n') break;
    }
    
    for(int ii=0;ii<nums.size();ii++){
        map[nums[ii]]=ii;
    }
    
    priority_queue<int,vector<int>,mycmp> pri_que;
    
    for(auto it:nums){
        pri_que.push(it);
        if(pri_que.size()>3) pri_que.pop();
    }
    vector<int> res(3);
    for(int ii=2;ii>=0;ii--){
        res[ii]=pri_que.top();
        pri_que.pop();
    }
    
    
    for(int ii=0;ii<res.size();ii++){
        int a=map[res[ii]];
        cout<<"("<<a<<","<<" "<<res[ii]<<")";
    }
    cout<<endl;
}