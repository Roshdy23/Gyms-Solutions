#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>

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
typedef complex<ld> point;
const ld  PI = acos(-1.0);
//vctor<vector<ll>> gf (N)
ll xr[] = { -1,1,0,0 ,1,-1,-1,1};
ll yr[] = { 0,0,1,-1 ,1,-1,1,-1};
//ll xr[]={0,0,1,1};
//ll yr[]={0,1,0,1};
const ll mod =  1e9+7;
const int M =  1e9+7;
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod,vector<string> &s)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod,s);
    string temp="";
    temp.push_back(from_rod);
    temp.pb(' ');
    temp.pb(to_rod);
    s.pb(temp);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod,s);
}
void solve(int t) {
ll n ,k;cin>>n>>k;

vector<string> s;
    towerOfHanoi(n,'A','C','B',s);
if((k<s.size())||k-s.size()==1)
{
    cout<<"N\n";
}
else
{
    if((k-s.size())&1)
    {
        cout<<"Y\n";
        for (auto i: s)cout << i << nl;
        cout<<"C B\n";
        fr(i,k-s.size()-2)
        {
            if(i%2==0)
            {
             cout<<"B A\n";
            }
            else
            {
                cout<<"A B\n";
            }
        }
        if((k-s.size()-2)%2==0)cout<<"B C\n";
        else cout<<"A C\n";
    }
    else {
        cout << "Y\n";
        fr(i, k - s.size()) {
            if (i % 2 == 0) {
                cout << "A B\n";
            } else {
                cout << "B A\n";
            }
        }
        for (auto i: s)cout << i << nl;
    }
}
}
int main() {
    //    freopen("car.in", "r", stdin);
    //            freopen("output.txt", "w", stdout);
    ELROSHDY

    ll t = 1;
//         cin>>t;




    while (t--) {


        solve(t);

    }
}