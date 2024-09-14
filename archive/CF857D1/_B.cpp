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

struct S {
    ll m_u, c, a;
};

void TC() {
    int n; cin >> n;
    vector<S> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].a;
    }
    sort(all(a), [](S &b, S &c){
        if (b.c == c.c) {
            return b.a < c.a;
        }
        else {
            return b.c > c.c;
        }
    });
    stack<S> st;
    for(int i = 0; i < n; i++) {
        if (st.size()) {
            a[i].m_u = max(a[i].a, st.top().m_u);
        }
        else a[i].m_u = a[i].a;
        st.push(a[i]);
    }
    ll mindiff = INT_MAX;
    set<ll> seen;
    while(st.size()) {
        ll ma = st.top().c;
        S ca = st.top();
        st.pop();
        // Check in seen to see if can swap, only works if nothing left or if max less
        if (st.size()) {
            ll ama = st.top().m_u;
            // Try finding a diff closest to ama
            mindiff = min(mindiff, abs(ma - ama));

            auto it = seen.lower_bound(ma);
            if (it != seen.end()) {
                ll af = *it;
                if (af > ama) {
                    mindiff = min(mindiff, abs(af - ma));
                }
            }
            if (it != seen.begin()) {
                ll bef = *prev(it);
                if (bef > ama) {
                    mindiff = min(mindiff, abs(bef - ma));
                }
            }
        }
        else {
            auto it = seen.lower_bound(ma);
            if (it != seen.end()) {
                ll af = *it;
                mindiff = min(mindiff, abs(af - ma));
            }
            if (it != seen.begin()) {
                ll bef = *prev(it);
                mindiff = min(mindiff, abs(bef - ma));
            }
        }
        
        seen.insert(ca.a);
    }
    cout << mindiff << endl;
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