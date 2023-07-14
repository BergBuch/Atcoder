#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(100001,0);
    long long sum=0;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        sum += a;
        A[a]++;
    }

    int Q;
    cin >> Q;
    for(int q=0;q<Q;q++){
        int b,c;
        cin >> b >> c;
        int count = A[b];
        A[b] = 0;
        A[c] += count;
        sum = sum + count*(c-b);

        cout << sum << endl;
    }
}
