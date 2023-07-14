#include<bits/stdc++.h>
using namespace std;

int main(){
    long long mod=1000000007;
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i=0;i<H;i++) cin >> a[i];
    vector<vector<long long>> dp(H,vector<long long>(W,0));
    dp[0][0]=1;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j]=='#') continue;
            if(i+1<H && a[i+1][j]=='.'){
                dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod;
            }
            if(j+1<W && a[i][j+1]=='.'){
                dp[i][j+1] = (dp[i][j+1] + dp[i][j])%mod;
            }
        }
    }
    
    cout << dp[H-1][W-1] << endl;
}
