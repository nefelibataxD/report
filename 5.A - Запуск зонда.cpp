#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
ull gcd(ull a, ull b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    ull ans = 1;
    for (int i = 0; i < n; i++) {
        ull t;
        cin >> t;
        ull g = gcd(ans, t);
        ans = ans / g * t;
    }
    
    cout << ans << "\n";
    
    return 0;
}
