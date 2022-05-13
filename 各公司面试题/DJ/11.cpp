/*
给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
例如 N = 18 L = 2：
5 + 6 + 7 = 18
3 + 4 + 5 + 6 = 18
都是满足要求的，但是我们输出更短的 5 6 7
输入描述：
输入数据包括一行： 两个正整数N(1 ≤ N ≤ 1000000000),L(2 ≤ L ≤ 100)
输出描述：
从小到大输出这段连续非负整数，以空格分隔，行末无空格。如果没有这样的序列或者找出的序列长度大于100，则输出No
示例1
输入：
18 2
复制
输出：
5 6 7
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,L;
    cin>>N>>L;
    vector<int> nums;
    int sum=0;
    if(N%2==0){
        int mid=N/(L+1)-1;
        sum+=mid;
        nums.push_back(mid);
        while(sum<N){
            mid=mid+1;
            sum+=mid;
            nums.push_back(mid);
        }
        if(sum==N){
            for(int ii=0;ii<nums.size();ii++){
                if(ii==nums.size()-1) cout<<nums[ii];
                else cout<<nums[ii]<<" ";
            }
        }
        else cout<<"No"<<endl;
    }else{
        int mid=N/L;
        sum+=mid;
        nums.push_back(mid);
        while(sum<N){
            mid+=1;
            sum+=mid;
            nums.push_back(mid);
        }
         if(sum==N){
            for(int ii=0;ii<nums.size();ii++){
                if(ii==nums.size()-1) cout<<nums[ii];
                else cout<<nums[ii]<<" ";
            }
         }else cout<<"No"<<endl;
    }
    
    return 0;
}
*/
/*
等差数列求和：
N为已知，只需要根据l来求得a那么在代码实现时，
我们可以从L开始，依次遍历所有l的可能(从L到100)，并检查相应求得的数值是否为整数即可。
因为l从小到大，那么一定先找到的是长度最小的。
*/
#include<iostream>
using namespace std;
int main() {
    int N, L;
    cin>>N>>L;
    for(int i = L; i <= 100; i++) {
        if((2*N+i-i*i)%(2*i) == 0) {//如果首项为整数
            int start = (2*N+i-i*i)/(2*i);
            for(int j = 0; j < i-1; j++) {//且
                cout<<start+j<<" ";
            }
            cout<<start+i-1;
            return 0;
        }
    }
    cout<<"No"<<endl;
}