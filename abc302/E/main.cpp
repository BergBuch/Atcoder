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
    int n,q;
    cin >> n >> q;
    int ans=n;
    vector<set<int>> g(n+1);
    rep(i,0,q){
        int x;
        cin >> x;
        if(x==1){
            int u,v;
            cin >> u >> v;
            if(g[u].size()==0) ans--;
            if(g[v].size()==0) ans--;
            g[u].insert(v);
            g[v].insert(u);
        }
        else{
            int v;
            cin >> v;
            if(g[v].size()!=0){    
                set<int>::iterator itr = g[v].begin();
                while(itr!=g[v].end()){
                    int w=*itr;
                    g[w].erase(v);
                    if(g[w].size()==0) ans++;
                    itr++;
                }
                ans++;
                g[v].clear();
            }
        }
        cout << ans << endl;
    } 
}
