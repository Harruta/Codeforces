#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

const ll MAXN = 5E5+16;
vll adj[MAXN];

void tc () {
    ll n;
    cin >> n;
    vll ve(n);
    for (ll &i : ve) cin >> i, i--;
    fill(adj, adj+n, vll({}));
    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string ans = string(n, '0');
    for (ll u = 0; u < n; u++) {
        map <ll, ll> mp;
        for (ll v : adj[u]) {
            mp[ve[v]]++;
        }
        mp[ve[u]]++;
        for (auto [a, b] : mp) {
            if (b >= 2) ans[a] = '1';
        }
    }
    cout << ans << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    ll T; cin >> T; while (T--) { tc(); }
    return 0;
}