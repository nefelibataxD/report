#include <iostream>
 
using namespace std;
using ll = long long;
 
const ll MOD = 1e9 + 7;
 
ll power(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}
 
ll modInverse(ll n) {
    return power(n, MOD - 2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll b1, q, n;
        cin >> b1 >> q >> n;
        
        b1 %= MOD;
        q %= MOD;
        
        if (q == 1) {
            ll ans = (b1 * (n % MOD)) % MOD;
            cout << ans << "\n";
        } else {
            ll numerator = (power(q, n) - 1 + MOD) % MOD;
            ll denominator = (q - 1 + MOD) % MOD;
            ll ans = (b1 * numerator) % MOD;
            ans = (ans * modInverse(denominator)) % MOD;
            cout << ans << "\n";
        }
    }
    
    return 0;
}
