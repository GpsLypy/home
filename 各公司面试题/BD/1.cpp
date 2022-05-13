#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<vector<int>> nums;
    int val;
    vector<int> vec(N,0);
    for(int ii=1;ii<N+1;ii++){
        for(int ii=0;ii<N;ii++){
             cin>>val;
             vec[ii]=val;
        }
        nums.push_back(vec);
    }
    
    vector<vector<int>> res;
    
    for(auto a:nums){
        vector<int> temp;
        for(int ii=0;ii<a.size();ii++){
                for(int jj=0;jj<K;jj++){
                    temp.push_back(a[ii]);
                }
        }
         for(int kk=0;kk<K;kk++){
          res.push_back(temp);
        }
    }
    
    for(auto b:res){
        for(auto c:b){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}