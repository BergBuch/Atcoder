#include<bits/stdc++.h>
using namespace std;

int a;
long long b,n;
long long f(long long x){
    return (a*x)/b - a*(x/b);
}

int main(){
    cin >> a >> b >> n;
    long long ans = max(f(n),f((n/b)*b - 1));
    cout << ans << endl;
}
