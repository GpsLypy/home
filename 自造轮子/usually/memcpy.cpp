#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
/*
【函数作用】：memcpy函数用于把源内存（sour所指向的内存区域）拷贝到目标内存（dest所指向的内存区域）
以拷贝的字节数作为循环结束条件。它可以拷贝任何类型的对象，因为函数的参数类型是void*（无类型指针），
但是由于拷贝的过程必须要一个字节一个字节的进行拷贝，所以要把void*强制转化为char*，这样在指针加的时候才会保证每次加一个字节
*/


// 实现strlen函数的功能。
size_t strlen1(const char*  str){
  size_t ii=0;
  
  while (str[ii]!='\0') ii++;
  
  return ii;
}


void*  my_memcpy(void *dst, const void *src, size_t count)
{
    assert(dst!=NULL&&src!=NULL);//加断言
    
    //1、注意此处不进行类型转换
    if(dst<=src||(char*)src+count<=(char*)dst){//源地址和目的地址不重叠，低字节向高字节拷贝  
        void* res = dst;
        while (count--)
        {
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        }
        return res;
    }else{   //源地址和目的地址重叠，高字节向低字节拷贝
        dst=(char*)dst + count -1;
        src=(char*)src + count -1;

        //2、不要把上面两行写到while循环里面
        while(count--){
            *(char*) dst = *(char*) src;
            dst=(char*) dst -1;
            src=(char*) src -1;
        }
    }
    return dst;  
}


// 实现strcpy函数的功能
char *strcpy1(char* dst, const char* src)
{
  assert(dst!=NULL&&src!=NULL);

  char* ret;
  my_memcpy(dst,src,strlen(src)+1);

  return ret;
}



int main()
{
    char str[10]="abc";  
    strcpy1(str+1,str); 
    cout<<str<<endl;
    

    char arr1[10] = { 0 };
    char arr2[20] = "abcdef";
    cout<<arr2[0]<<endl;
    cout<<arr1[0]<<endl;
    my_memcpy(arr2, arr1, 6);
    cout<<arr1[0]<<endl;
    cout<<arr2[0]<<endl;
    return 0;
}



