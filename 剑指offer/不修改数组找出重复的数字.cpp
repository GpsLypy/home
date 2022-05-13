#include <iostream>
using namespace std;

int countRange(const int* nums,int len,int start,int end){
    if(nums==nullptr) return 0;
    int count=0;
    for(int ii=0;ii<len;ii++){
        if(nums[ii]>=start&&nums[ii]<=end) count++;
    }
    return count;
}

int getDuplication(const int* nums,int len){
    if(nums==nullptr||len<=0) return -1;
    for(int ii=0;ii<len;ii++){
        if(nums[ii]<1||nums[ii]>len-1){
            return -1;
        }
    }

    int start=1;
    int end=len-1;
    while(end>=start){
        int mid=((end-start)>>1)+start;//找出中间元素
        int count=countRange(nums,len,start,mid);
        if(start==end){
            if(count>1) return start;
            else break;
        }
        if(count>(mid-start+1)){ //mid-start+1 意味着计算区间内元素的个数
            end=mid;
        }else{
            start=mid+1;
        }
    }
    return -1;
}


int main(){
    //int nums[]={2,3,5,4,7,2,6,7,7};
    int nums[]={1,1,9};
    int res=getDuplication(nums,sizeof(nums)/sizeof(int));
    cout<<res<<endl;
}