#include <iostream>
#include <vector>

using namespace std;

//读取到一个字符串判断该数的奇偶，然后看最后一位和1与的结果，
int main(){
    string s;

    while(1){
        cin>>s;
        if((s[s.size()-1]-'0') & 1){
            cout<<"是奇数"<<endl;
        }else cout<<"是偶数"<<endl;
    }

    return 0;
}
