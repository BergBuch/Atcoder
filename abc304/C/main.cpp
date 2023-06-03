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
    int n,d;
    cin >> n >> d;
    vi x(n),y(n);
    rep(i,0,n) cin >> x[i] >> y[i];
    //vector<vector<bool>> g(n,vector<bool>(n,false));
    //vector<set<int>> g2(n);
    vector<vector<int>> g3(n);
    rep(i,0,n)rep(j,i+1,n){
        int distance = ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        //if(distance <= d*d) g[i][j] = g[j][i] = true;
        //if(distance <= d*d) {g2[i].insert(j); g2[j].insert(i);}
        if(distance <= d*d) {g3[i].push_back(j); g3[j].push_back(i);}
    }
    queue<int> q;
    vector<bool> is_infected(n,false);
    vector<bool> is_searched(n,false);
    q.push(0);
    is_infected[0]=true;
    is_searched[0]=true;
    while(q.size()!=0){
        int now = q.front();
        q.pop();
        /*rep(i,0,n){
            if(is_searched[i]) continue;
            if(g[now][i]){is_infected[i] = true; q.push(i);}
        }*/
        for(auto e:g3[now]){
            if(is_searched[e]) continue;
            is_infected[e] = true;
            is_searched[e] = true;
            q.push(e);
        }
    }
    rep(i,0,n) YesNo(is_infected[i]);
}
