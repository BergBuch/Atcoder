#include<bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main(){
    long long N;
    string T;
    cin >> N >> T;

    vector<int> e(2*N);
    for(int i=0; i<2*N; i++){
        if(T[i]=='+') e[i] = 1;
        if(T[i]=='-') e[i] = -1;
        if(T[i]=='?') e[i] = 0;
    }

    
}
