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
    const ll mod= 1e9+7;

    bool ispal(string &s)
    {
        ll n =s.size();
        fr(i,n)
        {
            if(s[i]=='?'||s[n-i-1]=='?')continue;
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<ll>> &gf ,ll node, vector<bool >&isvis, string &s,set<char> &s2)
    {
        for(auto i:gf[node])
        {
            if(isvis[i])continue;


            if(s[i]!='?')s2.insert(s[i]);
            isvis[i]=1;

            dfs(gf,i,isvis,s,s2);
}
    }
    void solve(int t)
    {
        ll n , m;cin>>n>>m;
        string s;cin>>s;
        vector<pii> cond(m);
        vector<vector<ll>> gf(n);
        fr(i,m)
        {
            cin>>cond[i].first>>cond[i].second;
            cond[i].first--;
            cond[i].second--;
        }

        if(!ispal(s))
        {
            cout<<0<<nl;
            return ;
        }
        fr(i,m)
        {
          gf[cond[i].first].pb(cond[i].second);
            gf[cond[i].second].pb(cond[i].first);
        }

        fr(i,n)
        {
            gf[i].pb(n-i-1);
        }








        ll ans=1;
        vector<bool> isvis(n,0);
        fr(i,n)
        {
            if(!isvis[i])
            {

                isvis[i]=1;
                set<char> s2;
                if(s[i]!='?')s2.insert(s[i]);
                dfs(gf,i,isvis,s,s2);
                if(s2.size()==0)
                ans=(ans*26ll)%mod;
                else if(s2.size()>1)ans=0;
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