#include <iostream>
#include <cstring>
using namespace std;

/*
//手动实现string类
class Mystring{
public:
    Mystring(const char* p=nullptr){
        if(p){
            _p=new char[strlen(p)+1];
            strcpy(_p,p);
        }else{
            _p=new char[1];
            *_p='\0';
        }
    };
    //拷贝构造函数
    Mystring(const Mystring& s){
        _p=new char[strlen(s._p)+1];
        strcpy(_p,s._p);
    };
    //拷贝赋值函数
    Mystring& operator=(const Mystring& s){//1、返回值的类型为该类型的引用，传入的参数类型声明为常量的引用
        if(this!=&s){//2、检查是不是自我赋值
            delete[] _p;//3、分配新内存之前，是否释放实例自身已有的内存
            this->_p=new char[strlen(s._p)+1];
            strcpy(_p,s._p);
        }
        return *this;
    }
    ~Mystring(){};
private:
    char* _p;
};
*/

class Mystring{
public:
    Mystring(const char* p=nullptr){
        if(p){
            _p=new char[strlen(p)+1];
            strcpy(_p,p);
            cout<<"1"<<_p<<endl;
        }else{
            _p=new char[1];
            *_p='\0';
        }
    };
    //拷贝构造函数
    Mystring(const Mystring& s){
        _p=new char[strlen(s._p)+1];
        strcpy(_p,s._p);
        cout<<"2"<<_p<<endl;//打印指针_p所指对象的内容
    };
    //拷贝赋值函数（在赋值运算符函数中实现异常安全性）
    Mystring& operator=(const Mystring& s){//1、返回值的类型为该类型的引用，传入的参数类型声明为常量的引用
        if(this!=&s){//2、检查是不是自我赋值
           Mystring strTemp(s);//创建临时实例
           char *ptemp=strTemp._p;//交换实例自身的_p和strTemp的_p
           strTemp._p=_p;
           _p=ptemp;
           cout<<"3"<<_p<<endl;
        }
        return *this;
    }
    ~Mystring(){};
private:
    char* _p;
};


int main(){
    char temp[]="abcde";
    Mystring s1(temp);//默认构造
    Mystring s2=s1;//拷贝构造
    Mystring s3;//赋值运算符
    s3=s2;
    return 0;
}