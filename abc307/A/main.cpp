#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string ans;
    std::cin >> N;
    for(int i=0; i<N; i++){
        int sum=0;
        for(int j=0;j<7; j++){
            int a;
            std::cin >> a;
            sum += a;
        }
        if(i==N-1) ans += to_string(sum);
        else ans += to_string(sum) + " ";
    }
    std::cout << ans << endl;
}
