#include <iostream>
using namespace std;
template<typename T>
class Shared_ptr{
public:
    Shared_ptr(T* ptr=nullptr):_ptr(ptr),_pcount(new int(1)){}
    Shared_ptr(const Shared_ptr& s):_ptr(s._ptr),_pcount(s._pcount){
        (*_pcount)++;
    }

    Shared_ptr<T>& operator=(const Shared_ptr<T>& s){
        if(this!=&s){
            if(--(*(this->_pcount))==0){
                delete this->_pcount;
                delete this->_ptr;
            }

            this->_ptr=s._ptr;
            this->_pcount=s._pcount;
            (*_pcount)++;
        }
        return *this;
    }

    T* operator->(){
        return this->_ptr;
    }

    T& operator*(){
        return *(this->_ptr);
    }

    ~Shared_ptr(){
        if(--(*(this->_pcount))==0){
                delete this->_pcount;
                this->_pcount=nullptr;
                delete this->_ptr;
                this->_ptr=nullptr;
            }
    }
private:
    T* _ptr;
    int* _pcount;
};
int main(){
    Shared_ptr<int> sp1(new int(1));
    Shared_ptr<int> sp2(sp1);
    Shared_ptr<int> sp3;
    sp3=sp2;
}