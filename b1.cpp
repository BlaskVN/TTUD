#include <bits/stdc++.h>

using namespace std;

int slove(int n, int X, int Y){
    n = X + Y;
    X++;
    Y--;
    for(int i = 0; i < n; i++){
        n++;
    }
    return 0;
}

int main() {
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
