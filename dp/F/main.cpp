#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    s="z"+s;
    t="z"+t;
    //dp[i][j]はsのi文字目までとtのj文字目までに共通する部分列の最長
    vector<vector<int>> dp(3001,vector<int>(3001,0));
 
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int len = dp[s.size()][t.size()];
    string ans = string(len,'a');
    int i=s.size(),j=t.size();
    while(i!=0 && j!=0){
        if(j-1>=0 && dp[i][j]==dp[i][j-1]) j--;
        else if(i-1>=0 && dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j] - dp[i-1][j-1] == 1){
            len--;
            ans[len] = s[i];
            i--;j--;
        }
        
    }
    cout << ans << endl;
}
