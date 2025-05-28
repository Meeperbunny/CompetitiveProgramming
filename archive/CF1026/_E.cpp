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

void TC() {
    int n; cin >> n;
    vector<pair<int, int>> points(n);
    for(auto &e : points) {
        cin >> e.first >> e.second;
    }
    bool hasAnswer = false;
    for(int dir = 0; dir < 2; dir++) {
        map<int, pair<set<int>, set<int>>> hset;
        map<int, pair<set<int>, set<int>>> vset;
        map<int, int> hcnts, vcnts;
        vector<int> counts(n);
        for(auto &e : points) {
            hcnts[e.first]++;
            vcnts[e.second]++;
        }
        int start = 0;
        for(int i = 0; i < n; i++) {
            int par = 0;
            auto e = points[i];
            par += hcnts[e.first] - 1 + vcnts[e.second] - 1;
            if (par & 1) {
                // Pick arb for start
                start = i;
                hset[e.first].first.insert(i);
                vset[e.second].first.insert(i);
            }
            else {
                hset[e.first].second.insert(i);
                vset[e.second].second.insert(i);
            }
        }
        // If start is even is fine, just picj random and it should work;
        // Try both dirs
        int ci = start;
        cout << "Dir = " << dir << endl;
        cout << "Starting on " << start << endl;
        vector<int> p;
        int dd = dir;
        for(int i = 0; i < n; i++) {
            // Get curr
            p.push_back(ci);
            cout << "Pushing " << ci << endl;
            if (i == n - 1) break;
            // Remove myself, look for odds.
            auto cp = points[ci];
            // Try to remove from both
            {
                // REMOVE FROM HSET
                {auto it = hset[cp.first].first.find(ci);
                if (it != hset[cp.first].first.end()) {
                    hset[cp.first].first.erase(it);
                }}
                {auto it = hset[cp.first].second.find(ci);
                if (it != hset[cp.first].second.end()) {
                    hset[cp.first].second.erase(it);
                }}
            }
            {
                // REMOVE FROM VSET
                {auto it = vset[cp.second].first.find(ci);
                if (it != vset[cp.second].first.end()) {
                    vset[cp.second].first.erase(it);
                }}
                {auto it = vset[cp.second].second.find(ci);
                if (it != vset[cp.second].second.end()) {
                    vset[cp.second].second.erase(it);
                }}
            }
            // CHANGE PARITY OF ALL IT WAS REMOVED FROM
            swap(hset[cp.first].first, hset[cp.first].second);
            swap(vset[cp.second].first, vset[cp.second].second);
            // PICK ONE WITH ODD PARITY
    
            if (dd == 0) {
                // Look vert
                auto &s = hset[cp.first].first;
                if (s.empty()) {
                    break;
                }
                else {
                    auto it = s.begin();
                    ci = *it;
                    // We just choose now, we will remove in future.
                }
                dd = 1;
            }
            else {
                // Look vert
                auto &s = vset[cp.second].first;
                if (s.empty()) {
                    break;
                }
                else {
                    auto it = s.begin();
                    ci = *it;
                    // We just choose now, we will remove in future.
                }
                dd = 0;
            }
            
        }
        if (p.size() == n) {
            cout << "YES" << endl;
            for(auto e : p) cout << e + 1 << ' ';
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
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