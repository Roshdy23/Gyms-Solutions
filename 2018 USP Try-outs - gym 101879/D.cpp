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
ll getmx( vector<pair<int,pair<int,char>>> &v, ll n)
{
    ll maxb=0,maxw=0,ans=0;
    vector<pii> suf1(n+1);
    for(int i=n-1;i>=0;i--) {
        if (v[i].second.second == 'b')suf1[i].first=1;
        else suf1[i].second=1;
        suf1[i].first+=suf1[i+1].first;
        suf1[i].second+=suf1[i+1].second;
    }
    fr(i,n)
    {
        if(v[i].second.second=='b')
        {
            maxb++;
        }
        else
            maxw++;

        ll temp1=suf1[i+1].first+maxw;
        ll temp2=suf1[i+1].second+maxb;
       ll ans2=max(temp1,temp2);
       ans=max(ans,ans2);
    }
    return ans;
}
void solve(int t) {
    ll maxb = 0, maxw = 0;
    ll n;
    cin >> n;
    ll ans = 0;
    vector<pair<int, pair<int, char>>> v(n), v2;
    fr(i, n)cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    v2 = v;
    fr(i, n)swap(v2[i].first, v2[i].second.first);
    sort all(v);
    sort all(v2);
   cout<<max(getmx(v,n),getmx(v2,n))<<nl;
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