#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    vector<int> nums;
    vector<int> res;
    int sum;
    int N;
    for(int ii=0;ii<T;ii++){
  
        cin>>N;
        int Di,Ki;
        for(int ii=0;ii<N;ii++){
            
            cin>>Di>>Ki;
            for(int jj=0;jj<Ki;jj++){
                int num;
                cin>>num;
                nums.push_back(num);
            }
            sum+=Di;
        }
        res.push_back(sum);
        
    }
    for(int ii=0;ii<res.size();ii++){
       cout<<res[ii]<<endl;
    }
}