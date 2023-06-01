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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(m+n+1);
    rep(i,1,n+1){
        int a;
        cin>>a;
        rep(j,0,a){
            int s;
            cin>>s;
            g[s].push_back(m+i);
            g[m+i].push_back(s);
        }
    }
    queue<int> q;
    vector<int> depth(m+n+1,-1);
    depth[1]=0;
    q.push(1);
    //queueに繋がってるやつがmか判定探索、
    while(q.size()!=0){
        int c_node = q.front();
        q.pop();
        for(auto node: g[c_node]){
            if(depth[node]!=-1)continue;
            q.push(node);
            depth[node]=depth[c_node]+1;
        }
    }
    cout << (depth[m]/2)-1 << endl;
}
