#include <bits/stdc++.h>
using namespace std;
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define deb(x) cout << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using lli = long long int;
using vi = vector<lli>;
using vb = vector<bool>;
using ii = pair<lli, lli>;

lli n{};

lli min_time(vi &ts, lli t) {
  lli i{0};
  while (i < (lli)ts.size() && ts[i] <= t) t = max(t, ts[i++] + 1);
  return t;
}

lli solve(vector<vector<ii>> &sgs, vector<vi> &ts) {
  priority_queue<ii, vector<ii>, greater<ii>> pq{};  // time, planet
  vi time(n, LLONG_MAX);
  vb vis(n, false);
  pq.emplace(0, 0);
  time[0] = 0;

  while (!pq.empty()) {
    auto [t, p] = pq.top();
    pq.pop();
    if (t > time[p] || vis[p]) continue;
    vis[p] = true;
    if (p == n - 1) return t;
    lli left_time{min_time(ts[p], t)};
    for (auto [np, c] : sgs[p]) {
      lli nt{left_time + c};
      if (time[np] <= nt) continue;
      time[np] = nt;
      pq.emplace(nt, np);
    }
  }

  return -1;
}

int main() {
  _;
  lli m{}, a{}, b{}, c{};
  cin >> n >> m;
  vector<vector<ii>> sgs(n);
  vector<vi> ts(n);
  while (m--) {
    cin >> a >> b >> c;
    --a, --b;
    sgs[a].emplace_back(b, c);
    sgs[b].emplace_back(a, c);
  }
  lli t{};
  for (auto &v : ts) {
    lli k{};
    cin >> k;
    while (k--) {
      cin >> t;
      v.push_back(t);
    }
  }

  cout << solve(sgs, ts) << '\n';

  return EXIT_SUCCESS;
}
