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
    vi jisu(n+1,0);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        jisu[u]++;
        jisu[v]++;
    }
    vi stars(0);
    int star_sum=0;
    rep(i,1,n+1){
        if(jisu[i]>2){
            star_sum+=jisu[i]+1;
            stars.push_back(jisu[i]);
        }
    }
    string ans="";
    sort(stars.begin(),stars.end());
    while(star_sum < n-1){
        ans += to_string(2)+" ";
        star_sum += 3;
    }
    for(auto& e: stars) ans += to_string(e)+" ";
    ans.erase(ans.size()-1);
    cout << ans << endl;
}
