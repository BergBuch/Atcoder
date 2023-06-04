#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repa(e,a) for(auto e:(a))
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define sayYes cout<<"Yes"<<endl;
#define sayNo cout<<"No"<<endl;

vector<long long>find_prime(long long n){
    vector<bool> is_prime(n+1,true);
    is_prime[1] = false;
    for(int i=2;i<n+1;i++){
        if(!is_prime[i])continue;
        for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
    }
    vector<long long> prime_list;
    for(int i=1;i<n+1;i++) if(is_prime[i]) prime_list.push_back(i);
    return prime_list;
}

vector<int> calc_divisors(int n){
    vector<int> divisors;
    for(int i=1;i*i<=n;i++) if(n%i==0) divisors.push_back(i);
    int half = divisors.size();
    for(int i=half-1;i>=0;i--){
        if(divisors[i]*divisors[i]==n) continue;
        divisors.push_back(n/divisors[i]);
    }
    return divisors;
}
int main(){
    const ll mod = 998244353;
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi divisors = calc_divisors(n);
    vector<int> a(n+1),m(n+1);
    repa(e,divisors){
        if(e==n) continue;
        int cnt_absent = 0;
        for(int i=0;i<e;i++){
            bool can_absent = true;
            for(int j=i+e;j<n;j+=e) if(s[j]=='.') can_absent = false;
            if(can_absent) cnt_absent++;
        }
        a[e] = (1 << cnt_absent);
        cout << e << ":" << a[e] << endl;
    }
    m[1] = a[1];
    repa(e,divisors){
        if(e==1)continue;
        m[e] = a[e];
        repa(f,calc_divisors(e)){
            if(e==f)continue;
            m[e] -= m[f];
        }
    }
    int ans = 0;
    repa(e,divisors) ans += m[e];
    cout << ans << endl;
}
