/*
奇怪的键盘
题目描述：
小美得到了一个奇怪的键盘，上面一共有53个按键，包括26个小写字母、26个大写字母和空格。这个键盘的奇怪之处如下：

当小美按下一个按键时，该按键可能会被多次触发，即输出一连串按下按键所对应的字符。键盘会时不时地自动按下空格键。

在使用这个键盘来进行输入时，小美保证了相邻两次按下的按键一定不同以及不主动按下空格键，

现在给你小美使用这个键盘输入一个字符串后得到的结果，请你还原小美原本想要输入的这个字符串。
输入描述
        一行，一个包含小写字母、大写字母和空格的字符串，表示小美输入后得到的结果。

输出描述
        输出一行，表示小美原本想要输入的字符串。


样例输入
        a iC C  C GmyyyySp p
        样例输出
aiCGmySp

        提示
数据范围和说明

30%的数据保证 输入的字符串长度<=20

60%的数据保证 输入的字符串长度<=1000

100%的数据保证 输入的字符串长度<=100000
*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    string str;
    getline(cin,str);
    string ret;
    for(int i=0 ; i<str.size() ;i++){
        if(str[i] == ' ')
            continue;
        else{
            ret+=str[i];
            int tmp = i+1;
            while( tmp <str.size() && (str[tmp] == str[i] || str[tmp] == ' ') )
                tmp++;
            i = tmp-1;
        }
    }
    cout<<ret<<endl;
    return 0;
    
/*
   string s=" ",res;
   char temp;
   getline(cin,s);
    for(int ii=0;ii<s.size();ii++){
       cout<<"temp:"<<temp<<endl;
       if(s[ii]==' '){
            continue;
            cout<<"res:"<<res<<endl;
        }
       else if(ii>=1&&s[ii]==s[ii-1]||s[ii]==temp) {
           cout<<"res:"<<res<<endl;
           continue;
        }
       res+=s[ii];
       temp=s[ii];
       cout<<"res:"<<res<<endl;
    }
   
   cout<<res<<endl;
   return 0;
*/
}