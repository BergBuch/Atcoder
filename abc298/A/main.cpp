#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    bool exist_o = false;
    bool exist_x = false;
    for(int i=0; i<N; i++){
        if(S[i] == 'o') exist_o = true;
        if(S[i] == 'x') exist_x = true;
    }
    if(exist_o &&  !exist_x) cout << "Yes" << endl;
    else cout << "No" << endl;
} 
