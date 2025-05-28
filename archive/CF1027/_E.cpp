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

struct CS {
    ll offset = 0;
    bool isneg = true;
    map<ll, ll> nums;
    void flip() {
        // TODO
        isneg = !isneg;
    }
    void add(ll num) {
        // Always add a positive num
        if (isneg) {
            num = -num;
            nums[num - offset] += 1;
        }
        else {
            // IS GOOD
            nums[num - offset] += 1;
        }
    }
    void remove(ll num) {
        // TODO
        ll tn;
        if (isneg) {
            num = -num;
            tn = num - offset;
        }
        else {
            tn = num - offset;
        }
        nums[tn] -= 1;
        if (!nums[tn]) nums.erase(nums.find(tn));
    }
    ll max() {
        if (!isneg) {
            // IS GOOD
            return nums.rbegin()->first + offset;
        }
        else {
            // TODO
            return -(nums.begin()->first) - offset;
        }
    }
    void addToAll(ll num) {
        if (isneg) num = -num;
        offset += num;
    }
};

void TC() {
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> ans(n);
    auto dfs = [&](auto dfs, int i, int j, CS &s) -> void {
        // Flip current set, then add myself in as postiive.
        s.flip();
        // Add to all paths
        s.addToAll(a[i]);
        // Add myself in
        s.add(a[i]);

        ans[i] = s.max();
        // cout << "ON " << i << endl;
        // cout << s.offset << endl;
        // for(auto e : s.nums) {
        //     cout << '\t' << e.first << ' ' << e.second << endl;
        // }

        for(auto e : adj[i]) if (j != e) {
            dfs(dfs, e, i, s);
        }

        // Remove myself
        s.remove(a[i]);
        // Remove from all paths
        s.addToAll(-a[i]);

        s.flip();
    };
    CS s;
    dfs(dfs, 0, -1, s);
    for(auto e : ans) cout << e << ' ';
    cout << endl;
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