#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<long long> X(N);
    vector<long long> Y(N+1,0);
    vector<vector<long long>> dp(N+1,vector<long long>(N+1,-1));
    for(int i=0;i<N;i++) cin >> X[i];
    for(int i=0;i<M;i++){
        long long c,y;
        cin >> c >> y;
        Y[c]=y;
    }

    dp[0][0]=0;
    dp[0][1]=X[0]+Y[1];

    for(int i=1;i<N;i++){
        for(int j=0;j<=N;j++){
            if(dp[i-1][j]==-1) continue;
            dp[i][0] = max(dp[i][0],dp[i-1][j]);
        }
        for(int j=1;j<=N;j++){
            if(dp[i-1][j-1]==-1) continue;
            dp[i][j] = max(dp[i][j],dp[i-1][j-1] + X[i] + Y[j]);
        }
    }

    long long ans=0;
    for(int i=0;i<=N;i++) ans = max(ans,dp[N-1][i]);
    cout << ans << endl;
}
