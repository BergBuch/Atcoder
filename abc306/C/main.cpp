#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    vector<int> sorted_index;
    vector<int> count(n+1,0);
    for(int i=0; i<3*n; i++){
        cin >> a;
        count[a]++;
        if(count[a]==2) sorted_index.push_back(a);
        if(sorted_index.size()==n) break;
    }
    for(int i=0; i<n-1; i++) cout << sorted_index[i] << " ";
    cout << sorted_index[n-1] << endl;
}
