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

    bool check(int i, int j,vector<vector<char>> &v)
    {
        set<char>s;
        for(int ii = i ; ii<i+3;ii++)
        {
            for(int jj=j;jj<j+3;jj++)
            {
                s.insert(v[ii][jj]);
            }
        }
        return s.size()==9;
    }
  
    void solve(int t)
    {

        vector<vector<char>> v(9,vector<char>(9));
        fr(i,9)
        {
            fr(j,9)
            {
                cin>>v[i][j];
            }
        }

        for(int i=0;i<9;i+=3)
        {
            for(int j= 0 ;j<9;j+=3)
            {
                    if(!check(i,j,v))
                    {
                        cout<<"Invalid\n";
                        return ;
                    }
            }
        }

        fr(i,9)
        {
            set<char>s;
            fr(j,9)
            {
                s.insert(v[i][j]);
            }
            if(s.size()!=9)
            {
                cout<<"Invalid\n";
                return ;
            }
        }

        fr(j,9)
        {
            set<char>s;
            fr(i,9)
            {
                s.insert(v[i][j]);
            }
            if(s.size()!=9)
            {
                cout<<"Invalid\n";
                return ;
            }
        }

        cout<<"Valid\n";

    }


    signed main() {
        //    freopen("car.in", "r", stdin);
        //    freopen("output.txt", "w", stdout);
        ll t = 1;
     cin>>t;
        while (t--)
            solve(t);
    }