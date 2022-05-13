//最大最小堆 最大数->最小堆 最小数->最大堆
//最小堆的插入时间复杂度log(n) 初始化时间复杂度nlog(n)

struct Node{
    int value;
    int idx;
    Node(int v,int i):value(v),idx(i){}
    friend bool operator <(const struct Node &n1,const struct Node &n2);
};


 friend bool operator <(const struct Node &n1,const struct Node &n2){
     return n1.val<n2.val;
 }

 priority_queue<Node> pq;//此时pq为最大堆