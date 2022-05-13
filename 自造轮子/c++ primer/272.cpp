#include "271.h"
using namespace std;

double Example::rate=6.5;//静态成员的定义不能在函数内，所以要放在外面
const int Example::vecSize;
vector<double> Example::vec(vecSize);
int main(){
   
    return 0;
}