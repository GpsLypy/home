#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Matrix(vector<vector<int>>& nums,int n){
    int startx=0,starty=0;
    int loop=n/2;
    int mid=n/2;
    int count=1;
    int offset=1;
    int ii,jj;
    while(loop--){
        ii=startx;
        jj=starty;
        for( ii=startx;ii<startx+n-offset;ii++){
            nums[jj][ii]=count++;
        }
        for( jj=starty;jj<starty+n-offset;jj++){
            nums[jj][ii]=count++;
        }
        for(;jj>starty;jj--){
            nums[ii][jj]=count++;
        }
        for(;ii>startx;ii--){
            nums[ii][jj]=count++;
        }
        
        startx++;
        starty++;
        offset+=2;
    }
    if(n%2){
            nums[mid][mid]=count;
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(n,0));
    vector<int> res;
    Matrix(nums,n);
    for(auto a:nums){
        for(auto b:a){
            res.push_back(b);
        }
    }
    for(auto a:res){
        cout<<a<<" ";
    }
    cout<<endl;
}