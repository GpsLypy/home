
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;


int main(){
    
    int T ;//循环次数
    cin>>T;
    while(T--){
        cin>>N >> K;//输入N个数
        vector<int> data(N);
        for(int i=0;i<N;i++)
            cin >> data[i];
        sort(data.begin(), data.end());

        int ans;
        cout<<K<<" "<<N<<endl;
        if(K>N){
            cout<< "NO1" <<endl;
            continue; 
        }

        if(K==0) ans = 1;
        else ans = data[K-1] + 1;
        cout<<"结果"<<ans<<endl;

        if(ans < 1 || ans > N){//避免N=5时输入：12345 5这种情况
            cout<<"NO2"<<endl;
            continue;
        }
        
        if(K<N && data[K-1]==data[K]){//避免情况 1 2 2 3 4 K=2
            cout<< "NO3" <<endl;
            continue;
        }
        
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
}

