#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int q=0; q<T; q++){
        long long N,K;
        cin >> N >> K;
        long long num_bit=0;
        while(N!=0){
            num_bit += N%3;
            N /= 3;
        }
        if(num_bit<=K && (num_bit-K)%2==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
