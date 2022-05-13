
//第一版
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
       if(m==0){
           for(int ii=0;ii<n;ii++){
               A[ii]=B[ii];
           }
       } 
       while(m&&n){
           if(A[m-1]<=B[n-1]) {
               A[m+n-1]=B[n-1];
               n--;
           }
           else{
               A[m+n-1]=A[m-1];
               m--;
           }
       }
       while(n){
           A[m+n-1]=B[n-1];
           n--;
       }
    }
};

//第二版
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
       int a=m-1;//A数组索引
       int b=n-1;//B数组索引
       int l=m+n-1;//结果数组索引

       while(a>=0&&b>=0){
           if(A[a]<=B[b]) {
               A[l--]=B[b--];
           }
           else{
               A[l--]=A[a--];
           }
       }
       
       while(b>=0){
           A[l--]=B[b--];
       }
    }
};