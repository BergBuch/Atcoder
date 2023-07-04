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
    vector<pair<int,int>> cons(K);

    for(int i=0; i<K; i++){
        int p,dist;
        cin >> p >> dist;
        cons[i] = {p,dist};
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

    string ans = "Yes";

    for(int i=0; i<K; i++){
        int p,dist;
        p = cons[i].first;
        dist = cons[i].second;

        if(dist==0 && !is_black[p]){
            ans = "No";
            break;
        }
        
        queue<pair<int,int>> q;
        q.push(make_pair(p,0));
        vector<bool> is_searched(N+1,false);
        bool found_black = false;
        while(!q.empty()){
            int now_node = q.front().first;
            int now_dist = q.front().second;
            q.pop();
            if(now_dist==dist){
                if(is_black[now_node]) found_black = true;
                continue;
            }
            else{
                for(auto e: g[now_node]){
                    if(is_searched[e]) continue;
                    q.push(make_pair(e,now_dist+1));
                    is_searched[e] = true;
                }
            }
        }
        if(!found_black){
            ans = "No";
            break;
        }
    }
    if(ans=="Yes"){
        cout << ans << endl;
        for(int i=1; i<=N; i++) cout << is_black[i];
        cout << endl;
    }
    else{
        cout << ans << endl;
    }
}
