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
    int n1,m1,n2,m2;
    cin >> n1 >> n2 >> m1 >> m2;
    set<string>s,t;
    string x;
    for (int i = 0; i < n1; ++i) {
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < n2; ++i) {
        cin >> x;
        t.insert(x);
    }
    set<string>q;
    for(auto &i:s){
        if (t.count(i))
            q.insert(i);
    }
    for (int i = 0; i < m1; ++i) {
        cin >> x;
        if (q.count(x))
            q.erase(x);
    }
    for (int i = 0; i < m2; ++i) {
        cin >> x;
        if (q.count(x))
            q.erase(x);
    }
    for(auto &i:q)cout<<i<<endl;




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