#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    vector<ll> dt(n);
    for (int i = 0; i < n; ++i) {
        cin >> dt[i];
    }
 
    int l, r;
    while (cin >> l >> r) {
        if (l == 0 && r == 0) break;       
        reverse(dt.begin() + (l - 1), dt.begin() + r);
    }
 
    for (int i = 0; i < n; ++i) {
        cout << dt[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
 
    return 0;
}
