
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& nums){
    for(auto &num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

void insertSort(vector<int>& nums){
    int size=nums.size();
    if(size<2) return;
    for(int ii=1;ii<size;ii++){
        int temp=nums[ii];
        int jj;
        for(jj=ii-1;jj>=0;jj--){
            if(nums[jj]>temp){
                nums[jj+1]=nums[jj];
            }
            else break;
        }
        nums[jj+1]=temp;
    }
}



int main(){
    //vector<int> nums{2,4,5,1,3,78};
    vector<int> nums{1,24,67,23,4,78,90,456};
    insertSort(nums);
    print(nums);
    return 0;
}
/*

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for(auto a: nums){
        cout<<a<<" ";
    }
    cout<<endl;
}

void insertSort(vector<int>& nums){
	int size=nums.size();
	if(size<2) return;
	for(int ii=1;ii<size;ii++){
		int jj;//1
		for(jj=ii-1;jj>=0;jj--){
			if(nums[ii]<nums[jj]){
				nums[jj+1]=nums[jj];//整体向后移
			}else break;//2
		}
		nums[jj]=nums[ii];
	}
}

int main(){
     //vector<int> nums{1,24,67,23,4,78,90,456};
     vector<int> nums{2,4,5,1,3,78};
     insertSort(nums);
     print(nums);
}
*/