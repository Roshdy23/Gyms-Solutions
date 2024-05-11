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
    #define fr(i,n) for(int i=0;i<n;i++)
    #define fr1(i,n) for(int i=1;i<=n;i++)
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
    const int M = 998244353;
    


    void generateprimes(int n, vector<bool>& v)//generate primes in a range-----sieve_algorithm-----> nloglogn
    {
        v[0] = v[1] = 0;

        for (int i = 2; i <= n/i; i++)
        {
            if (v[i] == true)
            {

                for (int j = i*i; j <= n; j += i)
                {
                    v[j] = false;
                }
            }
        }
    }
    vector<ll> dp(1000007,0);
    vector<ll> pref(1000007,0);
    vector<bool> isprim(1000007,1);
    vector<vector<ll>>lev(10000);
    void solve(int t)
    {

ll op,n,k;cin>>op>>n>>k;
if(op==1)
{
ll teemp=dp[k];
ll ans= std::upper_bound(lev[teemp].begin(), lev[teemp].end(),k)-lev[teemp].begin();
fr1(i,teemp-1)
{
    ans+=std::upper_bound(lev[i].begin(), lev[i].end(),n)-lev[i].begin();
}
cout<<ans<<nl;
}
else
{
    ll temp=0;
fr1(i,1000)
{
    ll temp2= std::upper_bound(lev[i].begin(), lev[i].end(),n)-lev[i].begin();
    if(temp2>=k)
    {
        cout<<lev[i][k-1]<<nl;
        break;
    }
    else
        k-=temp2;
}
}

    }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);

        generateprimes(1000004,isprim);
        ELROSHDY
        fr1(i,1000000)
        {
                if(isprim[i]||i==1)pref[i]++;
                pref[i]+=pref[i-1];
        }

        fr1(i,1000000)
        {
            if(isprim[i]||i==1)dp[i]=1;
            else dp[i]=dp[i-pref[i]]+1;
        }

        fr1(i,1000000)
        {
          lev[dp[i]].pb(i);
        }
        ll t = 1;
        cin >> t;

        while (t--)
            solve(t);
    }