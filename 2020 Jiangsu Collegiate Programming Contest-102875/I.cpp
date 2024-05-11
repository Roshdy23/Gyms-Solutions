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
 


    vector<vector<ll>> a(500,vector<ll>(500)),b(500,vector<ll>(500)),costc(500,vector<ll>(500,OO)),costw(500,vector<ll>(500,OO));

    void dijkstra(int xsrc,int ysrc, vector<vector<ll>> & dist, int d, ll n ,ll m,int xe , int ye)
    {



        priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

        pq.push({ 0,{xsrc,ysrc } });
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (dist[cur.second.first][cur.second.second] != -1)continue;
            dist[cur.second.first][cur.second.second]= cur.first;
            ll x=cur.second.first;
            ll y= cur.second.second;


//            ll k2=getState2(cur.first,cur.second.first,cur.second.second);
            ll a1=a[cur.second.first][cur.second.second];
            ll b1=b[cur.second.first][cur.second.second];
            ll k = cur.first/(a1+b1);
            if(cur.first>=k*(a1+b1)&&cur.first<(a1+b1)*k+a1)
            {
                if(x+1<n&&dist[x+1][y]==-1)
                {
                    pq.push({dist[x][y]+costw[x][y],{x+1,y}});
                }
                if(x-1>=0&&dist[x-1][y]==-1)
                {
                    pq.push({dist[x][y]+costw[x-1][y],{x-1,y}});
                }

                if(y+1<m&&dist[x][y+1]==-1)
                {
                    pq.push({dist[x][y]+costc[x][y]+((k)*(a1+b1)+a1-cur.first),{x,y+1}});
                }
                if(y-1>=0&&dist[x][y-1]==-1)
                {
                    pq.push({dist[x][y]+costc[x][y-1]+((k)*(a1+b1)+a1-cur.first),{x,y-1}});
                }
            }
            else
            {
                if(x+1<n&&dist[x+1][y]==-1)
                {
                    pq.push({dist[x][y]+costw[x][y]+((k+1)*(a1+b1)-cur.first),{x+1,y}});
                }
                if(x-1>=0&&dist[x-1][y]==-1)
                {
                    pq.push({dist[x][y]+costw[x-1][y]+((k+1)*(a1+b1)-cur.first),{x-1,y}});
                }

                if(y+1<m&&dist[x][y+1]==-1)
                {
                    pq.push({dist[x][y]+costc[x][y],{x,y+1}});
                }
                if(y-1>=0&&dist[x][y-1]==-1)
                {
                    pq.push({dist[x][y]+costc[x][y-1],{x,y-1}});
                }
            }
        }
    }
    void solve(int t)
    {
        ll n,m,xs,xt,ys,yt;cin>>n>>m>>xs>>ys>>xt>>yt;
        xs--,xt--,ys--,yt--;
        fr(i,n)fr(j,m)cin>>a[i][j];
        fr(i,n)fr(j,m)cin>>b[i][j];
        fr(i,n)fr(j,m-1)cin>>costc[i][j];
        fr(i,n-1)fr(j,m)cin>>costw[i][j];
        vector<vector<ll>> dist(n,vector<ll>(m,-1));

        dijkstra(xs,ys,dist,0,n,m,xt,yt);
        cout<<dist[xt][yt]<<nl;
    }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);
        ll t = 1;
//        cin >> t;

        while (t--)
            solve(t);
    }