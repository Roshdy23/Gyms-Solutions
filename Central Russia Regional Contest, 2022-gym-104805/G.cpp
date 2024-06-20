#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>

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
typedef complex<ld> point;
const ld  PI = acos(-1.0);
//vctor<vector<ll>> gf (N)
ll xr[] = { -1,1,0,0 ,1,-1,-1,1};
ll yr[] = { 0,0,1,-1 ,1,-1,1,-1};
//ll xr[]={0,0,1,1};
//ll yr[]={0,1,0,1};
const ll mod =  1e9+7;
const int M =  1e9+7;

void solve(int t) {
int n ;cin>>n;
vector<pii> v;
fr(i,n)
{
    string a,b;cin>>a>>b;
    ll hours1=(a[0]-'0')*10+(a[1]-'0');
    ll min1=(a[3]-'0')*10+(a[4]-'0');
    ll seconds=(a[6]-'0')*10+(a[7]-'0');
    a=b;
    ll hours2=(a[0]-'0')*10+(a[1]-'0');
    ll min2=(a[3]-'0')*10+(a[4]-'0');
    ll seconds2=(a[6]-'0')*10+(a[7]-'0');

    ll val1=hours1*3600+min1*60+seconds;
    ll val2=hours2*3600+min2*60+seconds2;
    if(val2<val1)
    {
        v.pb({0,val2});
        v.pb({val1,24*3600});
    }
    else
    {
        v.pb({val1,val2});
    }

}
sort all(v);
ll right=0;
ll ans=0;
fr(i,v.size())
{
    ans+=max(v[i].first-right,0ll);
    right=max(right,v[i].second);
}
cout<<ans+max(24*3600-right,0ll)<<nl;
}
int main() {
    //    freopen("car.in", "r", stdin);
    //            freopen("output.txt", "w", stdout);
    ELROSHDY

    ll t = 1;
//         cin>>t;




    while (t--) {


        solve(t);

    }
}