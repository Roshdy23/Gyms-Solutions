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
    vector<vector<ll>> alldiv(100007);

    void generatediv(ll n, vector<ll>& v)// generate all divisors
    {
        ll i;
        for ( i = 1; i <= n / i; i++)
        {
            if (n % i == 0) {
                v.pb(i);
                v.pb(n / i);
            }
        }
        i--;
        if (i * i == n)
            v.pop_back();
    }

    void pre()
    {
        for(ll i =1;i<100005;i++)
        {
            generatediv(i,alldiv[i]);
        }
    }

    void solve(int t)
    {

      ll n,m,k;cin>>n>>m>>k;
      vector<ll> v(n);
      fr(i,n)cin>>v[i];

      vector<ll> temp(m+1,0);
      vector<ll> cnt(m+1,0);
      fr(i,n)
      {
          for(auto j:alldiv[v[i]])
          {
              cnt[j]++;
          }

      }
      vector<ll> ans(m+1,0);
      for(ll j =m; j>=1;j--)
      {
       ans[j]=cnt[j]*cnt[j]-temp[j];
       for(auto i:alldiv[j])
       {
           temp[i]+=ans[j];
       }
      }

      fr(i,k)
      {
           ll x;cin>>x;
           if(x<=m)
           cout<<ans[x]<<nl;
           else
               cout<<0<<nl;
      }

    }


    int main() {
        //    freopen("car.in", "r", stdin);
//            freopen("output.txt", "w", stdout);
        ELROSHDY
        pre();
        ll t = 1;
     cin>>t;



//    string t;
        while (t--) {


            solve(t);

        }
    }