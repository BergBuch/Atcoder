#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int a[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int f[100][100];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            f[i][j]=0;
        }
    }
    int x,y;
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            x=a[i][j];
            y=a[i][j+1];
            f[x][y]=1;
            f[y][x]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i][j]==1) ans++;
        }
    }
    cout << ans << endl;
}
