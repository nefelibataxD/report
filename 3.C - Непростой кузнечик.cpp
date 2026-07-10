#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l, r;
    cin >> l >> r;
    
    vector<int> dp(r + 1, 0);
    dp[1] = 1;
    
    for (int i = 1; i <= r; i++) {
        for (int j = 2 * i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }
    long long answer = 0;
    for (int i = l; i <= r; i++) {
        answer = (answer + dp[i]) % MOD;
    }
    
    cout << answer << "\n";
    
    return 0;
}
