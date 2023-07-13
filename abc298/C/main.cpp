#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int Q;
    cin >> N >> Q;
    vector<multiset<int>> cards(N+1);
    vector<set<int>> boxes(2<<17);

    for(int q=0; q<Q; q++){
        int ope;
        cin >> ope;
        if(ope==1){
            int i,j;
            cin >> i >> j;
            cards[j].insert(i);
            boxes[i].insert(j);
        }
        if(ope==2){
            int i;
            cin >> i;
            for(auto p=cards[i].begin(); p!=cards[i].end(); p++){
                if(p!=cards[i].begin()) cout << " ";
                cout << *p;
            }
            cout << endl;
        }
        if(ope==3){
            int i;
            cin >> i;
            for(auto p=boxes[i].begin(); p!=boxes[i].end(); p++){
                if(p!=boxes[i].begin()) cout << " ";
                cout << *p;
            }
            cout << endl;
        }
    }
}
