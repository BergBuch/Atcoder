#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int max_zero=0;
    int min_one=N-1;

    while(min_one - max_zero != 1){
        int half = (min_one + max_zero)/2;
        cout << "? " << half+1 << endl;
        int s;
        cin >> s;
        if(s==0) max_zero = half;
        if(s==1) min_one = half;
    }
    int p = max_zero+1;
    cout << "! " << p << endl;
}