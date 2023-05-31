#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s,t;
    cin >> n;
    cin >> s >> t;
    for (int i=0;i<n;i++){
        if(s[i]=='o')s[i]='0';
        if(s[i]=='l')s[i]='1';
        if(t[i]=='o')t[i]='0';
        if(t[i]=='l')t[i]='1';
    }
    if(s==t)cout << "Yes" << endl;
    else cout << "No" << endl;
}