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
    int n, a, b;
    cin >> n >> a >> b;
    union_find A(n), B(n);
    for(int q = 0; q < a; q++) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        A.unite(i, j);
    }
    for(int q = 0; q < b; q++) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        B.unite(i, j);
    }
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++) {
        for(int q = i + 1; q < n; q++) {
            if (A.find(i) != A.find(q) && B.find(i) != B.find(q)) {
                arr.push_back({i + 1, q + 1});
                A.unite(i, q);
                B.unite(i, q);
            }
        }
    }
    cout << arr.size() << endl;
    for(auto e : arr) {
        cout << e.first << ' ' << e.second << endl;
    }

}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}