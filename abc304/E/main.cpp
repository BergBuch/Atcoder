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

struct UnionFind{
    vector<int> par;

    UnionFind(int n): par(n){
        for(int i=0; i<n; i++) par[i] = i;
    }

    int root(int x){
        if(par[x]==x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx==ry) return;
        par[rx] = ry;
    }

    bool is_same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

};
int main(){
    int n,m;
    cin >> n >> m;
    UnionFind g(n+1);
    int u,v;
    rep(i,0,m){
        cin >> u >> v;
        g.unite(u,v);
    }
    set<set<int>> ng;
    int k;
    cin >> k;
    int x,y;
    rep(i,0,k){
        cin >> x >> y;
        ng.insert(set<int>{g.root(x),g.root(y)});
    }
    
    int Q,p,q;
    cin >> Q;
    rep(i,0,Q){
        cin >> p >> q;
        if(ng.count(set<int>{g.root(p),g.root(q)})==0) sayYes
        else sayNo
    }
}
