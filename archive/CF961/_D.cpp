#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int popcnt(int n) {
    int t = 0;
    for(int q = 0; q < 19; q++) {
        t += (n >> q) & 1;
    }
    return t;
}

void TC() {
    int n, c, k; cin >> n >> c >> k;
    string s; cin >> s;
    vector<int> candidates;
    vector<set<int>> pos(c);
    for(int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        pos[c].insert(i);
    }
    for(int i = 0; i < c; i++) {
        pos[i].insert(-1);
    }
    for(int i = 1; i < pow(2, c); i++) {
        candidates.push_back(i);
    }
    sort(candidates.begin(), candidates.end(), [](int a, int b){
        return popcnt(a) < popcnt(b);
    });
    // For each cand, try to get across. If you can't, then for each one you dont have at some point, make them good
    vector<bool> isGood(int(pow(2, c)), false);
    vector<int> currPos(int(pow(2, c)), n - 1);
    isGood[1 << (s[n - 1] - 'A')] = true;
    for(auto cand : candidates) {
        if (!isGood[cand]) continue;
        else {
            // dbg(cand, currPos[cand]);
            vector<int> ginds;
            for(int q = 0; q < c; q++) {
                if ((cand >> q) & 1) ginds.push_back(q);
            }
            while(true) {
                int cpos = currPos[cand];
                int nxt = cpos;
                // dbg("running", cand, cpos, nxt);

                for(auto e : ginds) {
                    auto it = pos[e].lower_bound(cpos);
                    if (it == pos[e].begin()) continue;
                    it = prev(it);
                    int npos = *it;
                    if (cpos - npos > k) continue;
                    else {
                        nxt = min(nxt, npos);
                    }
                }
                if (nxt == -1) {
                    cout << popcnt(cand) << endl;
                    return;
                }
                if (nxt == cpos) {
                    // dbg("Pushing");
                    for(int q = 0; q < c; q++) {
                        if (!((cand >> q) & 1)) {
                            int e = q;
                            auto it = pos[e].lower_bound(cpos);
                            if (it == pos[e].begin()) continue;
                            it = prev(it);
                            int npos = *it;
                            if (cpos - npos > k) continue;
                            else {
                                isGood[cand | (1 << q)] = true;
                                currPos[cand | (1 << q)] = min(currPos[cand | (1 << q)], cpos);
                            }
                        }
                    }
                    break;
                }

                currPos[cand] = nxt;
            }
            
        }
    }
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