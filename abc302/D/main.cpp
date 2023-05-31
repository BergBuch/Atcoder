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
    int n,m;
    ll d;
    cin>>n>>m>>d;
    vll a(n),b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cn=n-1,cm=m-1;
    ll max_sum=-1;
    while(cn>=0 and cm>=0){
        ll cd=abs(a[cn]-b[cm]);
        if(cd<=d){
            max_sum = a[cn]+b[cm];
            break;
        }
        if(a[cn]>b[cm]) cn--;
        else cm--;
    }
    cout << max_sum << endl;
}
