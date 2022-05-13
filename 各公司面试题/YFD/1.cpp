

/*
小猿非常热爱学习，所以他在猿辅导上购买了N节课来提升自己，每节课有一个开始时间S和结束时间E（S和E均用正整数表示）。
买完课程后，粗心的小猿发现这些课程之间有些时间冲突，幸好小猿有一种“一心多用”的超能力，
能同时兼顾K节课上课。当然是K越大，使用这种能力就越累。请问小猿最少需要一心几用，才能上完所有他买的课程呢？


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int minK(vector<vector<int>>& points){
        sort(points.begin(),points.end(),cmp);

        int k=1;
        int maxcount=1;
        int temp=1;
        for(int ii=1;ii<points.size();ii++){
            if(points[ii][0]>=points[ii-1][1]){//不挨着
                k++;
                temp=1;
            } 
            else{
                points[ii][1]=min(points[ii-1][1],points[ii][1]);
                temp++;
                maxcount=max(maxcount,temp);
            }
        }
        return maxcount;
    }
};


int N;
int main(){
    cin>>N;
    vector<vector<int>> points(N,vector<int>(2,0));
    for(int ii=0;ii<N;ii++){
        vector<int> path(2,0);
        cin>>path[0]>>path[1];
        points[ii]=path;
    }
    
    Solution s;
    int res=s.minK(points);
    cout<<res;
    return 0;
}
*/

#include<bits/stdc++.h>

using namespace std;
int main(){
    //freopen("in.dat", "r", stdin);
    int n; cin >> n;
    map<int,int> idx;
    for(int i = 0; i < n; i++){
        int s,e; cin >> s >> e;
        idx[s]++;
        idx[e]--;
    }
    vector<int> t;
    for(auto x:idx){
        t.push_back(x.second);
    }
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < idx.size(); i++){
        cur += t[i];
        ans = max(ans,cur);
    }
    cout << ans << endl;
    return 0;
}