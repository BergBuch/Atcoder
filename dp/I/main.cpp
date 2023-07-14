#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long double> p(N+1);
    for(int i=1;i<=N;i++) cin >> p[i];

    vector<vector<long double>> dp(N+1,vector<long double>(N+1,0));
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j+1] += dp[i][j]*p[i+1];
            dp[i+1][j] += dp[i][j]*((long double)1-p[i+1]);
        }
    }
    long double ans=0;
    for(int i=N/2+1;i<=N;i++){
        ans += dp[N][i];
    }
    cout << setprecision(11) << ans << endl;
}
