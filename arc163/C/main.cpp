#include<bits/stdc++.h>
using namespace std;

void answer(int N){
    string ans;
    vector<long long> A;

    if(N==1){
        ans="Yes";
        A.push_back(1);
    }
    else if(N==2){
        ans = "No";
    }
    else{
        ans = "Yes";
        int temp=1;
        for(int i=0; i<N-3; i++){
            temp *= 2;
            A.push_back(temp);
        }
        A.push_back(2*temp);
        A.push_back(3*temp);
        A.push_back(6*temp);
    }

    cout << ans << endl;
    if(ans == "Yes"){
        for(int i=0; i<A.size(); i++){
            if(i!=0) cout << " ";
            cout << A[i];
        }
        cout << endl;
    }
}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        answer(N);
    }
}
