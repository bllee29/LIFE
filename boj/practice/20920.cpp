#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define p pair<string, int>

using namespace std;

int n, m;
map<string, int> mWord;
vector<p> vWord;

void input(){
    string tmp;
    
    cin >> n >> m;

    vWord.reserve(n);
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        if(tmp.length() < m){
            continue;
        }
        else{
            mWord[tmp]++;
        }
    }
}

void solve(){
    for(auto& it : mWord){
        vWord.emplace_back(it);
    }

    sort(vWord.begin(), vWord.end(), [](const auto& a, const auto& b){
        if(a.second != b.second){
            return a.second > b.second;
        }
        else if(a.first.length() != b.first.length()){
            return a.first.length() > b.first.length();
        }   
        else{
            return a.first < b.first;
        }
    });

    for(auto& it : vWord){
        cout << it.first << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}