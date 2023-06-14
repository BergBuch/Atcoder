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
    //最初の入力
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    //準備。偶数番目までの和をもっておき、任意の区間の和をO(1)で求められるようにする。
    vector<long long> sum_sleep((n-1)/2 + 1);
    sum_sleep[0] = 0;
    for(int i=1; i<=(n-1)/2; i++){
        sum_sleep[i] = sum_sleep[i-1] + a[2*i] - a[2*i - 1];
    }

    //問題を解いていく
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        long long l,r;
        cin >> l >> r;
        int l_right = distance(a.begin(), lower_bound(a.begin(),a.end(),l));
        int r_right = distance(a.begin(), lower_bound(a.begin(),a.end(),r));
        long long low_edge=0;
        long long up_edge=0;
        int not_yet_sleep;
        int wake_up_just_now;
        //眠った状態からスタート
        if(l_right%2==0){
            low_edge = a[l_right] - l;
            not_yet_sleep = l_right;
        }
        //起きた状態からスタート
        else{
            not_yet_sleep = l_right - 1;
        }
        //眠った状態で終わり
        if(r_right%2==0){
            up_edge = r - a[r_right-1];
            wake_up_just_now = r_right-2;
        }
        //起きた状態で終わり
        else{
            wake_up_just_now = r_right - 1;
        }
        long long ans = low_edge + up_edge + sum_sleep[wake_up_just_now/2] - sum_sleep[not_yet_sleep/2];
        cout << ans << endl;
    }
}
