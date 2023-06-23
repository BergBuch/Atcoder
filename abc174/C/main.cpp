#include<bits/stdc++.h>
using namespace std;

int main(){
    long long k;
    cin >> k;
    long long sevens = 0;
    for(int i=1; i<=10000000; i++){
        sevens = sevens*10 + 7;
        sevens %= k;
        if(sevens == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
