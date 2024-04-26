#include<bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;


#define ll long long
#define ld long  double
#define vi vector<int>
#define vc vector<char>
#define vd vector<double>
#define vvi vector<vector<int>>
#define vvd vector<vector<double>>
#define vvc vector<vector<char>>
#define vvp vector<vector<pair<int,int>>>
#define vvpl vector<vector<pair<ll,ll>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vpl vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define vppi vector<pair<int,pair<int,int>>>
#define sz(v) sizeof(v)
#define scn(v) for (auto& i : v)cin >> i;
#define scnp(v) for (auto& i : v)cin >> i.first>>i.second;
#define srt(v) sort(v.begin(),v.end())
#define vb vector<bool>
#define vvb vector<vector<bool>>
//#define f first
//#define s second
#define INF  2e15+5
#define LINF  2e6+9

#define en cout<<'\n'
#define lp(i,n) for(int i=0;i<n;i++)
#define rlp(i,n) for(int i=n-1;i>=0;i--)
#define MAXN 200005
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

ll MOD = 1e9 + 7;
#define pll pair<ll,ll>
#define X first
#define Y second
#define pb push_
#define sINF 9e10;

#define mpi map<int,int>
#define mpl map<ll,ll>
#define YA cout<<"YES"; return;
#define NA cout<<"NO"; return;

ll setBit(ll num, ll idx, ll val = 1) {
    return (val) ? (num | (1 << idx)) : (num & ~(1 << idx));
}
int getBit(ll num, int idx) { return ((num >> idx) & 1) == 1; }

int cntBits(ll num) { int ret = 0; while (num) { if (num % 2)ret++; num /= 2; } return ret; }




ll fastPow(ll x, ll n, ll m) {
    if (n == 0) {
        return 1;
    }
    ll po = fastPow(x, n / 2, m);
    po = (po * po) % m;
    if (n & 1) {
        po *= x;
    }
    return po % m;
}


const int N = 2e5 + 10;
ll Fact[N], FactInv[N];

ll modInv(ll x, ll m) {
    return fastPow(x, m - 2, m) % m;
}
void preFact() {
    Fact[0] = 1;
    for (int i = 1; i < N; i++) {
        Fact[i] = (i * Fact[i - 1]) % MOD;
    }
    FactInv[N - 1] = fastPow(Fact[N - 1], MOD - 2, MOD) % MOD;

    for (int i = N - 2; i >= 0; i--) {
        FactInv[i] = (i + 1) * FactInv[i + 1] % MOD;
    }
}
ll nCr(int n, int r) {

    return Fact[n] * ((FactInv[n - r]) % MOD * FactInv[r] % MOD) % MOD;
}


ll mul(ll a, ll b) {
    return (((a % MOD + MOD) * (b % MOD + MOD)) % MOD);
}
ll add(ll a, ll b) {
    return ((a + b) % MOD);
}

vvl row_wait,col_wait;
ll dp[1000+5][1000+5];
bool vis[1000+5][1000+5];
vvi grid;

ll rec(int i,int j){
    if(i==0&&j==0){
        return 0;
    }
    ll& ret= dp[i][j];
    if(vis[i][j]){
        return ret;
    }
    
    vis[i][j]=1;

    ll ch1=INF; //top
    ll ch2=INF; //left
    if(i>0){
        ch1 = col_wait[i-1][j]*col_wait[i-1][j] + rec(i-1,j);
    }
    if(j>0){
        ch2 = row_wait[i][j-1]*row_wait[i][j-1] + rec(i,j-1);
    }
    return ret = min(ch1,ch2);
}
void burnx(int ts){
    int n,m;
    cin>>n>>m;
    grid = vvi(n,vi(m));
    for(auto &it:grid){
        scn(it);
    }
    row_wait =vvl(n+3,vl(m+3,0));
    col_wait =vvl(n+3,vl(m+3,0));
    for(int j=0;j<m;j++){
        col_wait[1][j]=grid[0][j];
    }
    for(int i=0;i<n;i++){
        row_wait[i][1]=grid[i][0];
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<m;j++){
            col_wait[i][j]=col_wait[i-1][j]+grid[i-1][j];
        }
    }
    for(int j=2;j<=m;j++){
        for(int i=0;i<n;i++){
            row_wait[i][j]=row_wait[i][j-1]+grid[i][j-1];
        }
    }

    cout<<rec(n-1,m-1);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
    int  t = 1;

    //freopen("powers.in", "r", stdin);
    //preFact();
 //   cin >> t;
    while (t) {
        burnx(t+5);
        t--;
        en;
    }
    return 0;
}