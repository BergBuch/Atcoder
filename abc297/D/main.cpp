#include<bits/stdc++.h>
using namespace std;

int main(){
    long long A,B;
    cin >> A >> B;
    long long ans = 0;
    while(A!=B){
        if(A>B){
            ans += A/B;
            if(A%B==0){
                A = B;
                ans--;
                continue;
            }
            A = A%B;
        }
        else if(B>A){
            ans += B/A;
            if(B%A==0){
                B = A;
                ans--;
                continue;
            }
            B = B%A;
        }
    }
    cout << ans << endl;
}
