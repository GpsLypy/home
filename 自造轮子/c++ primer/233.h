/* ************************************************************************
> File Name:     233.h
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Fri 16 Jul 2021 04:53:36 PM CST
> Description:   
 ************************************************************************/

#ifndef __233__H
#define __233__H
#include <string>
#include <iostream>
using namespace std;
class Person{
 friend istream& read(istream &is,Person& per);
 friend ostream& printf(ostream &os,const Person& per);
private:
    string strName;
    string strAddress;
public:
    Person()=default;
    Person(const string &name,const string &add){
        strName=name;
        strAddress=add;
    }
   explict Person(istream& is);
   
public:
    string getName() const{
        return strName;
    }
    //常量成员函数只读取数据成员的值，不会做出任何改变
    string getAddress() const{
        return strAddress;
    }
};
   
   
 istream& read(istream &is,Person& per){
    is>>per.strName>>per.strAddress;
    return is;
}
 ostream& printf(ostream &os,const Person& per){
    os<<per.getName()<<per.getAddress();
    return os;
}
 Person::Person(istream& is){
    read(is,*this);
}
  
#endif
