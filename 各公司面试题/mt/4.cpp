/*
最少操作次数
        时间限制： 1000MS
内存限制： 65536KB
题目描述：
小美给了小团一个长度为n（n为偶数）的序列A，序列中的数都是介于[1,100000]的整数。小团想把这个序列变得漂亮后再送回给小美。小美觉得一个序列是漂亮的当且仅当这个序列的前一半和后一半是一样的，即对于1<=i<=n/2都满足A[i]==A[i+n/2]。

小团可以按进行以下操作任意次：

选择两个介于[1, 100000]之间的数x和y，然后将序列A中所有值为x的数替换为y。

注意，每次操作都会在上一次操作后得到的序列上进行。小团想知道他最少需要操作多少次可以把序列变成漂亮的。



输入描述
        第一行是一个整数n，表示序列的长度。数据保证n为偶数。

第二行有n个用空格隔开的整数，第i个数表示A[i]的值。数据保证1<=A[i]<=100000。

输出描述
        输出小团需要的最少操作次数。


样例输入
10
4 2 1 5 2 10 2 1 5 8
样例输出
2

提示
        数据范围和说明

30%的数据保证 n<=10，1<=A[i]<=10000。

70%的数据保证 n<=1000，1<=A[i]<=10000。

100%的数据保证 n<=100000，1<=A[i]<=10000。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getIndex(vector<int>& tree , int num){
    int l = 0 , r = tree.size() -1;
    while(l<r){
        int mid = (l+r)>>1;
        if(tree[mid] == num)
            return mid;
        if(tree[mid] > num)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int findroot(vector<int> & tree , int x){
    if(tree[x] != -1){
        tree[x] = findroot(tree,tree[x]);
        return tree[x];
    }else
        return x;
}

int main(){
    int N;
    cin>>N;
    vector<int> data(N);
    for(int i=0;i<N;i++)
        cin>>data[i];

    vector<int> tmp(data);
    sort(tmp.begin(),tmp.end());
    tmp.erase( unique(tmp.begin(),tmp.end()) , tmp.end());
    
    vector<int> tree(tmp.size(),-1);

    int ans = 0;

    for(int i=0;i<N/2 ;i++){
        if(data[i] != data[i+N/2]){
            int x = getIndex(tmp,data[i]) , y = getIndex(tmp,data[i+N/2]);
            int xroot = findroot(tree,x) , yroot = findroot(tree,y);
            if(xroot!=yroot){
                tree[xroot] = yroot;
                ans++;
            }
        }
    }
    cout<< ans <<endl;
    return 0;
}