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

vector<long long>find_prime(long long n){
    vector<bool> is_prime(n+1,true);
    is_prime[1] = false;
    for(int i=2;i<n+1;i++){
        if(!is_prime[i])continue;
        for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
    }
    vector<long long> prime_list;
    for(int i=1;i<n+1;i++) if(is_prime[i]) prime_list.push_back(i);
    return prime_list;
}

vector<int> calc_divisors(int n){
    vector<int> divisors;
    for(int i=1;i*i<=n;i++) if(n%i==0) divisors.push_back(i);
    int half = divisors.size();
    for(int i=half-1;i>=0;i--){
        if(divisors[i]*divisors[i]==n) continue;
        divisors.push_back(n/divisors[i]);
    }
    return divisors;
}

int main(){
    for(auto e:find_prime(100)) cout << e;
}