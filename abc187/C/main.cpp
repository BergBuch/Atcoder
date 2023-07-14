#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool is_satis = true;
    string ans;
    set<string> d;
    vector<string> S(N);
    for(int i=0;i<N;i++) cin >> S[i];

    for(int i=0;i<N;i++){
        if(S[i][0]!='!'){
            d.insert(S[i]);
        }
    }
    for(int i=0;i<N;i++){
        if(S[i][0]=='!'){
            S[i] = S[i].substr(1);
            if(d.find(S[i])!=d.end()){
                is_satis = false;
                ans = S[i];
                break;
            }
        }
    }
    
    if(is_satis) cout << "satisfiable" << endl;
    else cout << ans << endl;
}
