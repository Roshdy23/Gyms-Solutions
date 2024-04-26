#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <omp.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define OO 4e18
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define nl endl
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define fr(i,n) for(ll i=0;i<n;i++)
#define fr1(i,n) for(ll i=1;i<=n;i++)
#define posmod(v,m) ((v%m)+m)%m
#define all(v) (v.begin(),v.end())
#define allg(v) (v.begin(),v.end(),greater<ll>())
#define ELROSHDY ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

const ll N = 2e5 + 5;
//vctor<vector<ll>> gf (N)
ll xr[] = { -1,1,0,0 };
ll yr[] = { 0,0,1,-1 };
//ll xr[]={0,0,1,1};
//ll yr[]={0,1,0,1};
const ll mod = 1e9 + 7;
const int M = 1e9+7;
long long mod2(long long x) {
    return ((x % M + M) % M);
}
long long add(long long a, long long b) {
    return mod2(mod2(a) + mod2(b));
}
long long mul(long long a, long long b) {
    return mod2(mod2(a) * mod2(b));
}

struct segtree
{
    int size;
    vector<ll>values ;
    void init(int n)
    {
        size = 1;
        while (size < n)size *= 2;
        values.assign(2 * size, 0);
    }
    void Build(ll* v, int x, int lx, int rx)
    {
        if (rx - lx == 1) { values[x] = v[lx]; return; }

        int md = (rx + lx) / 2;

        Build(v, 2 * x + 1, lx, md);

        Build(v, 2 * x + 2, md, rx);

        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void Build(ll* v,ll n)
    {
        init(n);
        Build(v, 0, 0, size);
    }
    ll Range(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx||l>=rx)return 0;

        if (rx <= r && lx >= l)return values[x];

        int md = (rx + lx) / 2;

        ll val_l = Range(l, r, 2 * x + 1, lx, md);

        ll val_r = Range(l, r, 2 * x + 2, md, rx);

        return val_l+ val_r;
    }

    ll Range(int l, int r)
    {
        return Range(l, r, 0, 0, size);
    }
};
void solve(int t)
{
ll n , k;cin>>n>>k;
vector<string> v(n);
getline(cin,v[0]);
fr(i,n) {
    string tt; getline(cin,tt);
v[i]=tt;
}
ll cur=-1;
fr(i,k)
{
    ll temp;
cin>>temp;
cur+=temp+1;
cur%=n;
cout<<v[cur]<<nl;
}

}


signed main() {
//    freopen("car.in", "r", stdin);
    //    freopen("output.txt", "w", stdout);



    ELROSHDY

    ll t = 1;
//    cin >> t;

    while (t--)
        solve(t);
}