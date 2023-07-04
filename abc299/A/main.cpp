#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    string ans = "out";
    int state = 0;
    for(int i=0; i<N; i++){
        if(state==0){
            if(S[i]=='|') state++;
        }
        else if(state==1){
            if(S[i]=='|') state++;
            if(S[i]=='*') ans = "in";
        }
    }
    cout << ans << endl;
}
