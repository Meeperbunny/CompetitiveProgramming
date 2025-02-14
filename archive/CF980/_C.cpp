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

vector<int> computeLPS(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

bool KMP(const vector<int>& text, const vector<int>& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }
        if (j == m) return true;
        if (i < n && text[i] != pattern[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return false;
}

vector<int> findCyclicShiftIndices(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return {};
    vector<int> doubled = a;
    doubled.insert(doubled.end(), a.begin(), a.end());
    
    vector<int> lps = computeLPS(b);
    vector<int> indices;
    int n = doubled.size(), m = b.size();
    int i = 0, j = 0;
    
    while (i < n) {
        if (doubled[i] == b[j]) {
            i++, j++;
        }
        if (j == m) {  // Found a match
            indices.push_back(i - m);
            j = lps[j - 1];  // Continue searching
        } else if (i < n && doubled[i] != b[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    
    // Filter indices to only include those within the first `a.size()`
    vector<int> validIndices;
    for (int idx : indices) {
        if (idx < a.size()) {
            validIndices.push_back(idx);
        }
    }
    return validIndices;
}

void TC() {
    int n, k; cin >> n >> k;
    vector<int> inoutA(n), inoutB(n);
    int ma, mb;
    vector<vector<int>> adjA(n), adjB(n);
    vector<int> pA(n, -1), pB(n, -1);
    for(auto &e : inoutA) cin >> e;
    cin >> ma;
    for(int i = 0; i < ma; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjA[a].push_back(b);
    }
    for(auto &e : inoutB) cin >> e;
    cin >> mb;
    for(int i = 0; i < mb; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjB[a].push_back(b);
    }
    int outA = accumulate(all(inoutA), 0);
    int incA = n - outA;
    int outB = accumulate(all(inoutB), 0);
    int incB = n - outB;
    // Check is balanced
    if (outA != incB || outB != incA) {
        cout << "NO" << endl;
        return;
    }
    if (incA == 0 || incA == n) {
        cout << "YES" << endl;
        return;
    }
    bool isFine = true;
    auto dfsA = [&](auto dfs, int i, int curr) {
        if (pA[i] != -1) {
            if (pA[i] % k != curr % k) {
                isFine = false;
            }
            return;
        }
        pA[i] = curr;
        for(auto e : adjA[i]) {
            dfs(dfs, e, (curr + 1) % k);
        }
    };
    dfsA(dfsA, 0, 0);
    auto dfsB = [&](auto dfs, int i, int curr) {
        if (pB[i] != -1) {
            if (pB[i] % k != curr % k) {
                isFine = false;
            }
            return;
        }
        pB[i] = curr;
        for(auto e : adjB[i]) {
            dfs(dfs, e, (curr + 1) % k);
        }
    };
    dfsB(dfsB, 0, 0);
    if (!isFine) {
        cout << "NO" << endl;
        return;
    }
    map<int, pair<int, int>> cntsA, cntsB;
    for(int i = 0; i < n; i++) {
        auto &p = cntsA[pA[i]];
        p = {p.first + int(inoutA[i] == 0), p.second + int(inoutA[i] == 1)};
    }
    for(int i = 0; i < n; i++) {
        auto &p = cntsB[pB[i]];
        p = {p.first + int(inoutB[i] == 0), p.second + int(inoutB[i] == 1)};
    }
    vector<int> OA(k), IA(k), OB(k), IB(k);
    for(int i = 0; i < k; i++) {
        OA[i] = cntsA[i].second;
        IA[i] = cntsA[i].first;
        OB[i] = cntsB[i].second;
        IB[i] = cntsB[i].first;
    }
    vector<int> indsA = findCyclicShiftIndices(OA, IB);
    vector<int> indsB = findCyclicShiftIndices(IA, OB);
    bool w = false;
    vector<int> cnts(k, 0);
    for(auto e : indsA) cnts[(e + 2) % k]++;
    for(auto e : indsB) cnts[e]++;
    for(auto e : cnts) if (e == 2) w = true;
    cout << (w ? "YES" : "NO") << endl;
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