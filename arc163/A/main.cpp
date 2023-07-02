#include<bits/stdc++.h>
using namespace std;

string getAns(int N, string S){
    string ans = "No";
    for(int i=0; i<N-1; i++){
        string former = S.substr(0,i+1);
        string latter = S.substr(i+1);
        if(former<latter) ans = "Yes";
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        string S;
        cin >> N >> S;
        cout << getAns(N,S) << endl;
    }
}
