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

int s_cnt[256],t_cnt[256];

int main(){
    string s,t;
    cin >> s >> t;
    int at='@';
    
    for(auto e:s)s_cnt[e]++;
    for(auto e:t)t_cnt[e]++;

    bool ans=true;

    rep(i,'a','z'+1){
        bool is_atcoder=false;
        for(char e:"atcoder")if(i==e)is_atcoder=true;
        if(s_cnt[i]<t_cnt[i]){
            if(is_atcoder){
                s_cnt[at] -= t_cnt[i]-s_cnt[i];
                if(s_cnt[at]<0) ans=false;
            }
            else ans=false;
        }
        if(s_cnt[i]>t_cnt[i]){
            if(is_atcoder){
                t_cnt[at] -= s_cnt[i]-t_cnt[i];
                if(t_cnt[at]<0) ans=false;
            }
            else ans=false;
        }
    }
    YesNo(ans);
}
