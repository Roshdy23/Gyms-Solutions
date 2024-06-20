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
    //ll xr[]={0,0,1,1};
    //ll yr[]={0,1,0,1};
    const ll mod =  1e9+7;
    const int M =  998244353;




    void solve(int t)
    {

        ll n ;cin>>n;
        ordered_set_pair os;
        vector<ll> v(n);

        set<ll>s;
        vector<ll> val(1e5+7,0);
        ll sum=0;
        fr(i,n)
        {
            cin>>v[i];

            os.insert({v[i],i});
            val[v[i]]=os.order_of_key({v[i],i});
            sum+=val[v[i]];

        }
        s.insert(sum);
        ll m;cin>>m;
        fr(i,m)
        {
         ll u,a;cin>>u>>a;
         u--,a--;
         vector<ll> temp;
         ll min=0;
         ll pos=0;
         for(ll j = u+1;j<a;j++)temp.pb(v[j]);

        if(v[a]<v[u])min++;
        for(auto j:temp) {
            if (v[u] >j)min++;
            if(v[u]<j)pos++;

            if(v[a]>j)pos++;
            if(v[a]<j)min++;
        }
        if(v[a]>v[u])pos++;
        swap(v[a],v[u]);
        sum+=pos;
        sum-=min;
        s.insert(sum);

        }
        cout<<*s.begin()<<nl;
    }


    int main() {
        //    freopen("car.in", "r", stdin);
//            freopen("output.txt", "w", stdout);
        ELROSHDY

        ll t = 1;
     cin>>t;



//    string t;
        while (t--) {


            solve(t);

        }
    }