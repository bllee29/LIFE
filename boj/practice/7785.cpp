#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
map<string, string> record;

void input(){
    cin >> n;
}
 
// void solve(){
//     string name, log;
//     for(int i = 0; i < n; ++i){
//         cin >> name >> log;
//         if(record.find(name) != record.end()){
//             record.erase(name);
//         }
//         else{
//             record.emplace(name, log);
//         }
//     }

//     for(auto rit = record.rbegin(); rit != record.rend(); ++rit){
//         cout << rit->first << "\n";
//     }
// }

// 이렇게 해도 되지만? 이거는 원론적인 방법
// 문제의 핵심을 파악 할 수 있다면 핵심적인 내용만 사용하도록 하자

void solve(){
    string name, log;
    for(int i = 0; i < n; ++i){
        cin >> name >> log;
        if(log == "enter"){
            record[name] = 1;
            // 이렇게도 할당 가능
        }
        else{
            record.erase(name);
        }
    }

    for(auto rit = record.rbegin(); rit != record.rend(); ++rit){
        cout << rit->first << "\n";
    }
}

int main(){
    input();
    solve();
}
