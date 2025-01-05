#include <bits/stdc++.h>

struct Info {
    int total;
    std::vector<int> sequence;
};

void findPaths(int idx, const std::vector<int>& arr, int limit, int accum, std::vector<int>& track, std::vector<Info>& ans) {
    if (idx >= (int)arr.size() || arr[idx] == -1) return;
    track.push_back(idx);
    accum += arr[idx];
    if (accum > limit) {
        track.pop_back();
        return;
    }
    int l = 2 * idx + 1, r = 2 * idx + 2;
    bool leaf = true;
    if (l < (int)arr.size() && arr[l] != -1) {
        leaf = false;
        findPaths(l, arr, limit, accum, track, ans);
    }
    if (r < (int)arr.size() && arr[r] != -1) {
        leaf = false;
        findPaths(r, arr, limit, accum, track, ans);
    }
    if (leaf) {
        Info temp;
        temp.total = accum;
        temp.sequence = track;
        ans.push_back(temp);
    }
    track.pop_back();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, L;
    std::cin >> n >> L;
    std::vector<int> arr(n);
    for (auto &x: arr) std::cin >> x;
    std::vector<Info> ans;
    std::vector<int> track;
    if (n > 0 && arr[0] != -1) {
        findPaths(0, arr, L, 0, track, ans);
    }
    for (auto &p: ans) {
        std::cout << p.total;
        for (auto &node: p.sequence) {
            std::cout << ' ' << node;
        }
        std::cout << '\n';
    }
    return 0;
}
