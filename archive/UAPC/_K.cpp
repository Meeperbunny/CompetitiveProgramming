#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    ll N;
    double D;
    cin >> N >> D;
    vector<double> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    double totalError = 0;
    priority_queue<double> EE;
    ll ls = 0;
    for(int i = 0; i < N; i++) {
        double lower = ll(D * A[i]);
        ls += ll(D * A[i]);
        double upper = ll(D * A[i] + 1);
        double lowerError = abs(D * A[i] - lower);
        double upperError = abs(D * A[i] - upper);
        double reduction = lowerError - upperError;
        totalError += lowerError;
        EE.push(reduction);
    }
    ll k = ll(D) - ls;
    while(k--) {
        totalError -= EE.top();
        EE.pop();
    }
    cout << setprecision(10) << fixed << totalError << endl;
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