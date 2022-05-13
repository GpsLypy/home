#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

void selectSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;

    for(int ii=0;ii<size;ii++){
        int min=ii;
        for(int jj=ii+1;jj<size;jj++){
            
        }
    }
}


int main(){
    //vector<int> nums{2,4,5,1,3,78};
    vector<int> nums{1,24,67,23,4,78,90,456};
    insertSort(nums);
    print(nums);
    return 0;
}