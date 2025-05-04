#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<int> ropes;

void input(){
    cin >> n;
    ropes.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> ropes[i];
    }  
    sort(ropes.begin(),ropes.end());
}

void solve(){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(ropes[i] * (n - i) > ans){
            ans = ropes[i] * (n - i);
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}