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

void solve(int t) {
int n ;cin>>n;
vector<ll> v(n);
fr(i,n)
{
    cout<<"get "<<i+1<<endl;
    cout.flush();
    int val;cin>>val;
    v[i]=val;
}
set<int,greater<int>> two,one,zero;
int cnt=0;
fr(i,n)
{
    if(v[i]==0)
    {
        zero.insert(i);
    }
    else if(v[i]==1)
    {
        one.insert(i);
    }
    else
    {
        two.insert(i);
    }
}

for(int i=n-1;i>=0;i--)
{
    if(v[i]==1)
    {
        auto it=two.lower_bound(i);
        if(it!=two.end()&&*it<i)
        {
            int ind=*it;
            swap(v[i],v[ind]);
          cout<<"swap "<<i+1<<' '<<ind+1<<endl;
          cout.flush();

            one.insert(*it);
            two.erase(it);
        }
    }
    else if(v[i]==0)
    {
        auto it=two.lower_bound(i);
        if(it!=two.end()&&*it<i)
        {
            int ind=*it;
            swap(v[i],v[ind]);
            cout<<"swap "<<i+1<<' '<<ind+1<<endl;
            cout.flush();
            two.erase(it);
        }
        else
        {
            auto it2=one.lower_bound(i);
            if(it2!=one.end()&&*it2<i)
            {
                int ind=*it2;
                swap(v[i],v[ind]);
                cout<<"swap "<<i+1<<' '<<ind+1<<endl;
                cout.flush();
                one.erase(it2);
            }
        }
    }
    else
    {
        cnt++;
    }
}
cout<<"Sorted!"<<endl;
cout.flush();
}
int main() {
    //    freopen("car.in", "r", stdin);
    //            freopen("output.txt", "w", stdout);
    ELROSHDY

    ll t = 1;
//         cin>>t;



    //    string t;
    while (t--) {


        solve(t);

    }
}