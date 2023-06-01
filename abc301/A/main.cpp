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
    string s;
    cin>>n>>s;
    int t,a;
    t=a=0;
    rep(i,0,n){
        if(s[i]=='T')t++;
        else a++;
        if(t==(n+1)/2){
            cout<<"T"<<endl;
            return 0;
        }
        if(a==(n+1)/2){
            cout<<"A"<<endl;
            return 0;
        }
    }
}
