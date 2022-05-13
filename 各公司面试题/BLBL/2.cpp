#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

int main(){
    int len=500;
    vector<string> arr;
    string temp;

    while(cin>>temp){
        arr.push_back(temp);
    }
    /*
    for(auto a:arr){
        cout<<a<<endl;
    }
    */
    unordered_set<int> map;
    int x;
    char ch;
    string s;
    vector<int> a;
    istringstream is(arr[0]);
    
    while(is>>x){
         a.push_back(x);
        is>>ch;
    }
    
    for(int ii=0;ii<a.size();ii++){
       map.insert(a[ii]);
    }
    
    int res=0;
    for(int ii=1;ii<arr.size();ii++){
       istringstream is(arr[ii]);
		while(is>>x){
			if(map.find(x)!=map.end()){
                res=x;
            }
        }
    }
 
    cout<<res<<endl;
    
}