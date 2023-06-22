#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    vector<vector<int>> t(n,vector<int>(k,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin >> t[i][j];
        }
    }

    int loop = 1;
    for(int i=0; i<n; i++) loop *= k;

    string ans = "Nothing";
    for(int i=0; i<loop; i++){
        int current_xor = 0;
        int chosen = i;
        for(int j=0; j<n; j++){
            current_xor ^= t[j][chosen%k];
            chosen /= k;
        }
        if(current_xor == 0){
            ans = "Found";
            break;
        }
    }
    cout << ans << endl;
}
