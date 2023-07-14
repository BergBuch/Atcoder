#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> H(N,vector<int>(3));
    for(int i=0;i<N;i++) cin >> H[i][0] >> H[i][1] >> H[i][2];

    vector<vector<long long>> dp(N,vector<long long>(3,LLONG_MIN));
    for(int i=0;i<3;i++) dp[0][i] = H[0][i];

    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k==j) continue;
                dp[i][j] = max(dp[i][j],dp[i-1][k]+H[i][j]);
            }
        }
    }

    cout << max(max(dp[N-1][0],dp[N-1][1]),dp[N-1][2]) << endl; 
}
