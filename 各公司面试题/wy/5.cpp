#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    int sum=0;
    vector<int> res(T);
    for(int ii=0;ii<T;ii++){
        int N;
        int A,B;
        cin>>N;
        cin>>A>>B;
        for(int jj=0;jj<N;jj++){
            int A_i,B_i,C_i;
            cin>>A_i>>B_i>>C_i;
            if(A<B_i) res.push_back(-1);
            while(A>B_i) {
                C_i-=A-B_i;
                sum=A-B_i-C_i;
                if(C_i<=0) break;
                if(sum<0) sum=1;
            }
        }
        res.push_back(sum);
    }
    for(auto a:res){
        cout<<a<<endl;
    }
    return 0;
}