#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define ll long long
#define ld long double
const int N = 1e3 + 10;
const int M = 400 + 7;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const ll inf = 1e18;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
ll arr[N];

ll fastPow(ll x, ll n) {
    ll m = mod;
    if (n == 0) {
        return 1;
    }
    ll po = fastPow(x, n / 2);
    po = (po * po) % m;
    if (n & 1) {
        po *= x;
    }
    return po % m;
}

int mul(ll a, ll b) {
    return (a % mod) * (b % mod) % mod;
}

#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);


void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i: v)cin >> i;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll sum = v[i];
        int st = i;
        while (st > 0 && 2ll * v[i] > v[st - 1] + sum)
            st--,sum += v[st];
        int end = i;
        for (int l = st; l <= i; l++) {
            while (end < n - 1 && 2ll * v[i] > v[end + 1] + sum)
                end++,sum += v[end];
            sum -= v[l];
            ans += end - i + 1;
        }
    }
    cout << ans << endl;
}


::int32_t main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    fast
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}