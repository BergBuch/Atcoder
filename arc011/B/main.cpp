#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> d(256,'x');
    d['b'] = d['c'] = '1';
    d['d'] = d['w'] = '2';
    d['t'] = d['j'] = '3';
    d['f'] = d['q'] = '4';
    d['l'] = d['v'] = '5';
    d['s'] = d['x'] = '6';
    d['p'] = d['m'] = '7';
    d['h'] = d['k'] = '8';
    d['n'] = d['g'] = '9';
    d['z'] = d['r'] = '0';
    d['B'] = d['C'] = '1';
    d['D'] = d['W'] = '2';
    d['T'] = d['J'] = '3';
    d['F'] = d['Q'] = '4';
    d['L'] = d['V'] = '5';
    d['S'] = d['X'] = '6';
    d['P'] = d['M'] = '7';
    d['H'] = d['K'] = '8';
    d['N'] = d['G'] = '9';
    d['Z'] = d['R'] = '0';

    int N;
    cin >> N;
    string s;
    vector<string> ans(N,"");
    for(int i=0; i<N; i++){
        cin >> s;
        for(char moji: s){
            if(d[moji] != 'x'){
                string str(1,d[moji]);
                ans[i] += str;
            }
        }
    }
    string output;
    for(int i=0; i<N; i++){
        if(ans[i]=="") continue;
        output += ans[i] + " ";
    }
    if(output!="") output.resize(output.size()-1);
    cout << output << endl;
}
