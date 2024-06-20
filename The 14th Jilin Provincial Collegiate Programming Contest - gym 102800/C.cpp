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
const ll INF = 2e12+5;
#define LINF  2e6+9

#define en cout<<'\n'
#define lp(i,n) for(int i=0;i<n;i++)
#define rlp(i,n) for(int i=n-1;i>=0;i--)
#define MAXN 200005
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

ll MOD = 1e9 + 7;
ll MOD2=  998244353;
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

/*

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
*/


ll mul(ll a, ll b) {
    return (((a % MOD + MOD) * (b % MOD + MOD)) % MOD);
}
ll add(ll a, ll b) {
    return ((a + b) % MOD);
}
ll sub(ll a,ll b){

    return ((a%MOD-b%MOD)%MOD+MOD)%MOD;
}


ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll sumDig(int n){
    ll sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}


// 5-> 9 : 01
// 4: 012
// 3: 0123
// 2: 01234
void burnx(string &t)
{

    string a,b;
    getline(cin,b);
    a=t;

    int m = a.length();
    int n = b.length();

    // Create a table to store results of sub-problems
    vvl  lookup(m+1,vl(n+1,0));

    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;



    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (a[i - 1] == b[j - 1]) {
                lookup[i][j] = (lookup[i - 1][j - 1]%MOD +
                                lookup[i - 1][j]%MOD) % MOD;
            }

            else {

                lookup[i][j] = lookup[i - 1][j] % MOD;
            }
        }
    }

    cout<< lookup[m][n];
    en;
}



int main() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);


    string t;
    while(getline(cin,t)){
        burnx(t);
    }
    return 0;
}