#include<bits/stdc++.h>
using namespace std;

long long mod_inv(int x,int mod){
    long long ans=1;
    long long k=mod-2;
    while(k>0){
        if(k&1) ans = (ans*x)%mod;
        x = (x*x)%mod;
        k = (k>>1);
    }
    return ans;
}

long long dp[101][101][2];

int main(){
    long long mod = 998244353;
    int N,A,B,P,Q;
    cin >> N >> A >> B >> P >> Q;
    long long Pinv = mod_inv(P,mod);
    long long Qinv = mod_inv(Q,mod);
    for(int i=0;i<N;i++) dp[N][i][1] = 1;
    for(int i=N-1; i>=1; i--){
        for(int j=N-1;j>=1;j--){
            for(int k=1;k<=P;k++){
                dp[i][j][0] = (dp[i][j][0] + dp[min(i+k,N)][j][1] * Pinv) % mod;
            }
            for(int k=1;k<=Q;k++){
                dp[j][i][1] = (dp[j][i][1] + dp[j][min(i+k,N)][0] * Qinv) % mod;
            }
        }
    }
    cout << dp[A][B][0] << endl;
}
