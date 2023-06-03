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
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    rep(i,0,n) cin >> s[i] >> a[i];
    int min_i;
    ll min_age=1e10;
    rep(i,0,n){
        if(a[i]<min_age){
            min_i = i;
            min_age = a[i];
        }
    }
    rep(i,min_i,n) cout << s[i] << endl;
    rep(i,0,min_i) cout << s[i] << endl;
}
