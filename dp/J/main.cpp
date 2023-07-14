#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int c1=0,c2=0,c3=0;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x==1)c1++;
        if(x==2)c2++;
        if(x==3)c3++;
    }

    vector<vector<vector<int>>> dp(c1+1,vector<vector<int>>(c2+1,vector<int>(c3+1,0)));
    vector<vector<vector<bool>>> flag(c1+1,vector<vector<bool>>(c2+1,vector<bool>(c3+1,false)));
    
    dp[c1][c2][c3] = 0;
    
    function<double(int,int,int)> f = [&](int a,int b,int c) -> double{
        if(a>=c1||b>=c2||c>=c3) return 0;
        if(a<0||b<0||c<0) return 0;
        if(flag[a][b][c]) return dp[a][b][c];
        flag[a][b][c] = true;
        double res=0;
        if(a+1<=c1) res += (1+f(a+1,b,c))*((a+1)/N) / (double(a+b+c)/N);
        if(b+1<=c2 && a>=1) res += (1+f(a-1,b+1,c))*((b+1))/N  / (double(a+b+c)/N);
        if(c+1<=c3 && b>=1) res += (1+f(a,b-1,c+1))*((c+1))/N  / (double(a+b+c)/N);
        return dp[a][b][c]=res;
    };

    cout << f(0,0,0) << endl;
}
