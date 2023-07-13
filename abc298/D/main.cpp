#include<bits/stdc++.h>
using namespace std;

int main(){
    int mod = 998244353;
    vector<long long> mod_of_10n(700000);
    mod_of_10n[0]=1;
    for(int i=1; i<700000;i++){
        mod_of_10n[i] = (mod_of_10n[i-1]*10)%mod;
    }

    int Q;
    cin >> Q;
    queue<int> num_q;
    num_q.push(1);
    long long ans=1;
    for(int q=0; q<Q; q++){
        int ope;
        cin >> ope;
        if(ope==1){
            int x;
            cin >> x;
            num_q.push(x);
            ans = ((ans*10)%mod + x) % mod;
        }
        if(ope==2){
            int x = num_q.front();
            num_q.pop();
            ans += x * (mod - mod_of_10n[num_q.size()]);
            ans %= mod;
        }
        if(ope==3){
            cout << ans << endl;
        }
    }
}
