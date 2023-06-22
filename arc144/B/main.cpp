#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long a,b;
    cin >> N >> a >> b;
    vector<long long> A(N);
    long long input;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    long long l=1LL,r=1000000000LL;
    while(l<r-1){
        long long c = (l+r+1)/2;
        cout << "searching " << c << endl;
        long long x=0,y=0;
        for(int i=0; i<N; i++){
            if(A[i]<c) x += ((c-A[i])%a==0)?((c-A[i])/a):((c-A[i])/a + 1);
        }
        if(x>y) r=c;
        else l=c;
        cout << "l=" << l << ",r=" << r << endl;
    }
    cout << l << endl;
}