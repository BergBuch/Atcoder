#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> vote;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(vote.find(s) != vote.end()){
            vote[s]++;
        }
        else{
            vote[s]=1;
        }
    }
    string ans_name;
    int max_vote=0;
    for(auto e: vote){
        if(max_vote<e.second){
            max_vote = e.second;
            ans_name = e.first;
        }
    }
    cout << ans_name << endl;
}
