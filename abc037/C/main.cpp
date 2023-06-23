#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<long long> s(N+1,0);
    for(int i=1; i<=N; i++){
        long long a;
        cin >> a;
        s[i] = s[i-1] + a;
    }
    long long ans=0;
    for(int i=K; i<=N; i++){
        ans += s[i] - s[i-K];
    }
    cout << ans << endl;
}
