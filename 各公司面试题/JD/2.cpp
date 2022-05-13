/*
01比
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小明有一个只包含0和1的字符串，现在小明希望将整个字符串尽可能的切割成多个字符串，
要求是每个字符串里面0出现的次数和1出现的次数的比例是一致的。
解释：假设一个字符串出现0的次数是a次，出现1的次数是b，
另一个字符串出现0的次数是c次，出现1的次数是d次，
那么这两个字符串01出现次数比例相同表示a:b=c:d，即a*d=b*c。
注意这里a,b,c,d都是可以为0的。现在对于一个字符串的所有前缀字符串，输出最多可以切割成多少个符合要求的字符串。



输入描述
第一行一个整数n，表示01字符串的长度，1<=n<=500000

第二行一个长度为n的01字符串。

输出描述
一行n个整数，第i个数表示原字符串中下标由0到i组成的前缀字符串可以切割出多少符合要求的字符串。


样例输入
3
001
样例输出
1 2 1

提示
第一个前缀字符串是0，没法切，答案是1

第二个前缀字符串是00，可以切得到0，0，答案是2

第三个前缀字符串是001，可以切，但是切后没法保证比例要求，因此答案是1



样例2：

输入：

4

0000

输出：

1 2 3 4

 

样例3：

输入：

4

0101

输出：

1 1 1 2

 

样例4：

输入：

9

010100001

输出：

1 1 1 2 1 2 1 1 3
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    vector<int> res;
    while(1){
        cin>>s;
        if(s.size()==n) break;
    }

    cout<<s.size()<<endl;

    int index=1;
    while(index<s.size()+1){
        string s1=s.substr(0,index++);
        //cout<<"s1="<<s1<<endl;
        if(s1.size()==1) {
            res.push_back(1);
            continue;
        }

        if(s1.size()%2==0){
            int count1=0,count0=0;
            for(auto a:s){
                if(a=='0') count0++;
                else count1++;
            }
            if(count0==s1.size()||count1==s1.size()) res.push_back(s1.size());

            if(count0==count1) res.push_back(s1.size()/2);//
            continue;
        }

        if(s1.size()%2==1){
            int count0=0,count1=0;
            for(auto a:s1){
                if(a=='0') count0++;
                else count1++;
            }
            if(count1!=count0) res.push_back(1);
        }

    }

    for(auto b: res){
        cout<<b<<" ";
    }

    cout<<endl;


    return 0;
}
