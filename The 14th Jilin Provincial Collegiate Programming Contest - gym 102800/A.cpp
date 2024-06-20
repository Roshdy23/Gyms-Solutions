#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;
const int N = 1e5 + 7;
const int M = 1e6 + 7;
const int LOG = 18;
const int MOD = 1e9 + 7;
const ll inf = 1e13;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
string arr[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#",
                "G",
                "G#", "A", "A#", "B"};

void solve() {
    string n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int pos1, pos2, pos3;
    for (int i = 0; i < 22; ++i) {
        if (arr[i] == n1) {
            pos1 = i;
            for (int j = i; j < 22; ++j) {
                if (arr[j] == n2) {
                    pos2 = j;
                    for (int k = j; k < 22; ++k) {
                        if (arr[k] == n3) {
                            pos3 = k;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    if (pos2 - pos1 == 4 && pos3 - pos2 == 3)
        cout << "Major triad";
    else if (pos2 - pos1 == 3 && pos3 - pos2 == 4)
        cout << "Minor triad";
    else cout << "Dissonance";
    cout << endl;
}


int32_t main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    fast


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}