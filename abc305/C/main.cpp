#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repa(e,a) for(auto e:(a))
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define sayYes cout<<"Yes"<<endl;
#define sayNo cout<<"No"<<endl;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h+2);
    s[0] = s[h+1] = string(w+2,'.');
    for (int i=1; i<=h; i++){
        string input_s;
        cin >> input_s;
        s[i] = '.' + input_s + '.';
    }
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(s[i][j]=='#') continue;
            int cnt=0;
            if(s[i+1][j]=='#') cnt++;
            if(s[i-1][j]=='#') cnt++;
            if(s[i][j+1]=='#') cnt++;
            if(s[i][j-1]=='#') cnt++;
            
            if(cnt>=2) cout << to_string(i) + " " + to_string(j) << endl;
        }
    }
}
