#include<bits/stdc++.h>
using namespace std;

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