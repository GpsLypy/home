#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    stack<int> st;
    vector<int> nums{n};
    
    while(1){
        for(int ii=0;ii<nums.size();ii++){
            if(nums[ii]>1){
                int x,y,z;
                x=nums[ii]/2;
                y=nums[ii]%2;
                z=nums[ii]/2;
                if(ii==nums.size()-1){
                    nums.pop_back();
                    nums.push_back(x);
                    nums.push_back(y);
                    nums.push_back(z);
                    break;
                }
                if(nums.size()==1) {nums.pop_back();}
                else{
                    for(int jj=nums.size()-1;jj>ii;jj--){
                        st.push(nums[jj]);
                        nums.pop_back();
                    }
                    nums.pop_back();
                }
                nums.push_back(x);
                nums.push_back(y);
                nums.push_back(z);
                while(!st.empty()){
                    int temp=st.top();
                    st.pop();
                    nums.push_back(temp);
                }
                break;
            }
        }
        int count=0;
        for(int ii=0;ii<nums.size();ii++){
            if(nums[ii]<=1) count++;
        }
        if(count==nums.size()) break;
    }
    int res=0;
    for(int ii=l-1;ii<=r-1;ii++){
        if(nums[ii]==1) res++;
    }
    cout<<res<<endl;
    return 0;
}