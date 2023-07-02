#include<bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int N,M;
    cin >> N >> M;

    multiset<long long> P;
    vector<long long> L(M);
    vector<long long> D(M);
    long long ans=0;
    for(int i=0; i<N; i++){
        long long temp;
        cin >> temp;
        ans += temp;
        P.insert(temp);
    }
    for(int i=0; i<M; i++) cin >> L[i];
    for(int i=0; i<M; i++) cin >> D[i];

    //いいクーポンから先に並び変える
    vector<int> best_coupon_iter(M);
    for(int i=0; i<M; i++) best_coupon_iter[i]=i;
    auto f = [&](int& a, int& b){
        if(D[a] > D[b]) return true;
        else if(D[a] == D[b]) return L[a] < L[b];
        else return false;
    };
    sort(best_coupon_iter.begin(),best_coupon_iter.end(),f);
    
    //クーポンを前から見ていく。
    for(int i: best_coupon_iter){
        //クーポンが使用可能かどうか。
        auto item_iter = P.lower_bound(L[i]);
        if(item_iter != P.end()){
            P.erase(item_iter);
            ans -= D[i];
        }
        if(P.empty()) break;
    }

    cout << ans << endl;
}
