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
int dirx[]={2,0,1,3};
//ll xr[]={0,0,1,1};
//ll yr[]={0,1,0,1};
const ll mod =  1e9+7;
const int M =  998244353;

bool valid(int x,int y, int n,int m,vector<vector<char>> &gf)
{
    if(x>=0&&x<n&&y>=0&&y<m&&gf[x][y]!='#')return true;
    return false;
}

void solve() {
    int n,m,l,r,f,t;cin>>n>>m>>l>>r>>f>>t;
    priority_queue<pair<ll,pair<ll,pii>>, vector<pair<ll, pair<ll,pii>>>, greater<pair<ll, pair<ll,pii>>>> pq;
    vector<vector<vector<ll>>>dist (n,vector<vector<ll>>(m,vector<ll>(4,-1)));
    vector<vector<char>> gf(n,vector<char>(m));
    ll stx=0,sty=0,gx=0,gy=0;
    vector<pii> check;

    fr(i,n)
    {
        fr(j,m)
        {
            cin>>gf[i][j];
            if(gf[i][j]=='*')
            {
                gx=i;
                gy=j;
                check.pb({gx,gy});
            }
            else if(gf[i][j]!='*'&& gf[i][j]!='#'&&gf[i][j]!='.')
            {
                stx=i;
                sty=j;

            }
        }
    }

    // counter clock wise +1 clock wise -1

    pq.push({0,{0,{stx,sty}}});
    dist[stx][sty][0]=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        ll d=it.first;
        int x=it.second.second.first;
        int y=it.second.second.second;
        int dir=it.second.first;
        int ndir1=(dir+1)%4;// costs r
        int ndir2=((dir-1)%4+4)%4;//costs l
        if(dist[x][y][ndir1]==-1||dist[x][y][ndir1]>dist[x][y][dir]+r)
        {
            dist[x][y][ndir1]=dist[x][y][dir]+r;
            pq.push({dist[x][y][ndir1],{ndir1,{x,y}}});
        }

        if(dist[x][y][ndir2]==-1||dist[x][y][ndir2]>dist[x][y][dir]+l)
        {
            dist[x][y][ndir2]=dist[x][y][dir]+l;
            pq.push({dist[x][y][ndir2],{ndir2,{x,y}}});
        }

        if(dir==0)
        {
            if(valid(x-1,y,n,m,gf))
            {
                if(dist[x-1][y][dir]==-1||dist[x-1][y][dir]>dist[x][y][dir]+f)
                {
                    dist[x-1][y][dir]=dist[x][y][dir]+f;
                    pq.push({dist[x-1][y][dir],{dir,{x-1,y}}});
                }
            }
        }else if(dir==1)
        {
            if(valid(x,y-1,n,m,gf))
            {
                if(dist[x][y-1][dir]==-1||dist[x][y-1][dir]>dist[x][y][dir]+f)
                {
                    dist[x][y-1][dir]=dist[x][y][dir]+f;
                    pq.push({dist[x][y-1][dir],{dir,{x,y-1}}});
                }
            }
        } else if(dir==2)
        {
            if(valid(x+1,y,n,m,gf))
            {
                if(dist[x+1][y][dir]==-1||dist[x+1][y][dir]>dist[x][y][dir]+f)
                {
                    dist[x+1][y][dir]=dist[x][y][dir]+f;
                    pq.push({dist[x+1][y][dir],{dir,{x+1,y}}});
                }
            }
        }
        else if(dir==3)
        {
            if(valid(x,y+1,n,m,gf))
            {
                if(dist[x][y+1][dir]==-1||dist[x][y+1][dir]>dist[x][y][dir]+f)
                {
                    dist[x][y+1][dir]=dist[x][y][dir]+f;
                    pq.push({dist[x][y+1][dir],{dir,{x,y+1}}});
                }
            }
        }
    }
    ll ans=OO;
    for(auto j:check) {
        gx=j.first;
        gy=j.second;
        fr(i, 4) {
            int nx = gx + xr[i];
            int ny = gy + yr[i];
            if (valid(nx, ny, n, m, gf) && dist[nx][ny][dirx[i]] != -1)ans = min(ans, dist[nx][ny][dirx[i]]);
        }
    }
    if(ans<=t)cout<<"YES\n";
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


        solve();

    }
}