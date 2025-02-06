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

void TC() {
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 1; i < n; i++) {
        if (n % i == 0) {
            bool awk = false;
            bool w = true;
            for(int z = 0; z < i; z++) {
                vector<int> cnt(26, 0);
                for(int q = z; q < n; q += i) {
                    cnt[s[q] - 'a']++;
                }
                // for(auto e : cnt) cout << e << ' ';
                // cout << endl;
                int fbig = 0, fsmall = 0;
                for(int q = 0; q < 26; q++) {
                    if (cnt[q] == 1 && !fsmall) {
                        fsmall = 1;
                    }
                    else if (cnt[q] && !fbig) {
                        fbig = 1;
                    }
                    else if (cnt[q] > 1 && fbig) {
                        w = false;
                    }
                    else if (cnt[q] == 1 && fbig && fsmall) {
                        w = false;
                    }
                }
                if (fsmall && !fbig) swap(fsmall, fbig);
                if (fsmall && awk) {
                    w = false;
                }
                if (fsmall && !awk) {
                    awk = true;
                }
                // cout << i << ' ' << z << ' ' << fsmall << ' '<< fbig << ' ' << awk << ' ' << w << endl;
            }
            if (w) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << n << endl;
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