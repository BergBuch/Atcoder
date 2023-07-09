#include<bits/stdc++.h>
using namespace std;

vector<int> par;
int root(int x){
    if (par[x]==x) return x;
    else return par[x] = root(par[x]);
}
void unite(int x,int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return;
    else par[rx] = ry;
}
bool isSame(int x, int y){
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
}


int main(){
    int N,M;
    cin >> N >> M;
    vector<int> a(M),b(M);
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    vector<int> c(N);
    for(int i=0; i<N; i++) cin >> c[i];

    par.resize(N);
    for(int i=0; i<N; i++) par[i] = i;

    string ans = "No";

    for(int i=0; i<M; i++){
        if(c[a[i]] == c[b[i]]) continue; //if color is same, skip this.
        unite(a[i],b[i]);
    }
    for(int i=0; i<M; i++){
        if(c[a[i]] != c[b[i]]) continue; //if color is different, skip this.
        if(isSame(a[i],b[i])){
            ans = "Yes";
            break;
        }
    }

    cout << ans << endl;
}
