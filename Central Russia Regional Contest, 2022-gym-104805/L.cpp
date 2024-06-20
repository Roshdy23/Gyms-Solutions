#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;
#define endl "\n"
const int N = 2e5 + 2;
const int M = 10 + 2;
const int LOG = 18;
const int mod = 1e9 + 7;
const ll inf = 1e13;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)cin >> i;
    vector<int> dp;
    dp.push_back(v[0]);
    for (int i = 1; i < n; ++i) {
        if (v[i] > dp.back())
            dp.push_back(v[i]);
        else {
            int lw = std::lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            dp[lw] = v[i];
        }
    }
    cout << dp.size() << endl;
}


int32_t main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    fast


    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}