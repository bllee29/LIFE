#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, string>> v;
int n; 

bool comp(const pair<int, string>& a, const pair<int, string>& b){
    return a.first < b.first;
}

void input(){
    cin >> n;
    int age;
    string name;

    v.reserve(n);

    for(int i = 0; i < n; ++i){
        cin >> age >> name;
        v.emplace_back(age, name);
    }
}

void solve(){
    stable_sort(v.begin(), v.end(), [](auto& a, auto& b){
        return a.first < b.first;
    });

    // stable_sort(v.begin(), v.end(), comp);

    for(int i = 0; i < n; ++i){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}