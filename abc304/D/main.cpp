#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repa(e,a) for(auto& e:(a))
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define sayYes cout<<"Yes"<<endl;
#define sayNo cout<<"No"<<endl;
int main(){
    int w,h;
    cin >> w >> h;
    int n;
    cin >> n;
    vi p(n),q(n);
    rep(i,0,n) cin >> p[i] >> q[i];
    int A,B;
    cin >> A;
    vi a(A+1);
    rep(i,0,A) cin >> a[i];
    a[A] = w;
    cin >> B;
    vi b(B+1);
    rep(i,0,B) cin >> b[i];
    b[B] = h;
    map<pair<int,int>,int> cnt;
    rep(i,0,n){
        int x,y;
        x = *lower_bound(a.begin(),a.end(),p[i]);
        y = *lower_bound(b.begin(),b.end(),q[i]);
        cnt[{x,y}]++;
    }
    int m=n,M=0;
    repa(e,cnt) M=max(M,e.second);
    if(cnt.size()==(A+1)*(B+1)){
        repa(e,cnt) m = min(m,e.second);
    }
    else m=0;
    cout << m << " " << M << endl;
}
