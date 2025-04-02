#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Rectangle 1
#define Covered 2
#define map_max 100

int m, n, k, sum;
int map[map_max + 1][map_max + 1];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> ans;

void print(){
    for(int j = m-1; j >= 0; --j){
        for(int i = 0; i < n; ++i){
            cout << map[j][i] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int y, int x){
    if(map[y][x] != 0){
        return;
    }

    ++sum;
    map[y][x] = Covered;
    // print();

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((0 <= nx) && (nx < n) && (0 <= ny) && (ny < m) && (map[ny][nx] == 0)){
            bfs(ny, nx);
        } 
    }
    return;
}

void input(){
    int x1, y1, x2, y2;
    cin >> m >> n >> k;

    for(int i = 0; i < k; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = y1; y < y2; ++y){
            for(int x = x1; x < x2; ++x){
                map[y][x] = Rectangle;
            }
        }
    }
}

void solve(){
    for(int y = 0; y < m; ++y){
        for(int x = 0; x < n; ++x){
            if(map[y][x] != 0){
                continue;
            }
            sum = 0;
            bfs(y,x);
            if(sum != 0){
                ans.emplace_back(sum);
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(auto& x: ans){
        cout << x << ' ';
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}