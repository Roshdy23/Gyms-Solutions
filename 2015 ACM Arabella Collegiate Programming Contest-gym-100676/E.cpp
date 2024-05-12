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


    void solve(int t)
    {

        ll n ;cin>>n;
        vector<ll> freq(10100,0);
        vector<ll> v(n);
        fr(i,n) {
            cin >> v[i];
            freq[v[i]]++;

        }
        ll ans=0;
        sort all(v);

        fr(i,n)
        {

            freq[v[i]]--;
            for(ll j = v[i];j<v[i]+32;j++)
            {

                if(v[i]==j)
                {
                    ans+=freq[j];
                }
                else
                {
                    ans+=freq[j];
                }
            }
        }
        cout<<ans<<nl;
    }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);
        ll t = 1;
     cin>>t;
        while (t--)
            solve(t);
    }