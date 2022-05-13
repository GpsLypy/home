/*
最大振幅计算
时间限制： 3000MS
内存限制： 589824KB
题目描述：
在监控与BI报表系统中，
我们经常会采集数据指标进行分析，
这里的数据往往都是时序数据，对于时序数据，
我们可以用一个数组来表示，例如数组下标表示时间顺序，
数组的值表示采集的指标数据大小。现在作为分析师的你，
得到如下一个任务：在给定一个整数形式的时序数据，
求出这个时序里最大的振幅（“落差”）（振幅 = 时序里相邻的“波峰”与“波谷”相差绝对值）



输入描述
一个数组，下标代表x轴的时间顺序，数组里的每个数值代表y轴的具体值

输出描述
整个曲线的相邻波峰与波谷的最大振幅落差


样例输入
1,2,3,8,5,3,6
2,2,3,8,8,6,5,10,7,6
1,2,3,4,5,6
样例输出
7
6
5
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int num;
    while(1){
        cin>>num;
        arr.push_back(num);
        if(cin.get()=='\n') break;
    }
    int res=INT_MIN;
    for(int ii=0;ii<arr.size()-1;ii++){
        for(int jj=ii+1;jj<arr.size();jj++){
            int temp=arr[jj]-arr[ii];
            if(temp>res) res=temp;
        }
    }
    cout<<res;
}

