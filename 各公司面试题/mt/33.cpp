/*

小美在数轴上放置了若干个机器人，这些机器人每到整数时刻，就会检查是否和其他机器人重合。如果重合，它就会原地爆炸。

这些机器人的移动速度均为 1 。举例来说，如果一个机器人初始位于点3，然后它的方向是向右的，则时刻1会位于点4，时刻2会位于点5。

小美现在给小团这样一个任务：小美将给出所有机器人的初始位置和初始朝向。小团的任务是判断每个机器人的爆炸时刻。当然，如果有一些机器人永远不会爆炸，则输出-1。

小团向你求助。你能帮帮小团吗？

注意事项1：一个机器人爆炸了之后，就不会再继续存在在这个数轴上。

举例来说，如果有三个机器人，一个位于位置0，向右，一个位于位置2，向右，一个位于位置4，向左。则时刻1的时候，后两个机器人会在位置3相遇并发生爆炸，此后第一个机器人和第三个机器人不会在时刻2继续爆炸（因为此时已经不存在第三个机器人了）

注意事项2：请注意，只有整数时刻机器人才会检查重合。

举例来说，如果有两个机器人，一个位于位置1，向右，一个位于位置2，向左，则它们并不会在整数时刻重合。因此它们两个不存在相遇爆炸。

注意事项3：保证机器人初始时刻不会重叠。换句话说，不存在在时刻0就立刻爆炸的机器人。

第一行一个正整数 n 表示有 n 个机器人。

接下来 n 行，每行一个正整数和一个字符，以空格分隔。正整数代表机器人的坐标，字符为大写字母 L 和 R 的其中一个，分别表示机器人向左运动 和 向右运动。


输出 n 行，每行一个数字，对应表示每个机器人的答案：

若该机器人会爆炸，输出爆炸时间；若该机器人不会爆炸，输出-1。


样例输入
10
94 R
74 L
90 L
75 R
37 R
99 R
62 R
4 L
92 L
44 R
样例输出
-1
6
23
-1
-1
-1
6
-1
-1
23
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

void calc(vector<pair<int, char>> robots){
    int n = robots.size();
    vector<int> robotsL, robotsR, res(n, -1);
    unordered_map<int, int> subs;//记录机器人放入顺序的原本位置
    for(int i = 0; i < robots.size(); i++) {
        subs[robots[i].first] = i;
        if(robots[i].second == 'L') robotsL.push_back(robots[i].first);
        else robotsR.push_back(robots[i].first);
    }
    
    sort(robotsL.begin(), robotsL.end());
    sort(robotsR.begin(), robotsR.end());
    /*
    int  i = 0;
    while(i < robotsL.size()){//往左走的机器人从小往大取
        int j = robotsR.size();//往右走的机器人从大往小取
        while(j > 0){
            j--;
            if(robotsR[j] > robotsL[i]) continue;//不产生碰撞
            if((robotsL[i] - robotsR[j]) % 2 != 0) continue;//不产生碰撞，错开了
            int s = (robotsL[i] - robotsR[j]) / 2;//走S步会发生碰撞
            res[subs[robotsL[i]]] = s;//在原始机器人所在位置记录结果
            res[subs[robotsR[j]]] = s;
            robotsL.erase(robotsL.begin() + i);//销毁发生碰撞的机器人
            robotsR.erase(robotsR.begin() + j);
            i--;
            j+=9999999;
            break;
        }
        i++;
    }
    */

    for(int ii=0;ii<robotsL.size();ii++){
        int jj=robotsR.size();
        while(jj>0){
            jj--;
            if(robotsR[jj]>robotsL[ii]) continue;
            if((robotsL[ii] - robotsR[jj]) % 2 != 0) continue;//不产生碰撞，错开了
            int s = (robotsL[ii] - robotsR[jj]) / 2;//走S步会发生碰撞
            res[subs[robotsR[jj]]]=s;
            res[subs[robotsL[ii]]]=s;
            robotsR.erase(robotsR.begin()+jj);
            robotsL.erase(robotsL.begin()+ii);
            ii--;
            break;
        }
        //ii++;
    }

    for(int i = 0;i < res.size(); i++){
        cout << res[i] << endl;
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, char>> robots(n);
    for(int i = 0; i < n; i++){
        cin >> robots[i].first >> robots[i].second;
    }
    calc(robots);
    return 0;
}










