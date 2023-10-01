#include <bits/stdc++.h>
using namespace std;
int checkPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return n > 1;
}
bool checkSum(int n, int s){
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n /= 10;
    }
    return sum == s;
}
void in(const vector<vector<int>>& v){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkCondition(const vector<vector<int>>& v, int s){
    for(int i = 0; i < 5; i++){
        int num = v[i][0]*10000 + v[i][1]*1000 + v[i][2]*100 + v[i][3]*10 + v[i][4];
        if(!checkPrime(num) || !checkSum(num, s))
            return false;
    }
    for(int j = 0; j < 5; j++){
        int num = v[0][j]*10000 + v[1][j]*1000 + v[2][j]*100 + v[3][j]*10 + v[4][j];
        if(!checkPrime(num) || !checkSum(num, s))
            return false;
    }
    int num1 = v[0][0]*10000 + v[1][1]*1000 + v[2][2]*100 + v[3][3]*10 + v[4][4];
    if(!checkPrime(num1) || !checkSum(num1, s))
        return false;
    int num2 = v[0][4]*10000 + v[1][3]*1000 + v[2][2]*100 + v[3][1]*10 + v[4][0];
    if(!checkPrime(num2) || !checkSum(num2, s))
        return false;
    return true;
}
void solve(vector<vector<int>>& v, int s, int row, int col, bool& found){
    if(found)   return;
    if(row == 5 && col == 0){
        if(checkCondition(v, s)){
            in(v);
            found = true;
        }
        return;   
    }
    if(col == 5){
        solve(v, s, row+1, 0, found);
        return;
    }
    for(int i = 0; i <= 9; i++){
        v[row][col] = i;
        solve(v, s, row, col+1, found);
    }
}

int main(){
    int s = 11;
    vector<vector<int>> v(5, vector<int>(5, 0));
    bool found = false;
    solve(v, s, 0, 0, found);
    return 0;
}