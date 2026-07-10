#include <iostream>
#include <string>
#include <vector>
#include <map>
 
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
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    map<char, int> cnt;
    for (char c : s) cnt[c]++;
    
    ll fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    
    ll denom = 1;
    for (auto& p : cnt) {
        ll f = 1;
        for (int i = 1; i <= p.second; i++) {
            f = (f * i) % MOD;
        }
        denom = (denom * f) % MOD;
    }
    
    ll ans = (fact * modInverse(denom)) % MOD;
    cout << ans << "\n";
    
    return 0;
}
