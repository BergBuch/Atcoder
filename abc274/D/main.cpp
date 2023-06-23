#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,x,y;
    vector<vector<int>> xdp(1001,vector<int>(30000,false));
    vector<vector<int>> ydp(1001,vector<int>(30000,false));

    cin >> N >> x >> y;

    vector<int> ax,ay;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(i%2==0) ax.push_back(a);
        else ay.push_back(a);
    }
    //xdp
    xdp[0][0+10000] = true;
    xdp[1][ax[0]+10000] = true;
    for(int i=1; i<ax.size(); i++){
        for(int j=-10000;j<=10000;j++){
            if(xdp[i][j+10000]){
                xdp[i+1][j+10000+ax[i]] = true;
                xdp[i+1][j+10000-ax[i]] = true;
            }
        }
    }
    //ydp
    ydp[0][0+10000] = true;
    for(int i=0; i<ay.size(); i++){
        for(int j=-10000;j<=10000;j++){
            if(ydp[i][j+10000]){
                ydp[i+1][j+10000+ay[i]] = true;
                ydp[i+1][j+10000-ay[i]] = true;
            }
        }
    }
    if(xdp[ax.size()][x+10000] && ydp[ay.size()][y+10000]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
