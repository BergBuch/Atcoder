#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> s(8);
    for(int i=0; i<8; i++){
        cin >> s[i];
    }
    bool c1,c2,c3;

    c1 = true;
    for(int i=0;i<7;i++){
        if(s[i]>s[i+1]){
            c1=false;
        }
    }

    c2 = true;
    c3 = true;
    for(int i=0;i<8;i++){
        if(s[i]<100 || s[i]>675){
            c2 = false;
        }
        if(s[i]%25!=0){
            c3 = false;
        }
    }
    if(c1 && c2 && c3) cout << "Yes" << endl;
    else cout << "No" << endl;
}
