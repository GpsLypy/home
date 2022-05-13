#include <iostream>
#include<vector>
using namespace std;
int T,st,position;
int main()
{
    cin>>T;//测试组数
    while(T--){
        cin>>position>>st;//给定初始位置和要走的步数
        //确定dp数和下标的含义
        vector<vector<double>>dp(61,vector<double>(st+1,0.0));
        //dp数组的初始化
        dp[0][1] = dp[60][1] = 0.50;  //dp[x][y]为从x位置开始，走y步掉下去的概率
        //dp公式的推导
        for(int i=2;i<=st;i++){
            for(int j = 0;j<61;j++){
                if(j==0){
                    dp[j][i] = (dp[j+1][i-1]+1.0)/2;
                }else if(j==60){
                    dp[j][i] = (dp[j-1][i-1]+1.0)/2;
                }else{
                    dp[j][i] = (dp[j+1][i-1]+dp[j-1][i-1])/2;
                }
            }
        }
        //格式化输出
        printf("%.8lf\n",1.0-dp[position][st]);
    }
    return 0;
}