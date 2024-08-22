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

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int j; cin >> j;
    return j - 1;
}

void TC() {
    int n; cin >> n;
    vector<bool> explored(n, false);
    int base = 0;
    explored[0] = true;
    vector<set<int>> edges(n);
    for(int q = 0; q < n; q++) {
        for(int i = 1; i < n; i++) {
            // Try to go to 1 if its unexplored
            int trying = i;
            if (explored[trying]) continue;
            int curr = 0;
            while(true) {
                int mid = query(curr + 1, trying + 1);
                if (mid == curr) {
                    // Edge between curr and trying.
                    edges[curr].insert(trying);
                    edges[trying].insert(curr);
                    explored[trying] = true;
                    break;
                }
                else if (explored[mid]) {
                    curr = mid;
                }
                else {
                    trying = mid;
                }
            }
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++) {
        for(auto e : edges[i]) {
            if (e > i) {
                cout << i + 1 << ' ' << e + 1 << ' ';
            }
        }
    }
    cout << endl;
    cout.flush();
}

int main() {
    // HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}