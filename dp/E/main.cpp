#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> w(N);
    vector<int> v(N);
    for(int i=0;i<N;i++) cin >> w[i] >> v[i];

    //dp[i][j]はi個目までの商品だけを使って、価値がjである最小の重さ
    vector<vector<long long>> dp(N,vector<long long>(100001,(long long)(1e12)));
    dp[0][0] = 0;
    dp[0][v[0]] = w[0];
    for(int i=1;i<N;i++){
        for(int j=0;j<=100000;j++){
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            if(j-v[i]<0) continue;
            dp[i][j] = min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
    }

    for(int j=100000;j>=0;j--){
        if(dp[N-1][j]<=W){
            cout << j << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
