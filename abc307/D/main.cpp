#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    std::cin >> N;
    string S;
    std::cin >> S;

    stack<int> st;
    vector<int> status(N,-1);
    for(int i=0; i<N; i++){
        if(S[i]=='('){
            st.push(i);
        }
        if(S[i]==')'){
            if(st.empty()) continue;
            status[st.top()] = i;
            st.pop();
        }
    }
    for(int i=0; i<N; i++){
        if(status[i]==-1){
            std::cout << S[i];
        }
        else{
            i=status[i];
        }
    }
    std::cout << endl;
}
