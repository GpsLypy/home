#include <iostream>
using namespace std;

class allocator1{
private:
    struct obj{
        struct obj* next;//embedded pointer
    };
public:
    void* allocate(size_t);
    void deallocate(void*,size_t);
private:
    obj* freeStore=nullptr;
    const int CHUNK=5;
};

int main(){
    cout<<sizeof(allocator1)<<endl;//8
    return 0;
}