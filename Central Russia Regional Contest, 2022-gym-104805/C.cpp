#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <omp.h>

using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define OO 4e18
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<ll,ll>, null_type,greater<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define nl '\n'
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define posmod(v,m) ((v%m)+m)%m
#define all(v) (v.begin(),v.end())
#define allg(v) (v.begin(),v.end(),greater<ll>())
#define ELROSHDY ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


//vctor<vector<ll>> gf (N)
ll xr[] = { -1,1,0,0 ,1,-1,-1,1};
ll yr[] = { 0,0,1,-1 ,1,-1,1,-1};
//ll xr[]={0,0,1,1};
//ll yr[]={0,1,0,1};
const ll mod =  1e9+7;
const int M =  1e9+7;

const int MAX_N = 200007;
const int LOG = 20;
vector<pii> children[MAX_N];
int up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MAX_N];
ll dist[MAX_N][LOG];

long long mod2(long long x) {
    return ((x % M + M) % M);
}
long long add(long long a, long long b) {
    return mod2(mod2(a) + mod2(b));
}
long long mul(long long a, long long b) {
    return mod2(mod2(a) * mod2(b));
}

ll modPow(ll a, ll b) {
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % M;
    ll res = 1;
    while (b) {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}

ll inv(ll x) {
    return modPow(x, M - 2);
}

ll divide(ll a, ll b) {
    return mul(a, inv(b));
}

void dfs(int a,int par) {
    for (pii b : children[a]) {
        if(par==b.first)continue;
        depth[b.first] = depth[a] + 1;
        dist[b.first][0]=b.second;
        up[b.first][0] = a; // a is parent of b
        for (int j = 1; j < LOG; j++) {
            up[b.first][j] = up[up[b.first][j - 1]][j - 1];
            dist[b.first][j]=mul(dist[b.first][j-1],dist[up[b.first][j-1]][j-1]);
        }
        dfs(b.first,a);
    }
}

int get_lca(int a, int b) { // O(log(N))
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if (a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
ll get(ll u,ll dis)
{
    if(dis==0)return 1;
    ll node=u;
    ll ans=1;
    fr(i,20)
    {
        if(dis&(1ll<<i))
        {
            ans=mul(ans,dist[node][i]);
            node=up[node][i];
        }
    }
    return ans;
}
ll getDist(ll u, ll v)
{
    ll lc= get_lca(u,v);
    ll dist1=abs(depth[u]-depth[lc]);
    ll dist2=abs(depth[v]-depth[lc]);
    return mul(get(v,dist2), get(u,dist1));
}
void solve(int t) {

    int n;cin>>n;
    fr(i,n-1) {
        ll u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        children[u].pb({v, cost});
        children[v].pb({u, cost});
    }
    dfs(0,-1);
    int q;cin>>q;
    fr(i,q)
    {
        ll l,r;cin>>l>>r;
        l--,r--;
        cout<<getDist(l,r)<<nl;
    }
}
int main() {
    //    freopen("car.in", "r", stdin);
    //            freopen("output.txt", "w", stdout);
    ELROSHDY

    ll t = 1;
//         cin>>t;



    //    string t;
    while (t--) {


        solve(t);

    }
}