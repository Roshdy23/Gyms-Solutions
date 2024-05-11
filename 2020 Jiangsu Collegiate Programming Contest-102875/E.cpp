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
    ll count1bits(ll num)
    {
        if (num <= 1)
            return num;
        return 1+ count1bits(num & (num - 1ll));
    }
    vector<ll> edges;
    vector<vector<ll>> gf(17);
    vector<bool> isvis(1ll<<16,0);
    vector<ll>nxt(1ll<<16);
    vector<pii> par(1ll<<16,{-1,-1});
    void pre(ll n )
    {
        for(ll i = 0 ;i < 1ll<<n;i++)
        {
            ll temp=0;
            fr(j,n)
            {
                if((i>>j)&1ll)
                {
                    for(auto ii:gf[j])
                    {
                        temp|=1ll<<ii;
                    }
                }
            }
            nxt[i]=temp;
        }
    }
    bool ok=false;
    void bfs(ll node)
    {
        queue<ll> q;
        q.push(node);
        isvis[node]=1;
        while(!q.empty())
        {
            ll next=q.front();
            q.pop();
            if(next==0) {
                ok=true;
                return;
            }

            for(auto i:edges)
            {
                ll temp=(next&i)^next;
                ll temp2=temp&i;
                if(!isvis[nxt[temp]])
                {
                    ll togo=nxt[temp];
                    par[togo]={i&next,next};
                    q.push(togo);
                    isvis[togo]=1;
                }
            }
        }
    }
  
    void solve(int t)
    {
        ll n ,m,k;cin>>n>>m>>k;
        ll sum=1ll<<n;

        fr(i,sum)
        {
            ll temp = count1bits(i);
            if(temp==k)
            {
                edges.pb(i);
            }
        }

        fr(i,m)
        {
            ll u ,v;cin>>u>>v;
            u--,v--;
            gf[u].pb(v);
            gf[v].pb(u);
        }
        pre(n);

        bfs((1ll<<n)-1);
        if(!ok)
        {
            cout<<-1<<nl;
        }
        else
        {
            vector<ll> ans;
            ll node=0;
            while(par[node].first!=-1)
            {
                ans.pb(par[node].first);
                node=par[node].second;
            }
//            ans.pb(node);
            reverse all(ans);
            cout<<ans.size()<<nl;
            for(auto i:ans)
            {
                fr(j,n)
                {
                    if((i>>j)&1)
                    {
                        cout<<(char)(j+'a');
                    }
                }
                cout<<nl;
            }
        }

    }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);
        ll t = 1;
//        cin >> t;

        while (t--)
            solve(t);
    }