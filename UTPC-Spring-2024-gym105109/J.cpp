#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define ll long long
#define ld long double
const int N = 2000 + 10;
const int M = 400 + 7;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const ll inf = 1e18;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int mul(int a, int b) {
    return (a % mod) * (b % mod) % mod;
}

#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);


void solve() {
    int n;
    cin >> n;
    int x,sz;
    set<int>s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> sz;
        int cnt = 0;
        while (sz--){
            cin >> x;
            if (s.find(x) == s.end())cnt++;
            s.insert(x);
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<endl;

}


::int32_t main() {
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