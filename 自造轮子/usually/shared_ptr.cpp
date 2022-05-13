#include <iostream>
using namespace std;

template<typename T>
class sharedPtr{
public:
    //默认构造、拷贝构造
    sharedPtr(T* ptr=nullptr):_ptr(ptr),_pcount(new int(1)){cout<<"1"<<endl;}//每次创建类的新对象时初始化指针并将引用计数置为1
    
    sharedPtr(const sharedPtr<T>& s):_ptr(s._ptr),_pcount(s._pcount){
        (*_pcount)++;
        cout<<"2"<<endl;
    }

    //拷贝赋值
    sharedPtr<T>& operator =(const sharedPtr<T>& s){
        if(this!=&s){//检查是不是自我赋值
            //减少左操作数所指对象的引用计数，如果引用计数减为0，则删除它所指向的对象以及引用计数
            if(--(*(this->_pcount)) == 0){
                delete this->_ptr;
                delete this->_pcount;//释放自身已有的内存
            }   
            this->_ptr=s._ptr;
            this->_pcount=s._pcount;
            (*_pcount)++;
            cout<<"3"<<endl;
        }
        return *this;
    } 

    //实现操作符*,得到所指的对象
    T& operator* (){
        return *(this->_ptr);
    }    

    //实现操作符->(自己本身也是个对象，把自己的内容插出来)//访问自己内部本身的东西
    T* operator ->(){
        return this->_ptr;
    }

    ~sharedPtr(){
        if(--(*(this->_pcount)) == 0){
            delete _pcount;
            _pcount=nullptr;
            delete _ptr;
            _ptr=nullptr;
            cout<<"~ shared_ptr"<<endl;
        }
    }
private:
    T* _ptr;//指向对象的指针
    int* _pcount;//指向引用计数的指针
};



int main(){
    sharedPtr<int> sp1(new int(1));
    sharedPtr<int> sp2(sp1);
    sharedPtr<int> sp3;
    sp3=sp2;
}