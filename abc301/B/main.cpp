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
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    cout << a[0];
    rep(i,1,n){
        if(a[i]>a[i-1]){
            while(a[i-1]!=a[i]){
                a[i-1]++;
                cout << " " << a[i-1];
            }
        }
        if(a[i]<a[i-1]){
            while(a[i-1]!=a[i]){
                a[i-1]--;
                cout << " " << a[i-1];
            }
        }
    }
    cout << endl;
}
