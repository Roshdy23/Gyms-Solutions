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
const int M =  998244353;
struct segtree
{
    int size;
    vector<pii>values ;



    ll operate(ll a, ll b )
    {
        if (b == OO) return a;
        return b;
    }

    void apply_operation(ll &a, ll b)
    {
        a = operate(a, b);

    }

    void init(int n)
    {
        size = 1;
        while (size < n)size *= 2;
        values.assign(2 * size, {-OO,OO});
    }


    void Build(pii* v, int x, int lx, int rx)
    {
        if (rx - lx == 1) { values[x] = v[lx]; return; }

        int md = (rx + lx) / 2;

        Build(v, 2 * x + 1, lx, md);

        Build(v, 2 * x + 2, md, rx);

        values[x].first = max(values[2 * x + 1].first , values[2 * x + 2].first);
        values[x].second = min(values[2 * x + 1].second, values[2 * x + 2].second);
    }

    void Build(pii* v,ll n)
    {
        init(n);
        Build(v, 0, 0, size);
    }



    void set(int i, pii v, int x,int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = v;
            return;
        }
        int md = (rx + lx) / 2;
        if (i < md)
        {
            set(i, v, x * 2 + 1, lx, md);
        }
        else
        {
            set(i, v, x * 2 + 2, md,rx);
        }

        values[x].first = max(values[2 * x + 1].first , values[2 * x + 2].first);
        values[x].second = min(values[2 * x + 1].second, values[2 * x + 2].second);
    }

    void set(int i, pii v)
    {
        set(i, v, 0, 0, size);
    }


    pii Range(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx||l>=rx)return {-OO,OO};

        if (rx <= r && lx >= l)return values[x];

        int md = (rx + lx) / 2;

        pii val_l = Range(l, r, 2 * x + 1, lx, md);

        pii val_r = Range(l, r, 2 * x + 2, md, rx);
        pii ret={-OO,OO};
        ret.first=max(val_l.first,val_r.first);
        ret.second=min(val_l.second,val_r.second);

        return ret ;
    }

    pii  Range(int l, int r)
    {
        return Range(l, r, 0, 0, size);
    }




};

pii arr[300000+7];

void solve(int t) {
int n,q;cin>>n>>q;
fr(i,n)
{
     ll l,r;cin>>l>>r;
     arr[i]={l,r};
}
segtree s;
s.Build(arr,n);
fr(i,q)
{
    char a;cin>>a;
    if(a=='?')
    {
        ll l ,r;cin>>l>>r;
        l--,r;
        pii temp=s.Range(l,r);
        cout<<max(temp.second-temp.first+1,0ll)<<nl;
    }
    else
    {
        ll ind;
        pii val;cin>>ind>>val.first>>val.second;
        s.set(ind-1,val);
    }
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