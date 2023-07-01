#include<bits/stdc++.h>
using namespace std;

//snukeかどうか判定
bool is_snuke(char s1, char s2){
    string sample = "snukes";
    for(int i=0; i<5; i++){
        if(sample[i] == s1 && sample[i+1] == s2) return true;
    }
    return false;
}

int main(){
    //入力。周りはaで囲った
    int H,W;
    cin >> H >> W;
    vector<string> s(H+2);
    s[0] = s[H+1] = string(W+2,'a');
    for(int h=1; h<=H; h++){
        string temp;
        cin >> temp;
        s[h] = "a"+temp+"a";
    }
    //入力終了

    string ans = "No";
    queue<pair<int,int>> q;
    vector<vector<bool>> is_searched(H+2,vector<bool>(W+2,false));
    vector<pair<int,int>> adjustments{{0,1},{0,-1},{1,0},{-1,0}};
    //幅優先探索。キューに入ったものから次の操作を行う。
    //隣り合うかつ、snukeの条件を満たすかつ、未探索のものをキューに入れる。
    //ただし、ゴールがキューに入れる条件を満たした場合、答えをtrueにして終了。
    q.push({1,1});
    while(!q.empty()){
        pair<int,int> now_search = q.front();
        q.pop();
        int h1 = now_search.first;
        int w1 = now_search.second;
        for(auto ad: adjustments){
            int h2 = h1 + ad.first;
            int w2 = w1 + ad.second;
            if(is_snuke(s[h1][w1],s[h2][w2]) && !is_searched[h2][w2]){
                q.push({h2,w2});
                is_searched[h2][w2] = true;
                if(h2==H && w2==W) ans = "Yes";
            }
        }
    }
    cout << ans << endl;
}
