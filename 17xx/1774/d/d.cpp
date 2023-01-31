/*
 * Author: UnPolinomio
 * Time: 2023-01-31 02:37:12
**/

#include <bits/stdc++.h>
using namespace std;
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define deb(x) cout << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
#define fore(x, a, b) for(lli x = a, ___lim___=b; x < ___lim___; ++x)
using lli = long long int;
using vi = vector<lli>;
using vb = vector<bool>;
using ii = pair<lli, lli>;

lli n{}, m{};

void solve(vector<vb>& a, vi& cnt, lli target) {
  vector<stack<lli>> ava(m);

  lli to_change{ 0 };
  fore(i, 0, n) {
    if(cnt[i] <= target) continue;
    to_change += cnt[i] - target;
    fore(j, 0, m) {
      if(a[i][j]) ava[j].push(i);
    }
  }

  cout << to_change << '\n';

  fore(i, 0, n) {
    if(cnt[i] >= target) continue;

    fore(j, 0, m) {
      if(a[i][j]) continue;

      while(!ava[j].empty() && (cnt[ava[j].top()] == target or !a[ava[j].top()][j] )) ava[j].pop();
      if(ava[j].empty()) continue;

      lli to{ ava[j].top() };
      ava[j].pop();
      ++cnt[i];
      --cnt[to];
      a[i][j] = true;
      a[to][j] = false;

      cout << (i + 1) << ' ' << (to + 1) << ' ' << (j + 1) << '\n';

      if(cnt[i] == target) break;
    }
  }
}

int main() {
  _;
  lli t{}, x{};
  cin >> t;

  while(t--) {
    cin >> n >> m;
    vector<vb> a(n, vb(m));
    vi cnt(n, 0);

    lli total{0};

    fore(i, 0, n) {
      lli row{ 0 };
      fore(j, 0, m) {
        cin >> x;
        a[i][j] = x == 1;
        row += x;
      }
      cnt[i] = row;
      total += row;
    }

    if(total % n != 0) {
      cout << -1 << '\n';
      continue;
    }

    solve(a, cnt, total / n);
  }

  return EXIT_SUCCESS;
}
