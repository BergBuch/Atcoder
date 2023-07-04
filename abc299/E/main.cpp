#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<set<int>>g(N+1);
    for(int i=1;i<=M;i++){
        int u,v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<bool> is_black(N+1,true);
    int K;
    cin >> K;

    for(int i=0; i<K; i++){
        int p,dist;
        cin >> p >> dist;
        if(dist==0)continue;

        queue<pair<int,int>> q;
        vector<bool> is_searched(N+1,false);
        q.push({p,0});
        is_searched[p] = true;
        while(!q.empty()){
            int now_node = q.front().first;
            int now_dist = q.front().second;
            q.pop();
            is_black[now_node] = false;
            if(now_dist+1 >= dist) continue;
            for(auto e: g[now_node]){
                if(is_searched[e]) continue;
                q.push({e,now_dist+1});
                is_searched[e] = true;
            }
        }
    }

    for(int i=1; i<=N; i++) if(is_black[i]){
        cout << "Yes" << endl;
        for(int i=1; i<=N; i++){
            if(is_black[i]) cout << 1;
            else cout << 0;
        }
        cout << endl;
        return 0;
    } 
    cout << "No" << endl;
    return 0;
}
