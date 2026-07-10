#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> price(n + 2);
    price[1] = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        price[i + 1] = price[i] + a;
    }
    ll best_profit = 0;
    int buy = -1, sell = -1;
    ll min_price = price[1];
    int min_pos = 1;
    for (int j = 2; j <= n + 1; j++) {
        ll profit = price[j] - min_price;
        if (profit > best_profit) {
            best_profit = profit;
            buy = min_pos;
            sell = j;
        } else if (profit == best_profit && profit > 0) {
            if (min_pos < buy || (min_pos == buy && j < sell)) {
                buy = min_pos;
                sell = j;
            }
        }
        if (price[j] < min_price) {
            min_price = price[j];
            min_pos = j;
        }
    }
    if (best_profit <= 0) {
        cout << "-1 -1\n";
    } else {
        cout << buy << " " << sell << "\n";
    }
    return 0;
}
