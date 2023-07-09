#include<bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin >> N;
    vector<long long> a(N),b(N),d(N);
    bool flag_bob_win = false;
    int num_bigger = 0;
    for(int i=0; i<N; i++){
        cin >> a[i] >> b[i];
        d[i] = abs(a[i]-b[i]);
        if(a[i]>b[i]) num_bigger++;
        if(a[i]==b[i]) flag_bob_win = true;
    }
    sort(d.begin(),d.end());
    long long min_d = d[0];
    long long ans=0;
    for(int i=0; i<N; i++) ans += max(a[i],b[i]);
    if(num_bigger%2==1 && !flag_bob_win) ans -= min_d;
    cout << ans << endl;
}
