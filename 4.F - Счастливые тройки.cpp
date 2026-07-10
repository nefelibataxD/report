#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= k) {
            j++;
        }
        ll cnt = j - i - 1;
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
