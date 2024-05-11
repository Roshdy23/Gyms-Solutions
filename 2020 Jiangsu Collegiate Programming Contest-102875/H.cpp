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
 

  
    bool ok1=false;
    bool ok2=false;
    ll best(map<string,vector<char>> & mp , ll ind ,ll n , string cnt, string &s,  vector<vector<ll>> &dp  )
    {
        if(cnt.size()>5)return 0;
        if(ind>=n)
        {
            if(cnt=="") {
                    ok1=true;
                return 1;
            }
            else return 0;
        }
       auto &ret = dp[ind][cnt.size()];
    if(~ret) {

        return ret;
    }
    ret=0;
        string temp2(1,s[ind]);
        cnt.append(temp2);

        if(mp[cnt].size()>0) {
            ret = (mp[cnt].size() * best(mp, ind + 1, n, "", s, dp));
        }
        ret = (ret+best(mp,ind+1,n,cnt,s,dp));
        if(ret>1)
        {
            ok2=true;
            ret%=128;
        }
        return ret;
    }
    void solve(int t)
    {
        ok1=false;
        ok2=false;
        ll n , m ;cin>>n>>m;
        map<string,vector<char>> mp;
        fr(i,m)
        {
            char a;cin>>a;
            string s;cin>>s;



            mp[s].pb(a);
        }
    vector<vector<ll>> dp(n,vector<ll>(10,-1));
        string s;cin>>s;
        string cnt="";
        ll val=best(mp,0,n,cnt,s,dp);
        if(!ok1)
        {
            cout<<"nonono\n";
        }
        else if(!ok2&&ok1)
        {
            cout<<"happymorsecode\n";
        }
        else
        {
            cout<<"puppymousecat "<<val%128<<nl;
        }

    }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);


        ELROSHDY

        ll t = 1;
        cin >> t;

        while (t--)
            solve(t);
    }