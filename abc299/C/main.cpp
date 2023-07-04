#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    if(string(N,'o')==S){
        cout << -1 << endl;
        return 0;
    }

    int ans=0;
    int now_combo = 0;
    for(auto s: S){
        if(s=='-'){
            ans = max(ans,now_combo);
            now_combo=0;          
        }
        if(s=='o') now_combo++;
    }
    ans = max(ans,now_combo);
    if(ans==0) ans = -1;
    cout << ans << endl;
}
