#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int,int>> p;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        p.insert({x,y});
    }
    pair<int,int> t(0,0);
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            t.first++;
        }
        if(s[i]=='L'){
            t.first--;
        }
        if(s[i]=='U'){
            t.second++;
        }
        if(s[i]=='D'){
            t.second--;
        }
        h--;
        if(h<0){
            cout << "No" << endl;
            return 0;
        }
        if(h<k and p.count({t.first,t.second})){
            h=k;
            p.erase({t.first,t.second});
        }
    }
    cout << "Yes" << endl;
}
