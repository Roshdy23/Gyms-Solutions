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
ll  get(char a)
{
    if(a>='0'&&a<='9')
    {
        return a-'0';
    }
    return a-'A'+10;
}
char rev(ll x)
{
    if(x>=0&&x<=9)return x+'0';
    return 'A'+x-10;
}
string calc(string &a,string &b,ll  base)
{
    if(b.size()>a.size())swap(a,b);
    b=string(a.size()-b.size(),'0')+b;
    int car=0;
    int n=a.size();
    string ret="";
    for(int i=n-1;i>=0;i--)
    {
        ll temp1=get(b[i]);
        ll temp2=get(a[i]);
        ll temp3=temp1+temp2+car;
        car=temp3/base;
        ll cur=temp3%base;
        char aa=rev(cur);
        ret.pb(aa);
    }
    if(car)ret.pb(rev(car));
    reverse all(ret);
    return ret;
}


void solve(int t) {
    string a,b,c;cin>>a>>b>>c;
int ans=0;
int val=0;
    for(int i=1;i<=37;i++)
    {
        if(calc(a,b,i)==c) {
            ans++;
            val=i;
        }
    }
    if(ans!=1)
    {
        cout<<0<<nl;
    }
    else
        cout<<val<<nl;
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