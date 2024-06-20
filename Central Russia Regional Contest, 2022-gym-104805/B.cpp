#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define ld long double
using namespace std;
#define endl "\n"
const int N = 86400;
const int M = 1e9 + 7;
const int LOG = 18;
const int mod = 1e9 + 7;
const ll inf = 1e13;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};


void solve() {
    int n;
    cin >> n;
    set<pair<ld, int>> s;
    for (int i = 0; i < n; ++i) {
        ld x;
        cin >> x;
        s.insert({(ld) sqrt((ld) 1e6 / x), i});
    }
    int k;
    cin >> k;
    vector<tuple<ld, int, int>> q(k);
    ld t, e;
    for (int i = 0; i < k; ++i) {
        auto &[x, y, z] = q[i];
        cin >> t >> e >> y;
        x = (ld) sqrt(pow(t, 2) + pow(e, 2));
        z = i;
    }
    vector<pair<int, int>> ans;
    std::sort(q.rbegin(), q.rend());
    for (int i = 0; i < k; ++i) {
        auto &[dist, r, ind] = q[i];
        auto it = s.lower_bound({(dist - r), 0});
        if (it != s.end()) {
            ans.push_back({it->second, ind});
            s.erase(it);
        }
    }
    cout << ans.size() << endl;
    for (auto &i: ans)cout << i.first + 1 << ' ' << i.second + 1 << endl;
}


int32_t main() {
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    fast


    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
