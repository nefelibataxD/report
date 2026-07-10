#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, k, m;
    cin >> n >> k >> m;
 
    vector<bool> is_bad(n + 1, false);
    for (int i = 0; i < m; i++) {
        int bad_point;
        cin >> bad_point;
        is_bad[bad_point] = true;
    }
    vector<long long> dp(n + 1, 0);
    long long MOD = 1e9 + 7;
 
    dp[0] = 1; 
    for (int i = 1; i <= n; i++) {
        if (is_bad[i]) {
            dp[i] = 0;
            continue;
        }
 
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            } else {
                break; 
            }
        }
    }
 
    cout << dp[n] << endl;
 
    return 0;
}
