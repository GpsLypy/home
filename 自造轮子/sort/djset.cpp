/*
并查集是一种用来合并不相交集合的数据结构（虽然我在视频里面写得非常不像数据结构）。
一个比较常用的地方是：用来检测一个图里面是不是包含有环。这个结构在Kruskal算法（最小生成树）里面有非常重要的作用
*/

#include <bits/stdc++.h>
using namespace std;

#define VERTICES 6

void initialise(int parent[],int rank[]){
    for(int ii=0;ii<VERTICES;ii++){
        parent[ii]=-1;
        rank[ii]=0;
    }
}

int find_root(int x,int parent[]){
    int x_root=x;
    while(parent[x_root]!=-1){
        x_root=parent[x_root];
        cout<<"111"<<endl;
    }
    return x_root;
}

int union_vertices(int x,int y,int parent[],int rank[]){
    int x_root=find_root(x,parent);
    int y_root=find_root(y,parent);
    if(x_root==y_root){
        return 0;
    }else{
        //parent[x_root]=y_root;//会出现长链问题，要做路径压缩
        if(rank[x_root] > rank[y_root]){
            parent[y_root]=x_root;
        }else if(rank[y_root > rank[x_root]]){
            parent[x_root]=y_root;
        }else{
            parent[x_root]=y_root;//
            rank[y_root]++;
        }
        return 1;
    }
}
int main(){
    int parent[VERTICES]={0};
    int rank[VERTICES]={0};
    //把图打进去:6条边，每条边带两个顶点
    int edges[6][2]={
        {0,1},{1,2},{1,3},
        {3,4},{2,5},{5,4}
    };
    initialise(parent,rank);
    for(int ii=0;ii<6;ii++){
        int x=edges[ii][0];
        int y=edges[ii][1];
        //cout<<ii<<endl;
        if(union_vertices(x,y,parent,rank)==0){
            cout<<"Cycle detected!"<<endl;
            exit(0);
        }
    }
    cout<<"No detected!"<<endl;
    return 0;
}