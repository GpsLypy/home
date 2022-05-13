#include <bits/stdc++.h>
using namespace std;


class Product{
public:
    virtual void show()=0;
    virtual ~Product(){};
};

class ProductA:public Product{
public:
    void show(){
        cout<<"ProductA"<<endl;
    }
    ~ProductA(){
        cout<<"~ProductA"<<endl;
    }
};

class ProductB:public Product{
public:
    void show(){
        cout<<"ProductB"<<endl;
    }
    ~ProductB(){
        cout<<"~ProductB"<<endl;
    }
};

class Factory{
public:
    Product* createProduct(const string& Type){
        if(Type=="A") return new ProductA;
        if(Type=="B") return new ProductB;
        return nullptr;
    }
};

int main(){
    Factory f;
    Product* ff=f.createProduct("A");
    ff->show();
    return 0;
}