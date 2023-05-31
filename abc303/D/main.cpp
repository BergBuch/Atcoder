#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = s.size();
    long long r[n+1][2];
    r[0][0] = 0;
    r[0][1] = z;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='a'){
            r[i][0] = min(r[i-1][0] + x, r[i-1][1]+ z + x);
            r[i][1] = min(r[i-1][0] + z + y, r[i-1][1] + y);
        }
        if(s[i-1]=='A'){
            r[i][0] = min(r[i-1][0] + y, r[i-1][1]+ z + y);
            r[i][1] = min(r[i-1][0] + z + x, r[i-1][1] + x);
        }
    }
    long long ans = min(r[n][0],r[n][1]);
    cout << ans << endl;
}
