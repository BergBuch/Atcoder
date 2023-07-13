#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N,vector<int>(N)),B(N,vector<int>(N));
    for(int i=0; i<N; i++)for(int j=0;j<N;j++) cin >> A[i][j];
    for(int i=0; i<N; i++)for(int j=0;j<N;j++) cin >> B[i][j];
    
    bool ans = false;
    bool is_ok = true;
    for(int i=0; i<N; i++)for(int j=0;j<N;j++){
        if(A[i][j]==0) continue;
        if(B[i][j]==0) is_ok = false;
    }
    if(is_ok) ans = true;

    is_ok = true;
    for(int i=0; i<N; i++)for(int j=0;j<N;j++){
        if(A[j][N-1-i]==0) continue;
        if(B[i][j]==0) is_ok = false;
    }
    if(is_ok) ans = true;

    is_ok = true;
    for(int i=0; i<N; i++)for(int j=0;j<N;j++){
        if(A[N-1-i][N-1-j]==0) continue;
        if(B[i][j]==0) is_ok = false;
    }
    if(is_ok) ans = true;

    is_ok = true;
    for(int i=0; i<N; i++)for(int j=0;j<N;j++){
        if(A[N-1-j][i]==0) continue;
        if(B[i][j]==0) is_ok = false;
    }
    if(is_ok) ans = true;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
