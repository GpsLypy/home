#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int ii=0;ii<n;ii++){
        cin>>arr[ii];   
    }
/*
    cout<<arr.size()<<endl;
    for(auto a : arr){
        cout<<a<<" ";
    }
    cout<<endl;

*/
    int res=INT_MIN;

    sort(arr.begin(),arr.end());

    for(int ii=0;ii<arr.size()-1;ii++){
        int temp=arr[ii+1]-arr[ii];
        if(temp>res) res=temp;
    }

    cout<<res;
}
