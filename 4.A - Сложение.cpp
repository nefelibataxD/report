#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<ll> diff(n + 2, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        ll v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }
    ll current = 0;
    for (int i = 1; i <= n; i++) {
        current += diff[i];
        cout << current << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}
