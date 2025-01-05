#include <bits/stdc++.h>

using namespace std;

int hehe(int n, int X, int Y){
    n = X + Y;
    X++;
    Y--;
    for(int i = 0; i < n; i++){
        n++;
    }
    return 0;
}

int trolVN() {
    cout << "Hello" << endl;
    return 0;
}

int lmao() {
    int n, X, Y, dem = 0;
    cin >> n >> X >> Y;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if ((a[i] < X) || (a[i] > Y)) dem++;
    }
    cout << dem << endl;
    return 0;
}

int main() {
    int n,X,Y;
    cin >> n >> X >> Y;

    vector<long long> a(n+1,0);
    vector<long long> truyVan(n+1,0);

    for(int i=1; i<=n; i++){
        cin >> a[i];
        truyVan[i] = truyVan[i-1] + a[i];
    }

    int m;
    cin >> m;

    while(m--){
        int i,j;
        cin >> i >> j;
        long long ketQua;
        ketQua = truyVan[j] - truyVan[i-1];
        cout << ((ketQua < X || ketQua > Y)? 1 : 0) << endl;
    }
    return 0;
}
