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
    int n; cin >> n;
    vector<vector<int>> arr(n);
    union_find dsu(n);
    for(int i = 0; i < n; i++) {
        arr[i].push_back(i);
    }
    int lnu = 0;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int aa = dsu.find(a), bb = dsu.find(b);
        if (aa != bb) {
            dsu.unite(a, b);
            int nu = dsu.find(a);
            int ol = aa + bb - nu;
            if (arr[nu].size() < arr[ol].size()) swap(arr[nu], arr[ol]);
            for(int q = 0; q < arr[ol].size(); q++) {
                arr[nu].push_back(arr[ol][q]);
            }
            // cout << "Merging " << nu << ' ' << aa + bb - nu << endl;
            lnu = nu;
        }
    }
    for(auto e : arr[lnu]) {
        cout << e + 1 << ' ';
    } cout << endl;
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