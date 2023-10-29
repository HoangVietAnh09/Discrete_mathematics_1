#include <bits/stdc++.h>
using namespace std;

int a[100][100], n, k, x[100];
int hang = 0;

void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}

void result() {
    for (int j = 1; j <= n; j++) {
        int res = x[j] * a[hang][j];
        if (res > 0)
            cout << res;
    }
    cout << ' ';
}

void chuyenVi() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
}

void check() {
    int res = 0;
    for (int j = 1; j <= n; j++) {
        res += a[hang][j] * x[j];
    }
    if (res == k) {
        result();
    }
}

void test(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            check();
        }
        else
            test(i + 1);
    }
}

int main() {
    init();
    while (hang < n) {
        ++hang;
        cout << "Cac cach chon cua hang " << hang << ": \n";
        test(1);
        cout << endl;
    }
    hang = 0;
    chuyenVi();
    while (hang < n) {
        ++hang;
        cout << "Cac cach chon cua cot " << hang << ": \n";
        test(1);
        cout << endl;
    }
    return 0;
}