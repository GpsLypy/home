/*
小美的序列检查
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小美给小团一个n个数字构成的数字序列，问小团能不能经过重新排列后形成1到n的排列。

举例：

小美给小团[2, 1, 3]，则可以经过重新排列后构成[1, 2, 3]，这是可行的。

小美给小团[4, 4, 1, 3]，则无法经过重新排列后构成[1, 2, 3, 4]，这是不可行的。

为了防止小团靠运气碰对答案，小美会进行多组询问。


输入描述
第一行是一个数T，表示有T组数据。

对于每组数据：

第一行一个数字n表示小美给出的序列由n个数字构成。

接下来一行n个空格隔开的正整数。

输出描述
对于每组数据，如果可以重新排列后得到1到n的排列，回答一行Yes，如果不可以，回答No

请注意大小写。
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        //vector<int> nums(n);//占用空间可能过大,故不采用
        set<int> se;
        for(int ii=0;ii<n;ii++){
            int number;
            cin>>number;
            if(se.find(number)!=se.end()||number>n){
                cout<<"No"<<endl;
                return 0;
            }
            se.insert(number);
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}


