#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,K;
    cin >> N >> K;
    vector<pair<long long, long long>> P(N);
    long long sum=0;
    for(int i=0;i<N;i++){
        long long a,b;
        cin >> a >> b;
        P[i] = make_pair(a,b);
        sum += b;
    }

    sort(P.begin(),P.end());
    long long ans=1;
    int i=0;
    while(sum>K){
        ans = P[i].first + 1;
        sum -= P[i].second;
        i++;
    }
    cout << ans << endl;
}
