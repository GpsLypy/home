/* ************************************************************************
> File Name:     116.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Mon 21 Jun 2021 09:07:48 PM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

/*
int main(){
    int ia[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    cout<<"利用范围for语句输出多维数组的内容："<<endl;
    for(int (&row)[4] : ia){
        for(int &col : row)
            cout<<col<<" ";
    }
    cout<<endl;
    cout<<"利用普通for语句和下标运算符输出多维数组的内容："<<endl;
    for(int ii=0;ii<3;ii++){
        for(int jj=0;jj!=4;jj++){
            cout<<ia[ii][jj]<<" ";
        }
    }
    cout<<endl;

    cout<<"利用普通for语句和指针输出多维数组的内容："<<endl;
    for(int (*p)[4]=ia;p!=ia+3;p++){
        for(int *q=*p;q!=*p+4;q++){
            cout<<*q<<" ";
        }
    }
    cout<<endl;
      
    return 0;
}
*/
int main(){
    int ia[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    using int_array=int[4];
    
    cout<<"利用范围for语句输出多维数组的内容："<<endl;
    for(int_array &row : ia){
        for(int &col : row)
            cout<<col<<" ";
    }
    cout<<endl;
    cout<<"利用普通for语句和下标运算符输出多维数组的内容："<<endl;
    for(int ii=0;ii<3;ii++){
        for(int jj=0;jj!=4;jj++){
            cout<<ia[ii][jj]<<" ";
        }
        cout<<endl;
    }
    

    cout<<"利用普通for语句和指针输出多维数组的内容："<<endl;
    for(int_array *p=ia;p!=ia+3;p++){
        for(int *q=*p;q!=*p+4;q++){
            cout<<*q<<" ";
        }
        cout<<endl;
    }
  
      
    return 0;
}

