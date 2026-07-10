#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
void shuffle(ll n, vector<ll> dt) {
    ll count = 0;
    while (!is_sorted(dt.begin(), dt.end())) {
        for (int i = 0; i + 1 < n; ++i) {
            if (dt[i] > dt[i + 1]) {
                swap(dt[i], dt[i + 1]);
                count += 1;
            }
        }
    }
    cout << count << '\n';
}
int main() {
    ll n;
    cin >> n;
    while (n > 0) {
        ll k;
        cin >> k;
        vector<ll> dt(k);
        for (int i = 0; i < k; ++i) cin >> dt[i];
        shuffle(k, dt);
        n--;
    }
    return 0;
}
