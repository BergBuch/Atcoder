#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> h(N);
    for(auto &x: h) cin >> x;
    
    vector<long long> dp(N,LLONG_MAX);
    dp[0] = 0;

    for(int i=0;i<N-1;i++){
        for(int k=1;k<=K;k++){
            if(i+k>N-1) continue;
            dp[i+k] = min(dp[i+k],dp[i]+abs(h[i]-h[i+k]));
        }
    }

    cout << dp[N-1] << endl;
}
