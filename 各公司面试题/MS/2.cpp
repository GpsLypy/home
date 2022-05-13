#include <iostream>
#include <stack>
#include <list>
#include <map>
#include <stddef.h>
using namespace std;

int a=10;
int main(){
    /*
    stack<int> s;
    for(int ii=0;ii<10;ii++){
        s.push(ii+1);
    }
    cout<<"s.top()="<<s.top()<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    */


   /*
   list<int> list1;
   list1.push_back(2);
   list1.push_back(3);
   list1.push_back(5);
   
   //for(int ii=0;ii<list1.size();ii++){
   //    cout<<list1[ii]<<endl;
   //}
   

   auto it=list1.begin();
   for(;it!=list1.end();it++){
       cout<<*it<<" ";
   }
   cout<<endl;

   */
   
   /*
   map<int,string> m;
   pair<int,string> p1(3,"hello");
   pair<int,string> p2(6,"world");
   m.insert(p1);
   m.insert(p2);
   cout<<m[3]<<endl;
   cout<<m[6]<<endl;

   map<int,string>::iterator itor=m.begin();
   for(;itor!=m.end();itor++){
       cout<<itor->first<<endl;
       cout<<itor->second<<endl;
       cout<<endl;
   }
   */
/*
   struct _test{
       char a;//1
       int b;//4
       short c;//2
   }test;

   cout<<sizeof(test)<<endl;
   cout<<alignof(test)<<endl;
   cout<<offsetof(_test,a)<<endl;
   cout<<offsetof(_test,b)<<endl;
   cout<<offsetof(_test,c)<<endl;
   */
struct S{
      int x;
      char y;
      int z;
      double a;
  };
   cout<<sizeof(S)<<endl;
   cout<<alignof(S)<<endl;
   cout<<offsetof(S,x)<<endl;
   cout<<offsetof(S,y)<<endl;
   cout<<offsetof(S,z)<<endl;
   cout<<offsetof(S,a)<<endl;
   cout<<sizeof(char*)<<endl;

 //  int a=99;
   cout<<a<<endl;
   return 0;
}