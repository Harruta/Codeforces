#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

void tc () {
    ll n, m, k;
    cin >> n >> m >> k;
    if (abs(n-m) > k || max(n, m) < k) {
        cout << "-1\n";
        return;
    }
    string ans;
    if (n > m) {
        ans = string(k, '0');
        n -= k;
        // assert(n >= 0);
        while (m > n) {
            ans += '1';
            m--;
        }
        // assert(n == m);
        while (n--) {
            ans += (ans.back() == '1' ? "01" : "10");
        }
    } else {
        ans = string(k, '1');
        m -= k;
        // assert(m >= 0);
        while (n > m) {
            ans += '0';
            n--;
        }
        // assert(m == n);
        while (m--) {
            ans += (ans.back() == '1' ? "01" : "10");
        }
    }
    cout << ans << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    ll T; cin >> T; while (T--) { tc(); }
    return 0;
}