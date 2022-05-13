/*
象棋问题
时间限制： 3000MS
内存限制： 589824KB
题目描述：
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击（1<=n<=9）。

输入描述
给你一个整数n。

输出描述
返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个不同的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

样例输入
n=4
样例输出
[[.Q.., ...Q, Q..., ..Q.], [..Q., Q..., ...Q, .Q..]]

提示
1 <= n <= 9。

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(int row,int col,vector<string>& path,int n){
    int count=0;
    for(int i=0;i<row;i++){
        if(path[i][col]=='Q'){
            return false;
        }
    }

    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(path[i][j]=='Q'){
            return false;
        }
    }

    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(path[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void backtracking(int n,int row,vector<string>& path,vector<vector<string>>& res){
    if(row==n){
        res.push_back(path);
        return;
    }
    for(int col=0;col<n;col++){
        if(isValid(row,col,path,n)){
            path[row][col]='Q';
            backtracking(n,row+1,path,res);
            path[row][col]='.';
        }
    }
}

void  solveNO(int n,vector<vector<string>>& res){
       res.clear();
      vector<string> path(n,string(n,'.'));
      backtracking(n,0,path,res);
      return;
}
int main(){
    string s;
    cin>>s;
    int size=s.size();
    string s1=s.substr(2,size-2);
    int n;
    n=s1[0]-'0';
    //cin>>n;
    vector<vector<string>> res;

    solveNO(n,res);
    int index=1;
    int count=1;
    cout<<'[';
    for(auto a: res){
        cout<<'[';
        for(auto b:a){
            if(index!=n){cout<<b<<',';cout<<" ";index++;}
            else {cout<<b;index=1;}
        }
        cout<<']';
        if(count!=res.size()){
            cout<<",";
            count++;
        }
    }
    cout<<']';
    cout<<endl;
}

