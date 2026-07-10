#include <iostream>
 
using namespace std;
using ll = long long;
 
const ll MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    ll fact = 1;
    for (ll i = 2; i <= n - 1; i++) {
        fact = (fact * i) % MOD;
    }
    
    ll inv2 = 500000004;
    ll ans = (fact * inv2) % MOD;
    
    cout << ans << "\n";
    
    return 0;
}
