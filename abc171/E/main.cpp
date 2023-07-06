#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    long long sum=0;
    for(int i=0; i<N; i++){
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i=0; i<N; i++){
        if(i!=0) cout << " ";
        cout << (sum^a[i]);
    }
    cout << endl;
}
