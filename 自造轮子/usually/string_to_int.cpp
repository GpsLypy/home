#include <bits/stdc++.h>
using namespace std;

int StringToInt(string &s){
    //1、考虑字符串为空的情况
    if (s.empty()) {
		cout<<"字符串为空"<<endl;
		return 0; //字符串为空 非法返回0
	}

    //去除字符串前部的空格
	int ii = 0;
    int size=s.size();
    bool minus = false; //用于标示是正号还是负号
	for (; ii < size; ii++) {
		if (s[ii] != ' ')
			break;
	}

    //判断非法字符和正负号
    if( (s[ii]<'0'||s[ii]>'9')&&(s[ii]!='+'&&s[ii]!='-') ) {
        cout<<"含有非法字符"<<endl;
        return 0;
    }else if(s[ii]=='+'){
        ii++;
    }else if(s[ii]=='-'){
        ii++;
        minus=true;
    }
    
    long num=0;    //开始遍历有效数字部分
    for(;ii<size;++ii){
        if(s[ii]>='0'&&s[ii]<='9'){
           num=num*10+s[ii]-'0';//核心处理逻辑(从前向后遍历字符串)
           //考虑最大正整数和最小负整数以及溢出
          // cout<<"11"<<endl;
           cout<<num<<endl;
           if(!minus&&num>=INT_MAX){
               cout<<"已超出整数所表示的范围"<<endl;
               num=INT_MAX;
               break;
           }
        }
        else if(s[ii]==' ') continue;
        else {
            num=0;
            cout<<"转换过程出现非法字符"<<endl;
            break;
        }
    }
    num=minus? -num : num;
    return num;
}
int main(){
    string s="12345678900";
    cout<<StringToInt(s)<<endl;
    return 0;
}