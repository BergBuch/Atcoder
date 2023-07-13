#include<bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main(){
    long long N;
    string T;
    cin >> N >> T;

    vector<vector<long long>> g(2*N+1,vector<long long>(N+2,0));
    vector<vector<long long>> f(2*N+1,vector<long long>(N+2,0));

    f[0][0] = 1;
    
    for(int i=0; i<2*N; i++){
        for(int j=0; j<=N; j++){
            if(T[i] != '-'){
                f[i+1][j+1] += f[i][j]%mod;
                g[i+1][j+1] += g[i][j] + f[i][j] * abs(2*j-i);
                g[i+1][j+1] %= mod;
            }
            if(T[i] != '+'){
                f[i+1][j] += f[i][j]%mod;
                g[i+1][j] += g[i][j] + f[i][j] * abs(2*j-i);
                g[i+1][j] %= mod;
            }
        }
    }

    cout << g[2*N][N] << endl;
}
