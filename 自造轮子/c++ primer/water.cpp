/* ************************************************************************
> File Name:     water.cpp
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sun 20 Jun 2021 04:33:32 PM CST
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

 class Solution {
public:
     static void buywater(){
            int money = 20; //20块钱
            int water = money;//一块钱买一瓶水
            int bottle = 0; //空瓶数量
            int bottleCap = 0;//瓶盖数量
            int index = 0; //计数 
            while(true){ //自制死循环，需要自己创建条件跳出循环
               index += water;  // 一共喝了多少水
               bottle += water;  //一瓶水喝完得一个空瓶
               bottleCap += water; //一瓶水喝完得一个瓶盖

               water = 0; //水喝完了

               water += bottle/2; //两个空瓶换一瓶水
               bottle = bottle%2; //剩下得空瓶(0 or 1)

               water += bottleCap/3; //三个瓶盖换一瓶水
               bottleCap = bottleCap%3; //剩余的瓶盖(0 or 1 or 2)
               if(water<=0){//当没水的时候跳出循
                      break;
                    }
                }
               cout<<index<<endl;
            }
};


int main(){
 Solution s;
 s.buywater();
return 0;
}
