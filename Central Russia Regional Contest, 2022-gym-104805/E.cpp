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
ld circleInter(point a, point b, ll r1, ll r2) {
    if (r1 > r2) {
        swap(r1, r2);
        swap(a, b);
    }
    ld d = sqrt((a.real() - b.real()) * (a.real() - b.real()) + (a.imag() - b.imag()) * (a.imag() - b.imag()));
    if (d >= r1 + r2) {
        return 0;
    }
    if (d + r1 <= r2) {
        return PI * r1 * r1;
    }
    ld theta = acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2)); //
    ld alpha = acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));//
    ld s1 = theta * r2 * r2;
    ld t1 = 0.5 * r2 * r2 * sin(2 * theta);
    ld s2 = alpha * r1 * r1;
    ld t2 = 0.5 * r1 * r1 * sin(2 * alpha);
    return (s1 - t1) + (s2 - t2);
}
bool compare(pair<int,point> p1,pair<int,point>p2)
{
    return p1.second.real()<p2.second.real();
}
void solve(int t) {
 int n ;cin>>n;
 vector<pair<ld,point>>v(n);
 ld ans=0;
 fr(i,n)
 {
     int x;cin>>x;
     ld r;cin>>r;
     v[i]={r,point(x,0)};
     ans+=PI * r*r;
 }
 sort (v.begin(),v.end(),compare);
 fr(i,n-1)
 {
     ans-= circleInter(v[i].second,v[i+1].second,v[i].first,v[i+1].first);
 }
 cout<<fixed<<setprecision(8)<<ans<<nl;

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