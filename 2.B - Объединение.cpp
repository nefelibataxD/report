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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }
 
    for (int i = 0; i < n - 1; i++) {
        ll a = pq.top(); pq.pop();  
        ll b = pq.top(); pq.pop();
        cout << a << " " << b << "\n";
        pq.push(a + b);  
    }
    return 0;
}
