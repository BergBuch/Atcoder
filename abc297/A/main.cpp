#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,D;
    cin >> N >> D;
    vector<int> t(N);
    for(int i=0;i<N;i++) cin >> t[i];
    for(int i=1;i<N;i++){
        if(t[i]-t[i-1]<=D){
            cout << t[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
