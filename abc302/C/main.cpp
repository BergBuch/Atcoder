#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define sayYes cout<<"Yes"<<endl
#define sayNo cout<<"No"<<endl
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,0,n) cin>>s[i];
    bool ans=false;
    sort(s.begin(),s.end());
    do{
        bool all_neighbor = true;
        rep(i,0,n-1){
            int same=0;
            rep(j,0,m) if(s[i][j]==s[i+1][j]) same++;
            if(same!=m-1) all_neighbor=false;
        }
        if(all_neighbor){
            ans=true;
            break;
        }
    }while(next_permutation(s.begin(),s.end()));
    YesNo(ans);
}
