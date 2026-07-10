#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<ll> dangerous(n);
    for (int i = 0; i < n; i++) {
        cin >> dangerous[i];
    }
    sort(dangerous.begin(), dangerous.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, f;
        cin >> s >> f;
        int left = min(s, f);
        int right = max(s, f);
        auto it1 = lower_bound(dangerous.begin(), dangerous.end(), left);
        auto it2 = upper_bound(dangerous.begin(), dangerous.end(), right);
        int count = it2 - it1;
        cout << count << '\n';
    }
 
    return 0;
}
