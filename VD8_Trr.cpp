#include <bits/stdc++.h>
using namespace std;
int n, k, a[1004], ok;
int check(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return n > 1;
}
void khoiTao(){
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
}
void sinh(){
    int i = n-1;
    while(i >= 1 && a[i] > a[i+1]){
        --i;
    }
    if(i == 0){
        ok = 0;
    }else{
        int j = n;
        while(a[i] > a[j]) --j;
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while(l < r){
            swap(a[l], a[r]);
            ++l, --r;
        }
    }
}

bool checkTong(int d[], int l, int r, int n){
    while(r <= n){
        int sum = 0;
        for(int i = l; i <= r; i++){
            sum += d[i];
        }
        if(!check(sum))
            return false;
        else
            l++, r++;
    }
    return true;
}

int main(){
    cin >> n;
    int c[2004], d[2004];
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    ok = 1;
    khoiTao();
    while(ok){
        map<int, int> mp;
        for(int i = 1; i <= n; i++){
            mp.insert({a[i], c[i]});
        }
        int t = 1;
        for(auto x : mp){
            d[t++] = x.second;
        }
        int l = 1, r = 3;
        if(checkTong(d, l, r, n)){
            for(int i = 1; i <= n; i++){
                cout << d[i] << " ";
            }
            cout << endl;
        }
        sinh();
    }
    return 0;
}
