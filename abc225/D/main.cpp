#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<pair<int,int>> state(N+1,make_pair(-1,-1));
    
    auto all_say = [&](int xx){
        //find first;
        int top = xx;
        while(state[top].first!=-1){
            top = state[top].first;
        }
        int i = top;
        string s = to_string(i);
        int count = 1;
        while(state[i].second != -1){
            i = state[i].second;
            s += " " + to_string(i);
            count ++;
        }
        cout << count << " " << s << endl;
    };

    for(int q=0; q<Q; q++){
        int query;
        cin >> query;
        if(query==1){
            int x,y;
            cin >> x >> y;
            state[x].second = y;
            state[y].first = x;
        }
        if(query==2){
            int x,y;
            cin >> x >> y;
            state[x].second = -1;
            state[y].first = -1;
        }
        if(query==3){
            int x;
            cin >> x;
            all_say(x);
        }
    }
}
