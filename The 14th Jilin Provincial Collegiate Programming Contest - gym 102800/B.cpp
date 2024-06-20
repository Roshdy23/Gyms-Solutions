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


    //vctor<vector<ll>> gf (N)
    ll xr[] = { -1,1,0,0 ,1,-1,-1,1};
    ll yr[] = { 0,0,1,-1 ,1,-1,1,-1};
    //ll xr[]={0,0,1,1};
    //ll yr[]={0,1,0,1};
    const ll mod =  998244353;
    const int M =  998244353;



    void solve(int t)
    {
        ll n , k;cin>>n>>k;
        set<ll>s;
        fr(i,n)
        {
            string sr;cin>>sr;
            int m=sr.length();
            ll temp=0;
            ll mult=1;
            for(int j = m-1;j>=0&&sr[j]!='/';j--)
            {
            temp+=(sr[j]-'0')*mult;
            mult*=10;
            }
            s.insert(temp);
        }

        int cnt=0;
        for(auto i:s)
        {
            if(cnt>=k)break;
            cout<<i<<' ';
            cnt++;
        }
        cout<<nl;
    }


    signed main() {
        //    freopen("car.in", "r", stdin);
//            freopen("output.txt", "w", stdout);
        ll t = 1;
     cin>>t;



        while (t--) {


            solve(t);

        }
    }