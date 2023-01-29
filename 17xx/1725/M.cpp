// DRAFT
#include <bits/stdc++.h>
using namespace std;
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define deb(x) cout << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
#define fore(i, a, b) for(lli i = a, ___lim___ =b; i<___lim___; ++i)
using lli = long long int;
using vi = vector<lli>;
using vb = vector<bool>;
using ii = pair<lli, lli>;

lli n{}, m{};

vi dijkstra(vector<vector<ii>> &from) {
  priority_queue<ii, vector<ii>, greater<ii>> pq{}; // dis, node
  vi mins(n, -1);
  vb vis(n, false);
  pq.emplace(0, 0);
  mins[0] = 0;

  while(!pq.empty()) {
    auto [dis, node] = pq.top();
    pq.pop();
    if(dis > mins[node] || vis[node] ) continue;
    vis[node] = true;

    for(auto [to, w] : from[node]) {
      if(mins[to] != -1 && dis + w >= mins[to]) continue;
      pq.emplace(dis + w, to);
      mins[to] = dis + w;
    }
  }

  return mins;
}

void dij_rev(vector<vector<ii>> &to, vi &mins) {
  priority_queue<ii, vector<ii>, greater<ii>> pq{}; // dis, node
  fore(i, 0, n) pq.emplace(mins[i], i);
  vb vis(n, false);

  while(n--) {
    auto [dis, node] = pq.top();
    pq.pop();
    if(dis == -1) continue;

    if(dis > mins[node] || vis[node]) continue;
    vis[node] = true;

    for(auto [from, w]: to[node]) {
      if(dis + w)
    }

  }
}

int main() {
  _;
  cin >> n >> m;


  lli u{}, v{}, w{};
  vector<vector<ii>> from(n);
  vector<vector<ii>> to(n);

  while(m--) {
    cin >> u >> v >> w;
    --u, --v;

    from[u].push_back({ v, w });
    to[v].push_back({ u, w });
  }

  vi mins{dijkstra(from)};
  dij_rev(to, mins);

  for(auto el : mins) cout << el << " ";
  cout << '\n';


  return EXIT_SUCCESS;
}
