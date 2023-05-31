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
    string cs = "snuke";
    int ans_k,ans_h,ans_w;
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    int dh[8]={-1,-1,-1,0,0,1,1,1};
    int dw[8]={-1,0,1,-1,1,-1,0,1};
    rep(i,0,h){
        rep(j,0,w){
            rep(k,0,8){
                bool is_snuke = true;
                rep(l,0,5){
                    //i,jマスを中心に8方向のうちkの方向にlマス先まで調べる
                    if(i+dh[k]*l>=h or i+dh[k]*l<0)is_snuke=false;
                    else if(j+dw[k]*l>=w or j+dw[k]*l<0)is_snuke=false;
                    else if(s[i+dh[k]*l][j+dw[k]*l]!=cs[l])is_snuke=false;
                }
                if(is_snuke){
                    ans_k=k;
                    ans_h=i+1;
                    ans_w=j+1;
                }
            }
        }
    }
    rep(i,0,5) cout << ans_h + dh[ans_k]*i << " " << ans_w + dw[ans_k]*i << endl;
}
