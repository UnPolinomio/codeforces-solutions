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
  int t{}, a{}, b{};
  cin >> t;
  char ch{};

  while (t--) {
    cin >> a >> ch >> b;
    cout << (a + b) << '\n';
  }

  return EXIT_SUCCESS;
}
