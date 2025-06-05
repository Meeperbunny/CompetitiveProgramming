#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    vector<pair<char, char>> ops(m);
    for(auto &p : ops) {
        cin >> p.first >> p.second;
    }

    set<int> BA, CA, BC, CB;
    int i = 0;
    for(auto &p : ops) {
        auto &[a, b] = p;
        if (a == 'b' && b == 'a') {
            BA.insert(i);
        }
        if (a == 'c' && b == 'a') {
            CA.insert(i);
        }
        if (a == 'c' && b == 'b') {
            CB.insert(i);
        }
        if (a == 'b' && b == 'c') {
            BC.insert(i);
        }
        i++;
    }
    for(int i = 0; i < n; i++) {
        auto &c = s[i];
        if (s[i] == 'a') {
            // Do nothing
        }
        else if (s[i] == 'b') {
            // Try swapping to a
            if (BA.size()) {
                BA.erase(BA.begin());
                s[i] = 'a';
            }
            else if (CA.size() && BC.size()) {
                // Get earliest BC.
                auto it = BC.begin();
                // Try to find a CA
                auto cit = CA.upper_bound(*it);
                if (cit == CA.end()) {
                    // Can't do. dont do anything
                }
                else {
                    BC.erase(it);
                    CA.erase(cit);
                    s[i] = 'a';
                }
            }
        }
        else {
            // Try swapping to a
            if (CA.size()) {
                CA.erase(CA.begin());
                s[i] = 'a';
            }
            else if (BA.size() && CB.size()) {
                // Get earliest CB.
                auto it = CB.begin();
                // Try to find a CA
                auto cit = BA.upper_bound(*it);
                if (cit == BA.end()) {
                    // Can't do. dont do anything
                }
                else {
                    CB.erase(it);
                    BA.erase(cit);
                    s[i] = 'a';
                }
            }
            // if still c and CB, do it with furthest.
            if (s[i] == 'c' && CB.size()) {
                CB.erase(prev(CB.end()));
                s[i] = 'b';
            }
            
        }
    }
    cout << s << endl;
}
// Why isthis wrong
/*
Order of flex may be wrong?
As 
*/
// BA 5
// WBA 6
// CA 5
// WCA 4
// CB 1 
// W1

// abcaababcbbcabcbbcabcbabbbbabc
//  BC  B BCBBC BC  c  c
// aaaaaaaaaaaaaaabbbabbbabbbbabb
// aaaaaaaaaaaaaaabbbabcbabbbbabc
// aaaaaaaaaaabaacaacabcbabbbbabc

// aaaaaaaaaaaaababbaabbbabbbbabc
// aaaaaaaaaaaaaaabbbabcbabbbbabc
// aaaaaaaaaaaaaaabbbabcbabbbbabc

// Use the earliest ba or ca.
// If can't use the earliest other and the comp.
// if is c and cant, then swap to b.


/*

if b -> a then should use asap.
if c -> a then should use asap.

if b -> c then ?
if c -> b then ?

any pref for ba or comb for C?
CB -> BA = CA as well, should use whenever?

CFLEX, CB if used for b.
use smaller fist

cout << a << ' ' << b << endl;
cout << BAC << ' ' << CAC << ' ' << CBC << ' ' << FLEX << endl;
cout << bpos.size() << ' ' << cpos.size() << ' ' << bc.size() << ' ' << cb.size() << endl;

30 20
aaaaaaaaaaaaaaabbbabcbabbbbabc
aaaaaaaaaaaaaaabbbabcbabbbbabc
b c
b c
b c
b c
b c
b c
b c
b c
*/


int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}