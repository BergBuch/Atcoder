#include<bits/stdc++.h>
using namespace std;

int main(){
    //input
    int N;
    std::cin >> N;
    vector<string> s(N);
    for(int i=0; i<N; i++) std::cin >> s[i];

    //search
    string ans="No";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            string cs = s[i] + s[j];
            bool is_cycle = true;
            for(int k=0; k<=(cs.size()-1)/2; k++){
                if(cs[k]!=cs[cs.size()-1-k]){
                    is_cycle=false;
                    break;
                }
            }
            if(is_cycle) ans = "Yes";
        }
    }
    std::cout << ans << endl;
}
