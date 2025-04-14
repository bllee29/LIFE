#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

int n, s;
int arr[MAXN];

void input(){
    cin >> n >> s;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

int solve(int i, int sum){
    if(i == n){
        return (sum == s) ? 1 : 0;
    }

    return solve(i + 1, sum) + solve(i + 1, sum + arr[i]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();

    int ans = solve(0,0);
    if(s == 0){
        cout << ans - 1;
    }
    else{
        cout << ans;
    }

}