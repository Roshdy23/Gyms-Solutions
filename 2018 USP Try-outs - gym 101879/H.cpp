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

const int INP_SIZE = 30000 + 9;
const int QUERIES_SIZE = 30000 + 9;
const int SQRTN = 175;  // sqrt(INP_SIZE)

struct query {
    int l, r, q_idx, block_idx;

    query() {}
    query(int _l, int _r, int _q_idx) {
        l = _l , r = _r , q_idx = _q_idx, block_idx = _l / SQRTN;
    }
    bool operator <(const query& y) const {
        if (block_idx != y.block_idx)
            return block_idx < y.block_idx;
        return r < y.r;
    }
};

int n, m,k; // input size and queries
vector<ll> inp(INP_SIZE);
vector<ll> q_ans(QUERIES_SIZE);
vector<query> queries(QUERIES_SIZE);

// You need to update following data structure
// per problem (e.g. use mutliset)
unordered_map<ll,ll>cnt;
vector<ll> cnt2(INP_SIZE);
set<ll,greater<ll>>s2;
// You need to update these 2 methods per a problem
void add(int idx) {
   cnt[inp[idx]]++;
   cnt2[cnt[inp[idx]]]++;

    ll temp=cnt2[cnt[inp[idx]]];
    if(temp==cnt[inp[idx]])s2.insert(cnt[inp[idx]]);
}

void remove(int idx) {

    cnt2[cnt[inp[idx]]]--;
    ll temp=cnt2[cnt[inp[idx]]];
    if(temp==cnt[inp[idx]]-1)s2.erase(cnt[inp[idx]]);
    cnt[inp[idx]]--;



}

void process() {  // don't change
    sort (queries.begin(),queries.begin()+m);

    int curL = 1, curR = 0; // tricky initialization and indexing
    for (int i = 0; i < m; i++) {
        while (curL < queries[i].l) remove(curL++);
        while (curL > queries[i].l) add(--curL);
        while (curR < queries[i].r) add(++curR);
        while (curR > queries[i].r) remove(curR--);
        q_ans[queries[i].q_idx] = s2.size()>0?*s2.begin():0;
    }

}

void solve(int t)
{
cin>>n>>m;
fr(i,n)cin>>inp[i];
fr(i,m){
    ll l,r;cin>>l>>r;
    l--,r--;
    queries[i]=query(l,r,i);
}
s2.insert(0);
process();
fr(i,m)cout<<q_ans[i]<<nl;
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