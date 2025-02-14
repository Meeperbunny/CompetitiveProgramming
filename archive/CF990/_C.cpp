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

struct Node {
    int key, priority, cnt, sz;
    Node* left;
    Node* right;
    Node(int k) : key(k), priority(rand()), cnt(1), sz(1), left(nullptr), right(nullptr) {}
};

int nodeSize(Node* t) {
    return t ? t->sz : 0;
}

void updateSize(Node* t) {
    if(t) t->sz = nodeSize(t->left) + nodeSize(t->right) + t->cnt;
}

// Splits the treap `t` into `l` and `r` based on key < splitKey
//  - `l` will have all keys < splitKey
//  - `r` will have all keys >= splitKey
void split(Node* t, int splitKey, Node*& l, Node*& r) {
    if(!t) { l = r = nullptr; return; }
    if(t->key < splitKey) {
        split(t->right, splitKey, t->right, r);
        updateSize(t);
        l = t;
    } else {
        split(t->left, splitKey, l, t->left);
        updateSize(t);
        r = t;
    }
}

// Merges two treaps (all keys in `a` <= all keys in `b`)
Node* mergeTreaps(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;
    if(a->priority > b->priority) {
        a->right = mergeTreaps(a->right, b);
        updateSize(a);
        return a;
    } else {
        b->left = mergeTreaps(a, b->left);
        updateSize(b);
        return b;
    }
}

struct Treap {
    Node* root = nullptr;
    
    // Inserts one occurrence of key k
    // If k already exists, increment its count. Otherwise create a new node.
    void insertKey(int k) {
        Node *L, *R; 
        split(root, k, L, R);           // L has all keys < k, R has all keys >= k
        Node *M, *RR;
        split(R, k + 1, M, RR);         // M has all keys in [k, k+1), RR has keys >= k+1
        
        if(!M) M = new Node(k);         // no node with this key yet
        else  M->cnt++;                 // key already exists, just increase the count
        
        root = mergeTreaps(L, mergeTreaps(M, RR));
    }
    
    // Deletes exactly one occurrence of key k (if present)
    void deleteKey(int k) {
        Node *L, *R; 
        split(root, k, L, R);           // L has all keys < k, R has all keys >= k
        Node *M, *RR;
        split(R, k + 1, M, RR);         // M has keys in [k, k+1), RR has keys >= k+1
        
        if(M) {
            if(M->cnt > 1) M->cnt--;    // if more than one copy, just decrement
            else M = nullptr;           // otherwise remove the node entirely
        }
        
        root = mergeTreaps(L, mergeTreaps(M, RR));
    }
    
    // Returns how many elements are strictly less than k
    int rankUtil(Node* t, int k) {
        if(!t) return 0;
        if(k <= t->key) return rankUtil(t->left, k);
        return nodeSize(t->left) + t->cnt + rankUtil(t->right, k);
    }
    int rankOf(int k) {
        return rankUtil(root, k);
    }
    
    // Returns total number of elements (sum of counts) in the treap
    int size() {
        return nodeSize(root);
    }
};


void TC() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &p : a) {
        cin >> p.first >> p.second;
    }
    map<int, vector<int>> vmap;
    for(auto e : a) {
        vmap[e.second].push_back(e.first);
    }
    Treap lower, upper;
    set<int> lw, up;
    for(auto e : a) {
        upper.insertKey(e.first);
        up.insert(e.first);
    }
    int bb = n;
    for(auto it = vmap.rbegin(); it != vmap.rend(); it++) {
        // cout << "A" << endl;
        // add the lowest point to lower, then binary search for the max abs
        for(auto x : it->second) {
            upper.deleteKey(x);
            if (up.count(x))
                up.erase(up.find(x));
            lower.insertKey(x);
            lw.insert(x);
        }

        auto pnt = [&](int i) {
            int lr = lower.rankOf(i + 1);
            int ur = upper.rankOf(i + 1);
            return min(min(lower.size() - lr, lr), 
                        min(upper.size() - ur, ur));
        };

        int k = -1;
        for(int j = 1e9; j >= 1; j /= 2) {
            while(true) {
                int c1 = pnt(k + j * 0);
                int c2 = pnt(k + j * 1);
                int c3 = pnt(k + j * 2);
                // cout << c1 << ' '<< c2 << ' ' << c3 << endl;
                if (c1 > c2 && c2 >= c3) {
                    k += j;
                } else break;
            }
        }
        // Now iter for the min
        if (lw.size()) {
            auto t = lw.lower_bound(it->first);
            t = (t == lw.begin() ? t : prev(t));
            for(int i = 0; i < 3 && t != lw.end(); t++, i++) {
                bb = min(bb, pnt(*t));
            }
        }
        if (up.size()) {
            auto t = up.lower_bound(it->first);
            t = (t == up.begin() ? t : prev(t));
            for(int i = 0; i < 3 && t != up.end(); t++, i++) {
                bb = min(bb, pnt(*t));
            }
        }
    }
    cout << bb << endl;
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