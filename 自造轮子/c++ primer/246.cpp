/* ************************************************************************
> File Name:     246.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 17 Jul 2021 05:44:45 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include "246.h"
using namespace std;
int main(){
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout<<"\n";
    myScreen.display(cout);
    cout<<"\n";
    cout<<myScreen.size()<<endl;
    cout<<"\n";
    Window_mgr w;
    w.clear();
    
    vector<int> vec{3,2,1};
    for(auto a:vec){
        cout<<a<<endl;
    }
    
    return 0;
}


