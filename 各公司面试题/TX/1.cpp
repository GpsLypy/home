#include <iostream>
#include <vector>
using namespace std;


int main(){
    int T;
    cin>>T;
    vector<int> nums;
    for(int ii=0;ii<T;ii++){
        int n;
        cin>>n;
        vector<int> res;
        for(int jj=0;jj<n;jj++){
            int temp;
            cin>>temp;
            res.push_back(temp);
        }
        int sum=0;
        for(int ii=0;ii<n;ii++){
            sum+=res[ii];
            for(int jj=ii+1;jj<n;jj++){
                res[jj]+=res[ii];
            }
        }
        nums.push_back(sum);
    }

    for(auto a: nums){
        cout<<a<<endl;
    }
    return 0;
}