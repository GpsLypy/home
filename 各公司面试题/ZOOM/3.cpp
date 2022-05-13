#include <iostream>
#include <vector>

using namespace std;

    int maxA(int N) {
        // dp数组含义：按键i次后屏幕显示dp[i]个A
        vector<int> dp(N + 1, 0);
        // 压缩为2个选择 → [1]按A;[2]按Ctrl-V (包含前方必有的Ctrl-A + Ctrl-C)
        for (int i = 1; i <= N; i++) {
            // [1]按A
            dp[i] = dp[i - 1] + 1;
            // [2]按Ctrl-V (包含前方必有的Ctrl-A + Ctrl-C)
            //(需通过额外变量j来确定Ctrl+C的位置，从而确定剪贴板中A的个数dp[j - 2]）)
            for (int j = 2; j < i; j++) 
                // dp[j - 2]表示剪贴板中A的个数，减去的2即为CA + CC两个组合键
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1)); // 最多可按(i-j)次C_V,还要加上本身，所以可以看做可按(i - j + 1)个Ctrl-V
        }
        return dp[N];
    }

int main(){
    int res=maxA(499);
    cout<<res<<endl;
}