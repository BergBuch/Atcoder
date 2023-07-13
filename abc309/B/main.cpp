#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    vector<string> B(N);
    B=A;

    for(int i=1;i<N;i++){
        B[0][i] = A[0][i-1];
        B[i][N-1] = A[i-1][N-1];
        B[N-1][i-1] = A[N-1][i];
        B[i-1][0] = A[i][0];
    }

    for(int i=0;i<N;i++) cout << B[i] << endl;
}
