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
    int l, r; cin >> l >> r;
    vector<int> nums(3);
    nums[0] = 2;
    nums[1] = 1;
    // Try adding cureent bit. If without is too little (with max add) or with is too much(with min add) then dont do
    for(int i = 30; i >= 1; i--) {
        sort(all(nums));
        int num = (1 << i);
        int maxAdd = num - 1;
        if (nums[2] + maxAdd >= l && nums[0] + num <= r) {
            nums[0] += num;
            nums[1] += num;
        }
    }
    cout << nums[0] << ' ' << nums[1] << ' ' << nums[2] << endl;
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