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
    ll n;
    cin >> n;
    ll cn = n;
    int ketasu=1;
    while(true){
        cn /= 10;
        if(cn>0)ketasu++;
        else break;
    }
    if(ketasu<=3){
        cout << n << endl;
        return 0;
    }
    ll ee[]={1,1,1,1,10,100,1000,10000,100000,1000000,};
    cout << (n/ee[ketasu])*ee[ketasu] << endl;
}
