#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long T;
    cin >> N >> T;
    vector<int> P(N);
    vector<long long> C(N),R(N);
    for(int i=0; i<N; i++) P[i] = i+1;
    for(int i=0; i<N; i++) cin >> C[i];
    for(int i=0; i<N; i++) cin >> R[i];
    vector<pair<int,long long>> d(N);
    for(int i=0; i<N; i++){
        int color = 0;
        if(C[i]==C[0]) color=1;
        if(C[i]==T) color=2;
        
        d[i] = make_pair(color,R[i]);
    }
    sort(P.begin(),P.end(),[&](int x,int y){return d[x-1]>d[y-1];});
    cout << P[0] << endl;
}
