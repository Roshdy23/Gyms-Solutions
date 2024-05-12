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

    void topo(string &node,vector<string> &final, map<string,vector<string>> &gf,   map<string,ll> &index,map<string,bool> &isvis) {
        for (auto &i: gf[node]) {
            if (!isvis[i]) {
                isvis[i] = true;
                topo(i,final,gf,index,isvis);
            }
        }
        final.pb(node);
    }

    ll best(vector<ll> &dp,ll state,vector<string> & alstr, ll cnt, vector<ll> &val,map<string,ll> &index,vector<ll> &mask)
    {
        ll &ret=dp[state];
        if(~ret)return ret;
        ret=0;
            fr(i,alstr.size())
        {

                if((state&(1ll<<i)))continue;
                if((mask[i]&state)!=mask[i])continue;

                   ret=max(ret ,best(dp,state|(1ll<<i),alstr,cnt+1,val,index,mask)+cnt*val[i]);

        }
        return ret;
    }
    bool isstring(string &s)
    {
        fr(i,s.length())
        {
            if((s[i]<'a'||s[i]>'z')&&( s[i] <'A' || s[i] > 'Z'))
            {
                return false;
            }
        }
        return true;
    }

    ll Convtoll(string &s)
    {
        ll mult=1;
        ll add=0;
        ll dig=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            dig+=(s[i]-'0')*mult;
            mult*=10;
        }
        return dig;
    }
        void solve(int t)
        {


            map<string,ll> index;

            vector<ll> mask(262150,0);
            vector<string> als2;
            ll n , m;
            cin>>n>>m;
            vector<ll> val(n);
            fr(i,n)
            {
                string s="";
                string temp;
                cin>>temp;
                while(isstring(temp))
                {
                    s=s+ " "+temp;
                    cin>>temp;
                }

                ll x= Convtoll(temp);
               val[i]=x;
                    index[s]=i;
                als2.pb(s);
            }

            fr(i,m)
            {
                string s="";
                string temp;
                cin>>temp;
                while(temp !="-->")
                {
                    s=s+" " +temp;
                    cin>>temp;
                }
            string  s2;
                getline(cin,s2);

                mask[index[s2]]|=(1ll<<index[s]);

            }


            vector<ll> dp(262150,-1);
            cout<<best(dp,0,als2,1,val,index,mask)<<nl;
        }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);
        ll t = 1;
     cin>>t;
        while (t--)
            solve(t);
    }