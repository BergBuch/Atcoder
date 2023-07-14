#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    int sn=0;
    int tn=N;
    while(tn>0){
        sn += tn%10;
        tn /= 10;
    }
    if(N%sn==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
