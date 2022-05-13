/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int startx=0,starty=0;
        int loop=n/2;//循环圈数
        int mid=n/2;
        int offset=1;
        int count=1;
        while(loop--){
            int ii=startx;
            int jj=starty;

            for(jj=starty;jj<n-offset+starty;jj++){
                res[ii][jj]=count++;
            }

            for(ii=startx;ii<n-offset+startx;ii++){
                res[ii][jj]=count++;
            }

            for(;jj>starty;jj--){
                res[ii][jj]=count++;
            }

            for(;ii>startx;ii--){
                res[ii][jj]=count++;
            }

            startx++;
            starty++;
            offset+=2;
        }

        if(n%2) res[mid][mid]=count;
        return res;
    }
};
// @lc code=end

