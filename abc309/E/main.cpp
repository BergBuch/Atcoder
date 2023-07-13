#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> children(N);
    for(int i=1;i<N;i++){
        int p;
        cin >> p; p--;
        children[p].push_back(i);
    }
    vector<int> ins(N,-1);
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        x--;
        ins[x] = y;
    }

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int nowp = q.front();
        q.pop();
        for(auto nowc: children[nowp]){
            ins[nowc] = max(ins[nowc],ins[nowp]-1);
            q.push(nowc);
        }
    }
    int ans=0;
    for(int i=0;i<N;i++) if(ins[i]!=-1) ans++;
    cout << ans << endl;
}
