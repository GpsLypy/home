/*
序列问题
题目描述：
小美有一个长度为n的序列A，A[i]表示序列中第i个数(1<=i<=n)。
她定义序列中第i个数的prev[i]值为前i-1个数中比A[i]小的最大的值，
即满足1<=j<i且A[j]<A[i]中最大的A[j]，若不存在这样的数，则prev[i]的值为0。
现在她想要你帮忙计算对于所有的i，prev[i]*i之和是多少，即Σprev[i]*i (1<=i<=n，A[1]为序列第1个数)。

输入描述
    第一行是一个整数n表示序列的长度。

    接下来一行n个数用空格隔开，第i个数表示A[i]的大小。

输出描述
        一行一个整数，表示答案。

样例输入
5
1 6 3 3 8
样例输出
39

提示
数据范围和说明

30%的数据保证 n<=20，1<=A[i]<=100。

60%的数据保证 n<=1000，1<=A[i]<=1000。

100%的数据保证 n<=100000，1<=A[i]<=100000。
*/

#include <bits/stdc++.h>
using namespace std;
/*
int N;
int main(){
    cin>>N;
    vector<int> A(N+1);
    for(int ii=1;ii<N+1;ii++){
        cin>>A[ii];
    }
    vector<int> prev(N+1,0);
    int temp=INT_MIN;
    for(int ii=1;ii<N+1;ii++){
        int num=A[ii];
        if(ii==1) {prev[ii]=0;continue;}
        for(int jj=1;jj<ii;jj++){
            if(A[jj]<num) temp=max(A[jj],temp);
        }
        prev[ii]=temp;
    }
    int res=0;
    for(int ii=1;ii<prev.size();ii++){
        res+=prev[ii]*ii;
    }
    cout<<res<<endl;
    return 0;
}
*/

//改成longlong
int main(){
    int N;
    cin>>N;
    vector<int> data(N+1);
    for(int i=1;i<N+1;i++)
        cin>>data[i];
    
    set<int> s;
    int ans = 0;

    for(int i=1;i<N+1;i++){
        auto it = s.lower_bound(data[i]);//在set中找大于data[i]的数,有则返回第一个大于等于x的迭代器；，不存在返回尾迭代器
        if(it != s.begin()){
            ans += (*(--it) * (i));
        }
        s.insert(data[i]);
    }

    cout<< ans <<endl;
    return 0;

}

