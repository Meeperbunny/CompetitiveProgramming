#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

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
    int n, m;
    cin >> n >> m;
    union_find dsu(n);
    vector<tuple<int, int, int, int>> T;
    for(int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d>>k;
        a--;
        T.push_back({a, d, k - 1, i});
    }
    vector<vector<int>> ends(11, vector<int>(10, -1));
    sort(all(T));
    vector<vector<int>> hasarc(n, vector<int>(11));
    int ct = 0;
    for(int i = 0; i < n; i++) {
        while(ct != T.size() && get<0>(T[ct]) <= i) {
            tuple<int, int, int, int> &C = T[ct];
            ct++;
            int a = get<0>(C), d = get<1>(C), kk = get<2>(C), i = get<3>(C);
            int rem = a % d;
            ends[d][rem] = max(a + d * kk, ends[d][rem]);
        }
        for(int D = 1; D <= 10; D++) {
            int r = i % D;
            if (ends[D][r] >= i) {
                dsu.unite(i, i + D);
            }
        }
    }
    set<int> u;
    for(int i = 0; i < n; i++) {
        u.insert(dsu.find(i));
    }
    cout << u.size() << endl;
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