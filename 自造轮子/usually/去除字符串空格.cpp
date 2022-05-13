#include <iostream>
#include <cstring>
using namespace std;

//遍历源字符串，删除空格
char *remove_blank(char *str)
{
    int index = 0;
    for(int ii=0;ii<strlen(str);ii++){
        if(str[ii] != ' '){
            str[index++] = str[ii];
        }  
    }
    str[index] = '\0';
    return str;
}


int main(){
    char s1[]=" 1 2  34 5 ";
    string s2=" 1 2  34 5 ";
    cout<<remove_blank(s1)<<endl;
}