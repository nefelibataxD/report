#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_set<ll> s;
        int l = 0, ans = 0;
        for (int r = 0; r < n; r++) {
            while (s.count(a[r])) {
                s.erase(a[l]);
                l++;
            }
            s.insert(a[r]);
            ans = max(ans, r - l + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
