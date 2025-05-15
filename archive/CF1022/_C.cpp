#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.assign(n, 1);
        components = n;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        size[x] += size[y];
        parent[y] = x;
        components--;
        return true;
    }
};

void TC() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    map<int, vector<int>> indmap;
    for(int i = 0; i < n; i++) indmap[a[i]].push_back(i);
    vector<bool> checked(n, false);
    int c = 0;
    for(auto it = indmap.rbegin(); it != indmap.rend(); it++) {
        auto &[num, v] = *it;
        for(auto e : v) {
            if (checked[e]) continue;
            c += 1;
            queue<pair<int, int>> Q;
            checked[e] = 1;
            Q.push({e, a[e]});
            while(Q.size()) {
                auto [cci, ccq] = Q.front();
                Q.pop();
                for(auto el : {cci - 1, cci + 1}) {
                    if (el < 0 || el >= n) continue;
                    if (checked[el]) continue;
                    if (a[el] <= ccq) {
                        checked[el] = 1;
                        Q.push({el, a[el]});
                    }
                }
            }
        }

    }
    cout << c << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}