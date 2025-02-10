#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

const ll MAXN = 2E5+16;
bool isComp[MAXN];
vll ps;
vector <array <ll, 3> > semiPs;

void tc () {
    ll n;
    cin >> n;
    vll ve(n);
    for (ll &i : ve) cin >> i;
    vll freq(n+2, 0);
    for (ll i : ve) freq[i]++;
    ll ans = 0;
    for (auto [v, i, j] : semiPs) {
        if (v > n) break;
        ans += freq[v]*(freq[v]+1)/2;
        if (i != j)
            ans += freq[v]*(freq[i] + freq[j]);
        else {
            ans += freq[v]*freq[i];
        }
    }
    ll acc = 0;
    for (ll i : ps) {
        if (i > n) break;
        ans += freq[i]*acc;
        acc += freq[i];
    }
    cout << ans << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (ll i = 2; i < MAXN; i++) {
        if (isComp[i]) continue;
        ps.push_back(i);
        for (ll j = i*i; j < MAXN; j += i) {
            isComp[j] = true;
        }
    }
    for (ll i : ps) {
        for (ll j : ps) {
            if (i*j > MAXN) break;
            if (j < i) continue;
            semiPs.push_back({ i*j, i, j });
        }
    }
    sort(semiPs.begin(), semiPs.end());
    ll T; cin >> T; while (T--) { tc(); }
    return 0;
}