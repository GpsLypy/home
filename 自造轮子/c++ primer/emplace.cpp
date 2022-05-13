#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Person{
    string name;
    int age;
    //初始化构造函数
    Person(string p_name,int p_age):name(std::move(p_name)),age(p_age){
        cout<<"I have been constructed"<<endl;
    }
    //拷贝构造函数
    Person(const Person& other):name(std::move(other.name)),age(other.age){
        cout<<"I have been copy constructed"<<endl;
    }
    //转移构造函数
    Person(Person&& other):name(std::move(other.name)),age(other.age){
        cout<<"I have been moved"<<endl;
    }

};

int main(){
    vector<Person> e;
    cout<<"emplace_back"<<endl;
    e.emplace_back("Jane",23);

    vector<Person> p;
    cout<<"push_back:"<<endl;
    p.push_back(Person("Mike",24));

    
    Person s("qwe",22);
    cout<<"test push_back"<<endl;
    p.push_back(Person(s));
    cout<<"test emplace_back"<<endl;
    e.emplace_back(Person(s));

    return 0;

}