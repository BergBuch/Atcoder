#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    long long l,r;
    cin >> l >> r;
    vector<long long> smaller{0LL},bigger{0LL};
    for(int i=0; i<N-2; i++){
        long long a;
        cin >> a;
        if(a>=l && a<=r) M--;
        if(a<l){
            smaller.push_back(l-a);
        }
        if(a>r){
            bigger.push_back(a-r);
        }
        if(a<l && a>r) M++;
    }
    sort(smaller.begin(),smaller.end());
    sort(bigger.begin(),bigger.end());
    /*
    cout << "smaller: ";
    for(auto e:smaller) cout << e << " ";
    cout <<endl;
    cout << "bigger: ";
    for(auto e:bigger) cout << e << " ";
    cout <<endl;

    cout << "M: " << M << endl;
    */
    
    long long ans = 1000000000000LL;
    if(M<=0) ans = 0;
    else{
        for(int i=0;i<=M;i++){
            long long cnt_l = i;
            long long cnt_r = M-i;
            if(cnt_r<0LL || cnt_r>=bigger.size()) continue;
            if(cnt_l<0LL || cnt_l>=smaller.size()) continue;
            ans = min(ans, smaller[cnt_l] + bigger[cnt_r]);
        }
    }
    if(l>r) if(ans<abs(l-r)) ans = abs(l-r);

    cout << ans << endl;

}
