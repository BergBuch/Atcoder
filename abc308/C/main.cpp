#include<bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int N;
    cin >> N;
    multimap<double,int> mp; //p[probability] = player_iterate
    for(int i=1; i<=N; i++){
        int a,b;
        cin >> a >> b;
        double probability = double(a)/double(a+b);
        mp.insert({1-probability,i});
    }

    //出力
    vector<int> ans;
    for(auto iter = mp.begin(); iter!=mp.end(); iter++){
        if(iter==mp.begin()) cout << iter->second;
        else cout << " " << iter->second;
    }

    cout << endl;
    
}
