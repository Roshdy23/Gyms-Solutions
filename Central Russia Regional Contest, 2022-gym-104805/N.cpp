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

void solve(int t) {
    int n ;cin>>n;
    vector<string> v(n);
    fr(i,n)cin>>v[i];
    string s;cin>>s;
    vector<bool> dp(s.size()+1,0);
//    dp[0]=true;
    fr(i,s.size())
    {
        ll len=i+1;


            fr(j,n)
            {

                if(v[j].size()<=len&&s.substr(i-v[j].size()+1,v[j].size())==v[j]&&(i-v[j].size()==-1||dp[i-v[j].size()]))
                {

                    dp[i]=1;
                    break;
                }
            }

    }
    if(dp[s.size()-1])cout<<"YES\n";
    else cout<<"NO\n";
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