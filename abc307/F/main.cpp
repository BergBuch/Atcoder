#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    std::cin >> N >> M;
    //グラフを構成。
    vector<vector<pair<int,long long>>> g(N+1);
    for(int i=0; i<M; i++){
        int u,v;
        long long w;
        std::cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    //最初の感染者たちを処理。
    vector<int> infected_day(N+1,-1);
    multiset<pair<long long,int>> uninfected_node;
    multiset<pair<long long,int>> searching_node;
    vector<long long> node_distance(N+1,1000000000000000LL);
    int K;
    std::cin >> K;
    for(int i=0; i<K; i++){
        int a;
        std::cin >> a;
        infected_day[a] = 0;
        node_distance[a] = 0;
        searching_node.insert({0,a});
    }
    for(int i=1; i<=N; i++){//感染していない人たちの距離を初期化
        if(infected_day[i]==-1){
            uninfected_node.insert({1000000000000000LL,i});
        }
    }

    //日付ごとに更新していく。
    int D;
    std::cin >> D;
    for(int d=1; d<=D; d++){
        long long x;
        std::cin >> x;
        pair<long long, int> now_search = *searching_node.begin();
        searching_node.erase(now_search);
        for(auto e : g[now_search.second]){
            if(node_distance[e.first] > node_distance[now_search.second]+e.second){
                node_distance[e.first] = node_distance[now_search.second]+e.second;
                if(infected_day[e.first]==-1 && node_distance[e.first]<=x){
                    infected_day[e.first] = d;
                }
                searching_node.insert({node_distance[e.first],e.first});
            }
        }
    }
}
