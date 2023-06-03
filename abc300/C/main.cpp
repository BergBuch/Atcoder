#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define sayYes cout<<"Yes"<<endl;
#define sayNo cout<<"No"<<endl;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h+2);
    c[0] = c[h+1] = string(w+2,'.');
    rep(i,1,h+1){
        cin >> c[i];
        c[i] = "." + c[i] + ".";
    }
    vi ans(min(h,w)+1);
    vector<vector<bool>> is_searched(h+2,vector<bool>(w+2,false));
    rep(i,0,h+2)rep(j,0,w+2){
        if(is_searched[i][j])continue;
        is_searched[i][j] = true;
        if(c[i][j]=='#'){
            int c_size = 1;
            char now=c[i+c_size][j+c_size];
            while(now=='#'){
                is_searched[i+c_size][j+c_size]=true;
                c_size++;
                now=c[i+c_size][j+c_size];
            }
            ans[(c_size-1)/2]++;
        }
    }
    cout << ans[1];
    rep(i,2,min(h,w)+1) cout << " " << ans[i];
    cout << endl;
}
