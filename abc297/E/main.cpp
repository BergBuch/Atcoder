#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    set<long long> P;
    vector<long long> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
        P.insert(A[i]);
    }

    for(int k=0; k<K-1;k++){
        long long cheap = *P.begin();
        P.erase(P.begin());
        for(int i=0; i<N; i++) P.insert(cheap+A[i]);
    }

    cout << *P.begin() << endl;
}
