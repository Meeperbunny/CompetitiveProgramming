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
    vector<string> a(n);
    for(auto &e : a) cin >> e;
    vector<ll> mcon(26, 0);
    for(int i = 0; i < n; i++) {
        string &s = a[i];
        vector<pair<int, char>> segments;
        char l = s[0];
        ll size = 0;
        vector<ll> msegs(26, 0);
        for(int q=  0; q < s.size(); q++) {
            if (s[q] == l) {
                size++;
            }
            else {
                segments.push_back({size, l});
                msegs[l - 'a'] = max(msegs[l - 'a'], size);
                size = 1;
                l = s[q];
            }
        }
        msegs[l - 'a'] = max(msegs[l - 'a'], size);
        segments.push_back({size, l});
        // If is all the same character, then mult the char in lcs
        // ---- for all others, len becomes 1.
        // If front and back is the same, if is fb char, do sz_p + sz_s + 1 as max, with rest as 1
        // If not the same, then add 1 + pre and 1 + suf sizes.
        // Update maxes with maxes in t.
        vector<ll> nmcon(26, 0);
        if (segments.size() == 1) {
            for(int q = 0; q < 26; q++) {
                if (q == segments[0].second - 'a') {
                    ll nsz = (mcon[q] + 1) * (segments[0].first) + mcon[q];
                    nmcon[q] = max(nmcon[q], nsz);
                }
                else {
                    if (mcon[q]) nmcon[q] = 1;
                }
            }
        }
        else {
            if (segments[0].second == segments[segments.size() - 1].second) {
                for(int q = 0; q < 26; q++) {
                    nmcon[q] = max(nmcon[q], msegs[q]);
                    if (q == segments[0].second - 'a') {
                        // Add all together
                        if (mcon[q]) {
                            ll nsz = segments[0].first + segments[segments.size() - 1].first + 1;
                            nmcon[q] = max(nmcon[q], nsz);
                        }
                    }
                    if (mcon[q]) {
                        nmcon[q] = max(nmcon[q], 1ll);
                    }
                }
            }
            else {
                for(int q = 0; q < 26; q++) {
                    nmcon[q] = max(nmcon[q], msegs[q]);
                    if (q == segments[0].second - 'a') {
                        // Add all together
                        ll nsz = ll(mcon[q] >= 1) + segments[0].first;
                        nmcon[q] = max(nmcon[q], nsz);
                    }
                    else if (q == segments[segments.size() - 1].second - 'a') {
                        // Add all together
                        ll nsz = ll(mcon[q] >= 1) + segments[segments.size() - 1].first;
                        nmcon[q] = max(nmcon[q], nsz);
                    }
                    if (mcon[q]) {
                        nmcon[q] = max(nmcon[q], 1ll);
                    }
                }
            }
        }
        mcon = nmcon;
        // for(int i = 0; i < 26; i++) {
        //     cout << char('a' + i) << ": " << mcon[i] << endl;
        // }
    }
    ll mc = 0;
    for(auto e : mcon) {
        mc = max(mc, e);
    }
    cout << mc << endl;
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