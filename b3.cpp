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

struct Node {
    int vitri;
    int tong;
    vector<int> thamchieu;
};

struct ThongTin {
    int ketQuaHienTai;
    vector<int> lienKet;
};

int bai2() {
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

void sloveTimDuong(int viTri, const vector<int>& cayNhiPhan, int limit, int accum, vector<int>& track, vector<ThongTin>& dapAn) {
    if (viTri >= (int)cayNhiPhan.size() || cayNhiPhan[viTri] == -1) return;
    track.push_back(viTri);
    accum += cayNhiPhan[viTri];
    if (accum > limit) {
        track.pop_back();
        return;
    }
    int l = 2 * viTri + 1, r = 2 * viTri + 2;
    bool leaf = true;
    if (l < (int)cayNhiPhan.size() && cayNhiPhan[l] != -1) {
        leaf = false;
        sloveTimDuong(l, cayNhiPhan, limit, accum, track, dapAn);
    }
    if (r < (int)cayNhiPhan.size() && cayNhiPhan[r] != -1) {
        leaf = false;
        sloveTimDuong(r, cayNhiPhan, limit, accum, track, dapAn);
    }
    if (leaf) {
        ThongTin temp;
        temp.ketQuaHienTai = accum;
        temp.lienKet = track;
        dapAn.push_back(temp);
    }
    track.pop_back();
}

int main(){
    int n, L;
    cin >> n >> L;

    vector<int> cayNhiPhan(n);
    for (auto &x: cayNhiPhan) {
        cin >> x;
    }

    vector<ThongTin> dapAn;
    vector<int> track;

    if (n > 0 && cayNhiPhan[0] != -1) {
        sloveTimDuong(0, cayNhiPhan, L, 0, track, dapAn);
    }

    for (auto &p: dapAn) {
        cout << p.ketQuaHienTai;

        for (auto &node: p.lienKet) {
            cout << " " << node;
        }
        cout << endl;
    }
    return 0;
}
