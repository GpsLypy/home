#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    vector<int> nums;
    int N;
    for(int ii=0;ii<T;ii++){
        cin>>N;
        nums.push_back(N);
    }
    vector<int> res;
    for(int ii=0;ii<nums.size();ii++){
        if(nums[ii]%2==1||nums[ii]/2==0){
            res.push_back(1);
        }
    }
    for(auto a:res){
        cout<<a<<endl;
    }
    return 0;
}