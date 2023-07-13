#include<bits/stdc++.h>
using namespace std;

int b1=-1,b2=-1;
int x=-1,z,y=-1;

int main(){
    string S;
    cin >> S;
    
    for(int i=0; i<8; i++){
        switch(S[i]){
            case 'B':
                if(b1==-1) b1=i;
                if(b1!=-1) b2=i;
                break;
            case 'K':
                z = i;
                break;
            case 'R':
                if(x==-1) x=i;
                if(x!=-1) y=i;
                break;
        }
    }
    
    bool con1 = (b2-b1)%2 == 1;
    bool con2 = x<z && z<y;

    if(con1&&con2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
