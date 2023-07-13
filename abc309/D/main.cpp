#include<bits/stdc++.h>
using namespace std;

int main(){
    int N1,N2,M;
    cin >> N1 >> N2 >> M;
    vector<vector<int>> edge(N1+N2);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    vector<bool> is_searched(N1+N2,false);
    vector<int> d(N1+N2,0);
    queue<int> q;
    int d1=0,d2=0;
    q.push(0);
    is_searched[0] = true;
    while(!q.empty()){
        int now_parent = q.front();
        q.pop();
        for(auto now_child: edge[now_parent]){
            if(is_searched[now_child]) continue;
            is_searched[now_child] = true;
            q.push(now_child);
            d[now_child] = d[now_parent] + 1;
            d1 = max(d1,d[now_child]);
        }
    }
    q.push(N1+N2-1);
    is_searched[N1+N2-1] = true;
    while(!q.empty()){
        int now_parent = q.front();
        q.pop();
        for(auto now_child: edge[now_parent]){
            if(is_searched[now_child]) continue;
            is_searched[now_child] = true;
            q.push(now_child);
            d[now_child] = d[now_parent] + 1;
            d2 = max(d2,d[now_child]);
        }
    }

    cout << d1+d2+1 << endl;
}
