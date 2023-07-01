#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> b; //ボールの情報
vector<string> swap_hist;//swap履歴　入れ替え座標を表す数字4*kのベクトル
vector<vector<int>> swap_hist2;
vector<vector<bool>> decided(30,vector<bool>(30,false));

void swap(int x1, int y1, int x2, int y2){//座標を指定してボールを入れ替える
    int temp;
    temp = b[x1][y1];
    b[x1][y1] = b[x2][y2];
    b[x2][y2] = temp;
    string current_swap = to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
    swap_hist.push_back(current_swap);
    vector<int> current_swap2{x1,y1,x2,y2};
    swap_hist2.push_back(current_swap2);
}

bool is_valid_pos(pair<int,int> pos){
    int x = pos.first;
    int y = pos.second;
    bool con1 = y<=x;
    bool con2 = x>=0;
    bool con3 = y>=0;
    bool con4 = x<=29;
    return con1 && con2 && con3 && con4;    
}

void swap_extend(pair<int,int> pos1, pair<int,int> pos2){//飛び飛びで入れ替える    
    pair<int,int> current_pos = pos1;
    pair<int,int> distination_pos = pos2;
    int x1 = current_pos.first;
    int y1 = current_pos.second;
    int x2 = distination_pos.first;
    int y2 = distination_pos.second;
    while(current_pos != distination_pos){
        x1 = current_pos.first;
        y1 = current_pos.second;
        if(x1 < x2 && y1 < y2 && !decided[x1+1][y1+1] && is_valid_pos({x1+1,y1+1})){
            swap(x1,y1,x1+1,y1+1);
            current_pos = {x1+1,y1+1};
        }
        else if(x1 > x2 && y1 > y2 && !decided[x1-1][y1-1] && is_valid_pos({x1-1,y1-1})){
            swap(x1,y1,x1-1,y1-1);
            current_pos = {x1-1,y1-1};
        }
        else if(x1 < x2 && !decided[x1+1][y1] && is_valid_pos({x1+1,y1})){
            swap(x1,y1,x1+1,y1);
            current_pos = {x1+1,y1};
        }
        else if(y1 < y2 && !decided[x1][y1+1] && is_valid_pos({x1,y1+1})){
            swap(x1,y1,x1,y1+1);
            current_pos = {x1,y1+1};
        }
        else if(x1 > x2 && !decided[x1-1][y1] && is_valid_pos({x1-1,y1})){
            swap(x1,y1,x1-1,y1);
            current_pos = {x1-1,y1};
        }
        else if(y1 > y2 && !decided[x1][y1-1] && is_valid_pos({x1,y1-1})){
            swap(x1,y1,x1,y1-1);
            current_pos = {x1,y1-1};
        }
    }
}

int dist(pair<int,int> pos1, pair<int,int> pos2){
    int x1 = pos1.first;
    int y1 = pos1.second;
    int x2 = pos2.first;
    int y2 = pos2.second;
    if((x1-x2)*(y1-y2)>0) return max(abs(x1-x2),abs(y1-y2));
    else return abs(x1-x2)+abs(y1-y2);
}

vector<pair<int,int>> find_acceptable(){
    vector<pair<int,int>> acceptable{};
    if(!decided[0][0]) acceptable.push_back({0,0});
    for(int i=1; i<30; i++){
        for(int j=0; j<=i; j++){
            bool decided_yet = !decided[i][j];
            bool parent1_decided = ((j==i) || decided[i-1][j]);
            bool parent2_decided = ((j==0) || decided[i-1][j-1]);
            bool left_decided = (j==0 || decided[i][j-1]);
            bool right_decided = (j==i || decided[i][j+1]);
            bool reject29 = (i != 29);  
            if (decided_yet && parent1_decided && parent2_decided && reject29 && (left_decided || right_decided)){
                acceptable.push_back({i,j});
            }
        }
    }
    return acceptable;
}

pair<int,int> nearest_acceptable(pair<int,int> pos){
    vector<pair<int,int>> acceptable = find_acceptable();
    if(acceptable.size()==0) return {-1,-1};
    pair<int,int> nearest_pair;
    int nearest_distance = 1000;
    for(auto accept_pair: acceptable){
        int d = dist(pos,accept_pair);
        if(d < nearest_distance){
            nearest_distance = d;
            nearest_pair = {accept_pair.first,accept_pair.second};
        }
    }
    return nearest_pair;
}

bool is_vio(int x, int y){//違反してるかどうか
    if(x==29) return false;
    if(b[x][y] < b[x+1][y] && b[x][y] < b[x+1][y+1]) return false;
    else{
        cout << "parent is " << b[x][y] << endl;
        cout << "children are " << b[x+1][y] << " and " << b[x+1][y+1] << endl;
        return true;
    }
}
void cout_vio_count(){
    int count = 0;
    for(int i=0; i<=28; i++){
        for(int j=0;j<=i; j++){
            if(is_vio(i,j)) count++;
        }
    }
    cout << "vio count is " << count << endl;
}

void cout_balls(){
    for(int i=28; i<=29; i++){
        for(int j=0; j<=i; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

pair<int,int> find_num(int num){//数字の座標を見つける pairを返す
    for(int i=0; i<30; i++){
        for(int j=0; j<=i; j++){
            if(b[i][j]==num) return {i,j};
        }
    }
    cout << "invalid num to the functon of find_num." << endl;
    return {-1,-1};
}



int main(){
    int N;
    N=30;
    b.resize(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<i+1; j++){
            int temp;
            cin >> temp;
            b[i].push_back(temp);
        }
    }

    for(int i=0; i<=465; i++){
    //i番のボールを確定させる。
        pair<int,int> pos_num = find_num(i);
        pair<int,int> distination = nearest_acceptable(pos_num);
        if(distination.first == -1 && distination.second == -1) continue;
        swap_extend(pos_num,distination);
        decided[distination.first][distination.second] = true;
    }
    int K = swap_hist.size();
    cout << K << endl;
    for(int i=0; i<K; i++){
        cout << swap_hist[i] << endl;
    }
    //cout_vio_count();
    //cout_balls();
    //cout << K << endl;
}
