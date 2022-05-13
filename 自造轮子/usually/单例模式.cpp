//介绍：简单的说就是让一个类只能实例化一个对象

//1、将构造函数和指向Singleton实例的指针设置为private
//2、当客户端调用getInstance时，判断p是否已经指向一个实例
//场景：重量级对象，不需要多个实例，如线程池，数据库连接池


//懒汉式是以时间换空间，适应于访问量较小时；推荐使用内部静态变量的懒汉单例，代码量少
//饿汉式是以空间换时间，适应于访问量较大时，或者线程比较多的的情况(本身就是线程安全的)

#include <iostream>
#include <mutex>
using namespace std;

//饿汉模式
class singleton{
private:
    singleton(){cout<<"hello-singleton..."<<endl;}//构造函数私有化,外部new不了
    static singleton*  p;//指向Singleton实例的指针也私有化

public:
    //由于外部不允许创建对象，
    //所以我们必须提供一个静态的方法来让外部可以获取到内部生成的实例
    static singleton* getInstance(){
        return p;
    } 

};

singleton* singleton:: p=new singleton();



//懒汉模式：延迟加载，只有在真正使用的时候，才开始实例化
//线程安全问题
//加锁优化
//防止编译器对指令重排，导致使用到尚未初始化的实例，volatile关键字

class singleton2{
private:
    singleton2(){cout<<"hi"<<endl;}
    static singleton2* _instance;//volatile
public:
    static singleton2* getInstance(){//static不通过对象就可以调用，也就是说提供了一种全局访问方法
        if(_instance==nullptr){
            _instance=new singleton2();
        }
        return _instance;
    }
};

singleton2* singleton2::_instance=nullptr;


//上述懒汉式单例模式存在问题：不可以用于多线程环境；也就是存在线程安全问题
//防止编译器对指令重排，导致使用到尚未初始化的实例，volatile关键字


//改进方法一：加同步(双检)锁前后两次判断实例是否存在，确保在多线程环境下只创建一个实例
//面试写出这种即可（可以在多线程环境下工作，又能防止实例被过早创建）
//双检锁懒汉模式
class singleton3{
private:
    singleton3(){ cout<<"hi 我是singleton3"<<endl; }
    static singleton3* _instance;//volatile
    static std::mutex mymutex; 
public:
    static singleton3* getInstance(){//static不通过对象就可以调用，也就是说提供了一种全局访问方法
        if(_instance==nullptr){
            //加锁
            std::unique_lock<std::mutex> lock(mymutex);
            if(_instance==nullptr){
                _instance=new singleton3();
            }
            //自动解锁
        }
        return _instance;
    }
};

singleton3* singleton3::_instance=nullptr;
std::mutex singleton3::mymutex;


//使用 (局)部静态变量 的懒汉单例（C++11线程安全，推荐）
class singleton4{
public: 
    static singleton4* getInstance(){
        static singleton4 s;
        return &s;
    }
private:
    singleton4(){cout<<"hi 我是singleton4"<<endl;}
};

int main(){
    //singleton* p1=singleton::instance();
    singleton2* p2=singleton2::getInstance();
    singleton2* p3=singleton2::getInstance();
    singleton3* p4=singleton3::getInstance();
    singleton4* p5=singleton4::getInstance();
    if(p2==p3) cout<<"相同"<<endl;
    delete p2;
    //delete p3; //sgn1 share same point with p2, so deleting p3 will make error
    return 0;
}


