#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    vector<long long> w(N),v(N);
    for(int i=0;i<N;i++) cin >> w[i] >> v[i];

    vector<vector<long long>> dp(N,vector<long long>(W+1,LLONG_MIN));
    for(int i=0;i<=W;i++){
        if(i<w[0]) dp[0][i] = max(0LL,dp[0][i]);
        else dp[0][i] = max(dp[0][i],v[0]);
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i]<0) continue;
            dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout << dp[N-1][W] << endl;
}
