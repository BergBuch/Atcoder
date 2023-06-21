#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long ans=0;
    for(int i=0; i<64; i++){
        unsigned long long b;
        cin >> b;
        ans += (b << i);
    }
    cout << ans << endl;
}
