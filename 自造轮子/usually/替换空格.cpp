#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count=0;//统计空格数量
        int Oldsize=s.size();//计算整个字符串长度

        for(int ii=0;ii<Oldsize;ii++){
            if(s[ii]==' ') count++;//统计空格出现的次数
        }

        s.resize(Oldsize+count*2);// 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小

        int Newsize=s.size();//扩充完计算新的大小

        int ii=Oldsize-1,jj=Newsize-1;//ii指针指向旧字符串尾部，jj指向新字符串尾部
        
        // 从后向前将空格替换为"%20";每次都保持ii,jj一起移动，所以最后才是jj-=2;
        for(;ii<jj;ii--,jj--){
            if(s[ii]!=' ') s[jj]=s[ii];
            else{
              s[jj]='0';
              s[jj-1]='2';
              s[jj-2]='%';
              jj-=2;//精妙之处
            }
        }
        return s;

    }
};


void ReplaceBlank(char string[],int len){
    if(string==nullptr||len<=0) return;
    int oldLen=0;
    int blanknum=0;
    
    int ii=0;
    while(string[ii]!='\0'){
        ++oldLen;
        if(string[ii]==' ') ++blanknum;
        ++ii;
    }

    int newLen=oldLen+2*blanknum;
    if(newLen>len) return;

    int indexOld=oldLen;
    int indexNew=newLen;

    while(indexOld>=0&&indexNew>indexOld){
        if(string[indexOld]!=' ') string[indexNew--]=string[indexOld];//indexOld不能--
        else{
            string[indexNew--]='0';
            string[indexNew--]='2';
            string[indexNew--]='%';
        }
        --indexOld;
    }
    
}

int main(){
    char string[]="we are happy.";

    ReplaceBlank(string,20);
    cout<<string<<endl;
}