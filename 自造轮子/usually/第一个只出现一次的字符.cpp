#include <iostream>
#include <string>

using namespace std;


int FirstNotRepeatingChar(string str){
    int map[256]={0};

    for(int ii=0;ii<str.size();ii++){
        map[str[ii]]++;
    }

    for(int ii=0;ii<str.size();ii++){
        if(map[str[ii]]==1) return ii;//返回对应字符对应的下标
    }

    return -1;
}
int main(){
    string s="aa";
    int res=FirstNotRepeatingChar(s);
    cout<<res<<endl;
}