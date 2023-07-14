#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    cout << N << endl;
    for(int i=0;i<N;i++){
        if(i!=0) cout << " ";
        cout << rand()%10000 + 1;
    }
    cout << endl;
}