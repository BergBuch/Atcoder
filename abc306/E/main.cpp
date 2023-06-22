#include<bits/stdc++.h>
using namespace std;

multiset<long long> x,y;
int n,k,q;
long long s=0;

void balance(){
    while(x.size()<k){
        auto iy = y.end(); iy--;
        long long max_y = *iy;
        x.insert(*iy);
        y.erase(iy);
        s += max_y;
    }
    if(x.empty() || y.empty()) return;

    while(true){
        auto ix = x.begin();
        auto iy = y.end();iy--;
        long long min_x = *ix;
        long long max_y = *iy;
        if(min_x<max_y){
            y.erase(iy);
            x.erase(ix);
            x.insert(max_y);
            y.insert(min_x);
            s += max_y - min_x;
        }
        else break;
    }
}
void erase(int e){
    auto ix = x.find(e);
    if(ix!=x.end()){
        x.erase(ix);
        s -= e;
    }
    else{
        y.erase(y.find(e));
    }
    balance();
}
void add(int e){
    y.insert(e);
    balance();
}

int main(){
    cin >> n >> k >> q;
    for(int i=0; i<k; i++){
        x.insert(0);
    }
    for(int i=k; i<n; i++){
        y.insert(0);
    }
    balance();
    vector<int> a(n,0);
    for(int i=0; i<q; i++){
        int index,new_y;
        cin >> index >> new_y;
        index--;
        add(new_y);
        erase(a[index]);
        a[index] = new_y;
        cout << s << endl;
    }
}
