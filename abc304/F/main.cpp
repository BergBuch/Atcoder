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

vector<long long>find_prime(long long n){
    vector<bool> is_prime(n+1,true);
    is_prime[1] = false;
    for(int i=2;i<n+1;i++){
        if(!is_prime[i])continue;
        for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
    }
    vector<long long> prime_list;
    for(int i=1;i<n+1;i++) if(is_prime[i]) prime_list.push_back(i);
    return prime_list;
}

vector<int> calc_divisors(int n){
    vector<int> divisors;
    for(int i=1;i<=n;i++) if(n%i==0) divisors.push_back(i);
    return divisors;
}

int main(){
    cout << find_prime(100000).size();
}
