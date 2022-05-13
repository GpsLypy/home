string multiply(string num1, string num2) {
    vector<int> A,B;
    int n=num1.size();
    int m=num2.size();
    vector<int> C(n+m);

    for(int ii=n-1;ii>=0;ii--) A.push_back(num1[ii]-'0');//-'0'把字符变成数字
    for(int ii=m-1;ii>=0;ii--) B.push_back(num2[ii]-'0');

    for(int ii=0;ii<A.size();ii++){
        for(int jj=0;jj<B.size();jj++){
            C[ii+jj]+=A[ii]*B[jj];
        }
    }

    int t=0;//存储进位
    for(int ii=0;ii<C.size();ii++){
        t+=C[ii];//为了利用上上面那个进位
        C[ii]=t%10;//进位操作的固定写法，先t%10取个位，然后再t/10进位
        t/=10;
    }

    int kk=C.size()-1;
    while(kk>0&&!C[kk]) kk--;//去除前导0 比如此例 "2" "3"->"06"

    string res;
    for(;kk>=0;kk--){
        res+=C[kk]+'0';//+'0'把数字变成字符
    }

    return res;

}
