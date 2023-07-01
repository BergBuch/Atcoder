#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> c(N);
    vector<string> d(M);
    vector<int> p(M);

    //入力
    int init_price;
    for(int i=0; i<N; i++){
        cin >> c[i];
    }
    for(int i=0; i<M; i++){
        cin >> d[i];
    }
    cin >> init_price;
    for(int i=0; i<M; i++){
        cin >> p[i];
    }

    map<string,int> price;
    for(int i=0; i<M; i++){
        price[d[i]] = p[i];
    }

    //計算
    int ans=0;
    for(int i=0; i<N; i++){
        if(price.find(c[i])!=price.end()){
            ans += price[c[i]];
        }
        else ans += init_price;
    }

    cout << ans << endl;
}
