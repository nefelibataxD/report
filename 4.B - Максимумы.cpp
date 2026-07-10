#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll total = 0;
    for (int i = 0; i < n; i++) {
        ll mx = a[i];
        for (int j = i; j < n; j++) {
            mx = max(mx, a[j]);
            total += mx;
        }
    }
    cout << total << "\n";
    return 0;
}
