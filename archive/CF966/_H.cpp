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

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN

using namespace std;

class SegmentTree {
private:
    vector<int> segTree;
    int n;

    // A utility function to get the middle index from corner indexes.
    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }

    // A recursive function that constructs the Segment Tree for array[ss..se].
    void buildSegmentTree(vector<int>& arr, int ss, int se, int si) {
        if (ss == se) {
            segTree[si] = arr[ss];
        } else {
            int mid = getMid(ss, se);
            buildSegmentTree(arr, ss, mid, 2 * si + 1);
            buildSegmentTree(arr, mid + 1, se, 2 * si + 2);
            segTree[si] = max(segTree[2 * si + 1], segTree[2 * si + 2]);
        }
    }

    // A function to get the maximum value in a given range of array indices.
    int rangeMaxQuery(int ss, int se, int qs, int qe, int si) {
        // If the segment of this node is part of the query range
        if (qs <= ss && qe >= se) {
            return segTree[si];
        }

        // If the segment of this node is outside the query range
        if (se < qs || ss > qe) {
            return INT_MIN;
        }

        // If a part of this segment overlaps with the query range
        int mid = getMid(ss, se);
        return max(rangeMaxQuery(ss, mid, qs, qe, 2 * si + 1),
                   rangeMaxQuery(mid + 1, se, qs, qe, 2 * si + 2));
    }

    // A recursive function to update the nodes which have the given index.
    void updateValue(int ss, int se, int i, int newValue, int si) {
        if (ss == se) {
            segTree[si] = newValue;
        } else {
            int mid = getMid(ss, se);
            if (i <= mid) {
                updateValue(ss, mid, i, newValue, 2 * si + 1);
            } else {
                updateValue(mid + 1, se, i, newValue, 2 * si + 2);
            }
            segTree[si] = max(segTree[2 * si + 1], segTree[2 * si + 2]);
        }
    }

public:
    // Constructor to build the segment tree from the given array
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n); // Allocating memory for segment tree
        buildSegmentTree(arr, 0, n - 1, 0);
    }

    // Function to return the maximum in the range [qs, qe]
    int rangeMaxQuery(int qs, int qe) {
        if (qs < 0 || qe >= n || qs > qe) {
            return INT_MIN; // Return a minimum value to indicate invalid range
        }
        return rangeMaxQuery(0, n - 1, qs, qe, 0);
    }

    // Function to update a value in the segment tree
    bool updateValue(int i, int newValue) {
        if (i < 0 || i >= n) {
            return false; // Indicate failure to update due to invalid index
        }
        updateValue(0, n - 1, i, newValue, 0);
        return true; // Indicate successful update
    }
};

// int main() {
//     vector<int> arr = {1, 3, 5, 7, 9, 11};
//     SegmentTree segTree(arr);

//     int maxVal = segTree.rangeMaxQuery(1, 4);
//     if (maxVal != INT_MIN) {
//         cout << "Maximum value in range [1, 4]: " << maxVal << endl;
//     }

//     if (segTree.updateValue(2, 10)) {
//         maxVal = segTree.rangeMaxQuery(1, 4);
//         if (maxVal != INT_MIN) {
//             cout << "Maximum value in range [1, 4] after update: " << maxVal << endl;
//         }
//     }

//     return 0;
// }


void TC() {
    int n; cin >> n;
    set<int> inset;
    set<int> anums;
    map<int, int> ntoind;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        inset.insert(a);
        anums.insert(a);
    }
    int Q; cin >> Q;
    vector<pair<char, int>> qs;
    while(Q--) {
        pair<char, int> q;
        cin >> q.first >> q.second;
        qs.push_back(q);
        if (q.first != '?') {
            anums.insert(q.second);
        }
    }
    int m = anums.size();
    vector<int> vas(m);
    int ind = 0;
    for(auto e : anums) {
        vas[ind] = e;
        ntoind[e] = ind++; 
    }
    // Create tree of gaps.
    // Query binary search on l/r bounds of earliest best query.
    // Print that number + 1.
    vector<int> rgap(m, 0);
    // initalize
    for(auto it = inset.begin(); next(it) != inset.end(); it++) {
        rgap[ntoind[*it]] = *next(it) - *it - 1;
    }
    rgap[ntoind[*inset.rbegin()]] = INT_MAX;
    SegmentTree tree(rgap);
    for(auto e : qs) {
        char c = e.first;
        int va = e.second;
        if (c == '+') {
            auto res = inset.insert(va).first;
            // Update prev el, and curr el
            if (res != inset.begin()) {
                auto p = prev(res);
                rgap[ntoind[*p]] = va - *p - 1;
                tree.updateValue(ntoind[*p], va - *p - 1);
            }
            if (next(res) == inset.end()) {
                rgap[ntoind[va]] = INT_MAX;
                tree.updateValue(ntoind[va], INT_MAX);
            }
            else {
                rgap[ntoind[va]] = *next(res) - *res - 1;
                tree.updateValue(ntoind[va], *next(res) - *res - 1);
            }
        }
        else if (c == '-') {
            // Get rid of curr, update prev
            auto res = inset.find(va);
            rgap[ntoind[va]] = 0;
            tree.updateValue(ntoind[va], 0);
            if (res != inset.begin()) {
                auto p = prev(res);
                if (next(res) == inset.end()) {
                    rgap[ntoind[*p]] = INT_MAX;
                    tree.updateValue(ntoind[*p], INT_MAX);
                }
                else {
                    rgap[ntoind[*p]] = *next(res) - *p - 1;
                    tree.updateValue(ntoind[*p], *next(res) - *p - 1);
                }
            }
            inset.erase(res);
        }
        else {
            if (inset.empty()) {
                cout << 1 << ' ';
                continue;
            }
            if (*inset.begin() - 1 >= va) {
                cout << 1 << ' ';
                continue;
            }
            // Query for rightmost index such that it is greater if begin is not
            int r = m;
            for(int j = m; j >= 1; j >>= 1) {
                while(true) {
                    int nind = r - j;
                    if (nind < 0) break;
                    if (tree.rangeMaxQuery(0, nind) >= va) {
                        r = nind;
                    }
                    else break;
                }
            }
            if (r == m) {
                cout << *inset.rbegin() + 1 << ' ';
            }
            else {
                cout << vas[r] + 1 << ' ';
            }
        }
    }
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