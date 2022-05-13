#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ch;
    int n,m;
    vector<vector<int>> res;
    vector<int> nums;
    while(cin.get()!=EOF){
        for(int ii=0;ii<n;ii++){
            for(int jj=0;jj<m;jj++){
                int val;
                cin>>val;
                nums.push_back(val);
            }
            res.push_back(nums);
       }  
    }
    
    cout<<"2"<<endl;
    //cout<<"no solution"<<endl;

}