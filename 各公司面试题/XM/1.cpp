#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1,vector<int>& nums2,int m,int n){
    int index=m;
    nums1.resize(m+n);
    for(int ii=0;ii<n;ii++){
        nums1[index++]=nums2[ii];
    }
    sort(nums1.begin(),nums1.end());
}
int main(){
    string s;
    cin>>s;
    int m=0,n=0;
    string ss;
    vector<int> nums1,nums2;
    for(int ii=0;ii<s.size();ii++){
        if(s[ii]=='m'||s[ii]=='='||s[ii]=='n'||s[ii]==',') continue;
        ss+=s[ii];
    }
    m=ss[0]-'0';
    n=ss[1]-'0';
    int temp=0;
    while(1){
        cin>>temp;
        //if(cin.get()==',') continue;
        nums1.push_back(temp);
  
        if(cin.get()=='\n') break;
    }
      while(1){
        cin>>temp;
        //if(cin.get()==',') continue;
        nums2.push_back(temp);
  
        if(cin.get()=='\n') break;
    }
    merge(nums1,nums2,m,n);
    for(auto a:nums1) {
        cout<<a<<" ";
    }
    cout<<endl;
}