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
    char p,q;
    cin >> p >> q;
    vector<int> d(256,0);
    d['A'] = 3;
    d['B'] = 1;
    d['C'] = 4;
    d['D'] = 1;
    d['E'] = 5;
    d['F'] = 9;
    int ans = 0;
    int larger_char = max(int(p),int(q));
    int smaller_char = min(int(p),int(q));
    for(int i = smaller_char; i<larger_char; i++){
        ans += d[i];
    }
    cout << ans << endl;
}
