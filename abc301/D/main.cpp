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
int main(){
    string s;
    cin >> s;
    ll n;
    cin >> n;

    ll blist[60];
    blist[0] = 1;
    rep(i,1,60) blist[i] = blist[i-1]*2;

    ll ans_num=0;
    for(int i=s.size()-1;i>=0;i--) if(s[i]=='1') ans_num+=blist[s.size()-1-i];

    if(ans_num>n){
        cout << -1 << endl;
        return 0;
    }

    rep(i,0,s.size()){
        if(s[i]=='?'){
            if(ans_num+blist[s.size()-1-i]<=n) ans_num += blist[s.size()-1-i];
        }
    }
    cout << ans_num << endl;
}
