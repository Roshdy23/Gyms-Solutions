#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 7;
const int M = 1e6 + 7;
const int LOG = 18;
const int MOD = 1e9 + 7;
const ll inf = 1e13;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(n);
    for (auto &i: v)cin >> i;
    int p, k;
    while (q--) {
        cin >> p >> k;
        k--;
        int dist = p * v[k];
        ll rem = dist % m;
        if ((dist / m) % 2 == 0) {
            cout << rem << endl;
        } else {
            cout << m - rem << endl;
        }
    }


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
