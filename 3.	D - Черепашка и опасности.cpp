#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<bool>> dangerous(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        dangerous[x][y] = true;
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dangerous[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    
    cout << dp[n][m] << "\n";
    
    return 0;
}
