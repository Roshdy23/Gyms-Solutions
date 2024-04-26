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
const ll M = 1e9+7;
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
    if (b == 1ll)
        return a % M;
    ll res = 1;
    while (b) {
        if (b % 2 == 1ll)
            res = mul(res, a);
        a = mul(a, a);
        b = b / 2ll;
    }
    return res;
}


ll fact[N];

void precalc() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
}

ll inv(ll x) {
    return modPow(x, M - 2ll);
}

ll divide(ll a, ll b) {
    return mul(a, inv(b));
}

ll nCr(ll n, ll r) {
    return divide(fact[n], mul(fact[r], fact[n - r]));
}
ll dp[1004][1004];
void solve(int t)
{
    ll n ,m;cin>>n>>m;
    vector<ll> v(n);
    fr(i,n)cin>>v[i];

    fr(i,m)
    {
        ll k ,x;cin>>k>>x;
        k--,x--;

        ll ans=1ll;
        fr(j,x+1ll)
        {
            ll num=k+x-j;
            ans=mul(ans,modPow(v[j],dp[k][x-j]));
        }
        cout<<ans%M<<nl;
    }
}


signed main() {
//    freopen("car.in", "r", stdin);
    //    freopen("output.txt", "w", stdout);



    ELROSHDY

    ll t = 1;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[0][1]=1;
    fr(i,1001)
    {
        fr(j,1001)
        {
            if(j>=1&&i>=1)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%(M-1);
            else
                dp[i][j]=1;
        }
    }
    cin >> t;

    while (t--)
        solve(t);
}