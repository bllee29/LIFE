#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #define Equilateral 0
// #define Scalene     1
// #define Isosceles   2
// #define Invalid     3


void solve(int a, int b, int c){
    int temp;
    if (a < b) { int temp = a; a = b; b = temp; }
    if (b < c) { int temp = b; b = c; c = temp; }
    if (a < b) { int temp = a; a = b; b = temp; }

    if(a == 0){
        return;
    }

    // Invalid
    if(a >= b + c){
        cout << "Invalid\n";
        return;
    }

    // Equilateral
    else if((a == b) && (b == c)){
        cout<< "Equilateral\n";
        return;
    }
    
    // Isosceles
    else if((a == b) || (b == c) || (c == a)){
        cout << "Isosceles\n";
        return;
    }

    // Scalene
    else{
        cout << "Scalene\n";
        return;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a = 1;
    int b = 1;
    int c = 1;

    while(a != 0){
        cin >> a >> b >> c;
        solve(a, b, c);
    }
    
}
