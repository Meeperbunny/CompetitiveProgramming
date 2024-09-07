#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n,m,k;cin>>n>>m>>k;

  queue<pair<pii, int>> edges;
  UF uf(n);
  rep(i,0,m){
    int u,v,w;cin>>u>>v>>w;u--;v--;
    edges.push({{v,u}, w});
  }

  vector<map<int,int>> mp(n);
  vector<vi> ch(n);
  while(!edges.empty()) {
    auto [e,w] = edges.front();edges.pop();
    auto [u,v] = e;
    u=uf.find(u);

    if(mp[u].count(w)){
      int vv=mp[u][w];

      // small to large
      if(sz(mp[vv]) < sz(mp[v])) swap(vv, v);
      uf.join(vv, v);
      mp[u][w]=vv;

      for(auto [w,uu]:mp[v])edges.push({{vv,uu}, w});
    }else{
      mp[u][w]=v;
    }
  }

  ll x=0;
  rep(i,0,n){
    if(uf.find(i)==i){
      ll y=uf.size(i);
      // cout<<y<<" ";
      x+=(y)*(y-1)/2;
    }
  }
  cout<<x<<"\n";
}