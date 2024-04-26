#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define ll long long
#define ld long double
const int N = 1e5 + 10;
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
bool vis[N];
vector<vector<int>> adj(N);
bool cyc = false;


ll fastPow(ll x, ll n) {
    ll m= mod;
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


template<int P>
struct MInt {
    int x;

    constexpr MInt() : x{} {}

    constexpr MInt(ll x) : x{norm(x % getMod())} {}

    static int Mod;

    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }

    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MInt &operator*=(MInt rhs) &{
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }

    constexpr MInt &operator+=(MInt rhs) &{
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MInt &operator-=(MInt rhs) &{
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MInt &operator/=(MInt rhs) &{
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        ll v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};


template<>
int MInt<0>::Mod = 1e9 + 7;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

int dfs(int node, int par) {
    if (vis[node]) {
        cyc = true;
        return 0;
    }
    vis[node] = true;
    int sz = 1;
    for (auto &i: adj[node]) {
        if (i != par)
            sz += dfs(i, node);
    }
    return sz;
}


void solve() {
    int n, k;
    cin >> n >> k;
    int u, v;
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i=0;i<=n;i++){
        if(adj[i].size()>2){
            return void(cout << -1 << endl);
        }
    }
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() && !vis[i])
            a.push_back(dfs(i, -1));
        if (cyc)
            return void(cout << -1 << endl);
    }
    Z ans = 1;
    int sum = 0;
    for (auto &i: a)sum += i;
    int tr = n - sum + (int) a.size();
    for (int i = tr; i > 1; --i) {
        ans *= i;
    }
    ans *= fastPow(2,a.size());
    cout<< ans << endl;
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