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

struct C {
    ll cnt = 0;
    ll id = 0;
    ll t = 0;
};

void TC() {
    ll n;
    cin >> n;
    stack<C> S;
    vector<ll> ans(n);
    ll maxval = 0;
    for(int i = 0; i < n; i++) {
        // Get current
        // Iterate until bottom of stack or cant go through or one of my own
        C curr;
        cin >> curr.cnt >> curr.id;
        maxval = max(curr.cnt, maxval);
        curr.t = 0;
        // dbg(curr.cnt, curr.id);
        while(S.size()) {
            // Get top to check against
            C to(S.top());
            S.pop();
            // If bottom, then end #
            // If cant go throgh, then end
            // If one of my own, then add to it
            ll left = curr.cnt - curr.t;
            if (to.id == curr.id) {
                curr.cnt = (left) + (to.cnt);
                maxval = max(curr.cnt, maxval);
                // dbg("Merging", (left), (to.cnt - curr.t));
            }
            else {
                if (left < to.cnt - curr.t) {
                    // dbg("Cant break through");
                    S.push(to);
                    break;
                }
                else {
                    // dbg("Broke through", (to.cnt - curr.t));
                    curr.t += (to.cnt - curr.t);
                }
            }
            if (curr.t > curr.cnt) {
                break;
            }
        }
        // dbg("Done, pushing");
        S.push(curr);
        ans[i] = maxval;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
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