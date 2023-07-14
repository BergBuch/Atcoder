#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> parent;

int f(int a){
    if(dp[a]!=-1) return dp[a];
    int res=0;
    for(auto nowp: parent[a]){
        res = max(res,f(nowp)+1);
    }
    return dp[a]=res;
}

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> x(M),y(M);
    parent.resize(N);
    for(int i=0;i<M;i++){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
        parent[y[i]].push_back(x[i]);
    }

    dp.resize(N);
    for(auto &e: dp) e=-1;

    int ans=0;
    for(int i=0;i<N;i++) ans = max(ans,f(i));
    cout << ans << endl;

}
