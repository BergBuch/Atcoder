#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define sayYes cout<<"Yes"<<endl;
#define sayNo cout<<"No"<<endl;

vector<ll> find_prime(ll n){
    vector<bool> is_prime(n+1,true);
    is_prime[1] = false;
    rep(i,2,n+1){
        if(!is_prime[i])continue;
        for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
    }
    vll prime_list;
    rep(i,1,n+1) if(is_prime[i]) prime_list.push_back(i);
    return prime_list;
}
int main(){
    ll n;
    cin >> n;
    vll primes = find_prime(ll(sqrt(n/12)));
    ll ans=0;
    for(int c=primes.size()-1;c>=2;c--){
        for(int b=c-1;b>=1;b--){
            for(int a=b-1;a>=0;a--){
                if(primes[a]*primes[a]*primes[b]*primes[c]*primes[c]<=n)ans++;
            }
        }
    }
    cout << ans << endl;
}
