#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long x,y;
    vector<vector<long long>> dp(n,vector<long long>(2,0));

    //最初の料理を食べる
    cin >> x >> y;
    if(x==0){
        dp[0][0] = y>0 ? y : 0;
        dp[0][1] = -4e18;
    }
    if(x==1){
        dp[0][0] = 0;
        dp[0][1] = y;
    }
    for(int i=1; i<n; i++){
        cin >> x >> y;
        if(x==0){
            dp[i][0] = max(dp[i-1][0],max(dp[i-1][0] + y,dp[i-1][1] + y));
            dp[i][1] = dp[i-1][1];
        }
        if(x==1){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0] + y, dp[i-1][1]);
        } 
    }
    long long ans = max(dp[n-1][0],dp[n-1][1]);
    cout << ans << endl;
}
