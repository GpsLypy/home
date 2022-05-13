/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        int n=matrix[0].size();
        int loop=n/2;
        int startx=0,starty=0;
        int offset=1;
        int mid=n/2;
        int ii,jj;
        while(loop--){
            ii=startx,jj=starty;
            for(jj=starty;jj<starty+m-offset;jj++){
                res.push_back(matrix[startx][jj]);
            }   

            for(ii=startx;ii<startx+n-offset;ii++){
                res.push_back(matrix[ii][jj]);
            }

            for(;jj>starty;jj--){
                res.push_back(matrix[ii][jj]);
            }


            for(;ii>startx;ii--){
                res.push_back(matrix[ii][jj]);
            }

            startx++;
            starty++;

            offset+=2;
        }

        if(n%2) res.push_back(matrix[mid][mid]);
        return res;
    }
};
// @lc code=end

