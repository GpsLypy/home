/*
小美现在有一个字符串，小美现在想知道能不能通过在字符串的尾端增加若干字符使得整个字符串变成一个回文串。

回文串的定义：若一个字符串，对他正序遍历和倒序遍历得到的结果是完全一致的，就称它是一个回文串。例如 abcba 就是一个回文串，因为无论正序还是倒序都是一样的。

 

对于字符串 abaaca，显然在该字符串末尾继续补上三个字符 aba 就可以构成 abaacaaba，就可以把原字符串变成回文串。换句话说，最少补上三个字符。

你的任务就是找到使得原来的字符串变成回文串所需要的最少字符数量。

* 本题数据保证没有空串，因此不考虑空串是否为回文串。

保证输入的字符串仅包含小写字母。

*/

//思路：双指针加中心扩散
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int len=s.size();
    int pos=0;
    int flag=0;
    //如果给定字符串包含了未来的中轴,那么我们就要找到这个中轴所在的位置，故采用双指针加中心扩散的方法
    //1、找出给定字符串的中间位置 2、放入midr,mid指针，在其左侧和做左侧分别放置ll,rr指针
    //为了找到一个字符串最中间两个位置，则ii=(len+1)/2  比如abaaca(aa) abaac(aa)
    for(int ii=(len+1)/2;ii<len;ii++){
        int mid=ii-1,midr=ii,ll=ii-2,rr=ii;
        //中轴特点是中轴左右两边是对称的，中轴分别和其左右不对称
        //两种情况1、mid==midr,则mid不是中轴，mid,midr要向外扩散,对应的flag==1
        //2、mid!=midr，则可能mid就是中心轴，ll,rr要向外扩散，flag==-1
        //两种情况看谁先到达
        while(midr<len&&s[mid]==s[midr]){
            mid--;
            midr++;
        }
        
        while(rr<len&&s[ll]==s[rr]){
            ll--;
            rr++;
        }

        if(midr==len){
            pos=ii-1;
            flag=1;
            break;
        }
        //如果Mid是中心轴，则rr先扩散到外面
        if(rr==len){
            pos=ii-1;
            flag=-1;
            break;
        }
    }
    
    if(flag==1){
        cout<<pos*2-len<<endl;
    }else if(flag==-1){
        cout<<(pos*2+1)-len<<endl;
    }else cout<<len-1<<endl;

    return 0;
}


