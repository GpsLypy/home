#include <forward_list>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    forward_list<int> f1;
    f1.push_front(1);
    f1.push_front(3);
    f1.push_front(2);
    f1.push_front(6);
    f1.push_front(5);

    forward_list<int>::iterator ite1=f1.begin();
    forward_list<int>::iterator ite2=f1.end();

    for(;ite1!=ite2;++ite1){
        cout<<*ite1<<" ";
    }
    cout<<endl;

    ite1=find(f1.begin(),f1.end(),2);
    if(ite1!=ite2){
        f1.insert_after(ite1,99);
    }

    for(auto it : f1) cout<<it<<" ";
    cout<<endl;

    ite1=find(f1.begin(),f1.end(),6);
    if(ite1!=ite2){
        f1.erase_after(ite1);
    }

    for(auto it : f1) cout<<it<<" ";
    cout<<endl;

    return 0;
}