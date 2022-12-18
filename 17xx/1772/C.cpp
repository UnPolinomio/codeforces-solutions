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

void solve(int k, int n) {
  int i{1};
  int d{1};

  while (k--) {
    cout << i << ' ';
    if (n - (i + d) + 1 < k)
      ++i;
    else {
      i += d;
      ++d;
    }
  }
  cout << '\n';
}

int main() {
  _;
  int t{}, k{}, n{};
  cin >> t;
  while (t--) {
    cin >> k >> n;
    solve(k, n);
  }

  return EXIT_SUCCESS;
}
