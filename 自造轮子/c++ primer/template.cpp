#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
int compare(const T& v1,const T& v2){
    if(v1>v2) return -1;
    if(v1<v2) return 1;
    return 0;
}

//模板特例化
template<>
int compare(const char* const& v1,const char* const& v2){
    cout<<"hello"<<endl;
    char str[3]="88";
    strcpy(v1,str);
    cout<<*v1<<"yyy"<<endl;
    return strcmp(v1,v2);
}

template <typename T>
void fun(T a)
{
	cout << "The main template fun(): " << a << endl;
}

template <>   // 对int型特例化
void fun(int a)
{
	cout << "Specialized template for int type: " << a << endl;
}

/*
int main()
{
	fun<char>('a');
	fun<int>(10);
	fun<float>(9.15);
	return 0;
}
*/
int func(int const& val){
    cout<<val<<endl;
    return val;

}






int main(){
    //函数特例化
    cout<<compare(122,21)<<endl;
    char s1[3]="6",s2[3]="23";
    cout<<compare<const char*>(s1,s2)<<endl;
    //cout<<compare<const char*>("hi","ho")<<endl;
    //cout<<compare<const char*>("hi","ho")<<endl;

    fun<char>('a');
	fun<int>(10);
	fun<float>(9.15);
    //cout<<func(99)<<endl; 


    //类特例化
    return 0;
}
