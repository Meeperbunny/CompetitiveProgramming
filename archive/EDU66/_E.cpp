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

ll furthestright[1000021][21];

void TC() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segs(n);
    vector<pair<int, int>> secs;
    memset(furthestright, 0, sizeof(furthestright));
    for(int i = 0; i < n; i++) {
        cin >> segs[i].first >> segs[i].second;
        segs[i].first *= 2;
        segs[i].second *= 2;
        secs.push_back({segs[i].first, -segs[i].second});
        secs.push_back({segs[i].second, segs[i].second});
    }
    sort(all(secs));
    multiset<int> maxr;
    int pt = 0;
    for(int q = 0; q < 21; q++) {
        for(int i = 0; i < 1000021; i++) {
            if (q == 0) {
                while (pt < secs.size() && secs[pt].first <= i && secs[pt].first != secs[pt].second) {
                    maxr.insert(-secs[pt].second);
                    pt++;
                }
                if (maxr.empty()) {
                    furthestright[i][q] = -1;
                }
                else {
                    furthestright[i][q] = *maxr.rbegin();
                }
                while (pt < secs.size() && secs[pt].first <= i && secs[pt].first == secs[pt].second) {
                    maxr.erase(maxr.find(secs[pt].second));
                    pt++;
                }
            }
            else {
                if (furthestright[i][q - 1] != -1) {
                    furthestright[i][q] = furthestright[furthestright[i][q - 1]][q - 1]; // TODO
                }
                else {
                    furthestright[i][q] = -1;
                }
            }
        }
    }
    while(m--) {
        int l, r;
        cin >> l >> r;
        l *= 2, r *= 2;
        if (furthestright[l][20] == -1 || furthestright[l][20] < r) {
            cout << -1 << endl;
        }
        else {
            ll jumps = 0;
            ll currspot = l;
            for(int top = 20; top >= 0; top--) {
                while (furthestright[currspot][top] < r) {
                    currspot = furthestright[currspot][top];
                    jumps += 1 << top;
                }
            }
            cout << jumps + 1 << endl;
        }
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