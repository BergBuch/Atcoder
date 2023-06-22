#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int main(){
    //グラフの情報を入力
    int N,M,K;
    cin >> N >> M >> K;
    graph.resize(N+1);
    vector<int> is_guarded(N+1,-1);

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //警備員情報から幅優先探索をしていく
    for(int i=0; i<K; i++){
        int p,h;
        cin >> p >> h;
        is_guarded[p] = h;
    }
    
    
}
