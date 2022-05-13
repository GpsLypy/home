#include <iostream>
#include <string>
using namespace std;

int main(){
    try{
        char* p=new char[100000000000000000];
        delete p;
    }
    catch(const std::bad_alloc &ex){
        cout<<ex.what()<<endl;
    }
    return  0;
}