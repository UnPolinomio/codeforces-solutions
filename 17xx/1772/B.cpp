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

int main() {
  _;
  int t{}, a{}, b{}, c{}, d{};
  cin >> t;

  while (t--) {
    cin >> a >> b >> c >> d;
    int mx{max({a, b, c, d})};
    int mn{min({a, b, c, d})};

    if ((a == mn && d == mx) || (a == mx && d == mn) || (b == mn && c == mx) ||
        (b == mx && c == mn))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return EXIT_SUCCESS;
}
